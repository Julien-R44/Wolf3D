/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 06:08:14 by jripoute          #+#    #+#             */
/*   Updated: 2015/03/25 13:51:05 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_stripe_sprite(t_mega *all, t_dsprite *spr, int stripe, t_img *img)
{
	int texelw;
	int texelt;
	int y;
	int d;
	int texy;

	y = spr->start.y;
	while (y < spr->end.y)
	{
		d = (y * 256) - ((HWIN) * 128) + (spr->h * 128);
		texy = ((d * 64) / spr->h) / 256;
		texelw = (stripe * (all->img.bpp / 8)) + (y * all->img.sizeline);
		texelt = (spr->texx * (img->bpp / 8)) + (texy * img->sizeline);
		if (img->data[texelt] != 0 || img->data[texelt + 1] != 0
			|| img->data[texelt + 2] != 0)
		{
			all->img.data[texelw] = img->data[texelt];
			all->img.data[texelw + 1] = img->data[texelt + 1];
			all->img.data[texelw + 2] = img->data[texelt + 2];
		}
		y++;
	}
}

void	calc_draw_stripe(t_mega *all, t_dsprite *sp, t_sprite *act)
{
	double		inv;
	t_dpos		spritepos;

	spritepos.x = (act->x) - all->cam.pos.x;
	spritepos.y = (act->y) - all->cam.pos.y;
	inv = 1.0 / (all->cam.cam.x * all->cam.dir.y - all->cam.dir.x
		* all->cam.cam.y);
	sp->transform.x = inv * (all->cam.dir.y * spritepos.x - all->cam.dir.x
		* spritepos.y);
	sp->transform.y = inv * (-all->cam.cam.y * spritepos.x + all->cam.cam.x
		* spritepos.y);
	sp->h = abs((int)(HWIN / sp->transform.y));
	sp->start.y = -sp->h / 2 + HWIN / 2;
	sp->start.y = (sp->start.y < 0) ? 0 : sp->start.y;
	sp->end.y = sp->h / 2 + HWIN / 2;
	if (sp->end.y >= HWIN)
		sp->end.y = HWIN - 1;
	sp->w = abs((int)(HWIN / (sp->transform.y)));
	sp->screenx = (int)((WWIN / 2) * (1 + sp->transform.x / sp->transform.y));
	sp->start.x = -sp->w / 2 + sp->screenx;
	if (sp->start.x < 0)
		sp->start.x = 0;
	sp->end.x = sp->w / 2 + sp->screenx;
	if (sp->end.x >= WWIN)
		sp->end.x = WWIN - 1;
}

void	insert_sort(t_dlist **list)
{
	t_dlist	*ins;
	double	elem;
	int		len;
	int		i;
	int		j;

	j = 0;
	i = 0;
	len = ft_dlstlen(*list);
	while (i < len)
	{
		j = i;
		ins = ft_dlstati(*list, i + 1);
		elem = ((t_sprite *)ins->content)->distance;
		while (j > 0 && ((t_sprite *)ins->before->content)->distance < elem)
		{
			ft_swap_contents(&ins, &ins->before);
			ins = ins->before;
			j--;
		}
		i++;
	}
}

void	sort_sprite_distance(t_mega *all, t_dlist *sprites)
{
	t_dlist		*nav;
	t_sprite	*act;

	nav = sprites;
	while (nav)
	{
		act = nav->content;
		if (act->texture == -1)
			ft_dlstdelone(&nav, NULL);
		act->distance = ((all->cam.pos.x - act->x) * (all->cam.pos.x - act->x)
			+ (all->cam.pos.y - act->y) * (all->cam.pos.y - act->y));
		nav = nav->next;
	}
	insert_sort(&sprites);
}

void	display_sprite(t_mega *all, double zbuffer[WWIN])
{
	t_dsprite	sprite;
	t_text		*text;
	t_dlist		*nav;
	t_sprite	*act;

	nav = all->sprites;
	sort_sprite_distance(all, all->sprites);
	while (nav)
	{
		act = nav->content;
		text = &all->text[act->texture];
		calc_draw_stripe(all, &sprite, act);
		while (sprite.start.x < sprite.end.x)
		{
			sprite.texx = (int)(256 * (sprite.start.x -
				(-sprite.w / 2 + sprite.screenx)) * 64 / sprite.w) / 256;
			if (sprite.transform.y > 0 && sprite.start.x > 0
			&& sprite.start.x < WWIN
			&& sprite.transform.y < zbuffer[sprite.start.x])
				draw_stripe_sprite(all, &sprite, sprite.start.x, &text->img);
			sprite.start.x++;
		}
		nav = nav->next;
	}
}

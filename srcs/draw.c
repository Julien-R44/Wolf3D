/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 04:57:19 by jripoute          #+#    #+#             */
/*   Updated: 2015/03/25 13:41:28 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	vanilla_mode(t_mega *all, t_ray *r, int y, int x)
{
	unsigned int color;

	color = 0xFCE298;
	if (r->c == 1)
		color = 0x2D2532;
	if (r->c == 2)
		color = 0x562F5B;
	if (r->c == 3)
		color = 0x888BC2;
	while (y < r->end.y)
	{
		ft_memcpy(&all->img.data[x * 4 + y * all->img.sizeline],
			&color, (sizeof(int)));
		y++;
	}
}

void		set_texture_to_image(t_mega *all, t_text *text, t_ray *r, int tex)
{
	int texy;
	int y;
	int x;
	int texelw;
	int	texelt;

	y = r->start.y;
	x = r->start.x;
	if (all->hook.vanilla)
	{
		vanilla_mode(all, r, y, x);
		return ;
	}
	while (y < r->end.y)
	{
		texy = ((((y * 256) - ((HWIN) * 128) +
			(r->line_h * 128)) * text->h) / r->line_h) / 256;
		texy = abs(texy);
		texelw = (x * (all->img.bpp / 8)) + (y * all->img.sizeline);
		texelt = (tex * (text->img.bpp / 8)) + (texy * text->img.sizeline);
		ft_memcpy(&all->img.data[texelw], &text->img.data[texelt], 3);
		y++;
	}
}

void		draw_skybox(t_mega *all, t_ray *r, int x)
{
	int		i;
	int		texelw;
	int		texelt;
	t_pos	sky;
	t_text	*skybox;

	i = 0;
	skybox = &all->text[SKYBOX];
	sky.x = (int)getdree(&r->dir);
	sky.x = (int)(((double)sky.x / 360.0) * skybox->w);
	sky.x = skybox->w - sky.x;
	while (i < HWIN / 2)
	{
		sky.y = ((double)i / ((double)HWIN / 2.0)) * skybox->h;
		texelw = i * all->img.sizeline + x * (all->img.bpp / 8);
		texelt = sky.y * skybox->img.sizeline + (skybox->img.bpp / 8) * sky.x;
		all->img.data[texelw] = skybox->img.data[texelt];
		all->img.data[texelw + 1] = skybox->img.data[texelt + 1];
		all->img.data[texelw + 2] = skybox->img.data[texelt + 2];
		i++;
	}
}

void		draw_sky_floor(t_mega *all, t_text *sky, t_text *floor, t_ray *r)
{
	int texelw;
	int texelt;

	texelt = (r->tex.x * (sky->img.bpp / 8)) + (r->tex.y * sky->img.sizeline);
	texelw = (r->start.x * (all->img.bpp / 8)) +
	((HWIN - r->end.y) * all->img.sizeline);
	if (all->hook.skybox == 0)
	{
		all->img.data[texelw] = sky->img.data[texelt];
		all->img.data[texelw + 1] = sky->img.data[texelt + 1];
		all->img.data[texelw + 2] = sky->img.data[texelt + 2];
	}
	draw_floor(all, floor, r, texelt);
}

void		draw_floor(t_mega *all, t_text *text, t_ray *r, int texelt)
{
	int texelw;

	texelw = (r->start.x * (all->img.bpp / 8)) + (r->end.y * all->img.sizeline);
	all->img.data[texelw] = text->img.data[texelt];
	all->img.data[texelw + 1] = text->img.data[texelt + 1];
	all->img.data[texelw + 2] = text->img.data[texelt + 2];
}

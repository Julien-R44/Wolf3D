/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dooorz.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 11:35:43 by jripoute          #+#    #+#             */
/*   Updated: 2015/03/25 13:37:01 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		get_door_to_draw(t_ray *r, t_door *d)
{
	d->is = 1;
	get_lign_to_draw(r, &d->r, r->start.x);
	d->tex_x = (int)(d->r.wall_x * (double)(64));
	if (r->side == 0 && r->dir.x > 0)
		d->tex_x = 64 - d->tex_x - 1;
	if (r->side == 1 && r->dir.y < 0)
		d->tex_x = 64 - d->tex_x - 1;
}

void		draw_door(t_mega *all, t_ray *d)
{
	int				dec;
	int				texy;
	int				tw;
	int				tt;
	t_text			*text;

	text = &all->text[DOOR];
	all->door.tex_x -= all->door.x;
	d->start.y -= 1;
	if (all->door.tex_x <= 0)
		return ;
	while (++d->start.y < d->end.y)
	{
		dec = d->start.y * 256 - HWIN * 128 + all->door.r.line_h * 128;
		texy = ((dec * text->h) / all->door.r.line_h) / 256;
		tw = d->start.y * all->img.sizeline + d->start.x * (all->img.bpp / 8);
		tt = (texy * text->img.sizeline + text->img.bpp / 8 * all->door.tex_x);
		if (text->img.data[tt] || text->img.data[tt + 1] ||
			text->img.data[tt + 2])
		{
			all->img.data[tw] = text->img.data[tt];
			all->img.data[tw + 1] = text->img.data[tt + 1];
			all->img.data[tw + 2] = text->img.data[tt + 2];
		}
	}
}

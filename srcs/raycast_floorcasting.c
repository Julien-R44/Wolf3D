/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_floorcasting.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 03:28:59 by y0ja              #+#    #+#             */
/*   Updated: 2015/03/24 20:57:59 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	get_lign_to_draw2(t_ray *r, t_ray *r2, int x)
{
	if (r->side == 0)
		r2->wall_dist = fabs((r->map.x - r->pos.x +
			(1 - r->step.x) / 2) / r->dir.x);
	else
		r2->wall_dist = fabs((r->map.y - r->pos.y +
			(1 - r->step.y) / 2) / r->dir.y);
	r2->line_h = abs((int)(HWIN / r2->wall_dist));
	if (r->side == 0 && r->dir.x > 0)
		r2->c = 1;
	else if (r->side == 0 && r->dir.x < 0)
		r2->c = 2;
	else if (r->side == 1 && r->dir.y > 0)
		r2->c = 3;
	else
		r2->c = 4;
}

void		get_lign_to_draw(t_ray *r, t_ray *r2, int x)
{
	get_lign_to_draw2(r, r2, x);
	if ((r2->start.y = -(r2->line_h) / 2 + HWIN / 2) < 0)
		r2->start.y = 0;
	if ((r2->end.y = r2->line_h / 2 + HWIN / 2) >= HWIN)
		r2->end.y = HWIN - 1;
	if (r->side == 1)
		r2->wall_x = r->pos.x + ((r->map.y - r->pos.y +
			(1 - r->step.y) / 2) / r->dir.y) * r->dir.x;
	else
		r2->wall_x = r->pos.y + ((r->map.x - r->pos.x +
			(1 - r->step.x) / 2) / r->dir.x) * r->dir.y;
	r2->wall_x -= floor(r2->wall_x);
	r2->start.x = x;
	r2->end.x = x;
}

void		draw_column_with_text(t_mega *all, t_ray *r)
{
	int		texx;
	t_text	*text;

	text = &all->text[all->map.map[r->map.x][r->map.y]] - 1;
	texx = (int)(r->wall_x * (double)(text->w));
	if (r->side == 0 && r->dir.x > 0)
		texx = text->w - texx - 1;
	if (r->side == 1 && r->dir.x < 0)
		texx = text->w - texx - 1;
	set_texture_to_image(all, text, r, texx);
}

void		get_orientation(t_ray *r, t_dpos *floor_wall)
{
	if (r->side == 0 && r->dir.x > 0)
	{
		floor_wall->x = r->map.x;
		floor_wall->y = r->map.y + r->wall_x;
	}
	else if (r->side == 0 && r->dir.x < 0)
	{
		floor_wall->x = r->map.x + 1.0;
		floor_wall->y = r->map.y + r->wall_x;
	}
	else if (r->side == 1 && r->dir.y > 0)
	{
		floor_wall->x = r->map.x + r->wall_x;
		floor_wall->y = r->map.y;
	}
	else
	{
		floor_wall->x = r->map.x + r->wall_x;
		floor_wall->y = r->map.y + 1.0;
	}
}

void		floor_casting(t_mega *all, t_ray *r)
{
	t_text	*text_floor;
	t_text	*text_sky;
	t_dpos	floor_wall;
	double	weight;
	double	dist;

	text_sky = &all->text[CEIL];
	text_floor = all->text_floor;
	get_orientation(r, &floor_wall);
	while (r->end.y < HWIN)
	{
		dist = HWIN / (2.0 * r->end.y - HWIN);
		weight = (dist - 0.0) / (r->wall_dist - 0.0);
		r->cur.x = weight * floor_wall.x + (1.0 - weight) * r->pos.x;
		r->cur.y = weight * floor_wall.y + (1.0 - weight) * r->pos.y;
		r->tex.x = (int)(r->cur.x * text_floor->w) % text_floor->w;
		r->tex.y = (int)(r->cur.y * text_floor->h) % text_floor->h;
		draw_sky_floor(all, text_sky, text_floor, r);
		r->end.y++;
	}
}

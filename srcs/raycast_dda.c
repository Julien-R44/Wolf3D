/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_dda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 02:07:36 by y0ja              #+#    #+#             */
/*   Updated: 2015/03/24 20:57:46 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MX_RAYPOS all->map.map[r->map.x][r->map.y]

#include "wolf3d.h"

void	new_ray(t_cam *cam, t_ray *r, int x)
{
	r->cam_x = (2 * x / ((double)WWIN)) - 1;
	r->pos.x = cam->pos.x;
	r->pos.y = cam->pos.y;
	r->dir.x = cam->dir.x + cam->cam.x * r->cam_x;
	r->dir.y = cam->dir.y + cam->cam.y * r->cam_x;
	r->map.x = ((int)r->pos.x);
	r->map.y = ((int)r->pos.y);
	r->delta.x = sqrt(1 + r->dir.y * r->dir.y / (r->dir.x * r->dir.x));
	r->delta.y = sqrt(1 + r->dir.x * r->dir.x / (r->dir.y * r->dir.y));
}

void	raycasting_calcul(t_mega *all)
{
	int		x;
	t_ray	r;
	double	zbuffer[WWIN];

	x = 0;
	while (x < WWIN)
	{
		all->door.is = 0;
		new_ray(&all->cam, &r, x);
		find_side_dist(&r);
		find_wall(all, &r);
		draw_skybox(all, &r, x);
		get_lign_to_draw(&r, &r, x);
		draw_column_with_text(all, &r);
		zbuffer[x] = r.wall_dist;
		floor_casting(all, &r);
		if (all->door.is && all->door.x != 64)
		{
			draw_door(all, &all->door.r);
			zbuffer[x] = all->door.r.wall_dist;
		}
		x++;
	}
	display_sprite(all, zbuffer);
}

void	find_side_dist(t_ray *r)
{
	if (r->dir.x < 0)
	{
		r->step.x = -1;
		r->side_dist.x = (r->pos.x - (int)r->pos.x) * r->delta.x;
	}
	else
	{
		r->step.x = 1;
		r->side_dist.x = ((int)r->pos.x + 1.0 - r->pos.x) * r->delta.x;
	}
	if (r->dir.y < 0)
	{
		r->step.y = -1;
		r->side_dist.y = (r->pos.y - (int)r->pos.y) * r->delta.y;
	}
	else
	{
		r->step.y = 1;
		r->side_dist.y = ((int)r->pos.y + 1.0 - r->pos.y) * r->delta.y;
	}
}

void	find_wall(t_mega *all, t_ray *r)
{
	while (42)
	{
		if (r->side_dist.x < r->side_dist.y)
		{
			r->map.x += r->step.x;
			r->side_dist.x += r->delta.x;
			r->side = 0;
		}
		else
		{
			r->map.y += r->step.y;
			r->side_dist.y += r->delta.y;
			r->side = 1;
		}
		if (r->map.x == 0)
			break ;
		if (MX_RAYPOS == NDOOR)
			get_door_to_draw(r, &all->door);
		else if (MX_RAYPOS > 0)
			break ;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 01:51:29 by y0ja              #+#    #+#             */
/*   Updated: 2015/03/24 20:57:16 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int		dcheck(t_mega *all, int x, int y)
{
	if (all->map.map[x][(int)(all->cam.pos.y)] == NDOOR && all->door.x == 64)
		return (1);
	if (all->map.map[(int)(all->cam.pos.x)][y] == NDOOR && all->door.x == 64)
		return (1);
	return (0);
}

void			move_up_down(t_mega *all, int mode)
{
	int x;
	int y;

	if (mode == UP)
	{
		x = all->cam.pos.x + all->cam.dir.x * all->cam.speed;
		y = all->cam.pos.y + all->cam.dir.y * all->cam.speed;
		if (dcheck(all, x, y) || all->map.map[x][(int)(all->cam.pos.y)] == 0)
			all->cam.pos.x += all->cam.dir.x * all->cam.speed;
		if (dcheck(all, x, y) || all->map.map[(int)(all->cam.pos.x)][y] == 0)
			all->cam.pos.y += all->cam.dir.y * all->cam.speed;
	}
	else if (mode == DOWN)
	{
		x = all->cam.pos.x - all->cam.dir.x * all->cam.speed;
		y = all->cam.pos.y - all->cam.dir.y * all->cam.speed;
		if (dcheck(all, x, y) || all->map.map[x][(int)(all->cam.pos.y)] == 0)
			all->cam.pos.x -= all->cam.dir.x * all->cam.speed;
		if (dcheck(all, x, y) || all->map.map[(int)(all->cam.pos.x)][y] == 0)
			all->cam.pos.y -= all->cam.dir.y * all->cam.speed;
	}
	all->e.refresh = 1;
}

void			strafe(t_mega *all, int mode)
{
	int x;
	int y;

	if (mode == RIGHT)
	{
		x = all->cam.pos.x + all->cam.cam.x * (all->cam.strafe_speed);
		y = all->cam.pos.y + all->cam.cam.y * (all->cam.strafe_speed);
		if (dcheck(all, x, y) || all->map.map[x][(int)(all->cam.pos.y)] == 0)
			all->cam.pos.x += all->cam.cam.x * (all->cam.strafe_speed);
		if (dcheck(all, x, y) || all->map.map[(int)(all->cam.pos.x)][y] == 0)
			all->cam.pos.y += all->cam.cam.y * (all->cam.strafe_speed);
	}
	if (mode == LEFT)
	{
		x = all->cam.pos.x - all->cam.cam.x * (all->cam.strafe_speed);
		y = all->cam.pos.y - all->cam.cam.y * (all->cam.strafe_speed);
		if (dcheck(all, x, y) || all->map.map[x][(int)(all->cam.pos.y)] == 0)
			all->cam.pos.x -= all->cam.cam.x * (all->cam.strafe_speed);
		if (dcheck(all, x, y) || all->map.map[(int)(all->cam.pos.x)][y] == 0)
			all->cam.pos.y -= all->cam.cam.y * (all->cam.strafe_speed);
	}
	all->e.refresh = 1;
}

void			turn(t_mega *all, double direction)
{
	double oldx;
	double oldpx;

	oldx = all->cam.dir.x;
	oldpx = all->cam.cam.x;
	all->cam.dir.x = all->cam.dir.x * cos(direction)
		- all->cam.dir.y * sin(direction);
	all->cam.dir.y = oldx * sin(direction) + all->cam.dir.y * cos(direction);
	all->cam.cam.x = all->cam.cam.x * cos(direction)
		- all->cam.cam.y * sin(direction);
	all->cam.cam.y = oldpx * sin(direction) + all->cam.cam.y * cos(direction);
	all->e.refresh = 1;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/01 07:00:55 by jripoute          #+#    #+#             */
/*   Updated: 2015/03/24 20:52:53 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init_map(t_map *map)
{
	map->map = NULL;
	map->width = 0;
	map->height = 0;
	map_parser(map);
}

void	init_hook(t_hook *hook)
{
	hook->shoot = 0;
	hook->up = 0;
	hook->down = 0;
	hook->left = 0;
	hook->right = 0;
	hook->strafe_left = 0;
	hook->strafe_right = 0;
	hook->minimap_enable = 0;
	hook->vdoor = 0;
	hook->action = 0;
	hook->bullet = 0;
	hook->skybox = 0;
}

void	init_cam(t_cam *cam, int posx, int posy)
{
	cam->speed = MOVESPEED;
	cam->rotspeed = ROTSPEED;
	cam->strafe_speed = STRAFE_SPEED;
	cam->pos.x = posx;
	cam->pos.y = posy;
	cam->dir.x = -1;
	cam->dir.y = 0;
	cam->cam.x = 0;
	cam->cam.y = 1;
	cam->statw = 0;
}

void	init_player(t_player *player)
{
	player->life = 100;
	player->ammo = 0;
	player->key = 0;
	player->weapon = KNIFE;
}

void	init_struct(t_mega *all)
{
	all->e.refresh = 1;
	init_hook(&all->hook);
	init_cam(&all->cam, (int)START_X, (int)START_Y);
	init_player(&all->player);
	init_textures(all);
	all->sprites = init_sprites(all);
	init_minimap(&all->e, &all->hook.minimap);
	stock_minimap(all);
	all->door.x = 0;
}

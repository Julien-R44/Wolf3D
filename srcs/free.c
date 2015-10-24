/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 03:44:39 by jripoute          #+#    #+#             */
/*   Updated: 2015/03/24 20:51:38 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	free_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->height)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
}

void	free_text_hud_weapon(t_mega *all)
{
	int i;
	int ret;

	i = 0;
	mlx_destroy_image(all->e.mlx, all->hook.minimap.img);
	while (all->text[i].filename)
	{
		mlx_destroy_image(all->e.mlx, all->text[i].img.img);
		i++;
	}
	free(all->text);
	i = 0;
	while (i < 5)
	{
		mlx_destroy_image(all->e.mlx, all->hud[i].img.img);
		mlx_destroy_image(all->e.mlx, all->weapon[i].img.img);
		i++;
	}
	free(all->hud);
	free(all->weapon);
}

void	free_sprites(t_dlist *sprites)
{
	ft_dlstdel(&sprites, NULL);
}

void	exit_free(t_mega *all)
{
	free_map(&all->map);
	free_text_hud_weapon(all);
	free_sprites(all->sprites);
	mlx_destroy_window(all->e.mlx, all->e.wmlx);
	exit(-1);
}

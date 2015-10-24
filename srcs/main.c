/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 15:49:46 by y0ja              #+#    #+#             */
/*   Updated: 2015/03/25 13:37:22 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		expose_hook(t_mega *all)
{
	all->e.refresh = 1;
	return (1);
}

void	init_game(t_mega *all)
{
	all->player.gun_loot = 0;
	init_map(&all->map);
	if ((all->e.mlx = mlx_init()) == NULL)
		ft_error(3);
	init_struct(all);
	all->e.wmlx = mlx_new_window(all->e.mlx, WWIN_HUD, HWIN_HUD, "Wolf 3D");
	all->img.img = mlx_new_image(all->e.mlx, WWIN, HWIN);
	all->img.data = mlx_get_data_addr(all->img.img, &all->img.bpp,
		&all->img.sizeline, &all->img.endian);
	all->text_floor = &all->text[CEIL];
	all->hook.vanilla = 0;
	all->hook.skybox = 0;
}

int		main(int argc, char const *argv[])
{
	t_mega all;

	init_game(&all);
	mlx_hook(all.e.wmlx, KEYPRESS, KEYPRESSMASK, &press_key_hook, &all);
	mlx_hook(all.e.wmlx, KEYRELEASE, KEYRELEASEMASK, &release_key_hook, &all);
	mlx_expose_hook(all.e.wmlx, expose_hook, &all);
	mlx_loop_hook(all.e.mlx, loop_hook, &all);
	mlx_loop(all.e.mlx);
	return (0);
}

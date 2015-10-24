/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 23:41:52 by jripoute          #+#    #+#             */
/*   Updated: 2015/03/24 20:52:41 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		mlx_put_img(t_mega *all, void *img_ptr, int x, int y)
{
	mlx_put_image_to_window(all->e.mlx, all->e.wmlx, img_ptr, x, y);
}

static void		update_nb_ammo(t_mega *all)
{
	int nb;

	nb = 4 + all->player.ammo;
	mlx_put_image_to_window(all->e.mlx, all->e.wmlx, all->hud[nb].img.img,
		(1125), (HWIN_HUD - all->hud[nb].h - 40));
}

void			display_hud(t_mega *all)
{
	mlx_put_img(all, all->hud[1].img.img, 0, 20);
	mlx_put_img(all, all->hud[3].img.img, 0, 0);
	mlx_put_img(all, all->hud[2].img.img, (WWIN_HUD - all->hud[2].w), 20);
	mlx_put_img(all, all->hud[0].img.img, (WWIN_HUD - all->hud[0].w) / 2,
		(HWIN_HUD - all->hud[0].h));
	if (all->player.key == 1)
		mlx_put_img(all, all->hud[14].img.img,
			(WWIN_HUD - 235), (HWIN_HUD - 295));
	if (all->player.weapon == KNIFE)
		mlx_put_img(all, all->hud[15].img.img,
			(WWIN_HUD - 330), (HWIN_HUD - 150));
	else
		mlx_put_img(all, all->hud[16].img.img,
			(WWIN_HUD - 330), (HWIN_HUD - 150));
	update_nb_ammo(all);
}

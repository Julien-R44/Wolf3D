/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 20:40:52 by lubaujar          #+#    #+#             */
/*   Updated: 2015/03/24 11:10:56 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		load_weapon(t_mega *all, char *file, int i)
{
	all->weapon[i].img.img = mlx_xpm_file_to_image(all->e.mlx, file,
		&all->weapon[i].w, &all->weapon[i].h);
}

static void		load_hud(t_mega *all, char *file, int i)
{
	all->hud[i].img.img = mlx_xpm_file_to_image(all->e.mlx, file,
		&all->hud[i].w, &all->hud[i].h);
}

static void		init_weapon_hud2(t_mega *all)
{
	load_hud(all, "./xpm/hud/top.xpm", 3);
	load_hud(all, "./xpm/hud/0.xpm", 4);
	load_hud(all, "./xpm/hud/1.xpm", 5);
	load_hud(all, "./xpm/hud/2.xpm", 6);
	load_hud(all, "./xpm/hud/3.xpm", 7);
	load_hud(all, "./xpm/hud/4.xpm", 8);
	load_hud(all, "./xpm/hud/5.xpm", 9);
	load_hud(all, "./xpm/hud/6.xpm", 10);
	load_hud(all, "./xpm/hud/7.xpm", 11);
	load_hud(all, "./xpm/hud/8.xpm", 12);
	load_hud(all, "./xpm/hud/9.xpm", 13);
	load_hud(all, "./xpm/hud/key_hud.xpm", 14);
	load_hud(all, "./xpm/hud/knife.xpm", 15);
	load_hud(all, "./xpm/hud/gun.xpm", 16);
}

void			init_weapon_hud(t_mega *all)
{
	all->weapon = (t_text *)ft_memalloc(sizeof(t_text) * 10);
	load_weapon(all, "./xpm/weapon/gun1.xpm", 0);
	load_weapon(all, "./xpm/weapon/gun2.xpm", 1);
	load_weapon(all, "./xpm/weapon/gun3.xpm", 2);
	load_weapon(all, "./xpm/weapon/gun4.xpm", 3);
	load_weapon(all, "./xpm/weapon/gun5.xpm", 4);
	load_weapon(all, "./xpm/weapon/knife1.xpm", 5);
	load_weapon(all, "./xpm/weapon/knife2.xpm", 6);
	load_weapon(all, "./xpm/weapon/knife3.xpm", 7);
	load_weapon(all, "./xpm/weapon/knife4.xpm", 8);
	load_weapon(all, "./xpm/weapon/knife5.xpm", 9);
	all->hud = (t_text *)ft_memalloc(sizeof(t_text) * 17);
	load_hud(all, "./xpm/hud/bottom.xpm", 0);
	load_hud(all, "./xpm/hud/left.xpm", 1);
	load_hud(all, "./xpm/hud/right.xpm", 2);
	init_weapon_hud2(all);
}

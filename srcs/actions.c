/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 02:26:58 by jripoute          #+#    #+#             */
/*   Updated: 2015/03/24 20:48:07 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

#define POS_X (int)all->cam.pos.x
#define POS_Y (int)all->cam.pos.y

static void		display_screamer(t_mega *all)
{
	t_sprite	content;

	content.x = 4;
	content.y = 33.5;
	content.texture = SCREAM;
	ft_dlstadd_end(&all->sprites, ft_dlstnew(&content, sizeof(t_sprite)));
	all->e.refresh = 1;
}

void			open_door(t_mega *all)
{
	if ((POS_X == 2 && POS_Y == 7) || (POS_X == 8 && POS_Y == 16))
		all->hook.vdoor = -1;
	if (all->hook.vdoor)
	{
		all->door.x += all->hook.vdoor;
		if (all->door.x > 64 || all->door.x < 0)
		{
			all->door.x -= (all->hook.vdoor);
			all->hook.vdoor = 0;
		}
		else
			all->e.refresh = 1;
	}
}

void			do_something(t_mega *all)
{
	if (((POS_X == 2 && POS_Y == 5) || (POS_X == 10 && POS_Y == 16)
		|| (POS_X == 16 && POS_Y == 28)) && all->player.key == 1)
	{
		all->hook.vdoor = (all->hook.vdoor == 1) ? -1 : 1;
		all->player.key = 0;
	}
	if (POS_X == 6 && (POS_Y == 30 || POS_Y == 31))
	{
		all->player.key = 1;
		all->e.refresh = 1;
	}
	if (POS_X == 3 && POS_Y == 33)
		display_screamer(all);
	if ((int)all->cam.pos.x == 5 && POS_Y == 24)
	{
		all->cam.pos.x += 2;
		all->hook.skybox = 1;
		all->text_floor = &all->text[CEIL];
		all->e.refresh = 1;
		all->hook.vanilla = 1;
	}
	all->hook.action = 0;
}

void			display_weapon(t_mega *all)
{
	int i;

	i = all->cam.statw;
	if (all->player.weapon == KNIFE)
		i += 5;
	mlx_put_image_to_window(all->e.mlx, all->e.wmlx, all->weapon[i].img.img,
		(WWIN_HUD - all->weapon[i].w) / 2, (HWIN - all->weapon[i].h + 20));
}

void			weapon_shoot(t_mega *all)
{
	if (all->player.ammo == 0 && all->player.weapon == GUN)
	{
		all->hook.shoot = 0;
		return ;
	}
	all->cam.statw += 1;
	if (all->cam.statw == 5)
	{
		all->cam.statw = 0;
		if (all->player.weapon == GUN)
			all->player.ammo -= 1;
		all->hook.shoot = 0;
	}
	all->e.refresh = 1;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 01:45:17 by y0ja              #+#    #+#             */
/*   Updated: 2015/03/24 20:52:02 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		loop_hook(t_mega *all)
{
	open_door(all);
	if (all->e.refresh == 1)
	{
		ft_bzero(all->img.data, WWIN * HWIN * 4);
		raycasting_calcul(all);
		mlx_put_image_to_window(all->e.mlx, all->e.wmlx, all->img.img,
			(WWIN_HUD / 2) - (WWIN / 2), 20);
		loot_ammo(all->sprites, &all->player, &all->cam);
		display_weapon(all);
		display_hud(all);
		all->e.refresh = 0;
	}
	key_hook(all);
	return (1);
}

int		key_hook(t_mega *all)
{
	if (all->hook.up)
		move_up_down(all, UP);
	if (all->hook.down)
		move_up_down(all, DOWN);
	if (all->hook.right)
		turn(all, -all->cam.rotspeed);
	if (all->hook.left)
		turn(all, all->cam.rotspeed);
	if (all->hook.strafe_left)
		strafe(all, LEFT);
	if (all->hook.strafe_right)
		strafe(all, RIGHT);
	if (all->hook.shoot)
		weapon_shoot(all);
	if (all->hook.minimap_enable)
		show_minimap(all);
	if (all->hook.action)
		do_something(all);
	return (1);
}

int		press_key_hook(int keycode, t_mega *all)
{
	if (keycode == ECHAP)
		exit_free(all);
	if (keycode == KEY_W)
		all->hook.up = 1;
	else if (keycode == KEY_S)
		all->hook.down = 1;
	else if (keycode == KEY_A)
		all->hook.strafe_left = 1;
	else if (keycode == KEY_D)
		all->hook.strafe_right = 1;
	else if (keycode == RIGHT)
		all->hook.right = 1;
	else if (keycode == LEFT)
		all->hook.left = 1;
	else if (keycode == SPACE)
		all->hook.shoot = 1;
	else if (keycode == TAB)
		all->hook.minimap_enable = 1;
	else if (keycode == KEY_F)
		all->hook.action = 1;
	return (1);
}

int		release_key_hook(int keycode, t_mega *all)
{
	if (keycode == KEY_W)
		all->hook.up = 0;
	else if (keycode == KEY_S)
		all->hook.down = 0;
	else if (keycode == KEY_A)
		all->hook.strafe_left = 0;
	else if (keycode == KEY_D)
		all->hook.strafe_right = 0;
	else if (keycode == RIGHT)
		all->hook.right = 0;
	else if (keycode == LEFT)
		all->hook.left = 0;
	else if (keycode == TAB)
		all->hook.minimap_enable = 0;
	else if (keycode == KEY_F)
		all->hook.action = 0;
	else if (keycode == 18 || keycode == 19)
	{
		if (keycode == 18)
			all->player.weapon = KNIFE;
		else if (keycode == 19 && all->player.gun_loot == 1)
			all->player.weapon = GUN;
		all->e.refresh = 1;
	}
	return (1);
}

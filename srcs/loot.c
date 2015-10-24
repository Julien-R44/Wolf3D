/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 04:35:11 by jripoute          #+#    #+#             */
/*   Updated: 2015/03/24 20:53:19 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static t_dlist		*del_sprite(t_dlist *link)
{
	t_dlist *prev;

	prev = link->before;
	prev->next = link->next;
	ft_dlstdelone(&link, NULL);
	return (prev);
}

void				loot_ammo(t_dlist *sprites, t_player *player, t_cam *cam)
{
	t_dlist		*nav;
	t_sprite	*t;
	double		dist;

	nav = sprites;
	while (nav)
	{
		t = nav->content;
		if (t->texture == AMMO || t->texture == KEY || t->texture == GUN_LOOT)
		{
			dist = sqrt((t->x - cam->pos.x) * (t->x - cam->pos.x)
				+ (t->y - cam->pos.y) * (t->y - cam->pos.y));
			if (dist < 0.7)
			{
				if (t->texture == AMMO)
					player->ammo = 8;
				else if (t->texture == KEY)
					player->key = 1;
				else if (t->texture == GUN_LOOT)
					player->gun_loot = 1;
				nav = del_sprite(nav);
			}
		}
		nav = nav->next;
	}
}

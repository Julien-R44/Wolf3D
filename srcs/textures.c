/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 02:29:11 by jripoute          #+#    #+#             */
/*   Updated: 2015/03/25 13:45:43 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		add_sprite(t_dlist **list, int sprite, double x, double y)
{
	t_sprite	content;

	content.y = y;
	content.x = x;
	content.texture = sprite;
	ft_dlstadd_end(list, ft_dlstnew(&content, sizeof(t_sprite)));
}

static void		init_sprite3(t_mega *all, t_dlist *list)
{
	add_sprite(&list, KNIGHT, 12.5, 10.5);
	add_sprite(&list, KNIGHT, 4.6, 2.4);
	add_sprite(&list, BARREL, 2.5, 11.5);
	add_sprite(&list, BARREL, 2, 12);
	add_sprite(&list, BARREL, 1.5, 11.5);
	add_sprite(&list, AMMO, 1.5, 20.5);
	add_sprite(&list, GUN_LOOT, 2.5, 20.5);
	add_sprite(&list, BLOOD, 3.5, 5.5);
	add_sprite(&list, BLOOD, 7.5, 8.5);
	add_sprite(&list, KEY, 4.3, 6.5);
	add_sprite(&list, KEY, 17.5, 3.9);
	add_sprite(&list, TABLE, 9, 3.5);
	add_sprite(&list, LIGHT, 7.5, 3);
	add_sprite(&list, LIGHT, 3.5, 9.5);
	add_sprite(&list, LIGHT, 17.5, 9.5);
	add_sprite(&list, LIGHT, 14.5, 7.5);
	add_sprite(&list, LIGHT, 2, 14.5);
	add_sprite(&list, CHEST, 4.5, 33.5);
}

static void		init_sprite2(t_mega *all, t_dlist *list)
{
	add_sprite(&list, LIGHT, 2, 18.5);
	add_sprite(&list, PUIT, 17.5, 19.5);
	add_sprite(&list, PUIT, 17.5, 13.5);
	add_sprite(&list, PILAR, 15.5, 19.5);
	add_sprite(&list, PILAR, 15.5, 13.5);
	add_sprite(&list, PILAR, 12.5, 19.5);
	add_sprite(&list, PILAR, 12.5, 13.5);
	add_sprite(&list, PILAR, 15.5, 6.5);
	add_sprite(&list, PILAR, 13.5, 6.5);
	add_sprite(&list, PILAR, 5.5, 14.5);
	add_sprite(&list, PILAR, 5.5, 18.5);
	add_sprite(&list, CAGE6, 14.5, 1.2);
	add_sprite(&list, DEAD, 16.9, 3.7);
	add_sprite(&list, TABLE3, 16.5, 4.6);
	add_sprite(&list, TABLE2, 13.5, 3.5);
	add_sprite(&list, LIGHT, 14.5, 2.5);
	add_sprite(&list, SINK, 17.5, 1.5);
	add_sprite(&list, CAGE3, 12.5, 4.5);
	add_sprite(&list, CAGE4, 13.5, 4.5);
	add_sprite(&list, CAGE5, 12.5, 1.5);
	add_sprite(&list, CUBE, 17.5, 24.8);
	add_sprite(&list, CAKE, 17.2, 24.3);
	add_sprite(&list, LIGHT, 16.5, 24.5);
	add_sprite(&list, CHEST, 6.5, 30.5);
	init_sprite3(all, list);
}

t_dlist			*init_sprites(t_mega *all)
{
	t_dlist		*list;

	list = NULL;
	add_sprite(&list, CAGE, 9.5, 1.5);
	add_sprite(&list, CAGE2, 1.5, 5.5);
	add_sprite(&list, BARREL, 4.5, 4.3);
	add_sprite(&list, BARREL, 4.2, 4.6);
	add_sprite(&list, KNIGHT, 7.5, 12.5);
	add_sprite(&list, KNIGHT, 7.5, 19.5);
	add_sprite(&list, KNIGHT, 15.5, 22.5);
	add_sprite(&list, KNIGHT, 12.5, 22.5);
	add_sprite(&list, KNIGHT, 15.5, 10.5);
	init_sprite2(all, list);
	return (list);
}

void			init_textures(t_mega *all)
{
	t_text	*text;
	int		texture_nb;
	int		nb;
	int		i;

	i = 0;
	nb = SKYBOX + 1;
	init_weapon_hud(all);
	getfile2load(all, nb);
	while (i < nb)
	{
		text = &all->text[i];
		text->img.img = mlx_xpm_file_to_image(all->e.mlx, text->filename,
											&text->w, &text->h);
		if (text->img.img == NULL)
			ft_error(4);
		text->img.data = mlx_get_data_addr(text->img.img, &text->img.bpp,
			&text->img.sizeline, &text->img.endian);
		if (!text->img.data)
			ft_error(4);
		free(text->filename);
		i++;
	}
}

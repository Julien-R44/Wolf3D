/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 04:03:06 by jripoute          #+#    #+#             */
/*   Updated: 2015/03/24 20:56:25 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

#define TILESIZE 10

static void		fill_square_minimap(t_mega *all, t_pos p1, t_pos p2, int color)
{
	int tmp;

	tmp = p1.y;
	while (p1.y < tmp + TILESIZE)
	{
		while (p1.x < p2.x)
		{
			ft_memcpy(&all->hook.minimap.data[p1.x * 4 + p1.y
				* all->hook.minimap.sizeline], &color, (sizeof(int)));
			p1.x += 1;
		}
		p1.x -= TILESIZE;
		p1.y += 1;
		p2.y += 1;
	}
}

static void		refresh_player_position_minimap(t_mega *all)
{
	static t_pos	p1;
	static t_pos	p2;
	t_pos			player;

	fill_square_minimap(all, p1, p2, 0x000000);
	player.x = (int)(all->cam.pos.x);
	player.y = (int)(all->cam.pos.y);
	p1.x = (player.y + 1) * TILESIZE;
	p1.y = (player.x + 1) * TILESIZE;
	p2.x = p1.x + TILESIZE;
	p2.y = p1.y;
	fill_square_minimap(all, p1, p2, 0xffffff);
}

void			init_minimap(t_env *e, t_img *img)
{
	img->img = mlx_new_image(e->mlx, LENGHT_WINDOW_MAP, HEIGHT_WINDOW_MAP);
	img->data = mlx_get_data_addr(img->img, &img->bpp,
		&img->sizeline, &img->endian);
	ft_bzero(img->data, 100 * 500 * 4);
}

void			show_minimap(t_mega *all)
{
	all->e.refresh = 1;
	mlx_put_image_to_window(all->e.mlx, all->e.wmlx, all->hook.minimap.img,
		WWIN_HUD / 16, 40);
	refresh_player_position_minimap(all);
}

void			stock_minimap(t_mega *all)
{
	t_pos	p1;
	t_pos	p2;
	int		i;
	int		j;

	i = 0;
	ft_set_pos(&p1, 10, 10);
	ft_set_pos(&p2, 20, 10);
	while (i < all->map.height)
	{
		j = 0;
		while (j < all->map.width)
		{
			if (all->map.map[i][j] >= 1)
				fill_square_minimap(all, p1, p2, 0x930000);
			p1.x += TILESIZE;
			p2.x += TILESIZE;
			j++;
		}
		p1.x = TILESIZE;
		p2.x = TILESIZE + TILESIZE;
		p1.y += TILESIZE;
		p2.y += TILESIZE;
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 20:33:22 by lubaujar          #+#    #+#             */
/*   Updated: 2015/03/24 11:11:48 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void			getfile2load3(t_mega *all, int i)
{
	all->text[++i].filename = ft_strdup("./xpm/sprites/cage3.xpm");
	all->text[++i].filename = ft_strdup("./xpm/sprites/cage4.xpm");
	all->text[++i].filename = ft_strdup("./xpm/sprites/cage5.xpm");
	all->text[++i].filename = ft_strdup("./xpm/sprites/cage6.xpm");
	all->text[++i].filename = ft_strdup("./xpm/sprites/dead.xpm");
	all->text[++i].filename = ft_strdup("./xpm/sprites/key.xpm");
	all->text[++i].filename = ft_strdup("./xpm/sprites/gun.xpm");
	all->text[++i].filename = ft_strdup("./xpm/sprites/sink.xpm");
	all->text[++i].filename = ft_strdup("./xpm/sprites/skulls.xpm");
	all->text[++i].filename = ft_strdup("./xpm/sprites/table.xpm");
	all->text[++i].filename = ft_strdup("./xpm/sprites/table2.xpm");
	all->text[++i].filename = ft_strdup("./xpm/sprites/table3.xpm");
	all->text[++i].filename = ft_strdup("./xpm/sprites/blood.xpm");
	all->text[++i].filename = ft_strdup("./xpm/sprites/knight.xpm");
	all->text[++i].filename = ft_strdup("./xpm/sprites/knight2.xpm");
	all->text[++i].filename = ft_strdup("./xpm/sprites/light.xpm");
	all->text[++i].filename = ft_strdup("./xpm/sprites/puit.xpm");
	all->text[++i].filename = ft_strdup("./xpm/sprites/companion.xpm");
	all->text[++i].filename = ft_strdup("./xpm/sprites/cake.xpm");
	all->text[++i].filename = ft_strdup("./xpm/sprites/chest.xpm");
	all->text[++i].filename = ft_strdup("./xpm/sprites/scream.xpm");
	all->text[++i].filename = ft_strdup("./xpm/skybox/sky1.xpm");
	all->text[++i].filename = NULL;
}

static void			getfile2load2(t_mega *all, int i)
{
	all->text[++i].filename = ft_strdup("./xpm/walls/stone5.xpm");
	all->text[++i].filename = ft_strdup("./xpm/walls/wall1.xpm");
	all->text[++i].filename = ft_strdup("./xpm/walls/wall2.xpm");
	all->text[++i].filename = ft_strdup("./xpm/walls/wall3.xpm");
	all->text[++i].filename = ft_strdup("./xpm/walls/ceil.xpm");
	all->text[++i].filename = ft_strdup("./xpm/walls/telep.xpm");
	all->text[++i].filename = ft_strdup("./xpm/walls/wood7.xpm");
	all->text[++i].filename = ft_strdup("./xpm/walls/door.xpm");
	all->text[++i].filename = ft_strdup("./xpm/sprites/barrel.xpm");
	all->text[++i].filename = ft_strdup("./xpm/sprites/pilar.xpm");
	all->text[++i].filename = ft_strdup("./xpm/sprites/ammo.xpm");
	all->text[++i].filename = ft_strdup("./xpm/sprites/pnj.xpm");
	all->text[++i].filename = ft_strdup("./xpm/sprites/cage1.xpm");
	all->text[++i].filename = ft_strdup("./xpm/sprites/cage2.xpm");
	getfile2load3(all, i);
}

void				getfile2load(t_mega *all, int nb)
{
	int i;

	i = -1;
	all->text = (t_text *)ft_memalloc(sizeof(t_text) * nb + 1);
	if (!all->text)
		ft_error(2);
	all->text[++i].filename = ft_strdup("./xpm/walls/wood.xpm");
	all->text[++i].filename = ft_strdup("./xpm/walls/wood2.xpm");
	all->text[++i].filename = ft_strdup("./xpm/walls/wood3.xpm");
	all->text[++i].filename = ft_strdup("./xpm/walls/wood4.xpm");
	all->text[++i].filename = ft_strdup("./xpm/walls/wood5.xpm");
	all->text[++i].filename = ft_strdup("./xpm/walls/wood6.xpm");
	all->text[++i].filename = ft_strdup("./xpm/walls/cat.xpm");
	all->text[++i].filename = ft_strdup("./xpm/walls/stone1.xpm");
	all->text[++i].filename = ft_strdup("./xpm/walls/stone2.xpm");
	all->text[++i].filename = ft_strdup("./xpm/walls/stone3.xpm");
	all->text[++i].filename = ft_strdup("./xpm/walls/stone4.xpm");
	getfile2load2(all, i);
}

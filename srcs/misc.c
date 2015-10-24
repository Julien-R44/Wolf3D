/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 01:43:54 by y0ja              #+#    #+#             */
/*   Updated: 2015/03/24 20:57:07 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

double		getdree(t_dpos *rdir)
{
	double	ret;

	if (rdir->x != 0)
		ret = atan(rdir->y / rdir->x) * 180.0 / PI;
	else
		ret = (rdir->y > 0) ? 90 : -90;
	if (ret < 0)
		ret += 180;
	if (rdir->y <= 0)
		ret += 180;
	return (ret);
}

void		ft_set_pos(t_pos *p, int x, int y)
{
	p->x = x;
	p->y = y;
}

void		ft_error(int er)
{
	if (er == 1)
		ft_putstr("Error : invalid map.");
	if (er == 2)
		ft_putstr("Error : malloc fail'd");
	if (er == 3)
		ft_putstr("Error : Mlx fail'd");
	if (er == 4)
		ft_putstr("error : failed to init textures");
	exit(-1);
}

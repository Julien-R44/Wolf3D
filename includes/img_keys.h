/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_keys.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 23:25:18 by jripoute          #+#    #+#             */
/*   Updated: 2015/03/25 13:41:22 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_KEYS_H
# define IMG_KEYS_H

# include "wolf3d.h"

/*
**	typedef enum	s_keys ----  X11 Keys
** {
** 	UP = 65362,
** 	DOWN = 65364,
** 	RIGHT = 65363,
** 	LEFT = 65361,
** 	ECHAP = 65307,
** 	TAB = 65289,
** 	SPACE = 32,
** 	KEY_W = 119,
** 	KEY_A = 97,
** 	KEY_D = 100,
** 	KEY_Q = 113,
** 	KEY_E = 101,
** 	KEY_S = 115,
** 	KEY_F = 102,
**	}				e_keys;
*/

typedef enum	e_keys
{
	UP = 126,
	DOWN = 125,
	RIGHT = 124,
	LEFT = 123,
	ECHAP = 53,
	TAB = 48,
	SPACE = 49,
	KEY_W = 13,
	KEY_A = 0,
	KEY_D = 2,
	KEY_Q = 12,
	KEY_E = 14,
	KEY_S = 1,
	KEY_F = 3,
	KEY_
}				t_keys;

typedef	struct	s_img
{
	void		*img;
	char		*data;
	int			bpp;
	int			sizeline;
	int			endian;
}				t_img;

typedef	struct	s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}				t_color;

#endif

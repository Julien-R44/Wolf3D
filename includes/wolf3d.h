/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 15:56:43 by jripoute          #+#    #+#             */
/*   Updated: 2015/03/25 13:50:57 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <fcntl.h>
# include <stdlib.h>
# include <time.h>
# include <stdint.h>
# include <X11/Xlib.h>
# include <X11/Xutil.h>
# include <sys/shm.h>
# include <X11/extensions/XShm.h>
# include "libft.h"
# include "mlx.h"
# include "img_keys.h"

# define WWIN_HUD 1600
# define HWIN_HUD 900
# define WWIN 1515
# define HWIN 660

# define LENGHT_WINDOW_MAP (420)
# define HEIGHT_WINDOW_MAP (210)
# define PI 3.14159265359
# define TILESIZE 10

# define NDOOR 99

# define MOVESPEED 0.18
# define ROTSPEED 0.08
# define STRAFE_SPEED 0.1
# define START_X 9.5
# define START_Y 2

# define KEYPRESS		(2)
# define KEYRELEASE		(3)
# define KEYPRESSMASK	(1L<<0)
# define KEYRELEASEMASK	(1L<<1)

typedef enum	e_weapon
{
	KNIFE,
	GUN,
}				t_weapon;

typedef enum	e_etext
{
	WOOD1 = 0,
	WOOD2,
	WOOD3,
	WOOD4,
	WOOD5,
	WOOD6,
	CAT,
	STONE1,
	STONE2,
	STONE3,
	STONE4,
	STONE5,
	WALL1,
	WALL2,
	WALL3,
	CEIL,
	TELEP,
	WOOD7,
	DOOR,
	BARREL,
	PILAR,
	AMMO,
	PNJ,
	CAGE,
	CAGE2,
	CAGE3,
	CAGE4,
	CAGE5,
	CAGE6,
	DEAD,
	KEY,
	GUN_LOOT,
	SINK,
	SKULLS,
	TABLE,
	TABLE2,
	TABLE3,
	BLOOD,
	KNIGHT,
	KNIGHT2,
	LIGHT,
	PUIT,
	CUBE,
	CAKE,
	CHEST,
	SCREAM,
	SKYBOX,
}				t_etext;

typedef struct	s_env
{
	void		*mlx;
	void		*wmlx;
	int			refresh;
}				t_env;

typedef struct	s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct	s_dpos
{
	double		x;
	double		y;
}				t_dpos;

typedef struct	s_cam
{
	int			statw;
	double		speed;
	double		rotspeed;
	double		strafe_speed;
	t_dpos		pos;
	t_dpos		dir;
	t_dpos		cam;
}				t_cam;

typedef	struct	s_map
{
	int			**map;
	int			width;
	int			height;
}				t_map;

typedef struct	s_ray
{
	int			c;
	int			side;
	int			line_h;
	double		cam_x;
	double		wall_x;
	double		wall_dist;
	t_pos		map;
	t_pos		start;
	t_pos		end;
	t_pos		tex;
	t_dpos		cur;
	t_dpos		pos;
	t_dpos		dir;
	t_dpos		delta;
	t_dpos		side_dist;
	t_pos		step;
}				t_ray;

typedef struct	s_dsprite
{
	t_dpos		transform;
	t_pos		start;
	t_pos		end;
	int			h;
	int			w;
	int			texx;
	int			screenx;
}				t_dsprite;

typedef struct	s_sprite
{
	double		x;
	double		y;
	double		distance;
	int			texture;
	t_dpos		pos;
	t_dpos		dir;
}				t_sprite;

typedef struct	s_hook
{
	int			vanilla;
	int			skybox;
	int			vdoor;
	int			bullet;
	int			action;
	int			shoot;
	int			down;
	int			up;
	int			right;
	int			left;
	int			strafe_right;
	int			strafe_left;
	int			minimap_enable;
	t_img		minimap;
}				t_hook;

typedef struct	s_text
{
	char		*filename;
	t_img		img;
	int			w;
	int			h;
}				t_text;

typedef struct	s_door
{
	int			is;
	int			tex_x;
	int			x;
	int			*actx;
	t_ray		r;
}				t_door;

typedef struct	s_player
{
	int			life;
	int			ammo;
	int			key;
	int			weapon;
	int			gun_loot;
}				t_player;

typedef struct	s_mega
{
	t_env		e;
	t_map		map;
	t_cam		cam;
	t_hook		hook;
	t_text		*text;
	t_dlist		*sprites;
	t_text		*weapon;
	t_player	player;
	t_door		door;
	t_text		*hud;
	t_text		*text_floor;
	t_img		img;
}				t_mega;

/*
** main.c
*/
void			init_game(t_mega *all);
int				expose_hook(t_mega *all);

/*
** init.c
*/
void			init_map(t_map *map);
void			init_hook(t_hook *hook);
void			init_struct(t_mega *all);
void			init_player(t_player *player);
void			init_cam(t_cam *cam, int posx, int posy);

/*
** raytrace_dda.c
*/
void			new_ray(t_cam *cam, t_ray *r, int x);
void			raycasting_calcul(t_mega *all);
void			find_side_dist(t_ray *r);
void			find_wall(t_mega *all, t_ray *r);

/*
** raytrace_dda2.c
*/
void			get_lign_to_draw(t_ray *r, t_ray *r2, int x);
void			draw_column_with_text(t_mega *all, t_ray *r);
void			get_orientation(t_ray *r, t_dpos *floor_wall);
void			floor_casting(t_mega *all, t_ray *r);

/*
** draw.c
*/
void			draw_skybox(t_mega *all, t_ray *r, int x);
void			draw_floor(t_mega *all, t_text *text, t_ray *r, int texelt);
void			draw_sky_floor(t_mega *all, t_text *sky, t_text *floor,
	t_ray *r);
void			set_texture_to_image(t_mega *all, t_text *text, t_ray *r,
	int texx);

/*
** sprites.c
*/
void			display_sprite(t_mega *all, double zbuffer[WWIN_HUD]);
void			calc_draw_stripe(t_mega *all, t_dsprite *sprite, t_sprite *act);
void			draw_stripe_sprite(t_mega *all, t_dsprite *sprite, int stripe,
	t_img *img);

/*
** hud.c
*/
void			display_hud(t_mega *all);

/*
** doooorz.c
*/
void			get_door_to_draw(t_ray *r, t_door *d);
void			draw_door(t_mega *all, t_ray *d);

/*
** textures.c
*/
void			getfile2load(t_mega *all, int nb);
void			init_textures(t_mega *all);
t_dlist			*init_sprites(t_mega *all);
void			init_weapon_hud(t_mega *all);

/*
** weapons.c
*/
void			display_weapon(t_mega *all);
void			weapon_shoot(t_mega *all);

/*
** loot.c
*/
void			loot_ammo(t_dlist *sprites, t_player *player, t_cam *cam);

/*
** actions.c
*/
void			open_door(t_mega *all);
void			do_something(t_mega *all);

/*
** hooks.c
*/
void			regul_fps(t_mega *all);
int				loop_hook(t_mega *all);
int				key_hook(t_mega *all);
int				press_key_hook(int keycode, t_mega *all);
int				release_key_hook(int keycode, t_mega *all);

/*
** minimap.c
*/
void			init_minimap(t_env *e, t_img *img);
void			stock_minimap(t_mega *all);
void			show_minimap(t_mega *all);

/*
** moves.c
*/
void			move_up_down(t_mega *all, int mode);
void			turn(t_mega *all, double direction);
void			strafe(t_mega *all, int mode);

/*
** parser.c
*/
void			map_parser(t_map *map);

/*
** free.c
*/
void			free_map(t_map *map);
void			free_text_hud_weapon(t_mega *all);
void			free_sprites(t_dlist *sprites);
void			exit_free(t_mega *all);

/*
** misc.c
*/
void			ft_error(int er);
double			getdree(t_dpos *rdir);
void			ft_set_pos(t_pos *p, int x, int y);

#endif

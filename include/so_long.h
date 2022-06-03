/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:01:03 by gbreana           #+#    #+#             */
/*   Updated: 2022/06/03 14:40:38 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../mlx/mlx.h"
#include "libft.h"
/*
	Sprites parameters
*/
# define	S_HEIGHT	64
# define	S_WIDHT		64
/*
	Assets
*/
# define	WALL		"./assets/env/wall.xpm"
# define	FLOOR		"./assets/env/floor.xpm"
# define	EXIT_CL		"./assets/env/door_cl.xpm"
# define	EXIT_OP		"./assets/env/door_op.xpm"
# define	COIN_1		"./assets/env/coin_1.xpm"
# define	COIN_2		"./assets/env/coin_2.xpm"
# define	PLAYER_S	"./assets/hero/player_forward.xpm"
# define	PLAYER_L	"./assets/hero/player_left.xpm"
# define	PLAYER_R	"./assets/hero/player_right.xpm"
# define	PLAYER_U	"./assets/hero/player_up.xpm"
# define	PLAYER_D	"./assets/hero/player_down.xpm"
# define	RAIDER_S	"./assets/enemy/raider_stay.xpm"
# define	RAIDER_J	"./assets/enemy/raider_jump.xpm"
# define	RAIDER_D	"./assets/enemy/raider_d.xpm"
/*
	Keycodes
*/
# define	KEY_W 13
# define	KEY_A 0
# define	KEY_S 1
# define	KEY_D 2
# define	KEY_ESC 53

typedef struct	s_coord
{
	int	x;
	int	y;
}				t_coord;

typedef struct	s_assets
{
	void	*wall;
	void	*floor;
	void	*item_1;
	void	*item_2;
	void	*item_3;
	void	*exit;
	void	*exit_cl;
	void	*exit_op;
	void	*player;
	void	*player_s;
	void	*player_l;
	void	*player_r;
	void	*player_u;
	void	*player_d;
	void	*raider_s;
	void	*raider_j;
}				t_assets;

typedef struct	s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	int			s_height;
	int			s_widht;
	int			map_height;
	int			map_widht;
	int			coins;
	int			exits;
	int			players;
	int			raiders;
	int			steps;
	t_assets	sprites;
	t_coord		p_coord;
	t_coord		r_coord;
}				t_game;


int		mouse_hook(int keycode);
/*
	Errors handling and some utils
*/
int		error(char *message);
int		game_over(t_game *game);
/*
	Utils
*/
int		check_input_params(int argc, char **argv);
void	free2d(char **arr, int len);
int		sym_count(t_game *game, char symbol);
void	map_obj_count(t_game *game);
int		check_sprites(t_assets *sprites);
/*
	Working with map
*/
int		check_map_symbols(t_game *game);
int		check_map_size(t_game *game);
int		check_map_walls(t_game *game);
int		check_map(t_game *game);
char	*file_to_array(char *filename);
int		count_lines(char *filename);
/*
	Initialisation
*/
t_game		*init_game(char *filename, int s_height, int s_widht);
void		init_sprites(t_game *game);
/*
	Render
*/
void    put_sprite(t_game *game, int i, int j);
int		render_map(t_game *game);
void	step(t_game *game);
/*
	Movements
*/
int		key_hook(int keycode, t_game *game);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
#endif

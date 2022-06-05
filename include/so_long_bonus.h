/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:01:03 by gbreana           #+#    #+#             */
/*   Updated: 2022/06/05 21:08:14 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../mlx/mlx.h"
# include "libft.h"
/*
	Sprites parameters
*/
# define S_HEIGHT	64
# define S_WIDHT	64
# define UPD_TIME	15
/*
	Assets
*/
# define WALL		"./assets/bonus/wall.xpm"
# define FLOOR		"./assets/bonus/floor.xpm"
# define EXIT_CL	"./assets/bonus/door_cl.xpm"
# define EXIT_OP	"./assets/bonus/door_op.xpm"
# define COIN_1		"./assets/bonus/coin_1.xpm"
# define COIN_2		"./assets/bonus/coin_2.xpm"
# define PLAYER_S	"./assets/bonus/player_s.xpm"
# define PLAYER_L	"./assets/bonus/player_l.xpm"
# define PLAYER_R	"./assets/bonus/player_r.xpm"
# define RAIDER_L	"./assets/bonus/raider_l.xpm"
# define RAIDER_R	"./assets/bonus/raider_r.xpm"
/*
	Keycodes
*/
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53
/*
	Structures
*/
typedef struct s_coord
{
	int	x;
	int	y;
}				t_coord;

typedef struct s_assets
{
	void	*wall;
	void	*floor;
	void	*item;
	void	*item_1;
	void	*item_2;
	void	*exit;
	void	*exit_cl;
	void	*exit_op;
	void	*player;
	void	*player_s;
	void	*player_l;
	void	*player_r;
	void	*raider;
	void	*raider_l;
	void	*raider_r;
}				t_assets;

typedef struct s_game
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
/*
	Errors handling and some utils
*/
int		error(char *message);
int		game_over(t_game *game);
/*
	Utils
*/
int		check_input_params(int argc, char **argv);
int		sym_count(t_game *game, char symbol);
int		check_sprites(t_assets *sprites);
void	free2d(char **arr, int len);
void	map_obj_count(t_game *game);
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
t_game	*init_game(char *filename, int s_height, int s_widht);
void	init_player_sprites(t_game *game);
void	init_env_sprites(t_game *game);
void	init_raider_sprites(t_game *game);
void	init_all_sprites(t_game *game);
/*
	Render
*/
int		render_map(t_game *game);
void	put_sprite(t_game *game, int i, int j);
void	update_sprites(t_game *game);
void	step(t_game *game);
/*
	Movements
*/
int		key_hook(int keycode, t_game *game);
int		is_end(t_game *game, int keycode);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
#endif

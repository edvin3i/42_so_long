/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:01:03 by gbreana           #+#    #+#             */
/*   Updated: 2022/06/05 02:31:47 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "libft.h"
/*
	Sprites parameters
*/
# define S_HEIGHT	64
# define S_WIDHT	64
/*
	Assets
*/
# define WALL		"./assets/mandatory/wall.xpm"
# define FLOOR		"./assets/mandatory/floor.xpm"
# define EXIT		"./assets/mandatory/exit.xpm"
# define COIN		"./assets/mandatory/coin.xpm"
# define PLAYER		"./assets/mandatory/player.xpm"
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
	void	*exit;
	void	*player;
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
	int			steps;
	t_assets	sprites;
	t_coord		p_coord;
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
t_game	*init_game(char *filename, int s_height, int s_widht);
void	init_sprites(t_game *game);
/*
	Render
*/
int		render_map(t_game *game);
void	put_sprite(t_game *game, int i, int j);
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

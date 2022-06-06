/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 17:36:49 by gbreana           #+#    #+#             */
/*   Updated: 2022/06/06 15:07:12 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

t_game	*init_game(char *filename, int s_height, int s_widht)
{
	char	*map_arr;
	t_game	*game;

	game = (t_game *) malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	map_arr = file_to_array(filename);
	game->map = ft_split(map_arr, '\n');
	game->map_height = count_lines(filename);
	if (game->map[0])
		game->map_widht = ft_strlen(game->map[0]);
	else
		game->map_widht = 0;
	game->s_height = S_HEIGHT;
	game->s_widht = S_WIDHT;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, s_widht * game->map_widht, \
						s_height * game->map_height, "so_long");
	game->coins = 0;
	game->exits = 0;
	game->players = 0;
	game->raiders = 0;
	game->steps = 0;
	free(map_arr);
	return (game);
}

void	init_player_sprites(t_game *game)
{
	game->sprites.player_s = mlx_xpm_file_to_image(game->mlx, PLAYER_S, \
						&game->s_widht, &game->s_height);
	game->sprites.player_l = mlx_xpm_file_to_image(game->mlx, PLAYER_L, \
						&game->s_widht, &game->s_height);
	game->sprites.player_r = mlx_xpm_file_to_image(game->mlx, PLAYER_R, \
						&game->s_widht, &game->s_height);
}

void	init_env_sprites(t_game *game)
{
	game->sprites.wall = mlx_xpm_file_to_image(game->mlx, WALL, \
						&game->s_height, &game->s_widht);
	game->sprites.floor = mlx_xpm_file_to_image(game->mlx, FLOOR, \
						&game->s_height, &game->s_widht);
	game->sprites.exit_cl = mlx_xpm_file_to_image(game->mlx, EXIT_CL, \
						&game->s_height, &game->s_widht);
	game->sprites.exit_op = mlx_xpm_file_to_image(game->mlx, EXIT_OP, \
						&game->s_widht, &game->s_height);
	game->sprites.item_1 = mlx_xpm_file_to_image(game->mlx, COIN_1, \
						&game->s_widht, &game->s_height);
	game->sprites.item_2 = mlx_xpm_file_to_image(game->mlx, COIN_2, \
						&game->s_widht, &game->s_height);
}

void	init_raiders(t_game *game)
{
	int	i;
	int	j;
	int	r_num;

	r_num = 0;
	i = -1;
	while (++i < game->map_height)
	{
		j = -1;
		while (++j < game->map_widht)
		{
			if (game->map[i][j] == 'R')
			{
				game->r_coord[r_num].x = j;
				game->r_coord[r_num].y = i;
				r_num++;
			}
		}
	}
	game->sprites.raider_l = mlx_xpm_file_to_image(game->mlx, RAIDER_L, \
						&game->s_widht, &game->s_height);
	game->sprites.raider_r = mlx_xpm_file_to_image(game->mlx, RAIDER_R, \
						&game->s_widht, &game->s_height);
}

void	init_all_sprites(t_game *game)
{
	init_player_sprites(game);
	init_env_sprites(game);
	init_raiders(game);
	game->sprites.item = game->sprites.item_1;
	game->sprites.exit = game->sprites.exit_cl;
	game->sprites.player = game->sprites.player_s;
	game->sprites.raider = game->sprites.raider_l;
	check_sprites(&game->sprites);
}

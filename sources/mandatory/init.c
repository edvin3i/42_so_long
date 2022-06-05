/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 17:36:49 by gbreana           #+#    #+#             */
/*   Updated: 2022/06/05 03:02:07 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

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
	game->steps = 0;
	free(map_arr);
	return (game);
}

void	init_sprites(t_game *game)
{
	game->sprites.wall = mlx_xpm_file_to_image(game->mlx, WALL, \
						&game->s_height, &game->s_widht);
	game->sprites.floor = mlx_xpm_file_to_image(game->mlx, FLOOR, \
						&game->s_height, &game->s_widht);
	game->sprites.exit = mlx_xpm_file_to_image(game->mlx, EXIT, \
						&game->s_height, &game->s_widht);
	game->sprites.item = mlx_xpm_file_to_image(game->mlx, COIN, \
						&game->s_widht, &game->s_height);
	game->sprites.player = mlx_xpm_file_to_image(game->mlx, PLAYER, \
						&game->s_widht, &game->s_height);
	check_sprites(&game->sprites);
}

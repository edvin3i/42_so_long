/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:11:46 by gbreana           #+#    #+#             */
/*   Updated: 2022/06/03 14:10:36 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int     main(int argc, char **argv)
{
	(void) argc;
	t_game	*game;
	
	game = init_game(argv[1], S_HEIGHT, S_WIDHT);
	check_map(game);
	init_sprites(game);
	render_map(game);
	
	mlx_hook(game->win, 2, 0, key_hook, game);
	mlx_hook(game->win, 17, 0L, game_over, game);
	mlx_loop_hook(game->mlx, render_map, game);
	mlx_loop(game->mlx);
	
	


	
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 20:00:17 by gbreana           #+#    #+#             */
/*   Updated: 2022/06/05 14:10:21 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void move_up(t_game *game)
{
	int	x;
	int	y;

	x = game->p_coord.x;
	y = game->p_coord.y;
	step(game);
	if (game->map[y - 1][x] == 'C')
		game->coins--;
	else if (game->map[y - 1][x] == 'E')
		game_over(game);
	game->map[y - 1][x] = 'P';
	game->map[y++][x] = '0';
}

void move_down(t_game *game)
{
	int	x;
	int	y;

	x = game->p_coord.x;
	y = game->p_coord.y;
	step(game);
	if (game->map[y + 1][x] == 'C')
		game->coins--;
	else if (game->map[y + 1][x] == 'E')
		game_over(game);
	game->map[y + 1][x] = 'P';
	game->map[y--][x] = '0';
}

void move_left(t_game *game)
{
	int	x;
	int	y;

	x = game->p_coord.x;
	y = game->p_coord.y;
	step(game);
	if (game->map[y][x - 1] == 'C')
		game->coins--;
	else if (game->map[y][x - 1] == 'E')
		game_over(game);
	game->map[y][x - 1] = 'P';
	game->map[y][x++] = '0';
}

void move_right(t_game *game)
{
	int	x;
	int	y;

	x = game->p_coord.x;
	y = game->p_coord.y;
	step(game);
	if (game->map[y][x + 1] == 'C')
		game->coins--;
	else if (game->map[y][x + 1] == 'E')
		game_over(game);
	game->map[y][x + 1] = 'P';
	game->map[y][x--] = '0';
}
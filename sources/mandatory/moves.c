/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 20:00:17 by gbreana           #+#    #+#             */
/*   Updated: 2022/06/03 14:44:22 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void move_up(t_game *game)
{
	int	x;
	int	y;

	x = game->p_coord.x;
	y = game->p_coord.y;
	if (game->map[y - 1][x] == 'C')
		game->coins--;
	game->map[y - 1][x] = 'P';
	game->map[y++][x] = '0';
	step(game);
}

void move_down(t_game *game)
{
	int	x;
	int	y;

	x = game->p_coord.x;
	y = game->p_coord.y;
	if (game->map[y + 1][x] == 'C')
		game->coins--;
	game->map[y + 1][x] = 'P';
	game->map[y--][x] = '0';
	step(game);
}

void move_left(t_game *game)
{
	int	x;
	int	y;

	x = game->p_coord.x;
	y = game->p_coord.y;
	if (game->map[y][x - 1] == 'C')
		game->coins--;
	game->map[y][x - 1] = 'P';
	game->map[y][x++] = '0';
	step(game);
}

void move_right(t_game *game)
{
	int	x;
	int	y;

	x = game->p_coord.x;
	y = game->p_coord.y;
	if (game->map[y][x + 1] == 'C')
		game->coins--;
	game->map[y][x + 1] = 'P';
	game->map[y][x--] = '0';
	step(game);
}
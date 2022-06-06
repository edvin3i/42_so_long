/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raiders_moves_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:05:03 by gbreana           #+#    #+#             */
/*   Updated: 2022/06/06 15:03:05 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	raiders_move_up(t_game *game, int r_num)
{
	int	x;
	int	y;

	x = game->r_coord[r_num].x;
	y = game->r_coord[r_num].y;
	if (game->map[y - 1][x] == 'P')
		game_over(game);
	game->map[y - 1][x] = 'R';
	game->map[y][x] = '0';
	game->r_coord[r_num].x = x;
	game->r_coord[r_num].y = y - 1;
}

void	raiders_move_down(t_game *game, int r_num)
{
	int	x;
	int	y;

	x = game->r_coord[r_num].x;
	y = game->r_coord[r_num].y;
	if (game->map[y + 1][x] == 'P')
		game_over(game);
	game->map[y + 1][x] = 'R';
	game->map[y][x] = '0';
	game->r_coord[r_num].x = x;
	game->r_coord[r_num].y = y + 1;
}

void	raiders_move_left(t_game *game, int r_num)
{
	int	x;
	int	y;

	x = game->r_coord[r_num].x;
	y = game->r_coord[r_num].y;
	if (game->map[y][x - 1] == 'P')
		game_over(game);
	game->map[y][x - 1] = 'R';
	game->map[y][x] = '0';
	game->r_coord[r_num].x = x - 1;
	game->r_coord[r_num].y = y;
}

void	raiders_move_right(t_game *game, int r_num)
{
	int	x;
	int	y;

	x = game->r_coord[r_num].x;
	y = game->r_coord[r_num].y;
	if (game->map[y][x + 1] == 'P')
		game_over(game);
	game->map[y][x + 1] = 'R';
	game->map[y][x] = '0';
	game->r_coord[r_num].x = x + 1;
	game->r_coord[r_num].y = y;
}

int	raiders_move(t_game *game)
{
	int	r_num;
	int	direction;

	r_num = -1;
	while (++r_num < game->raiders)
	{
		direction = rand() % 4;
		sel_direction(game, r_num, direction);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:37:35 by gbreana           #+#    #+#             */
/*   Updated: 2022/06/03 14:57:02 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int     key_hook(int keycode, t_game *game)
{
	int	x;
	int	y;

	x = game->p_coord.x;
	y = game->p_coord.y;
	if (keycode == KEY_W && game->map[y - 1][x] != '1')
		move_up(game);
	else if (keycode == KEY_S && game->map[y + 1][x] != '1')
		move_down(game);
	else if (keycode == KEY_A && game->map[y][x - 1] != '1')
		move_left(game);
	else if (keycode == KEY_D && game->map[y][x + 1] != '1')
		move_right(game);
	else if (keycode == KEY_ESC)
		game_over(game);
	if (game->coins == 0)
		game->sprites.exit = game->sprites.exit_op;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raiders_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:02:50 by gbreana           #+#    #+#             */
/*   Updated: 2022/06/06 14:59:56 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	sel_direction(t_game *game, int r_num, int direction)
{
	int		x;
	int		y;
	char	**map;

	x = game->r_coord[r_num].x;
	y = game->r_coord[r_num].y;
	map = game->map;
	if ((map[y - 1][x] == '0' || map[y - 1][x] == 'P') \
						&& direction == 0)
		raiders_move_up(game, r_num);
	else if ((map[y + 1][x] == '0' || map[y + 1][x] == 'P') \
						&& direction == 1)
		raiders_move_down(game, r_num);
	else if ((map[y][x - 1] == '0' || map[y][x - 1] == 'P') \
						&& direction == 2)
		raiders_move_left(game, r_num);
	else if ((map[y][x + 1] == '0' || map[y][x + 1] == 'P') \
						&& direction == 3)
		raiders_move_right(game, r_num);
}

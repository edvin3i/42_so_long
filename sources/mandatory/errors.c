/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:12:45 by gbreana           #+#    #+#             */
/*   Updated: 2022/06/05 03:02:32 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	error(char *message)
{
	ft_printf("\n\e[41mError:\n%s\e[0m\n", message);
	ft_printf("\n\e[46m\e[30mUsage: ./so_long [MAP_FILENAME.ber]\e[0m\n");
	exit(0);
}

int	game_over(t_game *game)
{
	ft_printf("\n\e[42m\e[30m<---------->Game Over!<---------->\e[0m\n");
	mlx_destroy_window(game->mlx, game->win);
	free2d(game->map, game->map_height);
	free(game);
	exit(0);
	return (1);
}

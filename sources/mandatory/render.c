/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:22:52 by gbreana           #+#    #+#             */
/*   Updated: 2022/06/05 03:13:24 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	put_sprite(t_game *game, int i, int j)
{
	if (game->map[i][j])
		mlx_put_image_to_window(game->mlx, game->win, \
							game->sprites.floor, j * S_HEIGHT, i * S_WIDHT);
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win, \
							game->sprites.wall, j * S_HEIGHT, i * S_WIDHT);
	else if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, \
							game->sprites.exit, j * S_HEIGHT, i * S_WIDHT);
	else if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, \
							game->sprites.item, j * S_HEIGHT, i * S_WIDHT);
	else if (game->map[i][j] == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win, \
							game->sprites.player, j * S_HEIGHT, i * S_WIDHT);
		game->p_coord.x = j;
		game->p_coord.y = i;
	}	
}

int	render_map(t_game *game)
{
	int		i;
	int		j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
			put_sprite(game, i, j);
	}
	return (0);
}

void	step(t_game *game)
{
	game->steps++;
	ft_printf("Steps: %d\n", game->steps);
}

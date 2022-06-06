/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 23:09:17 by gbreana           #+#    #+#             */
/*   Updated: 2022/06/06 15:10:23 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

int	check_input_params(int argc, char **argv)
{
	char	tmp[5];
	int		len;
	int		i;
	int		j;

	if (argc != 2)
		error("Wrong number of parameters.");
	len = ft_strlen(argv[1]);
	i = len - 4;
	j = 0;
	ft_strlcpy(tmp, ".ber", 5);
	while (i < len)
	{
		if (tmp[j++] != argv[1][i++])
			error("Map filename is not correct.");
	}
	return (0);
}

void	free2d(char **arr, int len)
{
	if (!arr)
		return ;
	while (--len >= 0)
		free(arr[len]);
	free(arr);
}

int	sym_count(t_game *game, char symbol)
{
	int		i;
	int		j;
	int		counter;

	counter = 0;
	i = game->map_height;
	while (--i >= 0)
	{
		j = 0;
		while (j < game->map_widht)
		{
			if (symbol == game->map[i][j])
				counter++;
			j++;
		}
	}
	return (counter);
}

void	map_obj_count(t_game *game)
{
	game->coins = sym_count(game, 'C');
	game->exits = sym_count(game, 'E');
	game->players = sym_count(game, 'P');
	game->raiders = sym_count(game, 'R');
}

int	check_sprites(t_assets *sprites)
{
	if (!sprites->wall)
		error("Wall sprite is not found");
	if (!sprites->floor)
		error("Floor sprite is not found");
	if (!sprites->exit_cl || !sprites->exit_op)
		error("Exit sprite is not found");
	if (!sprites->item_1 || !sprites->item_2)
		error("Collectible sprite is not found");
	if (!sprites->player_l || !sprites->player_r)
		error("Player sprite is not found");
	if (!sprites->raider_l || !sprites->raider_r)
		error("Raider sprite is not found");
	return (0);
}

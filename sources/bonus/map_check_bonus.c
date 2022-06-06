/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:18:51 by gbreana           #+#    #+#             */
/*   Updated: 2022/06/06 14:55:37 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

int	check_map_symbols(t_game *game)
{
	int		i;
	int		j;
	char	chrs[7];

	i = game->map_height;
	ft_strlcpy(chrs, "01CEPR", 7);
	while (--i >= 0)
	{
		j = 0;
		while (j < game->map_widht)
		{
			if (!ft_strchr(chrs, game->map[i][j]))
				error("Map contains wrong symbol(s).");
			j++;
		}
	}
	return (0);
}

int	check_map_size(t_game *game)
{
	int	i;

	if (!game->map_height || !game->map_widht)
		error("map has zero lines.");
	i = 0;
	while (++i < game->map_height)
	{
		if (ft_strlen(game->map[i]) != game->map_widht)
			error("map size is not valid.");
	}
	return (0);
}

int	check_map_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		if (i == 0 || i == game->map_height - 1)
		{
			while (j < game->map_widht)
			{
				if (game->map[i][j] != '1')
					error("map has broken walls.");
				j++;
			}
		}
		if (game->map[i][0] != '1' || game->map[i][game->map_widht - 1] != '1')
			error("map has broken walls.");
		i++;
	}
	return (0);
}

int	check_map(t_game *game)
{
	check_map_symbols(game);
	check_map_size(game);
	check_map_walls(game);
	map_obj_count(game);
	if (!game->coins)
		error("map does not contains any colectible.");
	else if (!game->exits)
		error("map does not contains any exit.");
	else if (!game->players)
		error("map does not contains any player.");
	else if (game->map_height <= 1)
		error("map is too small.");
	else if (!game->map_height && !game->map_widht)
		error("map is empty.");
	return (0);
}

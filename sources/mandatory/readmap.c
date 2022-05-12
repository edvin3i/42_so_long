/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 08:52:46 by gbreana           #+#    #+#             */
/*   Updated: 2022/05/13 00:52:37 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int		get_map_width(char **map)
{
	int	width;

	width = 0;
	while (*map[width] && *map[width] != '\n')
		width++;
	return(width);
}

int     count_lines(char *filename)
{
	int     lines_num;
	int     fd;
	char    *tmp;
	
	fd = open(filename, O_RDONLY);
	lines_num = -1;
	while(1)
	{
		tmp = get_next_line(fd);
		lines_num++;
		if (!tmp)
			break ;
		free(tmp);
	}
	close(fd);
	return (lines_num);
}

char    **file_to_array(char *filename)
{
	int     fd;
	int		lines_num;
	char	**map;

	lines_num = 0;
	map = malloc(lines_num * sizeof(char) + 1);
	if (!map)
		return (NULL);
	fd = open(filename, O_RDONLY);
	lines_num = count_lines(filename);
	map[lines_num] = NULL;
	while (--lines_num >= 0)
	{
		ft_printf("%d\t", lines_num);
		map[lines_num] = get_next_line(fd);
	}
		
	close(fd);
	return (map);
}
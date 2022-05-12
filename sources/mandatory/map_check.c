/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:18:51 by gbreana           #+#    #+#             */
/*   Updated: 2022/05/12 01:09:17 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int     check_filename(char *filename)
{
    char    tmp[5];
    size_t  i;
    size_t  j;
    size_t  len;

    len = ft_strlen(filename);
    i = len - 4;
    j = 0;
    ft_strlcpy(tmp, ".ber", 5);
    while (i < len)
    {
        if (tmp[j++] != filename[i++])
            return (1);
    }
    return (0);
}

int map_height(char **map)
{
	int height;
	
	height = 0;
	while (map[height])
		height++;
	return (height);
}


int check_map_size(char **map)
{
	int height;
	
	height = map_height(map) - 1;

    ft_printf("Map height = %d", height);

    while (map[height - 1])
    {
        ft_printf("\n-----------");
        
        ft_printf("\nARG 1: %d", ft_strlen(map[height]));
        ft_printf("\t%s", map[height]);
        
        ft_printf("\nARG 2: %d", ft_strlen(map[height-1]));
        ft_printf("\t%s", map[height-1]);
        if (ft_strlen(map[height]) != ft_strlen(map[height-1]))
        {
            error(2);
        }
            
        ft_printf("\n%d\t", height--);
    }
    return (height);
}
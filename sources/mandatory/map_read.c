/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 08:52:46 by gbreana           #+#    #+#             */
/*   Updated: 2022/06/05 14:25:53 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	count_lines(char *filename)
{
	int		lines_num;
	int		fd;
	char	*tmp;

	fd = open(filename, O_RDONLY);
	lines_num = 0;
	while (1)
	{
		tmp = get_next_line(fd);
		if (tmp)
		{
			if (tmp[0] == '\n')
			{
				free(tmp);
				error("Map has zero lines.");
			}
			lines_num++;
		}
		else
			break ;
		free(tmp);
	}
	close(fd);
	return (lines_num);
}

char	*file_to_array(char *filename)
{
	int		fd;
	char	*temp;
	char	*line;
	char	*new_line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error("File is not readable.");
	line = ft_strdup("");
	while (1)
	{
		new_line = get_next_line(fd);
		if (!new_line)
			break ;
		temp = line;
		line = ft_strjoin(line, new_line);
		free(temp);
		free(new_line);
	}
	close(fd);
	return (line);
}

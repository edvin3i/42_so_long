/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:01:03 by gbreana           #+#    #+#             */
/*   Updated: 2022/05/12 18:36:02 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../mlx/mlx.h"
#include "libft.h"

typedef struct  s_data
{
	void    *img;
	void    *mlx;
	void    *win;
	char    *addr;

	int     bits_per_pixel;
	int     line_length;
	int     endian;
}               t_data;


int		key_hook(int keycode);
int		mouse_hook(int keycode);

int		check_filename(char *filename);
int		count_lines(char *filename);
char	**file_to_array(char *filename);
int		error(int err_code);
void	free2d(char **arr);
int		check_map_size(char **map);
int		get_map_width(char **map);


#endif

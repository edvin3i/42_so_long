/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:11:46 by gbreana           #+#    #+#             */
/*   Updated: 2022/05/13 00:49:17 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int     main(int argc, char **argv)
{
    //int		width = 320;
    //int		height = 240;
    //int         fd;
	
	
    //int		color = 0x35E7E0;
    //t_data  data;

    if (argc != 2)
        error(1);
    
    check_filename(argv[1]);
	
    int cl = count_lines(argv[1]);
    ft_printf("%d\n", cl);


    char	**map = file_to_array(argv[1]);
	
    
    
    
    
while (--cl >= 0)
    ft_printf("%d", ft_strlen(map[cl]));

ft_printf("\n");



//check_map_size(map);
/*   

    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, width, height, "Hello, World!");
    mlx_key_hook(data.win, key_hook, &data);
    mlx_mouse_hook(data.win, mouse_hook, &data);
    mlx_loop(data.mlx);
*/
    return (0);
}
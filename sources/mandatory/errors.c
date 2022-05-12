/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:12:45 by gbreana           #+#    #+#             */
/*   Updated: 2022/05/12 00:57:38 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int error(int err_code)
{
    if (err_code == 1)
        ft_printf("\n\e[41mError:  map filename is missing    \e[0m\n");
    else if (err_code == 2)
        ft_printf("\n\e[41mError:  map is not valid           \e[0m\n");
    
    
    ft_printf("\n\e[46m\e[30mUsage: ./so_long [MAP_FILENAME.ber]\e[0m\n");
    exit(0);
}

void    free2d(char **arr)
{
    if (!arr)
        return ;
    while(*arr)
        free(*arr);
    free(arr);
}
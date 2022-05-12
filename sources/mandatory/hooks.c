/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:37:35 by gbreana           #+#    #+#             */
/*   Updated: 2022/05/05 13:00:42 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int     key_hook(int keycode)
{
    ft_printf("Key code: %d\n", keycode);
    return (0);
}

int     mouse_hook(int keycode)
{
    ft_printf("Mouse code: %d\n", keycode);
    return (0);
}
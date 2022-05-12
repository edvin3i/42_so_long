/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 10:48:23 by gbreana           #+#    #+#             */
/*   Updated: 2022/01/10 18:12:18 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_putstr(char *str)
{
	int	cnt;

	cnt = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (*str)
	{
		cnt += ft_putchar(*str);
		str++;
	}
	return (cnt);
}

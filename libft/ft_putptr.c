/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 20:02:36 by gbreana           #+#    #+#             */
/*   Updated: 2022/01/12 17:37:55 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_putptr(uintptr_t num)
{
	int	cnt;

	cnt = 0;
	cnt += ft_putstr("0x");
	if (num >= 16)
	{
		cnt += ft_puthex(num / 16, 'x');
		cnt += ft_puthex(num % 16, 'x');
	}
	else
	{
		if (num < 10)
			cnt += ft_putnbr(num);
		else
			cnt += ft_putchar(num - 10 + 'a');
	}
	return (cnt);
}

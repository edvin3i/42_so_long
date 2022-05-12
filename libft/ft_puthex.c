/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 22:03:46 by gbreana           #+#    #+#             */
/*   Updated: 2022/01/14 02:28:39 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_puthex(unsigned long num, int c)
{
	int	cnt;

	cnt = 0;
	if (num >= 16)
	{
		cnt += ft_puthex(num / 16, c);
		cnt += ft_puthex(num % 16, c);
	}
	else
	{
		if (num < 10)
			cnt += ft_putnbr(num);
		else if (c == 'x')
			cnt += ft_putchar(num - 10 + 'a');
		else if (c == 'X')
			cnt += ft_putchar(num - 10 + 'A');
	}
	return (cnt);
}

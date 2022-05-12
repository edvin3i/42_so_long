/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 20:02:36 by gbreana           #+#    #+#             */
/*   Updated: 2021/10/21 16:26:44 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_putnbr(int num)
{
	int				cnt;
	unsigned int	tmp;

	cnt = 0;
	if (num < 0)
	{
		cnt += ft_putchar('-');
		tmp = num * -1;
	}
	else
		tmp = num;
	if (tmp >= 10)
		cnt += ft_putnbr(tmp / 10);
	tmp %= 10;
	tmp += 48;
	cnt += ft_putchar(tmp);
	return (cnt);
}

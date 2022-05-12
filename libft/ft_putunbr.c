/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 20:02:36 by gbreana           #+#    #+#             */
/*   Updated: 2022/01/10 18:12:18 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_putunbr(unsigned int num)
{
	int	cnt;

	cnt = 0;
	if (num >= 10)
		cnt += ft_putunbr(num / 10);
	num %= 10;
	num += 48;
	cnt += ft_putchar(num);
	return (cnt);
}

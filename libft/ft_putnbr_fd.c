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

void	ft_putnbr_fd(int num, int fd)
{
	unsigned int	tmp;

	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		tmp = num * -1;
	}
	else
	{
		tmp = num;
	}
	if (tmp >= 10)
	{
		ft_putnbr_fd(tmp / 10, fd);
	}
	tmp %= 10;
	tmp += 48;
	ft_putchar_fd(tmp, fd);
}

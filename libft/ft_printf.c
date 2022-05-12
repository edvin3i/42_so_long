/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 09:09:12 by gbreana           #+#    #+#             */
/*   Updated: 2022/01/15 01:23:11 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_type_handler(int c, va_list args)
{
	int	counter;

	counter = 0;
	if (c == 'c')
		counter += ft_putchar(va_arg(args, int));
	else if (c == 's')
		counter += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		counter += ft_putptr(va_arg(args, uintptr_t));
	else if (c == 'd')
		counter += ft_putnbr(va_arg(args, int));
	else if (c == 'i')
		counter += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		counter += ft_putunbr(va_arg(args, unsigned int ));
	else if (c == 'x')
		counter += ft_puthex(va_arg(args, unsigned int), c);
	else if (c == 'X')
		counter += ft_puthex(va_arg(args, unsigned int), c);
	else if (c == '%')
		counter += ft_putchar('%');
	return (counter);
}

static int	ft_parser(const char *str, va_list args)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i] != '%')
			counter += ft_putchar(str[i]);
		else if (str[i] == '%' && str[i + 1])
		{
			i++;
			if (ft_strchri("cspdiuxX%", str[i]))
				counter += ft_type_handler(str[i], args);
			else if (str[i])
				counter += ft_putchar(str[i]);
		}
		i++;
	}
	return (counter);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		counter;

	counter = 0;
	va_start(ap, format);
	counter = ft_parser(format, ap);
	va_end(ap);
	return (counter);
}

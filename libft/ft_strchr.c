/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:25:35 by gbreana           #+#    #+#             */
/*   Updated: 2021/10/13 08:11:54 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/libft.h"

char	*ft_strchr(const char *src, int c)
{
	char	chr_c;

	chr_c = (char) c;
	while (*src != chr_c)
	{
		if (!*src)
			return (NULL);
		src++;
	}
	return ((char *)src);
}

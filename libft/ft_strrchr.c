/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 20:36:12 by gbreana           #+#    #+#             */
/*   Updated: 2021/10/17 23:17:42 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/libft.h"

char	*ft_strrchr(const char *src, int c)
{
	char		*ch_pos;
	const char	*end;

	ch_pos = 0;
	end = src;
	while (*end)
		end++;
	while (src <= end)
	{
		if (*src == c)
			ch_pos = (char *)src;
		src++;
	}
	return (ch_pos);
}

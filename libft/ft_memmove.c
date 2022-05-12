/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:22:51 by gbreana           #+#    #+#             */
/*   Updated: 2021/10/12 14:59:57 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst_iter;
	char	*src_iter;

	if (!dst && !src)
		return (NULL);
	else if (dst < src)
	{
		dst_iter = (char *) dst;
		src_iter = (char *) src;
		while (len--)
			*dst_iter++ = *src_iter++;
	}
	else
	{
		dst_iter = (char *) dst + len;
		src_iter = (char *) src + len;
		while (len--)
			*--dst_iter = *--src_iter;
	}
	return (dst);
}

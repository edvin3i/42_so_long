/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 09:12:32 by gbreana           #+#    #+#             */
/*   Updated: 2021/10/21 15:43:41 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

const void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*dst_iter;
	char	*src_iter;
	char	unsigned_c;

	dst_iter = (char *) dst;
	src_iter = (char *) src;
	unsigned_c = (char) c;
	if (!dst_iter && !src_iter)
		return (NULL);
	while (n--)
	{
		*dst_iter = *src_iter;
		if (*dst_iter == unsigned_c)
			return (++dst_iter);
		dst_iter++;
		src_iter++;
	}
	return (NULL);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dst_iter;
	char	*src_iter;

	dst_iter = (char *) dst;
	src_iter = (char *) src;
	if (!dst_iter && !src_iter)
		return (NULL);
	while (n--)
	{
		*dst_iter = *src_iter;
		dst_iter++;
		src_iter++;
	}
	return (dst);
}

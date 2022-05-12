/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:38:23 by gbreana           #+#    #+#             */
/*   Updated: 2022/05/06 16:01:21 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char		*dst_iter;
	const char	*src_iter;
	size_t		src_len;

	dst_iter = dst;
	src_iter = src;
	src_len = ft_strlen(src);
	if (!dst || !src)
		return (0);
	if (!dstsize)
		return (src_len);
	while (*src_iter && --dstsize)
		*dst_iter++ = *src_iter++;
	*dst_iter = 0x00;
	return (src_len);
}

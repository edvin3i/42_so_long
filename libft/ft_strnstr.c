/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 21:22:49 by gbreana           #+#    #+#             */
/*   Updated: 2021/10/20 03:53:08 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	ndl_len;

	ndl_len = (size_t) ft_strlen(needle);
	if (!ndl_len)
		return ((char *)haystack);
	while (len-- >= ndl_len)
	{
		if (!ft_memcmp(haystack, needle, ndl_len))
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}

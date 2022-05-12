/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 11:01:35 by gbreana           #+#    #+#             */
/*   Updated: 2021/10/09 12:39:53 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_iter;
	unsigned char	*s2_iter;
	size_t			result;

	s1_iter = (unsigned char *)s1;
	s2_iter = (unsigned char *)s2;
	result = 0;
	if (s1 == s2)
		return (result);
	while (result < n)
	{
		if (*s1_iter != *s2_iter)
			return (*s1_iter - *s2_iter);
		s1_iter++;
		s2_iter++;
		result++;
	}
	return (0);
}

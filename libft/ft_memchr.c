/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 10:29:12 by gbreana           #+#    #+#             */
/*   Updated: 2021/10/09 18:51:41 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*s_iter;
	char	chr_c;
	size_t	n_iter;

	s_iter = (char *)s;
	chr_c = (char)c;
	n_iter = 0;
	while (n_iter < n)
	{
		if (*s_iter == chr_c)
			return (s_iter);
		s_iter++;
		n_iter++;
	}
	return (NULL);
}

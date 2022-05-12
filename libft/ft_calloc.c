/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 10:36:23 by gbreana           #+#    #+#             */
/*   Updated: 2021/11/02 12:22:16 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	vol;
	void	*dest;

	vol = count * size;
	dest = malloc(vol);
	if (dest)
		ft_bzero(dest, vol);
	return (dest);
}

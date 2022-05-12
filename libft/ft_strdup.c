/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:13:33 by gbreana           #+#    #+#             */
/*   Updated: 2021/10/15 19:32:41 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/libft.h"

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	i = -1;
	dest = malloc(ft_strlen(src) + 1);
	if (dest == NULL)
		return (NULL);
	while (src[++i])
		dest[i] = src[i];
	dest[i] = 0;
	return (dest);
}

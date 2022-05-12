/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:54:17 by gbreana           #+#    #+#             */
/*   Updated: 2022/03/24 15:54:36 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnjoin(char *str1, char *str2)
{
	char	*result;
	char	*res_iter;
	int		res_len;

	if (!str1)
	{
		str1 = malloc(sizeof (char));
		str1[0] = '\0';
	}
	if (!str2)
		return (NULL);
	res_len = ft_strlen(str1) + ft_strlen(str2) + 1;
	result = (char *)malloc(res_len * sizeof(char));
	if (!result)
		return (NULL);
	res_iter = result;
	while (*str1)
		*res_iter++ = *str1++;
	while (*str2)
		*res_iter++ = *str2++;
	*res_iter = 0x00;
	return (result);
}

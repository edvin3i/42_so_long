/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 23:54:34 by gbreana           #+#    #+#             */
/*   Updated: 2022/05/06 16:39:07 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strjoin(const char *str1, const char *str2)
{
	char	*result;
	char	*res_iter;
	int		res_len;

	if (!str1 || !str2)
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

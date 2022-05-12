/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:43:29 by gbreana           #+#    #+#             */
/*   Updated: 2021/10/25 09:37:59 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	unsigned int	end;
	char			*result;
	char			*res_iter;

	if (!str)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(str) || start == len)
		return (ft_strdup(""));
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	res_iter = result;
	end = start + len - 1;
	while (start <= end)
		*res_iter++ = str[start++];
	*res_iter = 0x00;
	return (result);
}

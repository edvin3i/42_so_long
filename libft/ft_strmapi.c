/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 09:42:52 by gbreana           #+#    #+#             */
/*   Updated: 2021/10/19 11:56:37 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	unsigned int	str_len;
	char			*result;

	if (!s || !f)
		return (NULL);
	index = 0;
	str_len = ft_strlen(s);
	result = (char *)malloc(sizeof(char) * (str_len + 1));
	if (!result)
		return (NULL);
	while (index < str_len)
	{
		result[index] = f(index, s[index]);
		index++;
	}
	result[index] = 0x00;
	return (result);
}

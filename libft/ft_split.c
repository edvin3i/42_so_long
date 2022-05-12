/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:12:35 by gbreana           #+#    #+#             */
/*   Updated: 2022/05/03 16:16:36 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_word_count(const char *str, char delimiter)
{
	int		counter;
	int		prev_delim;
	int		i;

	counter = 0;
	prev_delim = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] == delimiter)
			prev_delim = 1;
		else if (prev_delim)
			counter++;
		if (str[i] != delimiter)
			prev_delim = 0;
		i++;
	}
	return (counter);
}

static char	*ft_word(const char *str, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (*str && *str == c)
		str++;
	while (str[i] && str[i] != c)
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (*str && *str != c)
		word[i++] = *str++;
	word[i] = 0x00;
	return (word);
}

static void	ft_freemem(char *arr, int wrd_cnt)
{
	while (wrd_cnt)
	{
		free(&arr[wrd_cnt - 1]);
		wrd_cnt--;
	}
}

static char	**ft_word_to_array(char **arr, const char *s, char c, int wrd_cnt)
{
	int	i;

	i = 0;
	while (i < wrd_cnt)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			arr[i] = ft_word(s, c);
			if (!arr[i])
			{
				ft_freemem(*arr, i);
				free(arr);
				return (NULL);
			}
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	arr[i] = NULL;
	return (arr);
}

char	**ft_split(const char *s, char c)
{
	int		num_words;
	char	**result;

	if (!s)
		return (NULL);
	num_words = ft_word_count(s, c);
	result = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (!result)
		return (NULL);
	result = ft_word_to_array(result, s, c, num_words);
	return (result);
}

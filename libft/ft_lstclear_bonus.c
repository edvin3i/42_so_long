/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 03:22:31 by gbreana           #+#    #+#             */
/*   Updated: 2021/11/11 12:34:54 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*slst;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		slst = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(slst, del);
	}
}

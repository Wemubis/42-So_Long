/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:37:11 by mle-boud          #+#    #+#             */
/*   Updated: 2022/11/16 18:22:16 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*elem;
	t_list	*adjacent;

	if (!lst || !del)
		return ;
	if (!*lst)
	{
		*lst = NULL;
		return ;
	}
	elem = *lst;
	while (elem)
	{
		adjacent = elem->next;
		ft_lstdelone(elem, del);
		elem = adjacent;
	}
	*lst = NULL;
}

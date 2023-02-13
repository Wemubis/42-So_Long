/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:25:03 by mle-boud          #+#    #+#             */
/*   Updated: 2023/02/13 18:20:57 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_lst	*new_element(char *data)
{
	t_lst	*new;

	new = malloc(sizeof(t_lst));
	if (!new)
		error("malloc");
	new->data = data;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

int	lst_size(t_lst *lst)
{
	int	x;

	x = 0;
	while (lst)
	{
		lst = lst->next;
		x++;
	}
	return (x);
}

void	add_back(t_lst **lst, t_lst *new)
{
	t_list	*last;

	if (!new || !lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new;
	new->prev = last;
}

void	*pop(t_lst *head)
{
	t_lst	*tmp;

	if (!head)
		return ;
	tmp = head;
	if (head->next == NULL)
		head = NULL;
	else
	{
		head = head->next;
		head->prev = NULL;
	}
	free(tmp);
}

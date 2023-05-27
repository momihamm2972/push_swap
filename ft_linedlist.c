/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linedlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 04:34:44 by momihamm          #+#    #+#             */
/*   Updated: 2023/05/24 00:32:09 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstnew(int content)
{
	t_node	*head;

	head = (t_node *) malloc(sizeof (t_node));
	head->a = (int)content;
	head->next = NULL;
	return (head);
}

t_node	*ft_lstlast(t_node *head)
{
	if (!head)
		return (0);
	while (head->next)
		head = head->next;
	return (head);
}

int	ft_lstsize(t_node *head)
{
	int	size;

	size = 0;
	if (!head)
		return (0);
	while (head)
	{
		head = head->next;
		size++;
	}
	return (size);
}

// void ft_lstadd_back(t_node **lst, t_node *new)
// {
// 	t_node *ptr;

// 	ptr = (t_node *)ft_lstlast(lst);

// }

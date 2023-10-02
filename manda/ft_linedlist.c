/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linedlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 04:34:44 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/02 07:12:06 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstnew(int content)
{
	t_node	*head;

	head = malloc (sizeof (t_node));
	head->data = content;
	head->prev = NULL;
	head->next = NULL;
	return (head);
}

void	ft_lstadd_front(t_node **lst, t_node *new)
{
	new->next = (*lst);
	(*lst) = new;
}

int	ft_lstsize(t_node *lst)
{
	t_node	*ptr;
	int		i;

	ptr = lst;
	i = 0;
	while (ptr)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
}

t_node	*ft_lstlast(t_node **lst)
{
	t_node	*ptr;

	if (!(*lst))
		return (NULL);
	if ((*lst)->next == NULL)
		return ((*lst));
	ptr = (*lst);
	while (ptr->next)
	{
		if (ptr->next->next == NULL)
			return (ptr->next);
		ptr = ptr->next;
	}
	return (NULL);
}

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*the_last;

	the_last = ft_lstlast(lst);
	the_last->next = new;
	new->prev = the_last;
}

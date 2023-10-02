/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_bonus0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:19:35 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/02 20:44:10 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_checker.h"

t_node	*ft_lstnew(int content)
{
	t_node	*head;

	head = malloc (sizeof (t_node));
	if (!head)
		return (NULL);
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

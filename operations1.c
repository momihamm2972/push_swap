/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 00:38:47 by momihamm          #+#    #+#             */
/*   Updated: 2023/07/09 16:05:46 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rev_rotate (t_node **stack)
{
	t_node *the_last;
	t_node *new_last;
	
	if (!(*stack))
		return ;
	the_last = ft_lstlast ((*stack));
	new_last = before_the_last(stack);
	the_last->next = (*stack);
	(*stack) = new_last->next;
	new_last->next = NULL;
}

void	rrr (t_node **stack_a, t_node **stack_b)
{
	rev_rotate (stack_a);
	rev_rotate (stack_b);
}

t_node *find_the_small_position(t_node **stack)
{
	t_node *ptr;

	ptr = (*stack);
	while (ptr)
	{
		if (ptr->position == 1)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}

int find_the_index_of_the_node (t_node **stack, t_parss *my_stru, int value)
{
	t_node *ptr;
	int size;

	ptr = (*stack);
	size = my_stru->sizeof_stack;
	if (ptr->data == value)
		return (size);
	while (ptr)
	{
		size--;
		ptr = ptr->next;
		if (ptr != NULL && ptr->data == value)
			return (size);
	}
	return (-1);
}

// int main ()
// {
// 	t_node *head =  ft_lstnew (32);
// 	head->position = 2;
// 	head->next = ft_lstnew (33);
// 	head->next->position = 1;
// 	head->next->next = ft_lstnew (12);
// 	head->next->next->position = 3;
// 	head->next->next->next = ft_lstnew (43);
// 	head->next->next->next->position = 4;
// 	t_node *ptr = find_the_small_position(&head);
// 	printf ("%d",ptr->data);
// }

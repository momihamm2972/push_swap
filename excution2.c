/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excution2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:57:31 by momihamm          #+#    #+#             */
/*   Updated: 2023/07/16 02:56:06 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_node *find_the_scnd_small_position(t_node **stack)
{
	t_node *ptr;

	ptr = (*stack);
	while (ptr)
	{
		if (ptr->position == 2)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}

int find_the_index_of_the_node (t_node **stack, t_parss *my_stru, int value)
{
	t_node *ptr;
	int size;
	(void)my_stru;
	ptr = (*stack);
	size = ft_lstsize ((*stack));
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



void    make_the_scnd_in_top (t_parss *my_sc, t_node **stack, int small)
{
    int indx;
       while (1)
        {
            indx = find_the_index_of_the_node (stack, my_sc, small);
            if (indx == 4)
                return ;
            else if (indx == 1)
            {
                rev_rotate (stack, 0);
                return ;
            }
            else if (indx == 3)
            {
                swap_2_elements (stack, 0);
                return ;
            }
            else
                rev_rotate (stack, 0);
        }
}

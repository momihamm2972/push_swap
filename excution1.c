/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excution1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:57:27 by momihamm          #+#    #+#             */
/*   Updated: 2023/07/16 02:56:02 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int finally_sorted (t_node **stack)
{
	t_node	*tmp;
	int		indx;
	
	if (!(*stack))
		return (1);
	tmp = (*stack);
	if (tmp->position == 0)
		indx = 1;
	else
		return (1);
	while (tmp)
	{
		tmp = tmp->next;
		if ((tmp != NULL) && (tmp->position != indx))
			return (1);
		indx++;	
	}
	return (0);
}

void    ft_tree_posi_exat (t_node **stack)
{
    t_node *ptr;
    
    ptr = (*stack);
    if (!ptr)
        return ;
    ptr->position -= 1;
    while (ptr)
    {
        ptr = ptr->next;
        if (ptr != NULL)
            ptr->position -= 1;
    }
}

void    ft_orederfor_stack_for (t_parss *my_struc, t_node **stack)
{
    t_node *small;
    int     node_indx;

    small = find_the_small_position (stack);
    node_indx = find_the_index_of_the_node (stack, my_struc, small->data);
        if (node_indx == 4)
            printf ("GOOD\n");
        else if (node_indx >= 2)
        {
            rotate (stack, 0);
            if (node_indx == 2)
                swap_2_elements (stack, 0);
        }
        else
            rev_rotate (stack, 0);
}

void    ft_tree (t_node **stack)
{
    if ((*stack)->position == 2 && (*stack)->next->position == 1)
	{
        swap_2_elements (stack, 0);
		return ;
	}
    if ((*stack)->next->next->position == 1 && (*stack)->next->position == 2
    && (*stack)->position == 3)
    {
        swap_2_elements (stack, 0);
        rev_rotate (stack, 0);
		return ;
    }
    if ((*stack)->next->position == 1 && (*stack)->next->next->position == 2
    && (*stack)->position == 3)
	{
        rotate (stack, 0);
		return ;
	}
	else
		ft_tree_complet (stack);
}

void	ft_tree_complet (t_node **stack)
{
    if ((*stack)->position == 1 && (*stack)->next->position == 3
    && (*stack)->next->next->position == 2)
	{
        swap_2_elements (stack, 0);
        rotate (stack, 0);
		return ;
    }
	if ((*stack)->position == 2 && (*stack)->next->position == 3
	&& (*stack)->next->next->position == 1)
	{
		rev_rotate (stack, 0);
		return ;
	}
}

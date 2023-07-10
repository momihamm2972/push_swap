/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 03:46:44 by momihamm          #+#    #+#             */
/*   Updated: 2023/07/09 22:27:09 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_2_elements(t_node **stack)
{
	int swaper;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return;
	swaper = (*stack)->data;
	(*stack)->data = (*stack)->next->data;
	(*stack)->next->data =	swaper;
	swaper = (*stack)->position;
	(*stack)->position = (*stack)->next->position;
	(*stack)->next->position =	swaper;
}


void	ss(t_node **stack_a, t_node **stack_b)
{
	swap_2_elements(stack_a);
	swap_2_elements(stack_b);
}

void	push_to_stack(t_node **stack_0, t_node **stack_1)
{
	// t_node *tmp;
	t_node *fri;
	
	if (!(*stack_0))
		return ;
	ft_lstadd_front(stack_1, ft_lstnew((*stack_0)->data));
	fri = (*stack_0);
	(*stack_0) = (*stack_0)->next;
	free (fri);
}

void	rotate (t_node **stack)
{
	// t_node *tmp;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
	t_node *last;
	
	if (!(*stack))
		return ;
	// tmp = (*stack);
	last = ft_lstlast ((*stack));
	last->next = (*stack);
	(*stack) = (*stack)->next;
	last->next->next = NULL;
}

void	rr (t_node **stack_a, t_node **stack_b)
{
	rotate (stack_a);
	rotate (stack_b);
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
                rev_rotate (stack);
                return ;
            }
            else if (indx == 3)
            {
                swap_2_elements (stack);
                return ;
            }
            else
                rev_rotate (stack);
        }
}

// int main ()
// {
// 	t_node *head = ft_lstnew (04);
// 	head->next = ft_lstnew (99);
// 	head->next->next = ft_lstnew (32);
// 	head->next->next->next = ft_lstnew (0);
// 	// swap_2_elements ;
// 	make_the_scnd_in_top ()
// 	print_nodes (&head);
// }

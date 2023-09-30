/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excution5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:57:41 by momihamm          #+#    #+#             */
/*   Updated: 2023/09/30 01:24:47 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	if_min_max_in_b (t_parss *azalim)
{
	if (min_value (azalim->stack_b) < min_value (azalim->stack_a))
	{
		an_node (azalim->stack_b, min_value (azalim->stack_b));
		make_it_top (azalim, min_value (azalim->stack_b));
		push_to_stack (azalim->stack_b, azalim->stack_a, 1);
	}
	if (big_value (azalim->stack_b) > big_value (azalim->stack_a))
	{
		an_node (azalim->stack_b, big_value (azalim->stack_b));
		make_it_top (azalim,big_value (azalim->stack_b));
		push_to_stack (azalim->stack_b, azalim->stack_a, 1);
		rotate (azalim->stack_a, 0);
	}         
}

void	rev_or (t_node **stack)
{
	t_node	*ptr;

	ptr = (*stack);
	while (ptr)
	{
		if (ptr->indx_of_node < (ft_lstsize ((*stack)) / 2))
			ptr->moves_b = ptr->indx_of_node;
		else if (ptr->indx_of_node >= (ft_lstsize ((*stack)) / 2))
		{
			ptr->moves_b = ft_lstsize ((*stack)) - ptr->indx_of_node;
			ptr->moves_b *= -1;
		}
		ptr = ptr->next;
	}
}

int	how_may_move (t_parss *kane, int info)
{
	t_node	*ptr;
	int		cont=0;

	ptr = (*kane->stack_a);
	while (ptr)
	{
		if (ptr->data > info)
		{
			if (ptr->moves_b >= 0)
			{
				cont = ptr->moves_b;
				// printf ("l3alamyaaaaaaaaaaaaaaaaaaaa  %d                  **\n",cont);
			}
			else if (ptr->moves_b < 0)
			{
				cont = ptr->moves_b * (-1);
				// printf ("kmi %d                                 **\n",cont);
			}
			// printf ("!!!!!!!!!!!!!!!!!!!!!!!!!!  %d  !!!!!!!!!!!!!!!!!!!!!\n",cont);
			return (cont);
		}
		ptr = ptr->next;
	}
	return (0);
}

void	keep_it (t_parss *speed)
{
	if_min_max_in_b (speed);
	best_move_in_b (speed);
	best_move_in_a (speed);
	total_of_a_b (speed);
	// rev_or (speed->stack_a);
}

void    ft_all_most (t_parss *sane)
{
    t_node  *ptr_a=NULL;
	t_node	*min_ista=NULL;
	t_node	*next_min=NULL;
	// t_node	*less;
    // t_node  *ptr_b;
	// int i=0;

    ptr_a = (*sane->stack_a);
    // ptr_b = (*sane->stack_b);
	while (ptr_a)
	{
		keep_it (sane);
		min_ista = min_instractions (sane->stack_b);
		// make_money (s)
		if (!min_ista)
		{
			// printf ("kmi\n");
			return;
		}
		// printf ("ministra      ===>%d<====\n",min_ista->data);
		next_min = next_of_num_sicondo (sane->stack_a, min_ista->data);
		// printf ("nextof min      >>>>>>>|>>>>%d<<<<<<<\n",next_min->data);
		if ((*sane->stack_a)->data != next_min->data && (*sane->stack_b)->data != min_ista->data)
		{
			if (next_min->moves_b < 0 && min_ista->moves_b < 0)
			{
				while ((*sane->stack_a)->data != next_min->data || (*sane->stack_b)->data != min_ista->data)
				{
					rrr (sane->stack_a, sane->stack_b);
					if ((*sane->stack_a)->data == next_min->data || (*sane->stack_b)->data == min_ista->data)
						break;
				}
			}
			else if (next_min->moves_b > 0 && min_ista->moves_b > 0)
			{
				while ((*sane->stack_a)->data != next_min->data || (*sane->stack_b)->data != min_ista->data)
				{
					// printf ("stacka %d p_a %d  stackb %d  p_b %d \n",(*sane->stack_a)->data ,next_min->data, (*sane->stack_b)->data ,min_ista->data);
					rr (sane->stack_a, sane->stack_b);
					if ((*sane->stack_a)->data == next_min->data || (*sane->stack_b)->data == min_ista->data)
						break;
				}
			}
		}
		// else
		// {
		make_money_a (sane->stack_a, next_min, next_min->data);
		make_money_b (sane->stack_b, min_ista, min_ista->data);
		// }
		push_to_stack (sane->stack_b, sane->stack_a, 1);
		// i++;
		if ((*sane->stack_b) == NULL)
		{
			// printf ("7wi\n");
			break;
		}
		// ptr_a = ptr_a->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excution1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:57:27 by momihamm          #+#    #+#             */
/*   Updated: 2023/09/25 20:46:41 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_the_lis(t_node **stack, int length)
{
	t_node	**head;
	t_node	*ptr;
	int		num;

	head = malloc (sizeof (t_node *));
	ptr = ft_lstlast (stack);
	num = length;
	while (ptr)
	{
		if (ptr->length == num)
		{
			ft_lstadd_front (head, ft_lstnew (ptr->data));
			num--;
		}
		ptr = ptr->prev;
		if (ptr == NULL)
			break ;
	}
	print_lis (head);
	ft_free_a_stack (head);
}

void	check_the_lis_are_in(t_node **stack, int length)
{
	t_node	*ptr;
	int		num;

	ptr = ft_lstlast(stack);
	num = length;
	while (ptr)
	{
		if (ptr->length == num)
		{
			ptr->are_in = 0;
			num--;
		}
		ptr = ptr->prev;
	}
}

int	find_the_big_length(t_node **stacka)
{
	t_node	*ptr;
	int		big;

	ptr = (*stacka);
	big = 0;
	while (ptr)
	{
		if (ptr->length > big)
			big = ptr->length;
		ptr = ptr->next;
	}
	return (big);
}

void	make_the_length_one(t_parss *length)
{
	t_node	*ptr;
	int		indx;

	ptr = (*length->stack_a);
	indx = 0;
	while (ptr)
	{
		ptr->length = 1;
		ptr->are_in = 1;
		ptr->indx_of_stack = indx;
		ptr = ptr->next;
		indx++;
	}
}

// void	print_lis (t_node **stacka)
// {
// 	t_node	*ptr;
// 	void	*bebe;

// 	bebe = (void *)0xbebebebebebebebe;
// 	ptr = (*stacka);
// 	while (ptr)
// 	{
// 		printf ("$%d\t",ptr->data);
// 		ptr = ptr->next;
// 		if (ptr == bebe)
// 			ptr = NULL;
// 	}
// 	ptr = (*stacka);
// 	printf ("\n");
// }

void	lis(t_parss *lewandowski)
{
	t_node	*ptr_i;
	t_node	*ptr_j;

	ptr_i = (*lewandowski->stack_a)->next;
	ptr_j = (*lewandowski->stack_a);
	while (ptr_i)
	{
		if (ptr_j->data < ptr_i->data)
		{
			if (ptr_i->length <= ptr_j->length +1)
			{
				ptr_i->length = ptr_j->length + 1;
			}
		}
		ptr_j = ptr_j->next;
		if (ptr_j->indx_of_stack == ptr_i->indx_of_stack)
		{
			ptr_j = (*lewandowski->stack_a);
			ptr_i = ptr_i->next;
		}
	}
}

void	best_move_in_b (t_parss *djaja)
{
	t_node	*ptr;

	ptr = (*djaja->stack_b);
	while (ptr)
	{
		if (ptr->indx_of_node <= (ft_lstsize ((*djaja->stack_b)) / 2))
		{
			ptr->moves_b = ptr->indx_of_node;
		}
		else if (ptr->indx_of_node >= (ft_lstsize ((*djaja->stack_b)) / 2))
		{
			ptr->moves_b = ft_lstsize ((*djaja->stack_b)) - ptr->indx_of_node;
			ptr->moves_b *= -1;
		}
		ptr = ptr->next;
	}
}

void	best_move_in_a (t_parss *jwan)
{
	t_node	*ptr_a;
	t_node	*ptr_b;

	// ptr_a = (*jwan->stack_a);
	ptr_b = (*jwan->stack_b);
	while (ptr_b)
	{
		ptr_a = (*jwan->stack_a);
		while (ptr_a)
		{
			if (ptr_b->data < ptr_a->data)
			{
				if (ptr_a->indx_of_node <= (ft_lstsize ((*jwan->stack_a)) / 2))
					ptr_a->moves_a = ptr_b->indx_of_node;
				else if (ptr_a->indx_of_node >= (ft_lstsize ((*jwan->stack_a)) / 2))
				{
					ptr_a->moves_a = ft_lstsize ((*jwan->stack_a)) - ptr_a->indx_of_node;
					ptr_a->moves_a *= -1;
				}
			}
			ptr_a = ptr_a->next;
		}
		ptr_b = ptr_b->next;
	}
}

void	total_of_a_b (t_parss *tamawayet)
{
	t_node	*ptr;
	int		p_value;

	ptr = (*tamawayet->stack_b);
	while (ptr)
	{
		if (ptr->moves_b < 0)
		{
			p_value = ptr->moves_b * (-1);
			ptr->total_moves = ptr->moves_a + p_value + 1;
		}
		else
			ptr->total_moves = ptr->moves_a + ptr->moves_b + 1;
		ptr = ptr->next;
	}
}

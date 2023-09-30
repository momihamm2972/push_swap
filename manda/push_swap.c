/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:42:06 by momihamm          #+#    #+#             */
/*   Updated: 2023/09/30 01:20:12 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	best_move_in_b(t_parss *djaja);
// void	best_move_in_a(t_parss *jwan);
// void	total_of_a_b(t_parss *tamawayet);

// void	best_move_in_b (t_parss *djaja)
// {
// 	t_node	*ptr;

// 	ptr = (*djaja->stack_b);
// 	while (ptr)
// 	{
// 		if (ptr->indx_of_node <= (ft_lstsize ((*djaja->stack_b)) / 2))
// 		{
// 			ptr->moves_b = ptr->indx_of_node;
// 		}
// 		else if (ptr->indx_of_node >= (ft_lstsize ((*djaja->stack_b)) / 2))
// 		{
// 			ptr->moves_b = ft_lstsize ((*djaja->stack_b)) - ptr->indx_of_node;
// 			ptr->moves_b *= -1;
// 		}
// 		ptr = ptr->next;
// 	}
// }

// void	best_move_in_a (t_parss *jwan)
// {
// 	t_node	*ptr_a;
// 	t_node	*ptr_b;

// 	// ptr_a = (*jwan->stack_a);
// 	ptr_b = (*jwan->stack_b);
// 	while (ptr_b)
// 	{
// 		ptr_a = (*jwan->stack_a);
// 		while (ptr_a)
// 		{
// 			if (ptr_b->data < ptr_a->data)
// 			{
// 				// if (ptr_a->indx_of_node <= (ft_lstsize ((*jwan->stack_a)) / 2))
// 				// 	ptr_b->moves_a = ptr_b->indx_of_node;
// 				// else if (ptr_a->indx_of_node >= (ft_lstsize ((*jwan->stack_a)) / 2))
// 				// {
// 				// 	ptr_b->moves_a = ft_lstsize ((*jwan->stack_a)) - ptr_a->indx_of_node;
// 				// 	ptr_b->moves_a *= -1;
// 				// }
// 				ptr_b->moves_a = ptr_a->indx_of_node;
// 				printf ("%d!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  |%d|   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n",ptr_b->data,ptr_b->moves_a);
// 				break;
// 			}
// 			ptr_a = ptr_a->next;
// 		}
// 		ptr_b = ptr_b->next;
// 	}
// }

// void	total_of_a_b (t_parss *tamawayet)
// {
// 	t_node	*ptr;
// 	int		p_value;

// 	ptr = (*tamawayet->stack_b);
// 	while (ptr)
// 	{
// 		if (ptr->moves_b < 0)
// 		{
// 			p_value = ptr->moves_b * (-1);
// 			ptr->total_moves = ptr->moves_a + p_value + 1;
// 		}
// 		else
// 			ptr->total_moves = ptr->moves_a + ptr->moves_b + 1;
// 		ptr = ptr->next;
// 	}
// }

void	mr(void)
{
	system ("leaks push_swap");
}

t_node *min_value_in (t_node **stack)
{
	t_node *ptr;
	t_node *node;
	int min;

	ptr = (*stack);
	min = ptr->data;
	while (ptr)
	{
		if (ptr->data < min)
		{
			min = ptr->data;
			node = ptr;
		}
		ptr = ptr->next;
	}
	return (node);
}

void	excution(t_parss *excution)
{
	int	big;

	make_the_length_one (excution);
	lis (excution);
	big = find_the_big_length (excution->stack_a);
	// // printf ("\nthe big is %d\n",big);
	check_the_lis_are_in (excution->stack_a, big);
	make_the_lis_in_a (excution);
	keep_it (excution);
	// ft_all_most (excution);
	// rev_or (excution->stack_a);
	// int m= min_value (excution->stack_a);
	// // // printf ("$$$$$$$$$ mekkez%d\n",m);
	// t_node *p=min_value_in (excution->stack_a);
	// if (p->moves_b > 0)
	// {
	// 	while ((*excution->stack_a)->data != m)
	// 		rotate (excution->stack_a, 0);
	// }
	// else if (p->moves_b < 0)
	// {
	// 	while ((*excution->stack_a)->data != m)
	// 		rev_rotate (excution->stack_a, 0);
	// }
	

	
	print_nodes (excution->stack_a);
	printf ("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	print_nodes(excution->stack_b);
}

// void	conti_nue (t_parss *cotinu)
// {
// 	total_of_a_b (cotinu);
// }

int	main(int ac, char **av)
{
	t_parss	*pars;

	if (ac >= 2)
	{
		pars = malloc (sizeof (t_parss));
		pars->arg1 = ft_strdup("");
		pars->indxarg = 0;
		while (av[++pars->indxarg])
		{
			if (only_sing (av[pars->indxarg]) == -91)
				exit (error_msg ());
			pars->ptr = pars->arg1;
			pars->ptr1 = finale_char (av[pars->indxarg]);
			pars->arg1 = ft_strjoin (pars->arg1, pars->ptr1);
			if (av[pars->indxarg + 1] != NULL)
				free (pars->ptr);
			free (pars->ptr1);
		}
		make_args_usefull (pars);
		excution (pars);
		// print_nodes (pars->stack_a);
		// free(pars->arg1);
	}
	// atexit (mr);
	exit(0);
}

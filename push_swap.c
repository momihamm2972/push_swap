/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:42:06 by momihamm          #+#    #+#             */
/*   Updated: 2023/06/22 13:22:59 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    first_trys (t_parss *my_sc, t_node **stack)
{
    // (void) my_sc;
    // (void) stack;
    // printf ("A 7chem %d",my_sc->len_of_arr);
    if (my_sc->sizeof_stack == 1)
        printf ("%d",(*stack)->data);
    else if (my_sc->sizeof_stack == 2)
    {
        swap_2_elements (stack);
        printf ("%d  %d",(*stack)->data, (*stack)->next->data);
    }
    else if (my_sc->sizeof_stack == 3)
    {
        // printf ("mimmi\n");
        ft_tree (my_sc, stack);
    }
}

void    ft_tree (t_parss *my_sc, t_node **stack)
{
    (void) my_sc;
    if ((*stack)->position == 2 && (*stack)->next->position == 1)
	{
        swap_2_elements (stack);
		return ;
	}
    if ((*stack)->next->next->position == 1 && (*stack)->next->position == 2
    && (*stack)->position == 3)
    {
        swap_2_elements (stack);
        rev_rotate (stack);
		return ;
    }
    if ((*stack)->next->position == 1 && (*stack)->next->next->position == 2
    && (*stack)->position == 3)
	{
        rotate (stack);
		return ;
	}
    if ((*stack)->position == 1 && (*stack)->next->position == 3
    && (*stack)->next->next->position == 2)
	{
        swap_2_elements (stack);
        rotate (stack);
		return ;
    }
	if ((*stack)->position == 2 && (*stack)->next->position == 3
	&& (*stack)->next->next->position == 1)
	{
		rev_rotate (stack);
		return ;
	}
}

int main (int ac, char **av)
{
    if (ac >= 2)
    {
        t_parss *pars;

        pars = malloc (sizeof (t_parss));
        pars->arg1 = malloc (1);
        pars->indxarg = 0;
        while (av[++pars->indxarg])
            pars->arg1 = ft_strjoin (pars->arg1, finale_char (av[pars->indxarg]));
        parssing (pars);
        // first_trys (parss,)
    }
}
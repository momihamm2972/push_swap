/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:42:06 by momihamm          #+#    #+#             */
/*   Updated: 2023/06/16 11:42:28 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    first_trys (t_parss *my_sc, t_node **stack)
{
    (void) my_sc;
    (void) stack;
    // printf ("A 7chem %d",my_sc->len_of_arr);
    if (my_sc->len_of_arr == 1)
        printf ("%d",(*stack)->data);
    else if (my_sc->len_of_arr == 2)
    {
        swap_2_elements ((*stack));
        printf ("%d  %d",(*stack)->data, (*stack)->next->data);
    }
    else if (my_sc->len_of_arr == 3)
    {
        
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
    }
}
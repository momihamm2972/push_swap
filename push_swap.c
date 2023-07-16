/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:42:06 by momihamm          #+#    #+#             */
/*   Updated: 2023/07/16 11:03:28 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
        /*+++excution+++*/
        first_trys (pars, &pars->head);
        if (pars->sizeof_stack > 5)
            scond_trys (pars, &pars->head, pars->stack_b);
        // print_nodes (&pars->head);
        // printf ("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n");
        // print_nodes (pars->stack_b);
        print_num (&pars->head);
    }
}
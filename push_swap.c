/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:42:06 by momihamm          #+#    #+#             */
/*   Updated: 2023/07/20 10:50:44 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    mr (void)
{
    system ("leaks push_swap");
}

int main (int ac, char **av)
{
    // atexit (mr);
    if (ac >= 2)
    {
        (void) av;
        t_parss *pars;
        char    *ptr;
        char    *ptr1;

        pars = malloc (sizeof (t_parss));
        pars->arg1 = ft_strdup("");
        ptr = pars->arg1;
        pars->indxarg = 0;
        while (av[++pars->indxarg])
        {
            ptr1 = finale_char (av[pars->indxarg]);
            pars->arg1 = ft_strjoin (pars->arg1, ptr1/*finale_char (av[pars->indxarg])*/);
            // printf ("{%s}\n",ptr1);
            free (ptr1);
        }
        // printf ("{%s}",pars->arg1);
        parssing (pars);
        /*+++excution+++*/
        first_trys (pars, &pars->head);
        if (pars->sizeof_stack > 5)
            scond_trys (pars, &pars->head, pars->stack_b);
        // print_nodes (&pars->head);
        // printf ("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n");
        // print_nodes (pars->stack_b);
        printf ("\n\n\n\n\n\n\n\n\n");
        print_num (&pars->head);
        free (ptr);
        free (pars);
        free(pars->arg1);
    }
    exit(0);
}
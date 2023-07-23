/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:42:06 by momihamm          #+#    #+#             */
/*   Updated: 2023/07/23 11:26:58 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    mr (void)
{
    system ("leaks push_swap");
}

void    free_struct (t_parss *my_struct)
{
    free (my_struct->head);
    free_matrix (my_struct->arg2);
    free (my_struct->arg1);
    free (my_struct->stack_b);
    free (my_struct->beforsorted);
    // free (my_struct->indx);
    // free (my_struct->indxarg);
    // free (my_struct->len_of_arr);
    // free (my_struct->sizeof_stack);
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
        // ptr = pars->arg1;
        pars->indxarg = 0;
        while (av[++pars->indxarg])
        {
            ptr = pars->arg1;
            ptr1 = finale_char (av[pars->indxarg]);
            pars->arg1 = ft_strjoin (pars->arg1, ptr1/*finale_char (av[pars->indxarg])*/);
            if (av[pars->indxarg + 1] != NULL)
                free (ptr);
            // printf ("{%s}\n",ptr1);
            free (ptr1);
        }
        // printf ("{%s}\n",pars->arg1);
        parssing (pars);
        /*+++excution+++*/
        first_trys (pars, &pars->head);
        if (pars->sizeof_stack > 5)
            scond_trys (pars, &pars->head, pars->stack_b);
        // print_nodes (&pars->head);
        // printf ("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n");
        // print_nodes (pars->stack_b);
        // printf ("\n\n\n\n\n\n\n\n\n");
        // print_num (&pars->head);
        // free (pars);
        free(pars->arg1);
    }
    exit(0);
        // free (ptr);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:42:06 by momihamm          #+#    #+#             */
/*   Updated: 2023/09/07 18:51:58 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    mr (void)
{
    system ("leaks push_swap");
}

void    excution (t_parss *excution)
{
    make_the_length_one (excution);
    lis (excution);
    print_lis (excution->stack_a);
    int big = find_the_big_length (excution->stack_a);
    printf ("\nthe big %d\n",big);
    // print_the_lis (excution->stack_a, big);
}

int main (int ac, char **av)
{
    // atexit (mr);
    if (ac >= 2)
    {
        t_parss *pars;

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
    exit(0);
}
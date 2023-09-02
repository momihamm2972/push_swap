/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:42:06 by momihamm          #+#    #+#             */
/*   Updated: 2023/09/01 07:41:49 by momihamm         ###   ########.fr       */
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
        pars->indxarg = 0;
        while (av[++pars->indxarg])
        {
            if (only_sing (av[pars->indxarg]) == -91)
                exit (error_msg ());
            ptr = pars->arg1;
            ptr1 = finale_char (av[pars->indxarg]);
            pars->arg1 = ft_strjoin (pars->arg1, ptr1);
            if (av[pars->indxarg + 1] != NULL)
                free (ptr);
            free (ptr1);
        }
        printf ("{%s}",pars->arg1);
        make_args_usefull (pars);
        free(pars->arg1);
    }
    exit(0);
}
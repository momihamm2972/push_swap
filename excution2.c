/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excution2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:57:31 by momihamm          #+#    #+#             */
/*   Updated: 2023/09/12 18:39:39 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_if_lis_in_a (t_node **stack)
{
    t_node *ptr;

    ptr = (*stack);
    while (ptr)
    {
        if (ptr->are_in == 1)
            return (1);
        ptr = ptr->next;
    }
    return (0);
}

void    make_the_lis_in_a (t_parss *fcbayern)
{
    (void) fcbayern;
    print_nodes (fcbayern->stack_a);
    t_node *ptr = (*fcbayern->stack_a);
    fcbayern->stack_b = malloc (sizeof (t_node *));
    (*fcbayern->stack_b) = ft_lstnew (91);
    (void)ptr;
    // while (1)
    // {
    //     if (ptr->are_in == 0)
    //     {
    //         // push_to_stack (fcbayern->stack_a,fcbayern->stack_b,0);
    //         printf ("push\n");
    //     }
    //     else
    //         rotate (fcbayern->stack_a,0);
    //     // printf ("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n");
    //     // print_nodes (fcbayern->stack_a);
    //     // printf ("BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB\n");
    //     // print_nodes (fcbayern->stack_b);
    // }
    printf ("kmi\n");
    push_to_stack (fcbayern->stack_a,fcbayern->stack_b,0);
}
mazal 3endi mochkil fach katkone stackBB khawya == SEV ;
khasni nkhedem 3ela nkheli lis f stackAA;
chi SEV bano 3end mo3ad;
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excution2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:57:31 by momihamm          #+#    #+#             */
/*   Updated: 2023/09/17 02:38:10 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    make_a_in_oredre (t_node **stack)
{
    while (1)
    {
        if ((*stack)->length == 1)
            return;
        else
            rotate (stack, 0);
    }
}

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
    // print_nodes (fcbayern->stack_a);
    t_node **ptr = fcbayern->stack_a;
    fcbayern->stack_b = malloc (sizeof (t_node *));
    (*fcbayern->stack_b) = NULL;
    // (void)ptr;
    while (1)
    {
        if (check_if_lis_in_a (fcbayern->stack_a) == 0)
            break;
        if ((*ptr)->are_in == 1)
            push_to_stack (fcbayern->stack_a, fcbayern->stack_b, 0);
        if ((*ptr)->are_in == 0)
            rotate (fcbayern->stack_a, 0);
    }
    make_a_in_oredre (fcbayern->stack_a);
    print_nodes (fcbayern->stack_a);
    printf ("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
    print_nodes(fcbayern->stack_b)                    ;
}
// chi SEV bano 3end mo3ad;
// tap;
// 0 4 12 "      2      10       " "6"    9 13 3 11        "7      15"
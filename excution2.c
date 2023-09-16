/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excution2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:57:31 by momihamm          #+#    #+#             */
/*   Updated: 2023/09/16 18:35:52 by momihamm         ###   ########.fr       */
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
        if (ptr->are_in == 0)
        {
            // printf ("ba9i\n");
            return (0);
        }
        ptr = ptr->next;
    }
    return (1);
}

void    make_the_lis_in_a (t_parss *fcbayern)
{
    (void) fcbayern;
    // print_nodes (fcbayern->stack_a);
    t_node **ptr = fcbayern->stack_a;
    fcbayern->stack_b = malloc (sizeof (t_node *));
    (*fcbayern->stack_b) = NULL;
    // (void)ptr;
    int i =0;
    while (i>=0)
    {
        // printf ("iwa\n");
        // printf ("data %d\t",(*ptr)->data);
		// printf ("lent %d\t",(*ptr)->length);
		// printf ("arei %d\t",(*ptr)->are_in);
		// printf ("next %p\n",(*ptr)->next);
        if (check_if_lis_in_a (fcbayern->stack_a) == 1)
        {
            // printf ("gheyreha*****************************%d\n",i);
            break;
        }
        if ((*ptr)->are_in == 1)
        {
            push_to_stack (fcbayern->stack_a, fcbayern->stack_b, 0);
            // printf ("push\n");
        }
        if ((*ptr)->are_in == 0)
        {
            rotate (fcbayern->stack_a, 0);
            // printf ("rotate\n");
        }
        i++;
        if (i > 40)
            break; 
    }
    make_a_in_oredre (fcbayern->stack_a);
    // rotate (fcbayern->stack_a, 0);
    // push_to_stack (fcbayern->stack_a, fcbayern->stack_b, 0);
    // push_to_stack (fcbayern->stack_a, fcbayern->stack_b, 0);
    // rotate (fcbayern->stack_a, 0);
    // push_to_stack (fcbayern->stack_a, fcbayern->stack_b, 0);
    // rotate (fcbayern->stack_a, 0);
    // rotate (fcbayern->stack_a, 0);
    // push_to_stack (fcbayern->stack_a, fcbayern->stack_b, 0);
    // push_to_stack (fcbayern->stack_a, fcbayern->stack_b, 0);
    // rotate (fcbayern->stack_a, 0);
    // push_to_stack (fcbayern->stack_a, fcbayern->stack_b, 0);
    // rotate (fcbayern->stack_a, 0);
    print_nodes (fcbayern->stack_a);
    printf ("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
    print_nodes(fcbayern->stack_b);
}
// mazal 3endi mochkil fach katkone stackBB khawya == SEV ;
// khasni nkhedem 3ela nkheli lis f stackAA;
// chi SEV bano 3end mo3ad;
// tap;
// 0 4 12 "      2      10       " "6"    9 13 3 11        "7      15"
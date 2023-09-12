/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excution2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:57:31 by momihamm          #+#    #+#             */
/*   Updated: 2023/09/12 16:43:25 by momihamm         ###   ########.fr       */
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
    t_node *ptr;
    int i=0;
    ptr = (*fcbayern->stack_a);
    fcbayern->stack_b = malloc (sizeof (t_node *));
    while (1)
    {
        if (check_if_lis_in_a (fcbayern->stack_a) == 0)
            break;
        // printf ("in %d are%d    %d\n",ptr->are_in,i,ptr->next->are_in);
        if (ptr->are_in == 1)
        {
            push_to_stack (fcbayern->stack_a, fcbayern->stack_b,0);
            printf ("\n\tpush\n");
        }
        if (ptr->are_in == 0)
        {
            rotate (fcbayern->stack_a,0);
            printf ("\n\trotate\n");
        }
        // printf ("%d\n",ptr->are_in);
        // ptr = ptr->next;
        i++;
        if (i == 13)
            break;
    }
    printf ("i=%d\n",i);
    // printf ("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n");
    print_nodes (fcbayern->stack_a);
    // printf ("BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB\n");
    // print_nodes (fcbayern->stack_b);
    
}

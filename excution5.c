/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excution5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:57:41 by momihamm          #+#    #+#             */
/*   Updated: 2023/07/16 11:04:34 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    scond_trys (t_parss *my_stc, t_node **stack_a, t_node **stack_b)
{
    int max;

    max = my_stc->sizeof_stack;
    while (1)
    {
        if ((*stack_b)->position == max)
        {
            push_to_stack (stack_b, stack_a, 0);
            max--;
        }
        else
            rotate (stack_b, 1);
        if (max == 0)
            break;
    }
}

void print_num (t_node **stack)
{
    t_node *ptr;

    ptr = (*stack);
    // printf ("%d ",ptr->data);
    while (ptr)
    {
        printf ("%d ",ptr->data);
        ptr = ptr->next;
    }
}
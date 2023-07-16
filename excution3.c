/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excution3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:57:34 by momihamm          #+#    #+#             */
/*   Updated: 2023/07/16 06:02:13 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    make_the_small_in_top_of_five(t_parss *my_sc, t_node **stack, int small)
{
    int indx;
    
    while (1)
    {
        indx = find_the_index_of_the_node (stack, my_sc, small);
        if (indx == 5)
            return ;
        else if (indx == 1)
        {
            rev_rotate (stack, 0);
            return ;
        }
        else if (indx == 4)
        {
            swap_2_elements (stack, 0);
            return ;
        }
        else
            rev_rotate (stack, 0);
    }
}

void    stack_for (t_node **stack, t_parss *my_sc)
{
    t_node **stack_1;

    stack_1 = malloc (sizeof (t_node));
    ft_orederfor_stack_for (my_sc, stack);
    // my_sc->sizeof_stack = 5;
    push_to_stack (stack, stack_1, 1);
    ft_tree_posi_exat (stack);
    ft_tree (stack);
    push_to_stack (stack_1, stack, 0);
}

void    stack_five (t_node **stack, t_parss *my_sc, int small, int scnd)
{
    t_node  **stack_1;
    // (void)scnd;
    stack_1 = malloc (sizeof (t_node));
    make_the_small_in_top_of_five (my_sc, stack, small);
    push_to_stack (stack, stack_1, 1);
    make_the_scnd_in_top (my_sc, stack, scnd);
    push_to_stack (stack, stack_1, 1);
    ft_tree_posi_exat (stack);
    ft_tree_posi_exat (stack);
    ft_tree (stack);
    push_to_stack (stack_1, stack, 0);
    push_to_stack (stack_1, stack, 0);
}

int    check_if_stil_node_of_chanck (t_node **stack, int range)
{
    t_node *ptr;

    ptr = (*stack);
    while (ptr)
    {
        if (ptr->position <= range)
            return (1);
        ptr = ptr->next;
    }
    return (0);
}

void    stack_one_h (t_node **stack, t_parss *my_stc)
{
    t_node **stack_b;
    int     devision;
    int     mid;
    int     push;

    stack_b = malloc (sizeof (t_node));
    devision = my_stc->sizeof_stack / 5;
    mid = 0;
    push = 0;
    while (1)
    {
        if (check_if_stil_node_of_chanck (stack, devision) == 0 && devision <= my_stc->sizeof_stack)
        {
            mid = 10;
            devision += my_stc->sizeof_stack / 5;
        }
        if ((*stack)->position <= devision)
        {
            push_to_stack (stack, stack_b, 1);
            push++;
            if ((*stack_b)->position <= ((devision / 2) + mid))
                rotate (stack_b, 1);
            if (push == my_stc->sizeof_stack)
                break;
        }
        else
            rotate (stack, 0);
    }
    print_nodes (stack_b);
}

void    first_trys (t_parss *my_sc, t_node **stack)
{
    t_node *small;
    t_node *scnd;
    
    small = find_the_small_position (stack);
    scnd = find_the_scnd_small_position (stack);
    my_sc->sizeof_stack = ft_lstsize ((*stack));
    if (my_sc->sizeof_stack == 2)
        swap_2_elements (stack, 0);
    else if (my_sc->sizeof_stack == 3)
        ft_tree (stack);
    else if (my_sc->sizeof_stack == 4)
        stack_for (stack, my_sc);
    else if (my_sc->sizeof_stack == 5)
        stack_five (stack, my_sc, small->data, scnd->data);   
    else if (my_sc->sizeof_stack > 5 && my_sc->sizeof_stack <= 100)
        stack_one_h (stack, my_sc);
}
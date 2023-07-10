/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:42:06 by momihamm          #+#    #+#             */
/*   Updated: 2023/07/10 19:27:40 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    make_the_small_in_top_of_five (t_parss *my_sc, t_node **stack, int small)
{
    int indx;
       while (1)
        {
            indx = find_the_index_of_the_node (stack, my_sc, small);
            if (indx == 5)
                return ;
            else if (indx == 1)
            {
                rev_rotate (stack);
                return ;
            }
            else if (indx == 4)
            {
                swap_2_elements (stack);
                return ;
            }
            else
                rev_rotate (stack);
        }
}

// void    make_the_scnd_in_top (t_parss *my_sc, t_node **stack, int small)
// {
//     int indx;
//        while (1)
//         {
//             indx = find_the_index_of_the_node (stack, my_sc, small);
//             if (indx == 4)
//                 return ;
//             else if (indx == 1)
//             {
//                 rev_rotate (stack);
//                 return ;
//             }
//             else if (indx == 3)
//             {
//                 swap_2_elements (stack);
//                 return ;
//             }
//             else
//                 rev_rotate (stack);
//         }
// }


void    stack_for (t_node **stack, t_parss *my_sc)
{
    t_node **stack_1;

    stack_1 = malloc (sizeof (t_node));
    ft_orederfor_stack_for (my_sc, stack);
    // my_sc->sizeof_stack = 5;
        push_to_stack (stack, stack_1);
        ft_tree_posi_exat (stack);
        ft_tree (stack);
        push_to_stack (stack_1, stack);
        // print_nodes (stack);
}

void    stack_five (t_node **stack, t_parss *my_sc, int small, int scnd)
{
    t_node  **stack_1;
    // (void) scnd;
    (void) small;
// printf ("%p%p%d\n\n",stack,my_sc,small);
    stack_1 = malloc (sizeof (t_node));
    make_the_scnd_in_top (my_sc, stack, scnd);
    push_to_stack (stack, stack_1);
    make_the_small_in_top_of_five (my_sc, stack, small);
     push_to_stack (stack, stack_1);
    // make_the_scnd_in_top (my_sc, stack,scnd);
    print_nodes (stack_1);
    printf ("|||||||||||||\n");
    ft_tree_posi_exat (stack);
    // ft_tree_posi_exat (stack);
    // printf ("\n||||||||%d||||||||||||%d||||||||\n",(*stack_1)->data,(*stack_1)->position);
    ft_tree_posi_exat (stack);
    ft_tree (stack);
    // swap_2_elements (stack_1);
    
    // stack_for (stack, my_sc);
    push_to_stack (stack_1, stack);
    printf("\n\n");
    print_nodes (stack_1);
    printf ("\n\n");
    push_to_stack (stack_1, stack);
    swap_2_elements (stack);
    // printf ("\n|||||||^^|%d|||^^|||||||||%d||^^||||||\n",(*stack_1)->data,(*stack_1)->position);
}

void    first_trys (t_parss *my_sc, t_node **stack)
{
    t_node *small = find_the_small_position (stack);
    t_node *scnd = find_the_scnd_small_position (stack);
    // t_node *ptr = (*stack);
    // int indx = find_the_index_of_the_node (stack, my_sc, small->data);
    
    my_sc->sizeof_stack = ft_lstsize ((*stack));
    if (my_sc->sizeof_stack == 1)
        printf ("%d",(*stack)->data);
    else if (my_sc->sizeof_stack == 2)
        swap_2_elements (stack);
    else if (my_sc->sizeof_stack == 3)
        ft_tree (stack);
    else if (my_sc->sizeof_stack == 4)
        stack_for (stack, my_sc);
    else if (my_sc->sizeof_stack == 5)
    {
        printf ("the small one is %d\n",small->data);
        // make_the_small_in_top_of_five (my_sc, stack, small->data);
        stack_five (stack, my_sc, small->data, scnd->data);   
    }
}

int main (int ac, char **av)
{
    if (ac >= 2)
    {
        t_parss *pars;

        pars = malloc (sizeof (t_parss));
        pars->arg1 = malloc (1);
        pars->indxarg = 0;
        while (av[++pars->indxarg])
            pars->arg1 = ft_strjoin (pars->arg1, finale_char (av[pars->indxarg]));
        parssing (pars);
    }
}
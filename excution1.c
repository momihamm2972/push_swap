/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excution1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:57:27 by momihamm          #+#    #+#             */
/*   Updated: 2023/09/16 17:48:02 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    print_the_lis (t_node **stack, int length)
{
    t_node **head= malloc (sizeof (t_node *));
    t_node *ptr;
    int     num;
    
    ptr = ft_lstlast (stack);
    num = length;
    while (ptr)
    {
        if (ptr->length == num)
        {
            ft_lstadd_front (head, ft_lstnew (ptr->data));
            num--;
        }
        ptr = ptr->prev;
        if (ptr == NULL)
            break;
    }
    print_lis (head);
    // printf ("ana hna2\n");
    // print_nodes (head);
    // printf ("ana hna\n");
    ft_free_a_stack (head);
    // printf ("ana hna1\n");
}

void    check_the_lis_are_in (t_node **stack, int length)
{
    t_node *ptr;
    int num;

    ptr = ft_lstlast(stack);
    num = length;
    while (ptr)
    {
        if (ptr->length == num)
        {
            ptr->are_in = 0;
            num--;
        }
        ptr = ptr->prev;
    }
}

int     find_the_big_length (t_node **stacka)
{
    t_node *ptr;
    int     big;

    ptr = (*stacka);
    big = 0;
    while (ptr)
    {
        if (ptr->length > big)
            big = ptr->length;
        ptr = ptr->next;
    }
    return (big);
}

void    make_the_length_one (t_parss *length)
{
    t_node  *ptr;
    int     indx;

    ptr = (*length->stack_a);
    indx = 0;
    while (ptr)
    {
        // printf ("|||||%d||||||||||||\t",ptr->length);
        ptr->length = 1;
        ptr->are_in = 1;
        ptr->indx_of_stack = indx;
        // printf ("|||||%d||||||||||||\n",ptr->length);
        ptr = ptr->next;
        indx++;
    }
}

void print_lis (t_node **stacka)
{
    t_node *ptr;
    void* bebe = (void*)0xbebebebebebebebe;
    ptr = (*stacka);
    while (ptr)
    {
        printf ("$%d\t",ptr->data);
        ptr = ptr->next;
        if (ptr == bebe)
            ptr = NULL;
    }
    ptr = (*stacka);
    printf ("\n");
    // while (ptr)
    // {
    //     printf ("*%d*\t",ptr->length);
    //     ptr = ptr->next;
    //     if (ptr == bebe)
    //         ptr = NULL;
    // }
}

void    lis (t_parss *lewandowski)
{
    t_node *ptr_i;
    t_node *ptr_j;

    ptr_i = (*lewandowski->stack_a)->next;
    ptr_j = (*lewandowski->stack_a);
    // printf ("%dmimi%d\n",ptr_i->data,ptr_j->data);
    while (ptr_i)
    {
        if (ptr_j->data < ptr_i->data)
        {
            if (ptr_i->length <= ptr_j->length +1)
            {
                ptr_i->length = ptr_j->length + 1;
            }
        }
        ptr_j = ptr_j->next;
        if (ptr_j->indx_of_stack == ptr_i->indx_of_stack)
        {
            ptr_j = (*lewandowski->stack_a);
            ptr_i = ptr_i->next;
        }
    }
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:55:38 by momihamm          #+#    #+#             */
/*   Updated: 2023/06/13 02:01:21 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}t_node;

t_node *ft_lstnew(int content)
{
	t_node *head;

	head = malloc (sizeof (t_node));
	head->data = content;
	head->next = NULL;
	return (head);
}

void ft_lstadd_front(t_node **lst, t_node *new)
{
	t_node *head;
			
	if (!(*lst))
		(*lst) = head;
	new->next = (*lst);
	(*lst) = new;
}

int ft_lstsize(t_node *lst)
{
	int i;

	i = 0;
	while (lst->next)
	{
		i++;
		lst->next = lst->next->next;
	}
	i++;
	return (i);
}

t_node *ft_lstlast(t_node *lst)
{
  t_node *ptr;
  
  ptr = lst;
    while (ptr->next)
    {
        if (ptr->next->next == NULL)
            return (ptr->next);
        ptr = ptr->next;
    }
}

void ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node *the_last;

	the_last = ft_lstlast((*lst));
	printf("I->%d\n",the_last->data);
	the_last->next = new;
	the_last = ft_lstlast((*lst));
	printf("II->%d\n",the_last->data);
}

void	swap_2_elements(t_node *stack)
{
	int swaper;

	if (stack == NULL || stack->next == NULL)
		return;
	swaper = stack->data;
	stack->data = stack->next->data;
	stack->next->data =	swaper;
}

void	push_to_stack(t_node *stack_0, t_node **stack_1)
{
	t_node *tmp;
	
	if (!stack_0)
	{
		printf ("kmi o tkma o 3ref ach kayen tma\n");
		return ;
	}
	ft_lstadd_front(stack_1, ft_lstnew(stack_0->data));
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	swap_2_elements(*stack_a);
	swap_2_elements(*stack_b);
}

t_node	*before_the_last(t_node **stack)
{
	while ((*stack)->next)
	{
		if ((*stack)->next->next->next == NULL)
			return ((*stack)->next);
		(*stack)->next = (*stack)->next->next;
	}
}

void    print_nodes(t_node **stack)
{
    int key_of_list;
    t_node *tmp;

    if (!stack)
        return;
    key_of_list = 0;
    tmp = (*stack);
    printf ("node=>%d==========>data==%d\n",key_of_list, tmp->data);
    while (tmp->next)
    {
        key_of_list++;
        printf ("node=>%d==========>data==%d\n",key_of_list, tmp->next->data);
        tmp = tmp->next;
    }
}

void	rotate (t_node **stack)
{
	t_node *tmp;
	t_node *last;
	
	tmp = (*stack);
	last = ft_lstlast ((*stack));
	last->next = (*stack);
	(*stack) = (*stack)->next;
	last->next->next = NULL;
}


int main(void)
{
	t_node *stack_a = ft_lstnew(83);
	// stack_a = NULL;
	// t_node *stack_b = ft_lstnew(16);
	stack_a->next = ft_lstnew(38);
	stack_a->next->next = ft_lstnew(61);
	stack_a->next->next->next = ft_lstnew (2);
	print_nodes (&stack_a);
	printf ("#####################\n");
	rotate (&stack_a);
	print_nodes(&stack_a);

}
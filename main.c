/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:55:38 by momihamm          #+#    #+#             */
/*   Updated: 2023/06/11 03:41:39 by momihamm         ###   ########.fr       */
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
	while (lst->next)
	{
		if (lst->next->next == NULL)
			return (lst->next);
		lst->next = lst->next->next;
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
	int	tmp_a;
	int tmp_b;

	tmp_a = (*stack_a)->data;
	(*stack_a)->data = (*stack_a)->next->data;
	(*stack_a)->next->data = tmp_a;
	tmp_b = (*stack_b)->data;
	(*stack_b)->data = (*stack_b)->next->data;
	(*stack_b)->next->data = tmp_b;
}

int main(void)
{
	t_node *stack_a = ft_lstnew(83);
	// stack_a = NULL;
	t_node *stack_b = ft_lstnew(16);
	stack_a->next = ft_lstnew(38);
	stack_b->next = ft_lstnew(61);
	// stack_a->next->next = ft_lstnew(54);
	// printf ("b%d\n",stac?k_b->data);
	// push_to_stack(stack_a, &stack_b);
	printf ("before A{%d %d}\tB[%d %d]\n",stack_a->data,stack_a->next->data,stack_b->data, stack_b->next->data);	
	ss (&stack_a, &stack_b);
	printf ("after A{%d %d}\tB[%d %d]\n",stack_a->data,stack_a->next->data,stack_b->data, stack_b->next->data);
}
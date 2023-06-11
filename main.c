/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:55:38 by momihamm          #+#    #+#             */
/*   Updated: 2023/06/11 01:38:00 by momihamm         ###   ########.fr       */
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
	tmp = stack_0;
	stack_0 = stack_0->next;
	free (tmp);
	printf ("wiwi\n");
	// printf("%d\n", stack_1->next->data);
	// printf ("A-->%d\tB-->%d\n",stack_0->data,stack_1->data);
}

int main(void)
{
	t_node *stack_a = ft_lstnew(83);
	// stack_a = NULL;
	t_node *stack_b = ft_lstnew(91);
	// printf ("b%d\n",stac?k_b->data);
	push_to_stack(stack_a, &stack_b);
	printf ("a%d\n",stack_a->data);
	printf ("b%d\n",stack_b->data);
	// stack->next = ft_lstnew(04);
	// printf ("%d\n",stack->data);
	// stack->next = ft_lstnew(910);
	// stack->next = a;
	// ft_lstadd_front(&stack,a);
	// printf("%d\n", a->next->data);
	// stack->next->next = ft_lstnew(47);
	// stack->next->next->next = ft_lstnew(2001);
	// printf ("be : %d %d\n",stack->data,stack->next->data);
	// swap_2_elements (stack);
	// printf ("af : %d %d\n",stack->data,stack->next->data);
	// a->next = ljadid;
	// printf("%d==>%d\n", ft_lstsize(ljadid),ljadid->data);
	// t_node *the_last = ft_lstlast(stack);
	// printf ("%d\n",the_last->data);
	// printf ("I--->%d\nII--->%d\nIII--->%d\n",stack->data,stack->next->data,stack->next->next->data);
	// while (stack->next)
	// {
	// 	if (stack->next->next == NULL)
	// 	{
	// 		printf ("%d\n",stack->next->data);
	// 		break;
	// 	}
	// 	stack->next = stack->next->next;
	// }
	// printf ("%p\n",stack->next);
	// t_node *new = ft_lstnew(10);
	// ft_lstadd_back(&stack, new);
}
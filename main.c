/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:55:38 by momihamm          #+#    #+#             */
/*   Updated: 2023/06/16 12:59:14 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct node
{
	int data;
	int position;
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

int	error_msg(void)
{
	write (2, "Error 404!!\n", 12);
	return (0);
}

void ft_lstadd_front(t_node **lst, t_node *new)
{
	// t_node *head;
			
	// if (!(*lst))
	// 	(*lst) = head;
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

	if (!lst)
		return (NULL);
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


void	ss(t_node **stack_a, t_node **stack_b)
{
	swap_2_elements(*stack_a);
	swap_2_elements(*stack_b);
}

t_node	*before_the_last(t_node **stack)
{
		t_node *ptr;

	if (!(*stack))
		return (NULL);
	ptr = (*stack);
    while (ptr->next)
    {
        if (ptr->next->next->next == NULL)
            return (ptr->next);
        ptr = ptr->next;
    }
}

void    print_nodes(t_node **stack)
{
    int key_of_list;
    t_node *tmp;

    if (!(*stack))
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
	
	if (!(*stack))
		return ;
	tmp = (*stack);
	last = ft_lstlast ((*stack));
	last->next = (*stack);
	(*stack) = (*stack)->next;
	last->next->next = NULL;
}

void	rr (t_node **stack_a, t_node **stack_b)
{
	rotate (stack_a);
	rotate (stack_b);
}


void rev_rotate (t_node **stack)
{
	t_node *the_last;
	t_node *new_last;
	
	if (!(*stack))
		return ;
	the_last = ft_lstlast ((*stack));
	new_last = before_the_last(stack);
	the_last->next = (*stack);
	(*stack) = new_last->next;
	new_last->next = NULL;
}

void	rrr (t_node **stack_a, t_node **stack_b)
{
	rev_rotate (stack_a);
	rev_rotate (stack_b);
}
int ft_double(t_node **stack, int data)
{
    t_node *ptr;
    int cont;

    ptr = (*stack);
    cont = 0;
    while (ptr)
    {
        if (ptr->data == data)
            cont++;
        if (cont > 1)
            exit (error_msg ());
        ptr = ptr->next;
    }
    return (0);
}

int sorted (t_node **stack)
{
	t_node *ptr;
	int checker;

	if (!(*stack))
		return (0);
	ptr = (*stack);
	checker = ptr->data;
	ptr = ptr->next;
	while (ptr)
	{
		printf ("ch==%d\tdata==%d\n",checker, ptr->data);
		if (checker < ptr->data)
		{
			checker = ptr->data;
			ptr = ptr->next;
		}
		else
		{
			printf ("hwawa mas tyiit\n");
			return (0);
		}
		if (ptr == NULL)
			exit (error_msg ());
	}
	return (0);
}

void	push_to_stack(t_node **stack_0, t_node **stack_1)
{
	t_node *tmp;
	t_node *fri;
	
	if (!(*stack_0))
		return ;
	ft_lstadd_front(stack_1, ft_lstnew((*stack_0)->data));
	fri = (*stack_0);
	(*stack_0) = (*stack_0)->next;
	free (fri);
}

int finally_sorted (t_node **stack)
{
	t_node	*tmp;
	int		indx;
	
	if (!(*stack))
		return (1);
	tmp = (*stack);
	if (tmp->position == 0)
		indx = 1;
	else
		return (1);
	while (tmp)
	{
		tmp = tmp->next;
		if ((tmp != NULL) && (tmp->position != indx))
			return (1);
		indx++;	
	}
	return (0);
}

int main(void)
{
    t_node *head = ft_lstnew (3);
	head->position = 0;
	head->next = ft_lstnew (7);
	head->next->position = 1;
	head->next->next = ft_lstnew (14);
	head->next->next->position = 2;
	head->next->next->next =  ft_lstnew (84);
	head->next->next->next->position = 4;
	head->next->next->next->next = ft_lstnew (95);
	head->next->next->next->next->position = 3;
	// t_node *stack;
	// push_to_stack (&head, &stack);
	printf ("\n\t%d\n\n", finally_sorted (&head));
}

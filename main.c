/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 22:25:40 by momihamm          #+#    #+#             */
/*   Updated: 2023/06/01 22:27:19 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct node
{
    int data;
    struct node *next;
}t_node;

t_node	*ft_lstnew(int content)
{
	t_node	*head;

	head = (t_node *) malloc(sizeof (t_node));
	head->data = content;
	head->next = NULL;
	return (head);
}

t_node	*ft_lstlast(t_node *head)
{
	if (!head)
		return (0);
	while (head->next)
		head = head->next;
	return (head);
}

int	ft_lstsize(t_node *head)
{
	int	size;

	size = 0;
	if (!head)
		return (0);
	while (head)
	{
		head = head->next;
		size++;
	}
	return (size);
}
void ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node *last;

	last = ft_lstlast(*lst);
	last->next = new;
}

void ft_lstadd_front(t_node **lst, t_node *new)
{
	t_node *head;
	
	head = ft_lstnew(new->data);
	if (!(*lst))
		(*lst) = head;
	head->next = (*lst);
	(*lst) = head;
}

int main(void)
{
    t_node *head = malloc (sizeof(t_node));
	head = NULL;
    // head->data = 20;
    // head->next = NULL;
    // printf ("%d",head->data);
    // head->next = ft_lstnew(50);
    // printf ("\n%d",head->next->data);
	// head->next->next = ft_lstnew(80);
	// printf ("\n%d",head->next->next->data);
	// head->next->next->next = ft_lstnew(100);
	// printf ("\n%d",head->next->next->next->data);
	// head->next->next->next->next = ft_lstnew(676);
	// printf ("\nlast is => %d",last->data);
	// printf ("\nlast is => %d",ft_lstsize(head));
	ft_lstadd_back (&head, ft_lstnew(21));
	t_node *last = ft_lstlast(head);
	// last = ft_lstlast(head);
	printf ("\nlast is => %d",last->data);
	// ft_lstadd_front (&head, ft_lstnew(404));
	// printf ("\nthe fornt one is %d",head->data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:08:48 by momihamm          #+#    #+#             */
/*   Updated: 2023/05/24 00:32:21 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int             data;
    struct  node    *next;
}t_node;

t_node	*ft_lstlast(t_node *head)
{
	if (!head)
		return (0);
	while (head->next)
		head = head->next;
	return (head);
}

int main(void)
{
    t_node *head = (t_node*)malloc (sizeof(t_node));
    head->data = 20;
    t_node *scond = (t_node*)malloc (sizeof(t_node));
    scond->data = 50;
    scond->next = NULL;
    printf ("%p\n%p",scond,ft_lstlast(head));
}
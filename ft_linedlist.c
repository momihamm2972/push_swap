/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linedlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 04:34:44 by momihamm          #+#    #+#             */
/*   Updated: 2023/09/05 14:21:45 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	// t_node *head;
			
	// if (!(*lst))
	// 	(*lst) = head;
	new->next = (*lst);
	(*lst) = new;
}

int ft_lstsize(t_node *lst)
{
	t_node	*ptr;
	int		i;

	ptr = lst;
	i = 0;
	while (ptr)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
}

t_node *ft_lstlast(t_node *lst)
{
	t_node *ptr;

	if (!lst)
		return (NULL);
	if (lst->next == NULL)
		return (lst);
	ptr = lst;
    while (ptr->next)
    {
        if (ptr->next->next == NULL)
            return (ptr->next);
        ptr = ptr->next;
    }
	return (NULL);
}

void ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node *the_last;

	the_last = ft_lstlast((*lst));
	the_last->next = new;
}

void	ft_free_a_stack (t_node **stack)
{
	t_node *ptr0;
	t_node *ptr1;

	ptr0 = (*stack);
	while (ptr0)
	{
		ptr1 = ptr0->next;
		free (ptr0);
		ptr0 = ptr1;
	}
	free (stack);
}

// int main(void)
// {
// 	t_node **head = malloc (sizeof (t_node *));
// 	(*head) = ft_lstnew (91);
// 	(*head)->next = ft_lstnew(20);
// 	(*head)->next->next = ft_lstnew (30);
// 	// ft_lstadd_back(&head, ft_lstnew(100));
// 	// head->next->next->next->next->next = ft_lst
// 	// printf ("nadi \n");>?
// 	// t_node *last = ft_lstlast (head);
// 	// printf ("candi\n")?;
// 	printf ("%d\t%d\t%d",(*head)->data, (*head)->next->data, (*head)->next->next->data);
// 	free ((*head)->next->next);
// 	free ((*head)->next);
// 	free ((*head));
// 	free (head);
// 	// ft_free_a_stack (head);
	
// }
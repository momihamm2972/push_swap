/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 03:46:44 by momihamm          #+#    #+#             */
/*   Updated: 2023/06/01 22:09:03 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_to_stack(t_node **head_0, t_node **head_1)
{
	t_node *new;

	head_1 = head_0;
	head_1->next = NULL;
	*head_0 = head_0->next;
	
}
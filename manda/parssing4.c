/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:58:02 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/01 08:12:53 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sipared_arg(char *str)
{
	if (str[0] == '+' || str[0] == '-')
		return (1);
	return (0);
}

char	*arg_v_r(char *str)
{
	if (istheargincowt (str) == 1 || istheargincowt (str) == 0)
	{
		if ((sipared_arg (str) == 1 && ft_strlen (str) >= 1)
			|| (sipared_arg (str) == 0 && ft_strlen (str) >= 1))
		{
			if (empty_arg(str) == 1)
			{
				if (ft_isdigit (str) == 0)
				{
					if (sing_of_arg (str) == 0)
						str = make_the_str_can_splited (str);
					else
						exit (error_msg ());
				}
				else
					exit (error_msg ());
			}
			else
				exit (error_msg ());
		}
		else
			exit (error_msg ());
	}
	return (str);
}

char	*finale_char(char *str)
{
	char	*final;
	char	*ptr;

	final = ft_strdup("");
	ptr = final;
	str = arg_v_r (str);
	final = ft_strjoin(final, str);
	free(str);
	free (ptr);
	ptr = final;
	final = ft_strjoin(final, "$$");
	free (ptr);
	return (final);
}

int	sorted(t_node **stack)
{
	t_node	*ptr;
	int		checker;

	if (!(*stack))
		return (0);
	ptr = (*stack);
	checker = ptr->data;
	ptr = ptr->next;
	while (ptr)
	{
		if (checker < ptr->data)
		{
			checker = ptr->data;
			ptr = ptr->next;
		}
		else
			return (0);
		if (ptr == NULL)
			exit (error_msg ());
	}
	return (0);
}

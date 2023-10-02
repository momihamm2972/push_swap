/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:57:59 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/02 07:14:31 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	istheargincowt(char *str)
{
	int	indx;

	indx = 0;
	while (str[indx])
	{
		if (str[indx] == 32)
			return (1);
		indx++;
	}
	return (0);
}

int	sing_of_arg(char *str)
{
	int	indx;

	indx = 1;
	while (str[indx])
	{
		if (str[indx] == '-' || str[indx] == '+')
		{
			if (str[indx + 1] == 32 || str[indx - 1] != 32)
				return (1);
		}
		indx++;
	}
	return (0);
}

int	ft_isdigit(char *str)
{
	int	indx;

	indx = 0;
	while (str[indx])
	{
		if ((str[indx] >= 48 && str[indx] <= '9') || str[indx] == 32
			|| str[indx] == '+' || str[indx] == '-')
			indx++;
		else
			return (1);
	}
	return (0);
}

char	*make_the_str_can_splited(char *str)
{
	int		indx;
	char	*dup;

	indx = 0;
	dup = ft_strdup (str);
	while (dup[indx])
	{
		if (dup[indx] == 32)
			dup[indx] = '$';
		indx++;
	}
	return (dup);
}

int	empty_arg(char *str)
{
	int	indx;

	indx = 0;
	while (str[indx])
	{
		if (str[indx] != 32)
			return (1);
		indx++;
	}
	return (0);
}

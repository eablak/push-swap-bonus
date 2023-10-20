/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:43:41 by eablak            #+#    #+#             */
/*   Updated: 2023/10/20 17:48:24 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_sorted(t_struct *strc)
{
	t_struct	*tmp;

	tmp = strc;
	while (tmp && tmp->next != NULL)
	{
		if (tmp->next->data < tmp->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	get_size_struct(t_struct **strc)
{
	int			i;
	t_struct	*keep;

	i = 0;
	keep = *strc;
	while ((*strc) != NULL)
	{
		(*strc) = (*strc)->next;
		i++;
	}
	*strc = keep;
	return (i);
}

t_struct	*get_last(t_struct *stack_a)
{
	while (stack_a && stack_a->next != NULL)
	{
		stack_a = stack_a->next;
		
	}
	return (stack_a);
}

t_struct	*get_last_before(t_struct *stack)
{
	while (stack && stack->next != NULL && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

void	array_control(char *all_array)
{
	if (all_array == NULL)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

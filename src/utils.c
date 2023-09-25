/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:43:41 by eablak            #+#    #+#             */
/*   Updated: 2023/09/23 16:12:03 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
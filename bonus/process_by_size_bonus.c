/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_by_size_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:18:01 by eablak            #+#    #+#             */
/*   Updated: 2023/10/19 14:43:04 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	find_max(t_struct *stack)
{
	int	max;

	max = stack->index;
	if (stack->next->index > max)
		max = stack->next->index;
	if (stack->next->next->index > max)
		max = stack->next->next->index;
	return (max);
}

void	little_sort(t_struct **stack_a)
{
	int	max;

	max = find_max((*stack_a));
	if ((*stack_a)->index == max)
		ra(stack_a);
	else if ((*stack_a)->next->index == max)
		rra(stack_a);
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a);
}

void	process_by_size(int size, t_struct **struct_a)
{
	if (size == 2)
		ra(struct_a);
	else if (size == 3)
		little_sort(struct_a);
	else
		big_sort(struct_a, size);
	free_struct(struct_a, size);
}
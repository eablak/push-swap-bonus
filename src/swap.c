/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:09:18 by eablak            #+#    #+#             */
/*   Updated: 2023/10/19 12:07:51 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_struct **stack)
{
	int	current_data;
	int	_index;

	current_data = (*stack)->data;
	_index = (*stack)->index;
	(*stack)->data = (*stack)->next->data;
	(*stack)->index = (*stack)->next->index;
	(*stack)->next->data = current_data;
	(*stack)->next->index = _index;
}

void	sa(t_struct **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_struct **stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_struct **stack_a, t_struct **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}

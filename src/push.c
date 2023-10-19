/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:28:31 by eablak            #+#    #+#             */
/*   Updated: 2023/10/19 14:44:09 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	_send(t_struct **stack1, t_struct **stack2)
{
	t_struct	*tmp;

	tmp = (*stack1)->next;
	(*stack1)->next = (*stack2);
	*stack2 = *stack1;
	*stack1 = tmp;
}

void	pa(t_struct **stack_a, t_struct **stack_b)
{
	_send(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	pb(t_struct **stack_a, t_struct **stack_b)
{
	_send(stack_a, stack_b);
	write(1, "pb\n", 3);
}

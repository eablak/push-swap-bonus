/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:15:47 by eablak            #+#    #+#             */
/*   Updated: 2023/10/19 12:07:47 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rreverse(t_struct **stack)
{
	t_struct	*tmp;
	t_struct	*tail;
	t_struct	*b_tail;

	tail = get_last(*stack);
	b_tail = get_last_before(*stack);
	tmp = (*stack);
	*stack = tail;
	(*stack)->next = tmp;
	b_tail->next = NULL;
}

void	rra(t_struct **stack_a)
{
	rreverse(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_struct **stack_b)
{
	rreverse(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_struct **stack_a, t_struct **stack_b)
{
	rreverse(stack_a);
	rreverse(stack_b);
	write(1, "rrr\n", 4);
}

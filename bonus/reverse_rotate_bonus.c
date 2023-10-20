/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:15:47 by eablak            #+#    #+#             */
/*   Updated: 2023/10/20 17:19:34 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rreverse(t_struct **stack)
{
	t_struct	*tmp;
	t_struct	*tail;
	t_struct	*b_tail;

	if (stack == NULL)
		return ;
	tail = get_last(*stack);
	b_tail = get_last_before(*stack);
	tmp = (*stack);
	*stack = tail;
	(*stack)->next = tmp;
	b_tail->next = NULL;
}

int	rra(t_struct **stack_a)
{
	rreverse(stack_a);
	write(1, "rra\n", 4);
	return (1);
}

int	rrb(t_struct **stack_b)
{
	rreverse(stack_b);
	write(1, "rrb\n", 4);
	return (1);
}

int	rrr(t_struct **stack_a, t_struct **stack_b)
{
	rreverse(stack_a);
	rreverse(stack_b);
	write(1, "rrr\n", 4);
	return (1);
}

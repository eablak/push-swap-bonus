/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:10:54 by eablak            #+#    #+#             */
/*   Updated: 2023/10/19 12:05:08 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"


void	reverse(t_struct **stack)
{
	t_struct	*head;
	t_struct	*root;

	head = (*stack);
	(*stack) = (*stack)->next;
	root = get_last(*stack);
	head->next = NULL;
	root->next = head;
}

void	ra(t_struct **stack_a)
{
	reverse(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_struct **stack_b)
{
	reverse(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_struct **stack_a, t_struct **stack_b)
{
	reverse(stack_b);
	reverse(stack_a);
	write(1, "rr\n", 3);
}

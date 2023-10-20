/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_processes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:35:30 by eablak            #+#    #+#             */
/*   Updated: 2023/10/20 11:55:28 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	position(t_struct **stack)
{
	t_struct	*tmp;
	int			i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

void	get_target_pos_utils(t_struct **tmp_a, int *target, int *target_indx)
{
	while ((*tmp_a))
	{
		if ((*tmp_a)->index < *target_indx)
		{
			*target_indx = (*tmp_a)->index;
			*target = (*tmp_a)->pos;
		}
		(*tmp_a) = (*tmp_a)->next;
	}
}

int	get_target_pos(t_struct **stack_a, int b_indx, int target_indx)
{
	t_struct	*tmp_a;
	int			target;

	tmp_a = *stack_a;
	target = 0;
	while (tmp_a)
	{
		if (tmp_a->index > b_indx && tmp_a->index < target_indx)
		{
			target_indx = tmp_a->index;
			target = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	if (target_indx != 2147483647)
		return (target);
	tmp_a = *stack_a;
	get_target_pos_utils(&tmp_a, &target, &target_indx);
	return (target);
}

void	position_processes(t_struct **struct_a, t_struct **struct_b)
{
	t_struct	*tmp;

	tmp = *struct_b;
	position(struct_a);
	position(struct_b);
	while (tmp)
	{
		tmp->target_pos = get_target_pos(struct_a, tmp->index, 2147483647);
		tmp = tmp->next;
	}
}

void	get_const(t_struct **stack_a, t_struct **stack_b)
{
	t_struct	*tmp_b;
	int			size_a;
	int			size_b;

	tmp_b = *stack_b;
	size_a = get_size_struct(stack_a);
	size_b = get_size_struct(stack_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->pos;
		if (tmp_b->pos > size_b / 2)
			tmp_b->cost_b = (size_b - tmp_b->pos) * -1;
		tmp_b->cost_a = tmp_b->target_pos;
		if (tmp_b->cost_a > size_a / 2)
			tmp_b->cost_a = (size_a - tmp_b->target_pos) * -1;
		tmp_b = tmp_b->next;
	}
}

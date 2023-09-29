/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:49:20 by eablak            #+#    #+#             */
/*   Updated: 2023/09/27 12:28:54 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_struct *create_struct(int i)
{
	t_struct *new_struct;

	new_struct = malloc(sizeof(t_struct));
	if (!new_struct)
		return (0);
	new_struct->data = i;
	new_struct->index = 0;
	new_struct->current_pos = 0;
	new_struct->target_pos = 0;
	new_struct->_const = 0;
	new_struct->reverse_A = 0;
	new_struct->reverse_B = 0;
	new_struct->pos = 0;
	new_struct->next = NULL;
	return (new_struct);
}

void struct_addback(t_struct **strct, t_struct *new)
{
	if (*strct == NULL || new == NULL)
	{
		*strct = new;
		return;
	}
	while ((*strct)->next != NULL)
	{
		(*strct) = (*strct)->next;
	}
	(*strct)->next = new;
}

t_struct *build_struct(int *arr, int size)
{
	t_struct *struct_a;
	t_struct *created_struct;
	t_struct *begin;
	int i;

	struct_a = malloc(sizeof(t_struct));
	if (!struct_a)
		return NULL;
	begin = struct_a;
	struct_a->data = arr[0];
	struct_a->current_pos = 0;
	struct_a->target_pos = 0;
	struct_a->_const = 0;
	struct_a->reverse_A = 0;
	struct_a->reverse_B = 0;
	struct_a->pos = 0;
	struct_a->next = NULL;
	i = 1;
	while (i < size)
	{
		created_struct = create_struct(arr[i]);
		struct_addback(&struct_a, created_struct);
		i++;
	}
	struct_a = begin;
	return (struct_a);
}

void start_processes(int *arr, int size)
{
	t_struct *struct_a;
	struct_a = build_struct(arr, size);
	if (struct_a == NULL)
		return;
	indexing(arr, size, &struct_a);
	process_by_size(size, &struct_a);
	// a yı freele
}
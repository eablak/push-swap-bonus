/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:21:08 by eablak            #+#    #+#             */
/*   Updated: 2023/09/29 15:24:24 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int sendB_first(t_struct **struct_a, t_struct **struct_b, int size)
{

	t_struct *_keepA;
	int i;
	int _pb;
	int first;

	i = 0;
	_pb = 0;
	first = 0;
	while (i < size)
	{
		if ((*struct_a)->index < (size / 2))
		{
			// printf("b ye giden değer %d\n",(*struct_a)->data);
			pb(struct_a, struct_b);
			_pb++;
		}
		else
		{
			// printf("a da kalan değer %d\n",(*struct_a)->data);
			if (first == 0)
			{
				_keepA = (*struct_a);
				first = 1;
			}
			ra(struct_a);
		}
		i++;
	}
	(*struct_a) = _keepA;
	return (_pb++);
}

void sendB_second(t_struct **struct_a, t_struct **struct_b, int size)
{

	int a_size;
	int i;
	int j;

	a_size = get_size_struct(struct_a);
	i = 0;
	j = 0;
	while (i < a_size)
	{
		if (((*struct_a)->index == size || (*struct_a)->index == size - 1 ||
			 (*struct_a)->index == size - 2) &&
			j != 3)
		{
			ra(struct_a);
			j++;
		}
		else
			pb(struct_a, struct_b);
		i++;
	}
}

void end_null(t_struct **strc, int size)
{

	int i = 0;
	t_struct *keep;

	keep = *(strc);
	while (i < size - 1)
	{
		(*strc) = (*strc)->next;
		i++;
	}
	(*strc)->next = NULL;
	*strc = keep;
}

void print_struct(t_struct **strc)
{
	t_struct *keep;

	keep = *strc;
	while (*strc)
	{
		printf("%d\n", (*strc)->data);
		(*strc) = (*strc)->next;
	}
	(*strc) = keep;
}

void clear_others(t_struct **strct_b, int data){
	t_struct *keepB;
	
	keepB = (*strct_b);
	// printf("start\n");
	while ((*strct_b))
	{
		if ((*strct_b)->data != data)
			(*strct_b)->move_for_min_const = 0;
		(*strct_b) = (*strct_b)->next;
	}
	(*strct_b) = keepB;
	// printf("end\n");
}

void _who(t_struct **strct_b)
{
	t_struct *keepB;
	int min;

	keepB = (*strct_b);
	min = 2147483647;
	while ((*strct_b))
	{
		// printf("\n%d sayısı için const %d",(*strct_b)->data, (*strct_b)->_const);
		if ((*strct_b)->_const < min){
			min = (*strct_b)->_const;
			(*strct_b)->move_for_min_const = 1;
			clear_others(&keepB, (*strct_b)->data);
			// printf("HERE %d\n",(*strct_b)->data);
		}
		(*strct_b) = (*strct_b)->next;
	}	
	(*strct_b) = keepB;
	// while((*strct_b)){
	// 	if ((*strct_b)->move_for_min_const == 1)
	// 		printf("SEND %d\n",(*strct_b)->data);
	// 	(*strct_b) = (*strct_b)->next;
	// }
	// (*strct_b) = keepB;
}

void big_sort(t_struct **struct_a, int size)
{
	t_struct *struct_b;
	int _pb;
	int i;

	struct_b = NULL;
	_pb = 0;
	i = 0;
	if (size > 6)
		_pb = sendB_first(struct_a, &struct_b, size);	
	// end_null(&struct_b, _pb);
	sendB_second(struct_a, &struct_b, size);
	if (!is_sorted(*struct_a))
		little_sort(struct_a);
	while (struct_b)
	{
		current_positions(&struct_b);
		target_positions(struct_a, &struct_b);
		calculate_const(struct_a, &struct_b);
		_who(&struct_b);
		if (struct_b->move_for_min_const == 1){
			placement(struct_a, &struct_b);
		}
		else{
			struct_b = struct_b->next;
		}
		// printf("A\n");
		// print_struct(struct_a);
		// printf("\nB\n");
		// print_struct(&struct_b);
		// getchar();
	}

	if (!is_sorted(*struct_a))
		ascending(struct_a,size);

	printf("A\n");
		print_struct(struct_a);
}

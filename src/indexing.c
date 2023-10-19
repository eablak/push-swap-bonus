/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:48:06 by eablak            #+#    #+#             */
/*   Updated: 2023/10/19 14:43:36 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*bubble_sort(int *numeros, int size)
{
	int	i;
	int	tmp;

	while (size >= 0)
	{
		i = 0;
		while (i < size - 1)
		{
			if (numeros[i] > numeros[i + 1])
			{
				tmp = numeros[i];
				numeros[i] = numeros[i + 1];
				numeros[i + 1] = tmp;
			}
			i++;
		}
		size--;
	}
	return (numeros);
}

void	indexing(int *arr, int size, t_struct **struct_a)
{
	bubble_sort(arr, size);
	t_struct *keep;

	keep = (*struct_a);
	int i;

	i = 0;
	while ((*struct_a) != NULL)
	{
		i = 0;
		while (i < size)
		{
			if ((*struct_a)->data == arr[i])
				(*struct_a)->index = i + 1;
			i++;
		}
		(*struct_a) = (*struct_a)->next;
	}
	(*struct_a) = keep;
}
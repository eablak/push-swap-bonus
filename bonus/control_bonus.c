/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:19:02 by eablak            #+#    #+#             */
/*   Updated: 2023/10/19 14:28:30 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_sorted_size(t_struct **strc, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if ((*strc)->next != NULL && (*strc)->next->data < (*strc)->data)
			return (0);
		(*strc) = (*strc)->next;
		i++;
	}
	return (1);
}

void	last_control(t_struct **strct_a, int size)
{
	if (is_sorted_size(strct_a, size))
		write(1, "OK", 2);
	else
		write(1, "KO", 2);
}
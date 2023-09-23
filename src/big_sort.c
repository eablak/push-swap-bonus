/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:21:08 by eablak            #+#    #+#             */
/*   Updated: 2023/09/23 16:31:53 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void send_b(t_struct **struct_a, t_struct **struct_b, int size){
    
    int	pushed;
	int	i;

	i = 0;
	pushed = 0;
	while (size > 6 && i < size && pushed < size / 2)
	{
		if ((*struct_a)->index <= size / 2)
		{
			pb(struct_a, struct_b);
			pushed++;
		}
		else
			ra(struct_a);
		i++;
	}
	while (size - pushed > 3)
	{
		pb(struct_a, struct_b);
		pushed++;
	}
}

void big_sort(t_struct **struct_a, int size){
    t_struct *struct_b;

    struct_b = NULL;
    send_b(struct_a,&struct_b,size);
    
}
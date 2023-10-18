/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascending.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:19:27 by eablak            #+#    #+#             */
/*   Updated: 2023/10/18 17:22:11 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    do_ascending(t_struct **strct_a, int min_pos, int size)
{
    if (min_pos <= (size / 2))
    {
        while (min_pos)
        {
            ra(strct_a);
            min_pos--;
        }
    }
    else
    {
        min_pos = size - min_pos;
        while (min_pos)
        {
            rra(strct_a);
            min_pos--;
        }
    }
}

void ascending(t_struct **strct_a, int size)
{
    int min;
    int i;
    int min_pos;
    t_struct *keep_a;

    min = 2147483647;
    min_pos = 0;
    keep_a = (*strct_a);
    i = 0;
    while (*strct_a)
    {
        if ((*strct_a)->data < min)
        {
            min_pos = i;
            min = (*strct_a)->data;
        }
        i++;
        (*strct_a) = (*strct_a)->next;
    }
    (*strct_a) = keep_a;
    do_ascending(strct_a, min_pos, size);
}
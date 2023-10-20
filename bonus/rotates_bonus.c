/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:44:48 by eablak            #+#    #+#             */
/*   Updated: 2023/10/20 12:03:55 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	_rrr(t_struct **strct_a, t_struct **strct_b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		rrr(strct_a, strct_b);
	}
}

void	_rr(t_struct **strct_a, t_struct **strct_b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rr(strct_a, strct_b);
	}
}

void	_ra(t_struct **strct_a, t_struct **strct_b, int *cost)
{
	(void)strct_b;
	while ((*cost))
	{
		if (*cost > 0)
		{
			ra(strct_a);
			(*cost)--;
		}
		else
		{
			rra(strct_a);
			(*cost)++;
		}
	}
}

void	_rb(t_struct **strct_a, t_struct **strct_b, int *cost)
{
	(void)strct_a;
	while ((*cost))
	{
		if (*cost > 0)
		{
			rb(strct_b);
			((*cost))--;
		}
		else
		{
			rrb(strct_b);
			((*cost))++;
		}
	}
}

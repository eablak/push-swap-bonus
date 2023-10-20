/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:38:21 by eablak            #+#    #+#             */
/*   Updated: 2023/10/20 12:04:59 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	placement_utils(t_struct **strct_a, t_struct **strct_b, int cost_a,
		int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		_rrr(strct_a, strct_b, &cost_a, &cost_b);
	if (cost_a > 0 && cost_b > 0)
		_rr(strct_a, strct_b, &cost_a, &cost_b);
	_ra(strct_a, strct_b, &cost_a);
	_rb(strct_a, strct_b, &cost_b);
	pa(strct_a, strct_b);
}

int	nb_abs(int nbr)
{
	if (nbr < 0)
		nbr *= -1;
	return (nbr);
}

void	placement(t_struct **strct_a, t_struct **strct_b)
{
	t_struct	*tmp;
	int			cheapest;
	int			cost_a;
	int			cost_b;

	tmp = *strct_b;
	cheapest = 2147483647;
	while (tmp)
	{
		if (nb_abs(tmp->cost_a) + nb_abs(tmp->cost_b) < nb_abs(cheapest))
		{
			cheapest = nb_abs(tmp->cost_a) + nb_abs(tmp->cost_b);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	placement_utils(strct_a, strct_b, cost_a, cost_b);
}

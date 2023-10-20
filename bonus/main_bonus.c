/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:38:24 by eablak            #+#    #+#             */
/*   Updated: 2023/10/20 19:10:47 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap_bonus.h"
#include "stdio.h"

void	last_processes(t_struct **struct_a, t_struct **struct_b, int size)
{
	last_control(struct_a, size);
	free_struct(struct_a, size);
	free_struct(struct_b, size);
}

int	main(int ac, char **av)
{
	int		size;
	char	*all_arguments;
	int		*arr;

	(void)ac;
	size = get_size(av) - 1;
	if (size == 0)
		return (1);
	all_arguments = unify(av);
	check_nan(all_arguments);
	arr = convert_digit(all_arguments, size);
	check_same(arr, size);
	checker(arr, size);
	free(arr);
}

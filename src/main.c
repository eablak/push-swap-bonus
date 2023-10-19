/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:04:40 by eablak            #+#    #+#             */
/*   Updated: 2023/10/19 14:39:59 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

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
	check_sorted(arr, size);
	check_same(arr, size);
    start_processes(arr,size);
	system("leaks push_swap");
	free(arr);
}

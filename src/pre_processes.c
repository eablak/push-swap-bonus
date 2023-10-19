/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_processes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:29:24 by eablak            #+#    #+#             */
/*   Updated: 2023/10/19 12:07:36 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

int	get_size(char **av)
{
	int		i;
	int		size;
	char	**array;
	int		j;

	i = 0;
	size = 0;
	while (av[i])
	{
		array = ft_split(av[i], ' ');
		j = 0;
		while (array[j])
		{
			free(array[j]);
			j++;
			size++;
		}
		free(array);
		i++;
	}
	return (size);
}

char	*unify(char **av)
{
	int		i;
	char	*all_array;
	char	**array;
	int		j;

	i = 1;
	all_array = NULL;
	while (av[i])
	{
		array = ft_split(av[i], ' ');
		array_control(array[0]);
		j = 0;
		while (array[j])
		{
			all_array = ft_strjoin(all_array, array[j]);
			all_array = ft_strjoin(all_array, " ");
			free(array[j]);
			j++;
		}
		free(array);
		i++;
	}
	return (all_array);
}

int	*convert_digit(char *str, int size)
{
	int		i;
	char	**array;
	int		*int_array;
	int		j;

	i = 0;
	int_array = malloc(sizeof(int) * size);
	while (str[i])
	{
		array = ft_split(str, ' ');
		j = 0;
		while (array[j])
		{
			int_array[j] = ft_atoi(array[j]);
			free(array[j]);
			j++;
		}
		free(array);
		i++;
	}
	free(str);
	return (int_array);
}

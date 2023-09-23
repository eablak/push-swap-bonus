/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:04:40 by eablak            #+#    #+#             */
/*   Updated: 2023/09/23 14:48:46 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    tüm değerleri a'ya at.
    a'da indeksleme işlemi yap
    en büyük 3 indekli değeri a da bırak diğerlerini b ye yolla(mantığı var)
    mantık -> önce eleman sayısının yarısından küçükleri sonra 3 den büyük olana kadar kalanları yolla
    a'da kalanaları kendi içinde sırala
    a ve b'dekilere pozisyon ataması yap
    b'dekilere hedef pozisyon ataması yap
    cost_a cost_b hesaplaması yap bunun maliyet hesabını yap en az olanı gönder
    hepsi a'ya gittikten sonra a'daki en küçük indeksliyi en başa çek finito
*/

#include "../libft/libft.h"
#include "../push_swap.h"

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
	
	free(arr);
}

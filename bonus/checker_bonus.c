/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:56:11 by eablak            #+#    #+#             */
/*   Updated: 2023/10/20 18:01:15 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	checker_rotates(t_struct **struct_a, t_struct **struct_b, char *str)
{
	int	i;

	i = 0;
	
	if (ft_strncmp(str, "rrr", 3) == 0)
		i = rrr(struct_a, struct_b);
	else if (ft_strncmp(str, "rra", 3) == 0)
		i = rra(struct_a);
	else if (ft_strncmp(str, "rrb", 3) == 0)
		i = rrb(struct_b);
	else if (ft_strncmp(str, "ra", 2) == 0)
		i = ra(struct_a);
	else if (ft_strncmp(str, "rb", 2) == 0)
		i = rb(struct_b);
	else if (ft_strncmp(str, "rr", 2) == 0)
		i = rr(struct_a, struct_b);
	return (i);
}

int	checker_swaps(t_struct **struct_a, t_struct **struct_b, char *str)
{
	int	i;

	i = 0;
	if (ft_strncmp(str, "sa", 2) == 0)
		i = sa(struct_a);
	else if (ft_strncmp(str, "sb", 2) == 0)
		i = sb(struct_b);
	else if (ft_strncmp(str, "ss", 2) == 0)
		i = ss(struct_a, struct_b);
	return (i);
}

int	checker_pushs(t_struct **struct_a, t_struct **struct_b, char *str)
{
	int	i;

	i = 0;
	if (ft_strncmp(str, "pa", 2) == 0)
		i = pa(struct_a, struct_b);
	else if (ft_strncmp(str, "pb", 2) == 0)
		i = pb(struct_a, struct_b);
	return (i);
}

void print_error(t_struct **struct_a,int size)
{
	write(1, "Error",5);
	free_struct(struct_a,size);
	exit(1);
}

void print_strct(t_struct **strct){
	t_struct	*kp;

	kp = (*strct);
	while ((*strct))
	{
		printf("%d\n",(*strct)->data);
		(*strct) = (*strct)->next;
	}
	(*strct) = kp;
}


void	checker(int *arr, int size)
{
	t_struct	*struct_a;
	t_struct	*struct_b;
	char		*str;
	int			i;

	struct_a = build_struct(arr, size);
	struct_b = NULL;
	str = "";
	i = 0;
	// print_strct(&struct_a);
	// printf("!!!!\n");
	while (str != NULL)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		if (checker_rotates(&struct_a, &struct_b, str))
			i++;
		else if (checker_swaps(&struct_a, &struct_b, str))
			i++;
		else if (checker_pushs(&struct_a, &struct_b, str))
			i++;
		else
			print_error(&struct_a,size);
		// printf("A\n");
		// print_strct(&struct_a);
		// printf("B\n");
		// print_strct(&struct_b);
		free(str);
	}
	last_control(&struct_a, size);
	free_struct(&struct_a, size);
	free_struct(&struct_b,size);
	printf("A\n");
	print_strct(&struct_a);
	printf("B\n");
	print_strct(&struct_b);
}

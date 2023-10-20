/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:20:53 by eablak            #+#    #+#             */
/*   Updated: 2023/10/20 12:06:12 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_struct
{
	int				data;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_struct	*next;
}					t_struct;

void				array_control(char *all_array);
void				check_same(int *arr, int size);
void				check_nan(char *all_arguments);
void				check_sorted(int *arr, int size);
void				start_processes(int *arr, int size);
void				process_by_size(int size, t_struct **struct_a);
void				indexing(int *arr, int size, t_struct **struct_a);
int					ra(t_struct **stack_a);
int					sa(t_struct **stack_a);
t_struct			*get_last(t_struct *stack_a);
int					rra(t_struct **stack_a);
void				big_sort(t_struct **struct_a, int size);
int					pb(t_struct **stack_a, t_struct **stack_b);
t_struct			*get_last_before(t_struct *stack);
int					get_size_struct(t_struct **strc);
void				little_sort(t_struct **stack_a);
void				current_positions(t_struct **strc);
void				target_positions(t_struct **struct_a, t_struct **struct_b);
void				calculate_const(t_struct **struct_a, t_struct **struct_b);
int					is_sorted(t_struct *strc);
void				placement(t_struct **strct_a, t_struct **strct_b);
int					rr(t_struct **stack_a, t_struct **stack_b);
int					rrr(t_struct **stack_a, t_struct **stack_b);
int					pa(t_struct **stack_a, t_struct **stack_b);
int					rrb(t_struct **stack_b);
int					rb(t_struct **stack_b);
void				ascending(t_struct **strct_a, int size);
void				position_processes(t_struct **struct_a,
						t_struct **struct_b);
void				get_const(t_struct **stack_a, t_struct **stack_b);
void				free_struct(t_struct **strc, int size);
int					get_size(char **av);
char				*unify(char **av);
int					*convert_digit(char *str, int size);
t_struct			*build_struct(int *arr, int size);
void				checker(int *arr, int size);
int					sb(t_struct **stack_b);
int					ss(t_struct **stack_a, t_struct **stack_b);
void				last_control(t_struct **strct_a, int size);
#endif
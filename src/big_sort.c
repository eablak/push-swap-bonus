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

void sendB_first(t_struct **struct_a, t_struct **struct_b, int size){

	t_struct *_keepA;
	int i;

	_keepA = (*struct_a);
	i = 0;
	while (i < size)
	{
		if ((*struct_a)->index < (size / 2))
			pb(struct_a,struct_b);
		else
			ra(struct_a);
		i++;
	}
	(*struct_a) = _keepA;
}

void sendB_second(t_struct **struct_a, t_struct **struct_b, int size){

	int a_size;
	int i;
	int j;

	a_size = get_size_struct(struct_a);
	i = 0;
	j = 0;
	while(i < a_size){
		if (((*struct_a)->index == size || (*struct_a)->index == size - 1 ||
			(*struct_a)->index == size -2 ) && j != 3){
				ra(struct_a);
				j++;
			}
		else
			pb(struct_a,struct_b);
		i++;
	}
}

void big_sort(t_struct **struct_a, int size){
    t_struct *struct_b;

    struct_b = NULL;
	if (size > 6)
    	sendB_first(struct_a,&struct_b,size);
	sendB_second(struct_a,&struct_b,size);

	int i = 0;
	int sizeA = get_size_struct(struct_a);
	int sizeB = get_size_struct(&struct_b);

	printf("A değerleri \n");
	while(i < sizeA){
		printf("%d\n",(*struct_a)->data);
		(*struct_a) = (*struct_a)->next;
		i++;
	}
	i = 0;
	printf("\nB değerleri \n");
	while(i < sizeB){
		printf("%d\n",(struct_b)->data);
		(struct_b) = (struct_b)->next;
		i++;
	}
}

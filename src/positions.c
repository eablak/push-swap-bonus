#include "../push_swap.h"

//b'den ayrılma maliyeti
void current_positions(t_struct **strc){
    
    t_struct *keep;
    int size;
    int i;

    size = get_size_struct(strc);
    keep = (*strc);
    i = 0;
    while(i < size){
        if (i <= (size / 2)){
            (*strc)->current_pos = i;
            (*strc)->reverse_B = 0;
        }
        else{
            (*strc)->current_pos = size - i;
            (*strc)->reverse_B = 1;
        }
        (*strc) = (*strc)->next;
        i++;
    }
    (*strc) = keep;
}

void	position(t_struct **stack)
{
	t_struct	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

int	get_target(t_struct **stack_a, int b_indx, int target_indx, int target)
{
	t_struct	*tmp_a;

	tmp_a = *stack_a;
	while (tmp_a)
	{
		if (tmp_a->index > b_indx && tmp_a->index < target_indx)
		{
			target_indx = tmp_a->index;
			target = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	if (target_indx != 2147483647)
		return (target);
	tmp_a = *stack_a;
	while (tmp_a)
	{
		if (tmp_a->index < target_indx)
		{
			target_indx = tmp_a->index;
			target = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (target);
}

void target_positions(t_struct **struct_a, t_struct **strct_b){
    t_struct	*tmp_b;
	int		target_pos;

	tmp_b = *strct_b;
	position(struct_a);
	position(strct_b);
	target_pos = 0;
	while (tmp_b)
	{
		target_pos = get_target(struct_a, tmp_b->index, 2147483647, target_pos);
		tmp_b->target_pos = target_pos;
		tmp_b = tmp_b->next;
	}
}

void calculate_const(t_struct **struct_a,t_struct **struct_b){
    t_struct *keep_b;
    keep_b = *struct_b;

    while(*struct_b){
        printf("%d sayisinin target: %d current: %d\n",(*struct_b)->data,(*struct_b)->target_pos,(*struct_b)->current_pos);
        (*struct_b)->_const = (*struct_b)->target_pos + (*struct_b)->current_pos;
        (*struct_b) = (*struct_b)->next;
    }
    (*struct_b) = keep_b;

    (void) struct_a;
}
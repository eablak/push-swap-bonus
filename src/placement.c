#include "../push_swap.h"

void _rrr(t_struct **strct_a, t_struct **strct_b){
    while((*strct_b)->target_pos && (*strct_b)->current_pos){
        (*strct_b)->target_pos--;
        (*strct_b)->current_pos--;
        rrr(strct_a,strct_b);
    }
}

void _rr(t_struct **strct_a, t_struct **strct_b){
    while((*strct_b)->target_pos && (*strct_b)->current_pos){
        (*strct_b)->target_pos--;
        (*strct_b)->current_pos--;
        rr(strct_a,strct_b);
    }
}

void _ra(t_struct **strct_a, t_struct **strct_b){
    while((*strct_b)->target_pos){
        if ((*strct_b)->reverse_A == 0)
            ra(strct_a);
        else
            rra(strct_a);
        (*strct_b)->target_pos--;
    }
}

void _rb(t_struct **strct_a, t_struct **strct_b){
    while((*strct_b)->target_pos){
        if ((*strct_b)->reverse_B == 0)
            rb(strct_a);
        else
            rrb(strct_a);
        (*strct_b)->target_pos--;
    }
}

void placement(t_struct **strct_a, t_struct **strct_b){

    if ((*strct_b)->reverse_A == 1 && (*strct_b)->reverse_B == 1)
        _rrr(strct_a,strct_b);
    if ((*strct_b)->reverse_A == 0 && (*strct_b)->reverse_B == 0)
        _rr(strct_a,strct_b);
    _ra(strct_a,strct_b);
    _rb(strct_a,strct_b);
    // printf("giden değer %d\n",(*strct_b)->data);
    pa(strct_a,strct_b);
}
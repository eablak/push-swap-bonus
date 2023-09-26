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

//a da yerleşme maliyeti
void target_positions(t_struct **struct_a,t_struct **struct_b){

    t_struct *keep_b;
    t_struct *keep_a;
    int i;

    keep_b = *struct_b;
    keep_a = *struct_a;
    i = 0;
    while(*struct_b){
        i = 0;
        (*struct_a) = keep_a;
        while(*struct_a){
            if ((*struct_b)->data < (*struct_a)->data){
                if (i < (get_size_struct(struct_a) / 2)){
                    (*struct_b)->target_pos = i;
                    (*struct_b)->reverse_A = 0;
                }
                else{
                    (*struct_b)->target_pos = get_size_struct(struct_a) - i;
                    (*struct_b)->reverse_A = 1;
                }
                break;
            }
            i++;
            (*struct_a) = (*struct_a)->next;
        }
        (*struct_b) = (*struct_b)->next;
    }
    (*struct_b) = keep_b;
    (*struct_a) = keep_a;
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
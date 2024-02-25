#include <stdio.h>
#include <stdlib.h>


typedef struct IntElement{
    struct IntElement *previous;
    int data;
    struct IntElement *next;
} IntElement;

IntElement *create_first_IE(int a);//creates the first element 
void push_IE(IntElement *base, IntElement *new);//places new element in front of base element

int main(){

    IntElement *x = create_first_IE(5);
    printf("%d\n", x->data);
    IntElement *x1 = create_first_IE(77);
    printf("%d\n", x1->data);
    push_IE(x,x1);
    printf("%p\n", x);
    printf("%p\n", x1->next);


    return 0;
}

IntElement *create_first_IE(int a){
    IntElement *ptr;
    ptr = (IntElement*)calloc(1,sizeof(IntElement));
    ptr->data = a;
    ptr->next = NULL;
    ptr->previous = NULL;
    return ptr;
}

void push_IE(IntElement *base, IntElement *new){
    new->next = base;
    base->previous = new;
     
}
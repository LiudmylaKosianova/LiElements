#include <stdio.h>
#include <stdlib.h>


typedef struct IntElement{
    struct IntElement *previous;
    int data;
    struct IntElement *next;
} IntElement;

IntElement *create_first_IE(int a);//creates the first elements 

int main(){

    IntElement *x = create_first_IE(5);
    printf("%d\n", x->data);

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
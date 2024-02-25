#include <stdio.h>
#include <stdlib.h>


typedef struct IntElement{
    struct IntElement *previous;
    int data;
    struct IntElement *next;
} IntElement;

IntElement *create_IE(int a);//creates an element 
void push_IE(IntElement *base, IntElement *new);//places new element on top of base element
IntElement *create_list(int a);//creates a list of a-elements and returns a pointer to the element on top of the list
int capacity (IntElement *ptr);

int main(){

    IntElement *list_5 = create_list(5);
    printf("%d\n", capacity(list_5));
    
    return 0;
}

IntElement *create_IE(int a){
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

IntElement *create_list(int a){
    IntElement *ptrBase = create_IE(0);
    for (int i=0; i<a-1; i++){
        IntElement *ptrNew = create_IE(0);
        push_IE(ptrBase, ptrNew);
        ptrBase = ptrNew;
    }

    return ptrBase;
}

int capacity (IntElement *ptr){
    IntElement *ptrA = ptr;
    int number = 0;
    while(ptrA != NULL){
        number++;
        ptrA = ptrA->previous;
    }
    return number;
}


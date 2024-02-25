#include <stdio.h>
#include <stdlib.h>


typedef struct IntElement{
    struct IntElement *previous;
    int data;
    struct IntElement *next;
} IntElement;

IntElement *create_IE(int a);//creates an element 
void push_IE(IntElement *last, IntElement *new);// links new element to end of the list
IntElement *create_list(int a);//creates a list of a-elements and returns a pointer to the last element
int capacity (IntElement *ptr);

int main(){  

    IntElement *list_5 = create_list(5);
    printf("list_5 %p\n", list_5);
    int count = 0;
    while(list_5 != NULL){
        count++;
        list_5 = list_5->previous;
    }

    int c = capacity(list_5);
    printf("count %d\n", count);
    printf("capacity %d\n", c);


    
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

void push_IE(IntElement *last, IntElement *new){
    last->next = new;
    new->previous = last;
     
}

IntElement *create_list(int a){
    IntElement *ptrLast = create_IE(0);
    for (int i=0; i<a-1; i++){
        IntElement *ptrNew = create_IE(0);
        push_IE(ptrLast, ptrNew);
        ptrLast = ptrNew;
    }

    return ptrLast;
}

int capacity (IntElement *ptr){
    IntElement *ptrA = ptr;
    printf("ptr argument capacity %p\n", ptr);
    int number = 0;
    while(ptrA != NULL){
        number++;         
        ptrA = ptrA->previous;
    }
    return number;
}


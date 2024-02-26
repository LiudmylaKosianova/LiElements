#include <stdio.h>
#include <stdlib.h>


typedef struct IntElement{
    struct IntElement *previous;
    int data;
    struct IntElement *next;
} IntElement;

IntElement *create_IE(int a);//creates an element 
void push_IE(IntElement *last, IntElement *new);// links new element to the end of the list
IntElement *create_list(int a);//creates a list of a-elements and returns a pointer to the last element
int capacity (IntElement *ptr);//returns number of elements in the list
IntElement *pop(IntElement *list, int a);


int main(){  

    IntElement *list_5 = create_list(5);

    IntElement *ptrCount = list_5;
    int count = 0;
    while(ptrCount != NULL){
        count++;
        ptrCount = ptrCount->previous;
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
    int number = 0;
    IntElement *ptrCount = ptr;
    
    while(ptrCount != NULL){
        number++;
        ptrCount = ptrCount->previous;
    }
    
    return number;
}

IntElement *pop(IntElement *list, int a){
    IntElement *found = list;
    while(found != NULL){
        if(found->data == a){
            return found;
        }
        found = found->next;
    }
    return found;

}


#include <stdio.h>
#include <stdlib.h>


typedef struct IntElement{
    struct IntElement *previous;
    int index;
    int data;
    struct IntElement *next;
} IntElement;

IntElement *create_IE(int a);//creates an element 
void push_IE(IntElement *last, IntElement *new);// links new element to the end of the list
IntElement *create_list(int a);//creates a list of a-elements and returns a pointer to the last element
int capacity (IntElement *ptr);//returns number of elements in the list
int capacity2(IntElement *ptr);//returns number of elements fin the list
IntElement *pop(IntElement *list, int a);//returns the pointer to the closest element with a-data
void set_IE(IntElement *list, int index, int a); //sets the data (a) of the element at index (index)
IntElement *resize (IntElement *ptr, int a); //changes the list size, returns the pointer to the new end of the list


int main(){  

    IntElement *list_5 = create_list(5);
    set_IE(list_5,3,99); 
    printf("capacity %d\n", capacity(list_5)); 
    list_5 = resize(list_5, 3);
    
    printf("new capacity %d\n", capacity(list_5));

        
    
    IntElement *ptr1 = list_5;
    
    int count = 0;
    while(ptr1 != NULL){
         
        if(ptr1->data == 99){
             
            break;
        }
        count++;
        ptr1 = ptr1->previous;
    }

    IntElement *ptr2 = pop(list_5, 99);

       
    
    return 0;
}

IntElement *create_IE(int a){
    IntElement *ptr;
    ptr = (IntElement*)calloc(1,sizeof(IntElement));
    ptr->data = a;
    ptr->index = 0;
    ptr->next = NULL;
    ptr->previous = NULL;
    return ptr;
}

void push_IE(IntElement *last, IntElement *new){
    new->index = last->index + 1;
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
        found = found->previous;
    }
    return found;

}

void set_IE(IntElement *list, int index, int a){
    IntElement *ptrA = list;
 
    while(ptrA != NULL){
        if(ptrA->index == index){
            ptrA->data = a;
            break;
        }
        ptrA = ptrA->previous;
    }

}

int capacity2(IntElement *ptr){
    return ptr->index + 1;
}

IntElement *resize (IntElement *ptr, int a){
    
    IntElement *ptrB;

    if(ptr->index < a+1){ 
        printf("ptr->index %d\n", ptr->index);       
        while(ptr->index < a-1){
            ptrB = create_IE(0);
            push_IE(ptr, ptrB);
            ptr = ptrB;
            
        }
        
        
    }else {        
        while(ptr->index > a-1){
            ptr = ptr->previous;
            ptr->next = NULL;
        }

    }
    return ptr;
}




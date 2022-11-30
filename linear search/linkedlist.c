// linear search in linked list 

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data; 
    struct node* next; 
}; 

struct node* head = NULL; 

int linearsearch(int item) {
    struct node* temp = head; 
    int index = 0; 
    while (temp != NULL) {
        if (temp->data == item) {
            return index; 
        }
        temp = temp->next;  
        index++; 
    }
    return -1; 
} 




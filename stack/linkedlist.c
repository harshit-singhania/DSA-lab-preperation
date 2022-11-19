// implementation of stack in linked list 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data; 
    struct node *next;
};

typedef struct node node ;

node *top = NULL;

void is_empty() {
    if (top == NULL) {
        printf("Stack is empty");
} else {
        printf("Stack is not empty");
    }
}

void is_full() {
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Stack is full");
    } else {
        printf("Stack is not full");
    }
}

void push(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    if (top == NULL) {
        top = new_node;
    } else {
        new_node->next = top;
        top = new_node;
    }
}

void pop() {
    if (top == NULL) {
        printf("Stack underflow");
    } else {
        node *temp = top; 
        top = top->next;
        printf("Popped element is %d", temp->data);
        free(temp);
    }
}

void traverse() {
    node *temp = top;
    while (temp != NULL) {
        printf("%d", temp->data);
        temp = temp->next;
    }
}

int main() {
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    traverse();
    pop();
    traverse();
    is_empty();
    is_full();
    return 0;
}



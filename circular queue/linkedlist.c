// circular queue in linked list 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data; 
    struct node *next;
};

typedef struct node node ;

node *front = NULL, *rear = NULL;

void is_empty() {
    if (front == NULL) {
        printf("Queue is empty");
    } else {
        printf("Queue is not empty");
    }
}

void is_full() {
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Queue is full");
    } else {
        printf("Queue is not full");
    }
}

void enqueue(int data) {
    node *new_node = (node *) malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    if (front == NULL) {
        front = rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }
    rear->next = front;
}

void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow");
    } 
    else {
        node *temp = front; 
        front = front->next;
        printf("Dequeued element is %d", temp->data);
        free(temp);
    }
}

void traverse() {
    node *temp = front;
    while (temp->next != front) {
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("%d", temp->data);
}

int main() {
    return 0;
}
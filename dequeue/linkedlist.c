// dequeue operations in linked list 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node node;

node *front = NULL;
node *back = NULL; 

bool is_empty() {
    if (front == NULL && back == NULL) {
        return true;
    } else {
        return false;
    }
}

void enqueue(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    if (is_empty()) {
        front = back = new_node;
    } else {
        back->next = new_node;
        back = new_node;
    }
}

void dequeue() {
    if (is_empty()) {
        printf("Queue is empty");
        return;
    } else if (front == back) {
        front = back = NULL;
    } else {
        node *temp = front;
        front = front->next;
        free(temp);
    }
}

void print() {
    if (is_empty()) {
        printf("Queue is empty");
        return;
    }
    node *temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    print();
    dequeued();
    print(); 
    return 0; 
}
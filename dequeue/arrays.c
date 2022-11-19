// dequeue in arrays 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

bool is_empty() {
    if (front == -1 && rear == -1) {
        return true;
    } else {
        return false;
    }
}

bool is_full() {
    if (rear == MAX-1) {
        return true;
    } else {
        return false;
    }
}

void enqueue(int data) {
    if (is_full()) {
        printf("Queue is full");
        return;
    } else if (is_empty()) {
        front = rear = 0;
    } else {
        rear++;
    }
    queue[rear] = data;
}

void dequeue() {
    if (is_empty()) {
        printf("Queue is empty");
        return;
    } else if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

void print() {
    if (is_empty()) {
        printf("Queue is empty");
        return;
    }
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    print();
    printf(" Queue is full: %d ", is_full()); 
    printf(" Queue is empty: %d ", is_empty()); 
    dequeue();
    dequeue();
    print(); 
} 
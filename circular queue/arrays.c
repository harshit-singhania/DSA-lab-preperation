// circular queue in arrays 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct queue {
    int front; 
    int rear; 
    int size; 
    int *arr;
};

typedef struct queue queue;

queue q;

void init(int size) {
    q.front = -1; 
    q.rear = -1;
    q.size = size;
    q.arr = (int *)malloc(sizeof(int)*size);
}

bool is_empty() {
    return q.front == -1;
}

bool is_full() {
    return (q.rear+1)%q.size == q.front;
}

void enqueue(int data) {
    if (is_full()) {
        printf("Queue overflow");
        return;
    }
    else {
        q.rear = (q.rear+1)%q.size;
        q.arr[q.rear] = data;
        if (q.front == -1) {
            q.front = 0;
        }
    }
}

void dequeue() {
    if (is_empty()) {
        printf("Queue underflow");
        return;
    }
    else {
        int temp = q.arr[q.front];
        q.front = (q.front+1)%q.size;
        if (q.front > q.rear) {
            q.front = q.rear = -1;
        }
        printf("Dequeued element is %d", temp);
    }
}

void traverse() {
    int i;
    for (i=q.front; i<=q.rear; i++) {
        printf("%d", q.arr[i]);
    }
}

int main() {
    return 0; 
}
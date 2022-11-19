// implementation of stack in arrays 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct stack {
    int top; 
    int size; 
    int *arr;
}; 

typedef struct stack stack;

stack s; 

void init(int size) {
    s.top = -1; 
    s.size = size; 
    s.arr = (int *)malloc(sizeof(int)*size);
} 

bool is_empty() {
    return s.top == -1;
} 

bool is_full() {
    return s.top == s.size-1;
}

void push(int data) {
    if (s.top == s.size-1) {
        printf("Stack overflow");
        return;
    }
    else {
        s.top++;
        s.arr[s.top] = data;
    }
}

void pop() {
    if (s.top == -1) {
        printf("Stack underflow");
        return;
    }
    else {
        int temp = s.arr[s.top];
        s.top--;
        printf("Popped element is %d", temp);
    }
}

void traverse() {
    int i;
    for (i=0; i<=s.top; i++) {
        printf("%d", s.arr[i]);
    }
}

int main() {
    init(5);
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    traverse();
    pop();
    traverse();
    return 0;
}




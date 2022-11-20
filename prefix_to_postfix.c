// prefix to postfix in c using stack in arrays 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct stack {
    int top; 
    int size; 
    char *arr;
};

typedef struct stack stack;

stack s;

bool is_empty() {
    return s.top == -1;
}

bool is_full() {
    return s.top == s.size-1;
}

void push(char data) {
    if (is_empty()) {
        s.top = 0;
        s.arr[s.top] = data;
    } else {
        s.top++;
        s.arr[s.top] = data;
    }
}

char pop() {
    if (is_empty()) {
        printf("Stack underflow");
        return;
    } else {
        char temp = s.arr[s.top];
        s.top--;
        return temp;
    }
}

int precedence(char ch) {
    if (ch == '+' || ch == '-') {
        return 1;
    } else if (ch == '*' || ch == '/') {
        return 2;
    } else if (ch == '^') {
        return 3;
    } else {
        return 0;
    }
}

void prefix_to_postfix(char *prefix) {
    int i = 0;
    char ch;
    while (prefix[i] != '\0') {
        ch = prefix[i];
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            char op1 = pop();
            char op2 = pop();
            char temp[3];
            temp[0] = op1;
            temp[1] = op2;
            temp[2] = ch;
            push(temp);
        } else {
            push(ch);
        }
        i++;
    }
    printf("Postfix expression: %s", pop());
}

int main() {
    s.top = -1;
    s.size = 100;
    s.arr = (char *)malloc(s.size * sizeof(char));
    char *prefix = (char *)malloc(100 * sizeof(char));
    printf("Enter prefix expression: ");
    scanf("%s", prefix);
    prefix_to_postfix(prefix);
    return 0;
}




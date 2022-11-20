// infix to prefix conversion in c using stack 

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

void infix_to_prefix(char *infix) {
    int i = 0;
    char ch;
    char *prefix = (char *)malloc(sizeof(char)*100);
    int j = 0;
    while (infix[i] != '\0') {
        i++;
    }
    i--;
    while (i >= 0) {
        if (infix[i] >= 'a' && infix[i] <= 'z') {
            prefix[j] = infix[i];
            j++;
        } else if (infix[i] == ')') {
            push(infix[i]);
        } else if (infix[i] == '(') {
            while ((ch = pop()) != ')') {
                prefix[j] = ch;
                j++;
            }
        } else {
            while (precedence(infix[i]) <= precedence(s.arr[s.top]) && !is_empty()) {
                ch = pop();
                prefix[j] = ch;
                j++;
            }
            push(infix[i]);
        }
        i--;
    }
    while (!is_empty()) {
        ch = pop();
        prefix[j] = ch;
        j++;
    }
    prefix[j] = '\0';
    printf("Prefix expression is %s", prefix);
}

int main() {
    s.size = 100;
    s.top = -1;
    s.arr = (char *)malloc(sizeof(char)*s.size);
    char *infix = (char *)malloc(sizeof(char)*100);
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infix_to_prefix(infix);
    return 0;
}


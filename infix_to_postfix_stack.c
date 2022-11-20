// infix to postfix conversion using stack in array

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

void infix_to_postfix(char *infix) {
    int i = 0;
    char ch;
    char *postfix = (char *)malloc(sizeof(char)*100);
    int j = 0;
    while (infix[i] != '\0') {
        if (infix[i] >= 'a' && infix[i] <= 'z') {
            postfix[j] = infix[i];
            j++;
            i++;
        } else if (infix[i] == '(') {
            push(infix[i]);
            i++;
        } else if (infix[i] == ')') {
            while ((ch = pop()) != '(') {
                postfix[j] = ch;
                j++;
            }
            i++;
        } else {
            while (precedence(infix[i]) <= precedence(s.arr[s.top]) && !is_empty()) {
                postfix[j] = pop();
                j++;
            }
            push(infix[i]);
            i++;
        }
    }
    while (!is_empty()) {
        postfix[j] = pop();
        j++;
    }
    postfix[j] = '\0';
    printf("Postfix expression is %s", postfix);
}

int main() {
    s.top = -1;
    s.size = 100;
    s.arr = (char *)malloc(sizeof(char)*100);
    char *infix = (char *)malloc(sizeof(char)*100);
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infix_to_postfix(infix);
    return 0;
}



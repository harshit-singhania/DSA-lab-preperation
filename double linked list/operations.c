#include <stdio.h>
#include <stdlib.h>

struct node {
    int data; 
    struct node *next, *prev;
}; 

typedef struct node node; 
node *head = NULL; 
node *tail = NULL;

void insert(int data, int pos) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (pos == 1) {
        new_node->next = head; 
        new_node->prev = NULL;
        if (head != NULL) {
            head->prev = new_node;
        }
        head = new_node;
    } else if (pos==-1) {
        node *temp = head;
        new_node->next = NULL;
        if (head == NULL) {
            new_node->prev = NULL;
            head = new_node;
            return;
        } 
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    } else { 
        node *temp = head;
        int count = 1;
        while (count < pos) {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next->prev = new_node;
        temp->next = new_node;
        new_node->prev = temp;
    }
}

void traverse() {
    node* temp = head; 
    while (temp!=NULL) {
        printf("%d", temp->data);
        temp = temp->next;
    }
}

void traverse_backwards() {
    node* temp = tail; 
    while (temp!=NULL) {
        printf("%d", temp->data);
        temp = temp->prev;
    }
}

void delete(int pos) {
    if (pos==1){
        node* temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
    }
    else if (pos==-1) {
        node *temp = tail; 
        tail = tail->prev;
        tail->next = NULL;
        free(temp);
    } 
    else {
        node *temp = head; 
        int count = 1 ; 
        while (count < pos) {
            temp = temp->next;
        } 
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
}

int search(int key) {
    node *temp = tail->next; 
    int count = 1; 
    while (temp!=tail) {
        if (temp->data == key) {
            return count;
        }
        temp = temp->next;
        count++;
    }
}

int main() {
    return 0;
}
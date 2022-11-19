#include <stdio.h>
#include <stdlib.h>

struct node {
    int data; 
    struct node *next;
}; 

typedef struct node node; 
node *head = NULL; 

void insert(int data, int pos) {
    node *new_node = (node *)malloc(sizeof(node)); 
    new_node->data = data;
    new_node->next = NULL; 
    if (pos == 1) {
        new_node->next = head;
        head = new_node;
        return; 
    } else if (pos == -1) {
        node *temp = head; 
        while (temp!=NULL) {
            if (temp->next == NULL) {
                temp->next = new_node;
                return; 
            }
            temp = temp->next; 
        }
        temp->next = new_node;
        return;
    } else {
        node *temp = head;
        int count = 1; 
        while (count < pos) {
            temp = temp->next;
        } 
        new_node->next = temp->next;
        temp->next = new_node;
        return;
    }
} 

void traverse() {
    node* temp = head; 
    while (temp!=NULL) {
        printf("%d", temp->data);
        temp = temp->next;
    }
} 

void delete(int pos) {
    if (pos==1) {
        node *temp = head; 
        head = head->next; 
        free(temp);
    } else {
        node *temp = head; 
        int count = 1;
        while (count < pos) {
            temp = temp->next;
        } 
        node *temp2 = temp->next;
        temp = temp2->next;
        free(temp2);
    }
}

void reverse() {
    node *prev = NULL;
    node *current = head;
    node *next = NULL;
    while (current!=NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
}

void swap_positions(int v1, int v2) {
    node *prev1 = NULL, *prev2 = NULL, *temp1 = head, *temp2 = head;
    while (temp1->data != v1) {
        prev1 = temp1;
        temp1 = temp1->next;
    }
    while (temp2->data != v2) {
        prev2 = temp2;
        temp2 = temp2->next;
    }
    if (prev1 == NULL) {
        head = temp2;
    } else {
        prev1->next = temp2;
    }
    if (prev2 == NULL) {
        head = temp1;
    } else {
        prev2->next = temp1;
    }
    node *temp = temp1->next;
    temp1->next = temp2->next;
    temp2->next = temp;
    return;
}

void search(int key) {
    node *temp = head;
    int count = 1;
    while (temp!=NULL) {
        if (temp->data == key) {
            printf("Found at %d", count);
            return;
        }
        temp = temp->next;
        count++;
    }
    printf("Not found");
}

void sort() {
    node *temp = head;
    while (temp!=NULL) {
        node *temp2 = temp->next;
        while (temp2!=NULL) {
            if (temp->data > temp2->data) {
                int temp3 = temp->data;
                temp->data = temp2->data;
                temp2->data = temp3;
            }
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
}

int main() {
    insert(1, 1);
    insert(2, 2);
    insert(3, 3);
    insert(4, 4);
    insert(5, 5);
    insert(6, 6);
    insert(7, 7);
    insert(8, 8);
    insert(9, 9);
    insert(10, 10);
    traverse();
    printf("Search 5");
    search(5);
    printf("Search 11");
    search(11);
    printf("Delete 5");
    delete(5);
    traverse();
    printf("Reverse");
    reverse();
    return 0; 
}
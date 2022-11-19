#include <stdio.h>
#include <stdlib.h>

struct node {
    int data; 
    struct node *next;
}; 

typedef struct node node; 
node *head = NULL; 
node *tail = NULL;

void insert(int data, int pos) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    // insert into circular linked list 
    if (head == NULL) {
        return; 
    } else {
        if (pos == 1) {
            new_node->next = tail->next;
            tail->next = new_node;
            return;
        }
        if (pos == -1) {
            new_node->next = tail->next; 
            tail->next = new_node;
            tail = new_node;
            return; 
        } else {
            node *temp = tail->next; 
            int count = 1;
            while (count < pos) {
                temp = temp->next;
                count++;
            }
            new_node->next = temp->next;
            temp->next = new_node;
            return;
        }
    }
} 

void traverse() {
    node* temp = tail->next; 
    while (temp!=tail) {
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("%d", temp->data);
    return; 
}

void delete(int pos) {
    if (pos==1) {
        node *temp = tail->next; 
        tail->next = tail->next->next;
        free(temp);
    } else if (pos == -1 ) {
        node *temp = tail->next; 
        while (temp->next != tail ) {
            temp = temp->next;
        } 
        temp->next = tail->next;
        free(tail);
        tail = temp;
    } else { 
        node *temp = tail->next; 
        int count = 1;
        while (count < pos) {
            temp = temp->next;
        }
        node *temp2 = temp->next;
        temp->next = temp->next->next;
        free(temp2);
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

void swap_nodes(int v1, int v2) {
    if (v1 == v2) {
        return; 
    }
    node *prev1 = NULL, *curr1 = tail->next;
    while (curr1 && curr1 != v1) {
        prev1 = curr1; 
        curr1 = curr1->next; 
    } 
    node *prev2 = NULL, *curr2 = tail->next;
    while (curr2 && curr2 != v2) {
        prev2 = curr2; 
        curr2 = curr2->next; 
    }
    if (curr1 == NULL || curr2 == NULL) {
        return; 
    }
    if (prev1!=NULL) {
        prev1->next = curr2;
    } else {
        tail->next = curr2;
    } 

    if (prev2!=NULL) {
        prev2->next = curr1;
    } else {
        tail->next = curr1;
    }

    node *temp = curr1->next;
    curr1->next = curr2->next;
    curr2->next = temp;
    return;
}

void sort() {
    node *temp = tail->next; 
    while (temp!=tail) {
        node *temp2 = temp->next; 
        while (temp2!=tail) {
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
    int n;
    scanf("%d", &n);
    int i;
    for (i=0; i<n; i++) {
        int data;
        scanf("%d", &data);
        insert(data, -1);
    }
    int pos;
    scanf("%d", &pos);
    insert(10, pos);
    traverse();
    delete(pos);
    traverse();
    int key;
    scanf("%d", &key);
    int pos2 = search(key);
    printf("%d", pos2);
    int v1, v2;
    scanf("%d %d", &v1, &v2);
    swap_positions(v1, v2);
    traverse();
    sort();
    traverse();
    return 0;
}
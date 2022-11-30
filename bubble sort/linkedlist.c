// bubble sort in ll
 
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node *newNode(int x)
{
    struct Node* temp = (Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    return temp;
}

void bubbleSort(Node *head)
{
    int swapped;
    Node *ptr1;
    Node *lptr = NULL;
 
    /* Checking for empty list */
    if (head == NULL)
        return;
 
    do
    {
        swapped = 0;
        ptr1 = head;
 
        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            { 
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}

int main()
{
    Node *head = newNode(10);
    head->next = newNode(9);
    head->next->next = newNode(8);
    head->next->next->next = newNode(7);
    head->next->next->next->next = newNode(6);
    head->next->next->next->next->next = newNode(5);
    head->next->next->next->next->next->next = newNode(4);
    head->next->next->next->next->next->next->next = newNode(3);
    head->next->next->next->next->next->next->next->next = newNode(2);
    head->next->next->next->next->next->next->next->next->next = newNode(1);
    bubbleSort(head);
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return 0;
}


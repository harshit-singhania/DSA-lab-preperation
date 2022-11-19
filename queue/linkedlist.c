// implementation of queue using linked list 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data; 
    struct node *next;
};

typedef struct node node ;
node *front = NULL, *rear = NULL; 

void is_empty() {
    if (front == NULL) {
        printf("Queue is empty");
    } else {
        printf("Queue is not empty");
    }
}

void is_full() {
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Queue is full");
    } else {
        printf("Queue is not full");
    }
}

void enqueue(int data) {
    node *new_node = (node *) malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    if (front == NULL) {
        front = rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }
}

void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow");
    } 
    else {
        node *temp = front; 
        front = front->next;
        printf("Dequeued element is %d", temp->data);
        free(temp);
    }
} 

void traverse() {
    node *temp = front;
    while (temp != NULL) {
        printf("%d", temp->data);
        temp = temp->next;
    }
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    enqueue(9);
    enqueue(10);
    enqueue(11);
    enqueue(12);
    enqueue(13);
    enqueue(14);
    enqueue(15);
    enqueue(16);
    enqueue(17);
    enqueue(18);
    enqueue(19);
    enqueue(20);
    enqueue(21);
    enqueue(22);
    enqueue(23);
    enqueue(24);
    enqueue(25);
    enqueue(26);
    enqueue(27);
    enqueue(28);
    enqueue(29);
    enqueue(30);
    enqueue(31);
    enqueue(32);
    enqueue(33);
    enqueue(34);
    enqueue(35);
    enqueue(36);
    enqueue(37);
    enqueue(38);
    enqueue(39);
    enqueue(40);
    enqueue(41);
    enqueue(42);
    enqueue(43);
    enqueue(44);
    enqueue(45);
    enqueue(46);
    enqueue(47);
    enqueue(48);
    enqueue(49);
    enqueue(50);
    enqueue(51);
    enqueue(52);
    enqueue(53);
    enqueue(54);
    enqueue(55);
    enqueue(56);
    enqueue(57);
    enqueue(58);
    enqueue(59);
    enqueue(60);
    enqueue(61);
    enqueue(62);
    enqueue(63);
    enqueue(64);
    enqueue(65);
    enqueue(66);
    enqueue(67);
    enqueue(68);
    enqueue(69);
    enqueue(70);
    enqueue(71);
    enqueue(72);
    enqueue(73);
    enqueue(74);
    enqueue(75);
    enqueue(76);
    enqueue(77);
    enqueue(78);
    enqueue(79);
    enqueue(80);
    enqueue(81);
    enqueue(82);
    enqueue(83);
    enqueue(84);
    enqueue(85);
    enqueue(86);
    enqueue(87);
    enqueue(88);
    enqueue(89);
    enqueue(90);
    enqueue(91);
    enqueue(92);
    enqueue(93);
    enqueue(94);
    enqueue(95);
    enqueue(96);
    enqueue(97);
    enqueue(98);
    enqueue(99);
}


// binary tree in c 

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node node;

node *root = NULL;

node *create_node(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert(int data) {
    node *new_node = create_node(data);
    if (root == NULL) {
        root = new_node;
    } else {
        node *temp = root;
        while (temp != NULL) {
            if (data < temp->data) {
                if (temp->left == NULL) {
                    temp->left = new_node;
                    break;
                } else {
                    temp = temp->left;
                }
            } else {
                if (temp->right == NULL) {
                    temp->right = new_node;
                    break;
                } else {
                    temp = temp->right;
                }
            }
        }
    }
}

void preorder(node *temp) {
    if (temp != NULL) {
        printf("%d ", temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}

void inorder(node *temp) {
    if (temp != NULL) {
        inorder(temp->left);
        printf("%d ", temp->data);
        inorder(temp->right);
    }
}

void postorder(node *temp) {
    if (temp != NULL) {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d ", temp->data);
    }
}

void search(int data) {
    node *temp = root;
    while (temp != NULL) {
        if (data == temp->data) {
            printf("Element found");
            break;
        } else if (data < temp->data) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    if (temp == NULL) {
        printf("Element not found");
    }
}

void delete(int key) {
    node *temp = root, *parent = NULL;
    while (temp != NULL) {
        if (key == temp->data) {
            break;
        } else if (key < temp->data) {
            parent = temp;
            temp = temp->left;
        } else {
            parent = temp;
            temp = temp->right;
        }
    }
    if (temp == NULL) {
        printf("Element not found");
    } else {
        if (temp->left == NULL && temp->right == NULL) {
            if (parent->left == temp) {
                parent->left = NULL;
            } else {
                parent->right = NULL;
            }
            free(temp);
        } else if (temp->left == NULL || temp->right == NULL) {
            if (temp->left == NULL) {
                if (parent->left == temp) {
                    parent->left = temp->right;
                } else {
                    parent->right = temp->right;
                }
            } else {
                if (parent->left == temp) {
                    parent->left = temp->left;
                } else {
                    parent->right = temp->left;
                }
            }
            free(temp);
        } else {
            node *successor = temp->right;
            while (successor->left != NULL) {
                successor = successor->left;
            }
            temp->data = successor->data;
            delete(successor->data);
        }
    }
}

struct node* findSmallest(struct node* root) {
    if (root->left == NULL) {
        return root;
    } else {
        return findSmallest(root->left);
    }
}

struct node* findLargest(struct node* root) {
    if (root->right == NULL) {
        return root;
    } else {
        return findLargest(root->right);
    }
}


int main() {
    insert(10);
    insert(5);
    insert(15);
    insert(3);
    insert(7);
    insert(12);
    insert(18);
    insert(1);
    insert(4);
    insert(6);
    insert(8);
    insert(11);
    insert(13);
    insert(16);
    insert(20);
    printf("Preorder traversal: ");
    preorder(root);
    printf(""); 
    printf("Inorder traversal: ");
    inorder(root);
    printf("");
    printf("Postorder traversal: ");
    postorder(root);
    printf("");
    return 0;
}

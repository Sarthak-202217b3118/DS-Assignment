#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* right;
    struct node* left;
};

struct node* newNode(int x){
    struct node* temp;
    temp = malloc(sizeof(struct node));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node* search(struct node* root, int x){
    if(root == NULL || root->data == x){
        return root;
    }
    else if(x > root->data){
        return search(root->right, x);
    }
    else{
        return search(root->left, x);
    }
}

struct node* insert(struct node* root, int x){
    if(root == NULL){
        return newNode(x);
    }
    else if(x > root->data){
        root->right = insert(root->right, x);
    }
    else{
        root->left = insert(root->left, x);
    }
    return root;
}

struct node* findMin(struct node* root){
    if(root == NULL){
        return NULL;
    }
    else if(root->left != NULL){
        return findMin(root->left);
    }
    return root;
}

struct node* del(struct node* root, int x){
    if(root == NULL){
        return NULL;
    }
    else if(x > root->data){
        root->right = del(root->right, x);
    }
    else if(x < root->data){
        root->left = del(root->left, x);
    }
    else{
        if(root->right == NULL && root->left == NULL){
            free(root);
            return NULL;
        }
        else if(root->right == NULL || root->left == NULL){
            struct node* temp;
            if (root->left == NULL){
                temp = root->right;
            }
            else{
                temp = root->left;
            }
            free(root);
            return temp;
        }
        else{
            struct node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = del(root->right, temp->data);
        }
    }
    return root;
}

void inOrder(struct node* root){
    if (root != NULL){
        inOrder(root->left);
        printf(" %d ", root->data);
        inOrder(root->right);
    }
}

int main(){
    struct node* root;
    root = newNode(20);
    insert(root, 5);
    insert(root, 1);
    insert(root, 15);
    insert(root, 9);
    insert(root, 7);
    insert(root, 12);
    insert(root, 30);
    insert(root, 25);
    insert(root, 40);
    insert(root, 45);
    insert(root, 42);
    printf("\n In Order Traversal After Insertion of nodes");
    inOrder(root);
    printf("\n");
    root = del(root, 1);
    root = del(root, 40);
    root = del(root, 45);
    root = del(root, 9);
    printf("\n In Order Traversal After Insertion of nodes");
    inOrder(root);
    printf("\n");
    return 0;
}

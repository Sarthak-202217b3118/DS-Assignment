# include <stdio.h>
# include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *left, *right;
} Node;

Node* newNode(int value){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

Node* insertNode(Node* root, int data){
    if (root == NULL){
    root = newNode(data);
    return root;
    }
    Node* queue[100];
    int front  = 0; int rear = 0;
    queue[rear++] = root;
    while(front != rear){
        Node* temp = queue[front++];
        if(temp->left == NULL){
            temp->left = newNode(data);
            break;
        }
        else{
            queue[rear++] = temp->left;
        }
        if(temp->right == NULL){
            temp->right = newNode(data);
            break;
        }
        else{
            queue[rear++] = temp->right;
        }
        }
        return root;
}


void delDeepest(Node* root, Node* d_node){
    Node* queue[100];
    int front = 0; int rear = 0;
    queue[rear++] = root;

    Node* temp;
    while(front != rear){
        temp = queue[front++];
        if (temp == d_node){
            temp = NULL;
            free(d_node);
            return;
        }
        if (temp->right){
            if(temp->right == d_node){
                temp->right = NULL;
                free(d_node);
                return;
            }
            else{
                queue[rear++] = temp->right;
            }
        }
        if (temp->left){
            if(temp->left == d_node){
                temp->left = NULL;
                free(d_node);
                return;
            }
            else{
                queue[rear++] = temp->left;
            }
        }
    }
}

Node* deletion(Node* root, int key){
    if(!root){
        return NULL;
    }
    if(root->left == NULL && root->right == NULL){
        if(root->data == key){
        return NULL;
        }
        else{
            return root;
        }
    }
    Node* queue[100];
    int front = 0; int rear = 0;
    queue[rear++] = root;
    Node* temp;
    Node* key_node = NULL;
    while (front != rear){
        temp = queue[front++];
        if (temp->data == key){
            key_node = temp;
        }
        if (temp->left){
            queue[rear++] = temp->left;
        }
        if (temp->right){
            queue[rear++] = temp->right;
        }
    }
    if (key_node != NULL){
        int x = temp->data;
        key_node->data = x;
        delDeepest(root, temp);
    }
    return root;
}

void inOrder(Node* root){
    if(!root){
        return;
    }
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void preOrder(Node* root){
    if(!root){
        return;
    }
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root){
    if(!root){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

void levelOrder(Node* root){
    if(!root){
        return;
    }
    Node* queue[100];
    int front = 0; int rear = 0;
    queue[rear++] = root;
    while(front != rear){
        Node* temp = queue[front++];
        printf("%d ", temp->data);
        if (temp->left){
            queue[rear++] = temp->left;
        }
        if (temp->right){
            queue[rear++] = temp->right;
        }
}
}

int main(){
    Node* root = NULL;
    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    printf("Preorder Traversal: ");
    preOrder(root);
    printf("\nInorder Traversal: ");
    inOrder(root);
    printf("\nPostorder Traversal: ");
    postOrder(root);
    printf("\nLevelorder Traversal ");
    levelOrder(root);
    root = deletion(root, 20);
    printf("\nInorder Traversal after deletion: ");
    inOrder(root);
    return 0;
}

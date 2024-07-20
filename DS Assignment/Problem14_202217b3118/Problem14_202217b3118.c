#include <stdio.h>
int maxNode = 15;
char tree[] = {'\0', 'D', 'A', 'F', 'E', 'B', 'R', 'T', 'G', 'Q', '\0', '\0',
'V', '\0', 'J', 'L'};

int getRight(int index){
    if(tree[index] != '\0' && ((2 * index) + 1) <= maxNode){
        return (2 * index) + 1;
    }
    return -1;
}

int getLeft(int index){
    if(tree[index] != '\0' && (2 * index) <= maxNode){
        return 2 * index;
    }
    return -1;
}

void preOrder(int index){
    if (index > 0 && tree[index] != '\0'){
        printf(" %c ", tree[index]);
        preOrder(getLeft(index));
        preOrder(getRight(index));
    }
}

void postOrder(int index){
    if (index > 0 && tree[index] != '\0'){
        postOrder(getLeft(index));
        postOrder(getRight(index));
        printf(" %c ", tree[index]);
    }
}

void inOrder(int index){
    if (index > 0 && tree[index] != '\0'){
        inOrder(getLeft(index));
        printf(" %c ", tree[index]);
        inOrder(getRight(index));
    }
}

int main(){
    printf("\npreOrder:\n");
    preOrder(1);
    printf("\npostOrder:\n");
    postOrder(1);
    printf("\ninOrder:\n");
    inOrder(1);
    printf("\n");
    return 0;
}





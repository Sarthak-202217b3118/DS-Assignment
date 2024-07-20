#include <stdio.h>
#include <stdlib.h>
int stack[100], choice, n, top, x, i;
void push(void);
void pop(void);
void display(void);

int main(){
    system("cls");
    top = -1;
    printf("\n Enter the size of the STACK (maximum = 100)");
    scanf("%d", &n);
    printf("STACK OPERATIONS USING ARRAY");
    printf("\n\t------------------------");
    printf("\n\t 1. PUSH \n\t 2. POP \n\t 3. DISPLAY \n\t 4. EXIT");
    do {
        printf("\n Enter your choice: ");
        scanf("%d", &choice);
        switch (choice){
        case 1:
            push();
            break;
        case 2 :
            pop();
            break;
        case 3 :
            display();
            break;
        case 4 :
            printf("EXIT PROGRAM \n");
            break;
        default:
            printf("Enter a valid choice: 1,2,3,4 \n");
        }
    }
    while(choice != 4);
    return 0;
}

void push(){
    if (top >= n-1){
        printf("STACK OVERFLOW \n");
    }
    else{
        printf("Enter value to push to stack: ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }
}

void pop(){
    if (top<=-1){
        printf("STACK UNDERFLOW \n");
    }
    else{
        printf("The popped value is %d \n", stack[top]);
        top--;
    }
}

void display(){
    if (top>=0){
        printf("\n The elements of the stack are: ");
        for (i=top; i>=0; i--){
            printf("\n%d", stack[i]);
        }
    }
    else{
        printf("\n STACK EMPTY \n");
    }
}

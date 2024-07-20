#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
 #define n 5

void main(){
    int queue[n], ch = 1, front = 0, rear = 0, i, j = 1, x =n;
    printf("Queue Using Array \n");
    printf("\n 1. Insertion \n 2. Deletion \n 3. Display \n 4. Exit \n");
    while(ch){
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
        case 1:
            if (rear==x){
                printf("\n Queue is full");
            }
            else{
                printf("\n Enter number %d: ", j++);
                scanf("%d", &queue[rear++]);
            }
            break;
        case 2:
            if (front==rear){
                printf("\n Queue is empty");
            }
            else {
                printf("Dequeued element is: %d", queue[front++]);
                x++;
            }
            break;
        case 3:
            for(i=front; i<rear; i++){
                printf("%d", queue[i]);
                printf("\n");
            }
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice. Please choose from below options");
    }
}
}

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
# define MAX 20

void create();
void insert();
void deletion();
void search();
void display();

int a, b[20], n, p, e, f, i, pos;

void main(){
    int ch;
    char g = 'y';
    do{
        printf("\n Main Menu");
        printf("\n 1. Create \n 2. Delete \n 3. Search \n 4. Display \n 5. Insert \n 6. Exit");
        printf("\n Enter your choice");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                create();
                break;
            case 2:
                deletion();
                break;
            case 3:
                search();
                break;
            case 4:
                display();
                break;
            case 5:
                insert();
                break;
            case 6:
                exit(0);
                break;
            default:
               printf("Enter a correct choice");
        }
        printf("\n Do you want to continue:::");
        scanf(" %c", &g);
}
        while(g=='y' || g=='Y');
            getch();
}

void create(){
    printf("Enter number of nodes");
    scanf("%d", &n);
    for(i=0; i<n; i++){
        printf("Enter the element");
        scanf("%d", &b[i]);
    }
}
void deletion(){
    printf("Enter position you wish to delete");
    scanf("%d", &pos);
    if(pos>n){
        printf("Invalid Position");
    }
    else {
        for (i = pos+1; i<n; i++){
            b[i-1] = b[i];
        }n--;
    }
    printf("\n Elements after deletion: ");
    for(i=0; i<n;i++){
        printf("\t%d", b[i]);
    }
}
void search(){
    printf("\n Enter the element to be searched");
    scanf("%d", &e);
    for(i=0; i<n; i++){
        if (b[i] == e){
            printf("Element is in position %d", &i);
        }
        else{
            printf("Element %d is not in the list::", &e);
            continue;
        }
    }
}
void insert(){
    printf("\n Enter the position to insert element");
    scanf("%d", &pos);
    if(pos>n){
        printf("Invalid Position");
    }
    else {
            for(i = MAX - i; i>=pos; i--){
                b[i+1] = b[i];
                printf("\n Enter the element to insert::");
                scanf("%d", &p);
                b[pos]=p;
                n++;
            }
    printf("List after insertion::\n");
    display();
    }
}
void display(){
    printf("\n The Elements of the ADT list are:");
    for(i=0; i<n; i++){
        printf("\n\n%d", b[i]);
    }
}


#include <stdio.h>

void insertSort(int a[], int n){
    int i, j, temp;
    for(i = 0; i < n; i++){
        temp = a[i];
        j = i - 1;
        while(j>=0 && temp <= a[j]){
            a[j+1] = a[j];
            j -= 1;
        }
        a[j+1] = temp;
    }
}

void printArr(int a[], int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d, ", a[i]);
    }
}

int main(){
       int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("The number of elements must be greater than 0.\n");
        return 1;
    }

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Array before sorting: \n");
    printArr(arr, n);

    insertSort(arr, n);
    printf("\n Array after sorting: \n");
    printArr(arr, n);
    return 0;
}

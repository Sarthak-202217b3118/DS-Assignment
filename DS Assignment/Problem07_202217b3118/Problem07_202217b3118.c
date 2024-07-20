#include <stdio.h>

void bubbleSort(int arr[], int n){
    int i, j;
    for(i = 0; i < n - 1; i++){
        for(j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main(){
    int n;
    printf("Enter number of elements in your array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter your array elements \n");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);
    printf("Sorted Array: \n ");
    for (int i = 0; i < n; i++){
        printf("%d, ", arr[i]);
    }
    return 0;
}

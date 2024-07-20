#include <stdio.h>

void merge(int a[], int beg, int mid, int end){
    int i, j, k;
    int n1 = mid - beg + 1;
    int n2 = end - mid;
    int leftArr[n1], rightArr[n2];

    for(i = 0; i < n1; i++){
        leftArr[i] = a[beg + i];
    }
    for(j = 0; j < n2; j++){
        rightArr[j] = a[mid + 1 + j];
    }

    i = 0; j = 0; k = beg;
    while(i < n1 && j < n2){
        if(leftArr[i] <= rightArr[j]){
            a[k] = leftArr[i];
            i++;
        }
        else{
            a[k] = rightArr[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        a[k] = leftArr[i];
        i++; k++;
    }
    while(j < n2){
        a[k] = rightArr[j];
        j++; k++;
    }
}

void mergeSort(int a, int beg, int end){
    if (beg < end){
        int mid = (beg + end)/2;
        mergeSort(a, beg, mid);
        mergeSort(a, mid + 1, end);
        merge(a, beg, mid, end);
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

    mergeSort(arr, 0, n - 1);
    printf("\n Array after sorting: \n");
    printArr(arr, n);
    return 0;
}

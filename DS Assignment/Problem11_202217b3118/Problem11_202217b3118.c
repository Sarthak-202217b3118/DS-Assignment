#include <stdio.h>

int linearSearch(int arr[], int n, int target){
    int i;
    for(i = 0; i < n; i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}

int main(){
       int target;
       int arr[] = {10, 2, 8, 5, 17};
       int n = sizeof(arr) / sizeof(arr[0]);
       printf("Enter the element to search in array: ");
       scanf("%d", &target);
       int result = linearSearch(arr, n, target);
       if (result == -1){
        printf("Element not found in the array");
       }
       else{
        printf("Element found at index: %d\n", result);
       }
       return 0;
}

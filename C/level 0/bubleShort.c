#include <stdio.h>

void bubbleSort(int arr[], int n){
    int i, j, tmp;
    for(i = 0; i < n-1; i++){
        //go throught the entire array
        for(j = 0; j < n-i-1; j++){
            //check if you need exchenge
            if(arr[j] > arr[j+1]){
                //element exchange
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }

    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
     printf("Array: ");
    for (int i=0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    bubbleSort(arr, n);
    printf("Sorted array: ");
    for (int i=0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
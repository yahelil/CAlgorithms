#include <stdio.h>
#include <stdlib.h>

int* partialSums(int arr[], int length);

int main()
{
    int arr[8] = {3, 5, 1, -15, 10, -1, 10, 14};
    int *sumarray = partialSums(arr, 8);
    for (int i = 0; i < 8; i++){
        printf("%d\n", sumarray[i]);
    }
    return 0;
}

int* partialSums(int* arr, int length){
    int *sumarray = (int*)malloc(length * sizeof(int));
    int sum = 0;
    for (int i = 0; i < length; i++){
        sum += arr[i];
        sumarray[i] = sum;
    }
    return sumarray;
}

#include <stdio.h>
#include <stdlib.h>

int* partialSums(int* arr, int length){
    int *sumarray = (int*)malloc(length * sizeof(int));
    int sum = 0;
    for (int i = 0; i < length; i++){
        sum += arr[i];
        sumarray[i] = sum;
    }
    return sumarray;
}

void print_array(int* arr, int length){
    int i;
    printf("\n");
    for (i = 0; i < length; i++){
        printf("%d ", arr[i]);
    }
}
int main(){
    int length, num, i;

    printf("Enter the length of the array: ");
    scanf("%d", &length); // getting the length of the array
    printf("The length is: %d\n", length);
    int arr[length];
    for (int i = 0; i < length; i++) {
        printf("Enter the integer in the %d index: ", i+1);
        scanf("%d", &num);
        arr[i] = num;
    }
    printf("The input array is: ");
    print_array(arr, length);
    int *sumarray = partialSums(arr, length);
    printf("\nThe sumed array is:");
    print_array(sumarray, length);

    return 0;
}

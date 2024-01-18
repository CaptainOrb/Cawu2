#include <stdio.h>

void incrementArray(int* arr, int size, int incrementBy) {
    for (int i = 0; i < size; i++) {
        *(arr+i) += incrementBy;
    }
}

int main() {
    int myArray[] = {1, 2, 3, 4, 5};
    int size = sizeof(myArray) / sizeof(myArray[0]);

    printf("Original Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", myArray[i]);
    }
    printf("\n");

    int incrementValue = 2;

    // Call the function to increment each element of the array
    incrementArray(myArray, size, incrementValue);

    printf("Array after incrementing by %d: ", incrementValue);
    for (int i = 0; i < size; i++) {
        printf("%d ", myArray[i]);
    }
    printf("\n");

    return 0;
}

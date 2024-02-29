#include <stdio.h>
//Fix the code with pointer!

void swapWithoutPointers(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 5, y = 10;

    printf("Before swapWithoutPointers: x = %d, y = %d\n", x, y);

    swapWithoutPointers(&x, &y);

    printf("After swapWithoutPointers: x = %d, y = %d\n", x, y);

    return 0;
}

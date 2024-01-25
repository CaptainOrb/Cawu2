#include <stdio.h>
#include <stdlib.h>

#define MAX 4

int stack[MAX] = {0};
int top = -1;

void add(int newValue){
    if (top == MAX-1){
        printf("STACK IS FULL\n");
        return;
    }
    stack[++top] = newValue;
}
void pop(){
    if (top == -1){
        printf("STACK IS EMPTY\n");
        return;
    }
    printf("REMOVE: %d\n", stack[top]);
    stack[top--] = -1;
}
void peek(){
    if (top == -1){
        printf("STACK IS EMPTY\n");
        return;
    }
    printf("TOP: %d\n", stack[top]);
}

int main(){
    add(9);
    add(7);
    add(5);
    add(3);
    add(1);
    peek();
    pop();
    peek();
    pop();
    pop();
    peek();
    pop();
    peek();
}
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* prev;
} Node;

Node* top = NULL;

void add(int newValue){
    Node* newNode = (Node*) malloc (sizeof(Node));
    newNode->value = newValue;
    newNode->prev = top;
    top = newNode;
}

void peek(){
    if (top == NULL){
        printf("STACK IS EMPTY!\n");
        return;
    }
    printf("TOP: %d\n", top->value);
}

void pop(){
    if (top == NULL){
        printf("STACK IS EMPTY!\n");
        return;
    }
    printf("Remove: %d\n", top->value);
    Node* tmp = top;
    top = top->prev;
    free(tmp);
}

void release(){
    while (top != NULL) pop();
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

    release();
}
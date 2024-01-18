#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;

void add(int newValue){
    Node* newNode = (Node*) malloc (sizeof(Node));

    newNode->value = newValue;
    newNode->next = NULL;

    if (head == NULL){
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
        tail->next = NULL;
    }
}

void show(){
    Node* current = head;
    while (current != NULL){
        printf("Value: %2d | Address: %12p | Next: %12p |\n",
        current->value, current, current->next);
        current = current->next;
    }
}

void release(){
    Node* current = head;
    while (current != NULL){
        Node* tmp = current;
        current = current->next;
        free(tmp);
    }
}

int main(){
    system("clear");

    // add nodes here
    add(9);
    add(2);
    add(10);
    add(11);

    show();
    release();
}
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* prev;
    struct Node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;

void add(int newValue){
    Node* newNode = (Node*) malloc (sizeof(Node));
    
    newNode->value = newValue;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL){
        head = newNode;
        tail = newNode;
    }
    else if (newValue < head->value){
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
    else if (newValue > tail->value){
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    else {
        Node* current = head;
        while (current->next->value < newValue) current = current->next;
        if (current->next->value == newValue){ // eliminate same value
            free(newNode);
            return;
        }

        // add the node
        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
    }
}

void popHead(){
    Node* tmp = head;
    head = head->next;
    head->prev = NULL;
    free(tmp);
}
void popTail(){
    Node* tmp = tail;
    tail = tail->prev;
    tail->next = NULL;
    free(tmp);
}
void popMiddle(int target){
    Node* current = head;
    // search from head:
    // the current node must be exactly the node before target node
    // thus, we will delete current->next
    while (current->next->value != target){
        current = current->next;
        if (current->next == NULL) return; // stop when not found
    }

    Node* tmp = current->next;
    current->next = tmp->next;
    tmp->next->prev = current;
    free(tmp);
}

void kill(int target){
    if (head->value == target){ // delete head
        popHead();
    }
    else if (tail->value == target){ // delete tail
        popTail();
    }
    else {
        popMiddle(target);
    }
    
}

void traceFromHead(){
    Node* current = head;
    while (current != NULL){
        printf("Value: %2d | Prev: %12p | Address: %12p | Next: %12p |\n",
            current->value, current->prev, current, current->next);
        current = current->next;
    }
}
void traceFromTail(){
    Node* current = tail;
    while (current != NULL){
        printf("Value: %2d | Prev: %12p | Address: %12p | Next: %12p |\n",
            current->value, current->prev, current, current->next);
        current = current->prev;
    }
}

void release(){
    Node* current = tail;
    while (current != NULL){
        Node* tmp = current;
        current = current->next;
        free(tmp);
    }
}

int main(){
    system("clear");
    add(11);
    add(7);
    add(13);
    add(8);
    add(13);
    kill(10);
    kill(7);
    traceFromHead();
    printf("\n\n");
    traceFromTail();
    release();
}
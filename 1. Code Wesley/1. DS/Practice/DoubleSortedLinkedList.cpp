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

void kill(int target){
    Node* current = head;

    if (head->value == target){ // delete head
        Node* tmp = head;
        head = head->next;
        head->prev = NULL;
        free(tmp);
        return;
    }
    if (tail->value == target){ // delete tail
        Node* tmp = tail;
        tail = tail->prev;
        tail->next = NULL;
        free(tmp);
        return;
    }

    while (current->next->value != target){
        current = current->next;
        if (current->next == NULL) return; // stop when not found
    }
    Node* tmp = current->next;

    current->next = tmp->next;
    tmp->next->prev = current;
    free(tmp);
}

void release(){
    Node* current = head;
    while (current != NULL){
        printf("Value: %2d | Prev: %12p | Address: %12p | Next: %12p |\n",
            current->value, current->prev, current, current->next);
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
    release();
}
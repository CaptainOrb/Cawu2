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
    else if (newValue < head->value){
        newNode->next = head;
        head = newNode;
    }
    else if (newValue > tail->value){
        tail->next = newNode;
        tail = newNode;
    }
    else {
        Node* current = head;
        while (current->next->value < newValue) current = current->next;
        if (current->next->value == newValue){
            free(newNode);
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }
}

void kill(int target){
    Node* current = head;

    if (head->value == target){ // delete head
        Node* tmp = head;
        head = head->next;
        free(tmp);
        return;
    }

    while (current->next->value != target){
        current = current->next;
        if (current->next == NULL) return; // stop when not found
    }
    if (current->next == tail){ // delete tail
        Node* tmp = tail;
        tail = current;
        free(tmp);
        return;
    }
    Node* tmp = current->next;
    current->next = tmp->next;
    free(tmp);
}

void release(){
    Node* current = head;
    while (current != NULL){
        printf("Value: %2d | Address: %12p | Next: %12p |\n",
            current->value, current, current->next);
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
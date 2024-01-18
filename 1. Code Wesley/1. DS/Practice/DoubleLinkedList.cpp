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
    Node* current = (Node*) malloc (sizeof(Node));
    current->value = newValue;
    current->prev = NULL;
    current->next = NULL;

    if (head == NULL){ // when there no existing node
        head = current;
        tail = current;
    }
    else if (newValue < head->value){ // less than head
        head->prev = current; // from null to current
        current->next = head; // from null to head
        head = current; // move the head to the new node
    }
    else if (newValue > tail->value){ // more than tail
        tail->next = current; // from null to current
        current->prev = tail; // from null to tail
        tail = current; // move the tail to the new node
    }
    else {  // when the value is in the middle
        Node* tmp = head;
        while (tmp->next->value < newValue) tmp = tmp->next;
        if (tmp->next->value == newValue){ // the value has existed before
            free(current);
        }
        else { // add new node
            current->next = tmp->next;
            current->prev = tmp;
            tmp->next->prev = current;
            tmp->next = current;
        }
    }
}

void view(){
    Node* current = head;
    while (current != NULL){
        printf("| VALUE = %03d | PREV = %12p | ADDRESS = %12p | NEXT = %12p |\n",
            current->value, current->prev, current, current->next);
        current = current->next;
    }
}

void release(){
    Node* current = head;
    while (current != NULL){
        free(current);
        current = current->next;
    }
}

void refresh(){
    head->prev = NULL;
    tail->next = NULL;
}

int main(){
    system("clear");
    add(1);
    add(10);
    add(20);
    add(-11);
    add(10);
    refresh();
    view();
    release();
}
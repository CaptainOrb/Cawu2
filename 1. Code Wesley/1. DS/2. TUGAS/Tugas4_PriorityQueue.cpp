#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// DEFINE
typedef char String[16];
typedef struct Patient {
    String name;
    int age;
    int status;
} Patient;
typedef struct Node {
    Patient patient;
    Node* next;
} Node;
enum Priority {
    LOW = 1,
    MEDIUM = 2,
    HIGH = 3
};

Node* front = NULL;
Node* rear = NULL;

// FUNCTIONS
void add(const char *name, int age, Priority status){
    Node* newNode = (Node*) malloc (sizeof(Node));
    strcpy(newNode->patient.name, name);
    newNode->patient.age = age;
    newNode->patient.status = status;

    if (rear == NULL){ // if queue is empty
        front = newNode;
        rear = newNode;
    }
    else if (front->patient.status > status){
        // add to front
        Node* tmp = front;
        front = newNode;
        front->next = tmp;
    }
    else {
        // iterate from front of queue
        Node* current = front;
        while (current != rear && current->next->patient.status <= status){
            current = current->next;
        }
        if (current == rear){
            // add to end
            rear->next = newNode;
            newNode->next = NULL;
            rear = newNode;
        }
        else {
            // add to middle
            newNode->next = current->next;
            current->next = newNode;
        }
    }
}
void next(int times = 1){
    for (int i = 0; i < times; i++){
        Node* tmp = front;
        front = front->next;
        free(tmp);
    }
}
void show(){
    printf("Linked List after entering data:\n");
    Node* current = front;
    while (current != NULL){
        printf("Nama: %-16s | Umur: %02d | Status: %02d |\n",
            current->patient.name, current->patient.age, current->patient.status);
        current = current->next;
    }
}
void release(){
    while (front != NULL) next();
}

int main(){
    add("Rizki", 33, LOW);
    add("Richard", 26, LOW);
    add("Andi", 16, HIGH);
    add("Nur", 74, MEDIUM);
    add("Coki", 66, LOW);

    show();
    next(3);
    show();
    release();
}
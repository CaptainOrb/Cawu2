#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char String[24];

typedef struct Node {
    int coefficient;
    int power;
    struct Node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;
String regex = "";

void add(int newCoefficient, int newPower){
    Node* newNode = (Node*) malloc (sizeof(Node));
    newNode->coefficient = newCoefficient;
    newNode->power = newPower;
    newNode->next = NULL;

    if (head == NULL){
        head = newNode;
        tail = newNode;
    }
    else if (newPower > head->power){
        newNode->next = head;
        head = newNode;
    }
    else if (newPower < tail->power){
        tail->next = newNode;
        tail = newNode;
    }
    else {
        Node* current = head;
        while (current->next->power > newPower) current = current->next;
        // if (current->next->power == newPower){ // delete existed value
        //     free(newNode);
        //     return;
        // }

        newNode->next = current->next;
        current->next = newNode;
    }
}

void kill(int targetCoefficient, int targetPower){
    Node* current = head;

    if (head->coefficient == targetCoefficient && head->power == targetPower){ // pop head
        Node* tmp = head;
        head = head->next;
        free(tmp);
        return;
    }

    while (current->next->power != targetPower || current->next->coefficient != targetCoefficient){
        current = current->next;
        if (current->next == NULL) return; // stop when not found
    }
    if (current->next == tail){ // pop tail
        Node* tmp = tail;
        tail = current;
        tail->next = NULL;
        free(tmp);
        return;
    }
    Node* tmp = current->next;
    current->next = tmp->next;
    free(tmp);
}

void convert(int coefficient, int power){
    if (power == 1) sprintf(regex, "%d\033[0;32mx\033[0m", coefficient);
    else if (power == 0) sprintf(regex, "%d", coefficient);
    else sprintf(regex, "%d\033[0;32mx^%d\033[0m", coefficient, power);
}

void release(){
    Node* current = head;
    printf("Result: ");
    while (current != NULL){
        convert(current->coefficient, current->power);
        if (current->next == NULL) printf("%s\n\n", regex);
        else printf("%s + ", regex);
        current = current->next;
    }
    current = head;
    while (current != NULL){
        printf("| Value: %dx^%d | Address: %16p | Next: %16p |\n",
            current->coefficient, current->power, current, current->next);
        Node* tmp = current;
        current = current->next;
        free(tmp);
    }
}

int main(){
    system("clear");
    add(6, 3);
    add(9, 2);
    add(7, 1);
    add(1, 0);

    kill(1, 0);
    release();
}
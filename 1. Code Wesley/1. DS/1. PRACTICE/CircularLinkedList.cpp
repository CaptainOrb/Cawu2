#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value; // value
    struct Node* next; // address of next node
} Node;


Node* head = NULL; // head address

void clearScreen(){
    printf("\033[H\033[J");
}

void add(){
    clearScreen();
    int newValue;
    printf("The value for new node: ");
    scanf("%d", &newValue); getchar();

    // add the value to new node
    Node* newNode = (Node*) malloc (sizeof(Node));
    newNode->value = newValue;

    if (head == NULL) newNode->next = newNode; 
    else {
        newNode->next = head->next;
        head->next = newNode;
    }
    head = newNode;
}

void del(){
    clearScreen();
    int targetValue;
    printf("The value to delete: ");
    scanf("%d", &targetValue); getchar();

    Node* search = head; // sample node for searching
    if (head->value == targetValue){ // when target in head node
        head = head->next;
        free(search);
    }
    else { // when target not in head node
        while (search->next->value != targetValue) search = search->next; // traverse all the nodes
        Node* del = search->next;
        search->next = del->next; // connect search with search->next->next
        free(del); // free search->next
    }
}

void show(){
    clearScreen();
    Node* current = head;

    do {
        printf("VALUE: %d | ADDRESS: %p | NEXT ADDRESS = %p\n", current->value, current, current->next);
        current = current->next; // move to next node
    } while (current != head);
    getchar();
}

int main(){
    int opt;
    do {
        clearScreen();
        printf("LINKED LIST\n");
        printf("===========\n");
        printf("1. Add\n");
        printf("2. Delete\n");
        printf("3. Show\n");
        printf("0. Exit\n");
        printf(">> ");
        scanf("%d", &opt); getchar();

        if (opt == 1) add();
        else if (opt == 2) del();
        else if (opt == 3) show();
    } while (opt != 0);

    if (head == NULL) return 0;

    // free the linked list
    Node* current = head;
    do {
        Node* temp = current;
        current = current->next;
        free(temp);
    } while (current != head);

    return 0;
}
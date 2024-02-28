#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

enum Status {
    VVIP = 1,
    VIP = 2,
    MEMBER = 3,
    GUEST = 4
};
typedef char String[128];
typedef struct Node {
    String name;
    Status status;
    struct Node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;


// ADDITIONAL FUNCTIONS

// Convert String to Status
Status toStatus(const char* status){
	if (strcmpi(status, "VVIP") == 0) return VVIP;
	if (strcmpi(status, "VIP") == 0) return VIP;
	if (strcmpi(status, "MEMBER") == 0) return MEMBER;
	if (strcmpi(status, "GUEST") == 0) return GUEST;
}
// Convert Status to String
const char* getTable(Status status){
	switch (status){
		case VVIP: return "VVIP";
		case VIP: return "VIP";
	}
	return "regular";
}
// Validate customer input format
bool validStatus(const char* status){
    if (
        strcmpi(status, "vvip") == 0 || strcmpi (status, "vip") == 0
        || strcmpi (status, "member") == 0 || strcmpi (status, "guest") == 0
    ) return true;
    else {
    	printf("Invalid customer format!\n");
    	return false;
	}
}


// LINKED LIST UTILS

Node* create(Status status, const char* name){
	Node* newNode = (Node*) malloc (sizeof(Node));
	newNode->status = status;
	strcpy(newNode->name, name);
	newNode->next = NULL;
	
	return newNode;
}
void release(){
	Node* c = front;
	while (c != NULL){
		Node* target = c;
		c = c->next;
		free(target);
	}
}
void popFront(){
	if (front != NULL){
		Node* target = front;
		front = front->next;
	}
}


// FUNCTIONAL REQUIREMENTS

void showQueue(){
    if (front == NULL) printf("Queue is empty\n");
    else {
        int counter = 1;
        for (Node* c = front; c != NULL; c = c->next)
            printf("%2d. %s\n", counter++, c->name);
    }
    printf("\n");
}
void add(Status status, const char* name){
    Node* newNode = create(status, name);
    
    if (front == NULL){ // empty queue
    	front = newNode;
    	rear = newNode;
	}
	else if (status < front->status){ // push front
		newNode->next = front;
		front = newNode;
	}
	else if (status >= rear->status){ // push rear
		rear->next = newNode;
		rear = newNode;
	}
	else { // push mid
		Node* c = front;
		// stop when c->next is less important than newNode
		while (c->next->status <= newNode->status)
			c = c->next;
		newNode->next = c->next;
		c->next = newNode;
	}
}
void serve(){
	printf("Attention! %s is being served at %s table\n", front->name, getTable(front->status));
	popFront();
}
void dismiss(){
	printf("End of the day!");
	while (front != NULL) popFront();
}


// MENU SCREEN
int menu(){
    int input;
    do {
    	system("cls");
	    printf("============================\n");
	    printf("SUNIB Restaurant Reservation\n");
	    printf("============================\n");
	
	    printf("Waiting line:\n");
	    showQueue();
	
	    printf("1. Add Customer to Queue\n");
	    printf("2. Serve One\n");
	    printf("3. Serve All\n");
	    printf("4. Dismiss Queue\n");
	    printf("0. Exit\n");
    	printf("Input Menu Number: ");
        scanf("%d", &input); getchar();
    } while (input < 0 || input > 4);
    return input;
}


int main(){
    do {
        switch (menu()){
            case 1: {
                String input;
                String status = "", name = "";
    			
                do {
                    scanf("%[^\n]", input); getchar();
                    sscanf(input, "%s %[^\n]", status, name);
                } while (!validStatus(status));
                
				add(toStatus(status), name);
                break;
            }
            case 2: {
                serve();
                getchar();
                break;
            }
            case 3: {
                while (front != NULL) serve();
                getchar();
                break;
            }
            case 4: {
                dismiss();
                getchar();
                break;
            }
            case 0: {
                system("cls");
                release();
                return 0;
            }
        }
    } while (true);
}

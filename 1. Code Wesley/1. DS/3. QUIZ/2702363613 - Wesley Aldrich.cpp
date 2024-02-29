#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	WESLEY ALDRICH
	2702363613
	PPTI 17
	
	DATA STRUCTURE
	QUIZ 1: "Istana Boneka"
*/

// DEFINITIONS
enum Ticket {
	FAST_TRACK,
	REGULER,
	NONE // when the Ticket couldn't be converted
};
typedef char String[32];
typedef struct Node {
	String name;
	Ticket ticket;
	struct Node* prev;
	struct Node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;
int count = 0;


// UTIL FUNCTIONS
Ticket toTicket(const char* str){
	if (strcmp(str, "REGULER") == 0) return REGULER;
	if (strcmp(str, "FAST_TRACK") == 0) return FAST_TRACK;
	return NONE;
}
const char* ticketToStr(Ticket ticket){
	switch (ticket){
		case REGULER: return "REGULER";
		case FAST_TRACK: return "FAST_TRACK";
		case NONE: return "<INVALID>"; // this shouldn't happen at all
	}
}


// FUNCTIONS

Node* create(const char* name, Ticket ticket){
	Node* newNode = (Node*) malloc (sizeof(Node));
	strcpy(newNode->name, name);
	newNode->ticket = ticket;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

void insert(Node* newNode){
	if (front == NULL){
		front = newNode;
		rear = newNode;
	}
	else if (newNode->ticket < front->ticket){
		newNode->next = front;
		front->prev = newNode;
		front = newNode;
	}
	else if (newNode->ticket >= rear->ticket){
		rear->next = newNode;
		newNode->prev = rear;
		rear = newNode;
	}
	else {
		Node* c = front;
		// stop when c->next is less important than newNode (which is c->next > newNode)
		while (c->next->ticket <= newNode->ticket)
			c = c->next;
		newNode->next = c->next;
		c->next->prev = newNode;
		newNode->prev = c;
		c->next = newNode;
	}
	count++;
}

Node* search(const char* targetName){
	if (front == NULL) NULL;
	Node* c = front;
	while (c != NULL){
		if (strcmp(c->name, targetName) == 0)
			return c;
		c = c->next;
	}
	return NULL;
}

void remove(Node* targetNode){
	if (targetNode == NULL) return;
	
	Node* left = targetNode->prev;
	Node* right = targetNode->next;
	if (targetNode == front && targetNode == rear){
		front = NULL;
		rear = NULL;
	}
	else if (targetNode == front){
		front = front->next;
		right->prev = left;
	}
	else if (targetNode == rear){
		rear = rear->prev;
		left->next = right;
	}
	else {
		left->next = right;
		right->prev = left;
	}
	
	free(targetNode);
	count--;
}

void call(){
	for (int i = 0; i < 4; i++){
		if (front == NULL) break;
		printf("%s ", front->name);
		remove(front);
	}
	printf("got into the boat.\n");
	printf("%d queues remaining.\n", count);
}

void clean(){
	while (front){
		Node* del = front;
		front = front->next;
		free(del);
	}
	printf("\n\nALL USED MALLOC RELEASED!\n");
}

void process(const char* str){
	String command;
	int amount = 0;
	sscanf(str, "%s %d\n", command, &amount);
	
	if (strcmp(command, "REGISTER") == 0){
		printf("\nINPUT FORMAT:\n[Name Ticket]\n");
		for (int i = 0; i < amount; i++){
			String newName;
			Ticket newTicket = NONE; // default value for ticket
			do {
				String newTicketStr;
				scanf("%s %[^\n]", newName, newTicketStr); getchar();
				newTicket = toTicket(newTicketStr); // convert the string to ticket
				if (newTicket == NONE) printf("Invalid Ticket Format!\n");
			} while (newTicket == NONE);
			
			insert(create(newName, newTicket));
		}
	}
	else if (strcmp(command, "REMOVE") == 0){
		printf("\nINPUT FORMAT:\n[Name]\n");
		for (int i = 0; i < amount; i++){
			String targetName;
			scanf("%[^\n]", targetName); getchar();
			
			remove(search(targetName));
		}
	}
	else if (strcmp(command, "CALL") == 0){
		call();
	}
	else printf("Invalid Input Format!\n");
}

void showQueue(){
	if (front == NULL) printf("Queue is empty.\n");
	else {
		printf("%-4s | %-12s | %-12s |\n", "NO", "NAME", "TICKET");
		Node* c = front;
		int counter = 0;
		while (c){
			printf("%4d | %-12s | %-12s |\n", ++counter, c->name, ticketToStr(c->ticket));
			c = c->next;
		}
	}
	printf("\n");
}

int main(){
	String buffer;
    do {
    	showQueue();
    	// valid input formats
    	printf("\nINPUTS:\n[REGISTER N1 | REMOVE N2 | CALL | EXIT]\n");
       	scanf("%[^\n]", buffer); getchar();
       	if (strcmp(buffer, "EXIT") == 0){
       		clean(); // free all used malloc before exit
       		return 0;
		}
    	else process(buffer);
    	printf("\n");
    } while (true);
}

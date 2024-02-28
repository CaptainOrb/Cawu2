#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

typedef char String[128];
typedef struct Node {
	String name;
	String type;
	int duration;
	struct Node* next;
} Node;

Node* table[MAX] = {0};
int count = 0;

// VALIDATIONS
bool validName(const char* name){
	String copy;
	strcpy(copy, name);
	char* str = copy;
	int count = 0;
	strtok(str, " ");
	while (str != NULL){
		str = strtok(NULL, " ");
		count++;
	}
	if (count == 2) return true;
	else return false;
}
bool validType(const char* str){
	String types[3] = {"SUV", "Sedan", "Hatchback"};
	for (int i = 0; i < 3; i++)
		if (strcmp(str, types[i]) == 0) return true;
	return false;
}


// UTILS
int hash(const char* str){
	int sum = 0;
	int len = strlen(str);
	for (int i = 0; i < len; i++) sum += str[i];
	return (sum % MAX);
}
Node* create(const char* name, const char* type, int duration){
	Node* newNode = (Node*) malloc (sizeof(Node));
	strcpy(newNode->name, name);
	strcpy(newNode->type, type);
	newNode->duration = duration;
	newNode->next = NULL;
	return newNode;
}
Node* add(Node* newNode){
	int key = hash(newNode->name);
	
	if (table[key] == NULL){
		table[key] = newNode;
	}
	else if (strcmp(newNode->name, table[key]->name) < 0){
		newNode->next = table[key];
		table[key] = newNode;
	}
	else {
		Node* c = table[key];
		while (strcmp(c->next->name, newNode->name) < 0 && c->next != NULL)
			c = c->next;
		newNode->next = c->next;
		c->next = newNode;
	}
	count++;
	printf("Successfully added %s!", newNode->name);
	getchar();
}
void show(){
	if (count == 0){
		printf("There is currently no vehicle");
	}
	else {
		for (int i = 0; i < MAX; i++){
			Node* c = table[i];
			while (c != NULL){
				printf("[%-24s | %12s | %4d ]\n", c->name, c->type, c->duration);
				c = c->next;
			}
		}
	}
}
Node* search(const char* name){
	int key = hash(name);
	Node* c = table[key];
	if (table[key] == NULL) return NULL;
	while (strcmp(c->name, name) < 0 && c != NULL) c = c->next;
	if (strcmp(c->name, name) == 0) return c;
	else return NULL;
}
void release(){
	for (int i = 0; i < MAX; i++){
		Node* c = table[i];
		while (c != NULL){
			Node* del = c;
			c = c->next;
			free(del);
		}
	}
}


// INTERFACES
int screen_menu(){
	int input;
	do {
		system("cls");
		printf("NeLson\'s Garage\n");
		printf("1. Insert New Vehicle\n");
		printf("2. View All Vehicles\n");
		printf("3. Update Storage Duration\n");
		printf("4. Exit\n");
		printf(">> ");
		scanf("%d", &input); getchar();
	} while (input < 1 || input > 4);
	return input;
}
void screen_insert(){
	system("cls");
	
	String name, type, confirm;
	int duration;
	do {
		printf("Vehicle Name: ");
		scanf("%[^\n]", name); getchar();
	} while (!validName(name));
	do {
		printf("Type [SUV | Sedan | Hatchback]: ");
		scanf("%[^\n]", type); getchar();
	} while (!validType(type));
	do {
		printf("Storage Duration: ");
		scanf("%d", &duration); getchar();
	} while (duration <= 0);
	do {
		printf("Are you sure to add %s? [Y | N]: ", name);
		scanf("%[^\n]", confirm); getchar();
	} while (strlen(confirm) != 1 || confirm[0] != 'Y' && confirm[0] != 'N');

	if (confirm[0] == 'Y') add(create(name, type, duration));
	else return;
}
void screen_view(){
	system("cls");
	show();
	getchar();
}
void screen_update(){
	system("cls");
	show();
	if (count > 0){
		Node* target = NULL;
		do {
			String targetName;
			printf("Input target name: ");
			scanf("%[^\n]", targetName); getchar();
			target = search(targetName);
		} while (target == NULL);
		
		int newDuration;
		do {
			printf("Input new storage duration: ");
			scanf("%d", &newDuration); getchar();
		} while (newDuration <= 0);
		
		target->duration = newDuration;
		printf("Successfully updated duration of %s!", target->name);
	}
	getchar();
}


int main(){
	do {
		switch(screen_menu()){
			case 1: {
				screen_insert();
				break;
			}
			case 2: {
				screen_view();
				break;
			}
			case 3: {
				screen_update();
				break;
			}
			case 4: {
				system("cls");
				release();
				return 0;
			}
		}
	} while (true);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// DEFINITIONS
#define MAX 10
typedef char String[128];
typedef struct Node {
	String id;
	String name;
	int price;
	struct Node* next;
} Node;

// DECLARATIONS
Node* table[MAX] = {0};
int size = 0;

// UTILS
const char* getId(){
	char ret[3];
	sprintf(ret, "%d%d%d", rand()%10, rand()%10, rand()%10);
	return ret;
}
Node* create(const char* name, int price){
	Node* newNode = (Node*) malloc (sizeof(Node));
	strcpy(newNode->id, getId());
	strcpy(newNode->name, name);
	newNode->price = price;
	newNode->next = NULL;
	return newNode;
}
void release(){
	for (int i = 0; i < MAX; i++){
		if (table[i] != NULL){
			Node* c = table[i];
			while (c != NULL){
				Node* del = c;
				c = c->next;
				free(del);
			}
		}
	}
}

// FUNCTIONAL REQUIREMENTS
int hash(const char* ID){
	int key = (ID[0] + ID[1] + ID[2]) % MAX;
	return key;
}
void add(Node* newNode){
	int key = hash(newNode->id);
	if (table[key] == NULL){
		table[key] = newNode;
	}
	else {
		Node* c = table[key];
		while (c->next != NULL) c = c->next;
		c->next = newNode;
	}
	size++;
}
void show(){
	system("cls");
	printf("==============================\n");
	printf("SUNIB Restaurant Menu Database\n");
	printf("==============================\n\n");
	
	if (size == 0){
		printf("No menu yet...\n");
	}
	else {
		for (int i = 0; i < MAX; i++){
			if (table[i] != NULL){
				Node* c = table[i];
				while (c != NULL){
					printf("Menu ID: %s\n", c->id);
					printf("Menu Name: %s\n", c->name);
					printf("Menu Price: %d\n\n", c->price);
					c = c->next;
				}
			}
		}
	}
}
Node* search(const char* id){
	int key = hash(id);
	Node* c = table[key];
	while (c != NULL){
		if (strcmp(c->id, id) == 0) return c;
		c = c->next;
	}
	return NULL;
}
void del(Node* target){
	int key = hash(target->id);
	Node* c = table[key];
	if (c == target){
		table[key] = c->next;
		free(c);
	}
	else {
		while (c->next != target) c = c->next;
		c->next = target->next;
		free(target);
	}
	printf("Successfully deleted a menu\n");
	size--
}

// INTERFACES
int screen_menu(){
	int selection;
	do {
		system("cls");
		printf("==============================\n");
		printf("SUNIB Restaurant Menu Database\n");
		printf("==============================\n");
		printf("1. Add a menu\n");
		printf("2. View all menu\n");
		printf("3. Delete a menu\n");
		printf("4. Exit\n");
		printf(">> ");
		scanf("%d", &selection); getchar();
	} while (selection < 1 || selection > 4);
	return selection;
}
void screen_add(){
	printf("\n");
	String name;
	int price;
	
	printf("Menu Name: ");
	scanf("%[^\n]", name); getchar();
	
	printf("Menu Price: ");
	scanf("%d", &price); getchar();
	
	add(create(name, price));
	printf("Succesfully added a menu!"); getchar();
}
void screen_view(){
	show();
	printf("\nPress to return to main menu..."); getchar();
}
void screen_delete(){
	show();
	if (size > 0){
		do {
			printf("Choose Menu ID to delete: ");
			String targetID;
			scanf("%s", targetID); getchar();
			Node* target = search(targetID);
			if (target != NULL){
				del(target);
				break;
			}
			else printf("Menu doesn\'t exist...\n\n");
		} while (true);
	}
	printf("\nPress to return to main menu..."); getchar();
}

// MAIN
int main(){
	do {
		switch (screen_menu()){
			case 1: {
				screen_add();
				break;
			}
			case 2: {
				screen_view();
				break;
			}
			case 3: {
				screen_delete();
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

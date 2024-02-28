#include <stdio.h>
#include <stdlib.h>

typedef char String[64];
typedef struct Node {
	int value;
	struct Node* left;
	struct Node* right;
} Node;

int count = 0;
Node* root = NULL;

Node* create(int value){
	Node* newNode = (Node*) malloc (sizeof(Node));
	newNode->value = value;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

Node* insert(Node* newNode, Node* current = root){
	if (current == NULL){
		if (root == NULL) root = newNode;
		count++;
		return newNode;
	}
	if (newNode->value < current->value)
		current->left = insert(newNode, current->left);
	else if (newNode->value > current->value)
		current->right = insert(newNode, current->right);
	return current;
}

Node* search(int targetValue, Node* current = root){
	if (current == NULL)
		return NULL;
	if (targetValue == current->value)
		return current;
	if (targetValue < current->value)
		return search(targetValue, current->left);
	if (targetValue > current->value)
		return search(targetValue, current->right);
}

Node* getPredecessor(Node* target){
	Node* c = target->left;
	while (c->right != NULL)
		c = c->right;
	return c;
}

Node* getParent(Node* targetNode, Node* parent = root){
	if (targetNode == parent->left || targetNode == parent->right)
		return parent;
	if (targetNode->value < parent->value)
		return getParent(targetNode, parent->left);
	if (targetNode->value > parent->value)
		return getParent(targetNode, parent->right);
	return NULL;
}

void remove(Node* target, Node* parent){
	if (root == NULL) return;
	
	if (target->left == NULL && target->right == NULL){
		if (parent->left == target){
			free(target);
			parent->left = NULL;
		}
		else {
			free(target);
			parent->right = NULL;
		}
		count--;
	}
	else if (target->left == NULL || target->right == NULL){
		Node* del = target->left? target->left : target->right;
		int copy = del->value;
		remove(del, getParent(del));
		target->value = copy;
	}
	else {
		Node* del = getPredecessor(target);
		int copy = del->value;
		remove(del, getParent(del));
		target->value = copy;
	}
}

void release(Node* current = root){
	if (current == NULL) return;
	release(current->left);
	release(current->right);
	free(current);
}

void header(){
	system("cls");
	printf("=======================\n");
	printf("Simple BST - CaptainOrb\n");
	printf("=======================\n\n");
}

void preorder(Node* current = root){
	if (current == NULL) return;
	printf("%02d ", current->value);
	preorder(current->left);
	preorder(current->right);
	if (current == root) printf("\n");
}

void inorder(Node* current = root){
	if (current == NULL) return;
	inorder(current->left);
	printf("%02d ", current->value);
	inorder(current->right);
	if (current == root) printf("\n");
}

void postorder(Node* current = root){
	if (current == NULL) return;
	postorder(current->left);
	postorder(current->right);
	printf("%02d ", current->value);
	if (current == root) printf("\n");
}

int menu(){
	int selection;
	do {
		header();
		printf("Current Node Count: %d\n\n", count);
		
		printf(">> 1. Add\n");
		printf(">> 2. Delete\n");
		printf(">> 3. Print\n");
		printf(">> 0. Exit\n");
		
		printf("\nYour Selection:\n");
		printf("--> ");
		scanf("%d", &selection); getchar();
	} while (selection < 0 || selection > 3);
	return selection;
} 

void screen_add(){
	header();
	printf("Enter new value to insert [Non-zero Integer]: ");
	int newValue;
	scanf("%d", &newValue); getchar();
	insert(create(newValue));
}

void screen_delete(){
	Node* target = NULL;
	do {
		header();
		printf("Enter value to delete [Existing Integer | 0 to go back]: ");
		int targetValue;
		scanf("%d", &targetValue); getchar();
		if (targetValue == 0) return;
		target = search(targetValue);
	} while (target == NULL);
	remove(target, getParent(target));
}

void screen_print(){
	while (true){
		int selection;
		do {
			header();
			
			printf("Select Way of Printing:\n");
			printf(">> 1. Preorder\n");
			printf(">> 2. Inorder\n");
			printf(">> 3. Postorder\n");
			printf(">> 0. Go Back\n");
			
			printf("\nYour Selection:\n");
			printf("--> ");
			scanf("%d", &selection); getchar();
		} while (selection < 0 || selection > 3);
		switch (selection){
			case 0: return;
			case 1: {
				preorder();
				break;
			}
			case 2: {
				inorder();
				break;
			}
			case 3: {
				postorder();
				break;
			}
		}
		getchar();
	}
}

int main(){
	while (true){
		switch (menu()){
			case 1: { 
				screen_add();
				break;
			}
			case 2: {
				screen_delete();
				break;
			}
			case 3: {
				screen_print();
				break;
			}
			case 0: {
				system("cls");
				release();
				return 0;
			}
		}
	}
}

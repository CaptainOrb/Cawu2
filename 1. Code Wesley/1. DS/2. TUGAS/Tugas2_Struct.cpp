#include <stdio.h>
#include <stdlib.h>

typedef char String[32];

typedef struct Character {
    String name;
    int health;
    int damage;
} Character;

typedef struct Item {
    String name;
    int value;
} Item;

int main(){
    Character* c1 = (Character*) malloc (sizeof(Character));
    Character* c2 = (Character*) malloc (sizeof(Character));
    Item* i1 = (Item*) malloc (sizeof(Item));
    Item* i2 = (Item*) malloc (sizeof(Item));

    printf("Player: ");
    scanf("%[^\n]", c1->name); getchar();
    printf("Health: ");
    scanf("%d", &c1->health); getchar();
    printf("Damage: ");
    scanf("%d", &c1->damage); getchar();

    printf("\nEnemy: ");
    scanf("%[^\n]", c2->name); getchar();
    printf("Health: ");
    scanf("%d", &c2->health); getchar();
    printf("Damage: ");
    scanf("%d", &c2->damage); getchar();

    printf("\nItems:\n");
    printf("Name: ");
    scanf("%[^\n]", i1->name); getchar();
    printf("Value: ");
    scanf("%d", &i1->value); getchar();

    printf("\nName: ");
    scanf("%[^\n]", i2->name); getchar();
    printf("Value: ");
    scanf("%d", &i2->value); getchar();


    printf("\n\nCharacter List:\n");
    printf("Player: ");
    printf("%s\n", c1->name);
    printf("Health: ");
    printf("%d\n", c1->health);
    printf("Damage: ");
    printf("%d\n", c1->damage);

    printf("\nEnemy: ");
    printf("%s\n", c2->name);
    printf("Health: ");
    printf("%d\n", c2->health);
    printf("Damage: ");
    printf("%d\n", c2->damage);

    printf("\n\nItem List:\n");
    printf("Name: ");
    printf("%s\n", i1->name);
    printf("Value: ");
    printf("%d\n", i1->value);

    printf("\nName: ");
    printf("%s\n", i2->name);
    printf("Value: ");
    printf("%d\n", i2->value);

    // running the program here will leads to memory leak.
    // to prevent it, free all the used memory!

    free(c1);
    free(c2);
    free(i1);
    free(i2);
}
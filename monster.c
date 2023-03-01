#include <stdio.h>
#include <string.h>
#include "monster.h"

struct monster create_monster(struct monster m1)
{
    printf("Enter the Monster's Name: ");
    scanf("%s", m1.name);

    printf("\nEnter the Monster's Type: ");
    scanf("%s", m1.type);

    printf("\nEnter the Monster's Health Points: ");
    scanf("%d", m1.hp);

    printf("\nEnter the Monster's Level: ");
    scanf("%d", m1.level);

    return m1;
}

void print_monster(struct monster m1)
{
    printf("Name: %s\n", m1.name);
    printf("Type: %s\n", m1.type);
    printf("Health Points: %d\n", m1.hp);
    printf("Level: %d", m1.level);
}

void save_monster(struct monster m1, FILE** fp)
{
    fwrite(m1.name, sizeof(m1.name), 1, fp);
    fputs(', ',fp);
    fwrite(m1.type, sizeof(m1.type), 1, fp);
    fputs(', ',fp);
    fwrite(m1.hp, sizeof(m1.hp), 1, fp);
    fputs(', ',fp);
    fwrite(m1.level, sizeof(m1.level), 1, fp);
    fputs(', ',fp);

}

void print_monsters(struct monster monsters[])
{
    print("Name\tType\tHP\tLevel\n");
    printf("------------------------");

    for(int i = 0; i < sizeof(monsters); i++)
    {
        printf("\n%s\t%s\t%d\t%d", monsters[i].name, monsters[i].level, monsters[i].hp, monsters[i].level);
    }
}

void load_monster(FILE** fp)
{
    struct monster monsters[128];

    struct monster m1;

    for (int i = 0; i < sizeof(monsters); i++)
    {
      *monsters[i].name = fread(monsters, sizeof(m1.name), i, fp);
      *monsters[i].type = fread(monsters, sizeof(m1.type), i, fp);
       monsters[i].hp = fread(monsters, sizeof(m1.hp), i, fp);
       monsters[i].level = fread(monsters, sizeof(m1.level), i, fp);
    }

    print_monsters(monsters);
    
}
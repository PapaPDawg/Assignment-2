#include <stdio.h>
#include <string.h>

#ifndef MONSTER_H
#define MONSTER_H


struct monster
{
    char name[32];
    char type[16];
    int hp;
    int level;
};
#endif
#include <stdio.h>
#include "monster.c"

int main()
{
    struct monster m1;

    char input_file[64];

    FILE* fp = fopen(input_file, 'a+');

    create_monster(m1);
    save_monster(m1, fp);

    return 0;
}
#include "move.h"

int main()
{
    FILE *map;
    FILE *base;
    map = fopen("map.txt", "a+");
    base = fopen("base.txt", "a+");
    int x, y;
    fscanf(base, "%d %d\n", &x, &y);
    printf("%d %d\n", x, y);
    struct tile** matrix =LoadMap(base, x, y);
    char *hexagonal = CreateMap(map);
    DisplayMap(hexagonal, matrix , x, y);
    move_player("MS",matrix,x,y);
    system("cls");
    DisplayMap(hexagonal, matrix , x, y);
    fclose(map);
    fclose(base);

}
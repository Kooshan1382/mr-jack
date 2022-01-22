#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct tile
{
    char character[10];
    char type[10];
};
char *CreateMap(FILE *map)
{
    char *hexagonal;
    hexagonal = (char *)malloc(10000);
    char c;
    if (hexagonal == NULL)
    {
        printf("no storage!");
    }
    int j;
    for (j = 0; (c = fgetc(map)) != EOF; j++)
    {
        hexagonal[j] = c;
    }
    hexagonal[j + 1] = '\0';
    return hexagonal;
}

struct tile **LoadMap(int x, int y)
{
    struct tile **matrix;
    matrix = malloc((y + 2) * sizeof(struct tile *));
    for (int i = 0; i < y + 2; i++)
    {
        matrix[i] = malloc((x + 2) * sizeof(struct tile));
    }
    for (int i = 0; i < y + 2;i++)
    {
        for (int j = 0; j < x + 2;j++)
        {
            if (i == 0 || i == y + 1 || j == 0 || j == x + 1)
            {
                strcpy(matrix[i][j].type, "out");
            }
            else{
                strcpy(matrix[i][j].type, "ins");
            }
        }
    }
    for (int i = 0; i < y + 2;i++)
    {
        for (int j = 0; j < x + 2;j++)
        {
                printf("%s ",matrix[i][j].type);
            
        }
        printf("\n");
    }
}
void DisplayMap(FILE *save)
{
}
int main()
{
    FILE *map;
    LoadMap(13,9);
    map = fopen("map.txt", "a+");
    char *curser = CreateMap(map);
    /*
    for (int i = 0; curser[i] != '\0'; i++)
    {
        printf("%c", curser[i]);
    } 
    */
}
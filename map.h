#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct tile
{
    char character[10];
    int type;
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

struct tile **LoadMap(FILE *base, int x, int y)
{
    struct tile **matrix;
    matrix = malloc((y + 2) * sizeof(struct tile *));
    for (int i = 0; i < y + 2; i++)
    {
        matrix[i] = malloc((x + 2) * sizeof(struct tile));
    }
    for (int i = 0; i < y + 2; i++)
    {
        for (int j = 0; j < x + 2; j++)
        {
            if (i == 0 || i == y + 1 || j == 0 || j == x + 1)
            {
                matrix[i][j].type = 0;
            }
            else
            {
                fscanf(base, "%d", &matrix[i][j].type);
            }
        }
    }
    for (int i = 0; i < y + 2; i++)
    {
        for (int j = 0; j < x + 2; j++)
        {
            if (i == 0 || i == y + 1 || j == 0 || j == x + 1)
            {
                strcpy(matrix[i][j].character, "NA");
            }
            else
            {
                char name[10];
                fscanf(base, "%s", name);
                strcpy(matrix[i][j].character, name);
            }
        }
    }
    return matrix;
}
void DisplayMap(char *hexagonal, struct tile **map, int x, int y)
{
    int char_count = 0;
    int type_count = 0;
    for (int i = 0; i < strlen(hexagonal); i++)
    {
        if (hexagonal[i] == 'c' && hexagonal[i+1] == 'h')
        {
            if (strcmp(map[char_count / (2 * 13) + 1][(char_count + 1) % 13 + 1].character, "NA") == 0)
            {
                printf("  ");
            }
            else
            {
                printf("%s", map[char_count / (2 * 13) + 1][(char_count + 1) % 13 + 1].character);
            }

            char_count += 2;
            i++;
        }
        else if (hexagonal[i] == 't')
        {
            if(map[type_count / (2 * 13) + 1][(type_count + 1) % 13 + 1].type==1){
                printf("  ");
            }
            else if(map[type_count / (2 * 13) + 1][(type_count + 1) % 13 + 1].type==0){
                printf("##");
            }
            else{
                printf("%d ", map[type_count / (2 * 13) + 1][(type_count + 1) % 13 + 1].type);
            }
            
            type_count += 2;
            i++;
        }
        else
        {
            printf("%c", hexagonal[i]);
        }
    }
}
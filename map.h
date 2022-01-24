#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct Escape
{
    char place[10];
    char gate1[10];
    char gate2[10];
    int mode;
};
struct tile
{
    char character[10];
    int type;
    int visibility;
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
    matrix = (struct tile **)malloc((y + 2) * sizeof(struct tile *));
    for (int i = 0; i < y + 2; i++)
    {
        matrix[i] = (struct tile *)malloc((x + 2) * sizeof(struct tile));
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
        if (hexagonal[i] == 'c' && hexagonal[i + 1] == 'h')
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
            if (map[type_count / (2 * 13) + 1][(type_count + 1) % 13 + 1].type == 1)
            {
                printf("  ");
            }
            else if (map[type_count / (2 * 13) + 1][(type_count + 1) % 13 + 1].type == 0)
            {
                printf("\U0001F3E1");
            }
             else if (map[type_count / (2 * 13) + 1][(type_count + 1) % 13 + 1].type == 3)
            {
                printf("\U0001F535");
            }
             else if (map[type_count / (2 * 13) + 1][(type_count + 1) % 13 + 1].type == 4)
            {
                printf("\U0001F534");
            }
             else if (map[type_count / (2 * 13) + 1][(type_count + 1) % 13 + 1].type == 2)
            {
                printf("\U0001F4A1");
            }
            else if (map[type_count / (2 * 13) + 1][(type_count + 1) % 13 + 1].type == 5)
            {
                printf("\U0001F311");
            }
            	
            else
            {
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
struct Escape *Load_Escape(FILE *base)
{
    struct Escape *Gates = (struct Escape *)malloc(4 * sizeof(struct Escape));
    for (int i = 0; i < 4; i++)
    {
        fscanf(base, "%s %d %s %s", &Gates[i].place, &Gates[i].mode, &Gates[i].gate1, &Gates[i].gate2);
    }
    return Gates;
};
void Clear_Visibility(struct tile **matrix, int x, int y){
    for (int i = 0; i < y + 2; i++)
    {
        for (int j = 0; j < x + 2; j++)
        {
            matrix[i][j].visibility=0;
        }
    }
}
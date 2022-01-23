#include "move.h"

void special_JB(struct tile **matrix, int x, int y)
{
    int flag = 1;
    int y_index, x_index;
    char input[10];
    int x_lift, y_lift;
    while (flag == 1)
    {
        printf("Which well would you like to lift? \n");
        for (int i = 0; i < y + 2; i++)
        {
            for (int j = 0; j < x + 2; j++)
            {
                if (matrix[i][j].type == 4)
                {
                    printf("%c%d ", (char)(i + 64), j);
                }
            }
        }
        printf("\n");
        scanf("%s", input);
        y_index = (int)(input[0]) - 64;
        x_index = atoi(input + 1);

        if (matrix[y_index][x_index].type == 4)
        {
            flag = 0;
            y_lift = y_index;
            x_lift = x_index;
            break;
        }
        printf("wrong one!\n");
    }
    flag = 1;
    while (flag == 1)
    {
        printf("Where would you like to put the well ? \n");
        for (int i = 0; i < y + 2; i++)
        {
            for (int j = 0; j < x + 2; j++)
            {

                if (matrix[i][j].type == 3)
                {
                    printf("%c%d ", (char)(i + 64), j);
                }
            }
        }
        printf("\n");
        scanf("%s", input);
        y_index = (int)(input[0]) - 64;
        x_index = atoi(input + 1);
        if (matrix[y_index][x_index].type == 3)
        {

            flag = 0;
            matrix[y_index][x_index].type = 4;
            break;
        }
        printf("wrong one!\n");
    }
    matrix[y_lift][x_lift].type = 3;
}
void special_JS(struct tile **matrix, int x, int y)
{
    int flag = 1;
    int y_index, x_index;
    char input[10];
    int x_lift, y_lift;
    while (flag == 1)
    {
        printf("Which light would you like to turn off? \n");
        for (int i = 0; i < y + 2; i++)
        {
            for (int j = 0; j < x + 2; j++)
            {
                if (matrix[i][j].type == 2)
                {
                    printf("%c%d ", (char)(i + 64), j);
                }
            }
        }
        printf("\n");
        scanf("%s", input);
        y_index = (int)(input[0]) - 64;
        x_index = atoi(input + 1);

        if (matrix[y_index][x_index].type == 2)
        {
            flag = 0;
            y_lift = y_index;
            x_lift = x_index;
            break;
        }
        printf("wrong one!\n");
    }
    flag = 1;
    while (flag == 1)
    {
        printf("Which light would you like to turn on? \n");
        for (int i = 0; i < y + 2; i++)
        {
            for (int j = 0; j < x + 2; j++)
            {

                if (matrix[i][j].type == 5)
                {
                    printf("%c%d ", (char)(i + 64), j);
                }
            }
        }
        printf("\n");
        scanf("%s", input);
        y_index = (int)(input[0]) - 64;
        x_index = atoi(input + 1);
        if (matrix[y_index][x_index].type == 5)
        {

            flag = 0;
            matrix[y_index][x_index].type = 2;
            break;
        }
        printf("wrong one!\n");
    }
    matrix[y_lift][x_lift].type = 5;
}
void special_WG(struct tile **matrix, int x, int y)
{
    char input[10];
    printf("who would you like to change position with ? ");
    scanf("%s", input);
    char temp[10];
    int xrecord, yrecord;
    int x_WG, y_WG;
    for (int i = 0; i < y + 2; i++)
    {
        for (int j = 0; j < x + 2; j++)
        {
            if (strcmp(matrix[i][j].character, input) == 0)
            {
                yrecord = i;
                xrecord = j;
            }
        }
    }
    for (int i = 0; i < y + 2; i++)
    {
        for (int j = 0; j < x + 2; j++)
        {
            if (strcmp(matrix[i][j].character, "WG") == 0)
            {
                y_WG = i;
                x_WG = j;
            }
        }
    }
    strcpy(matrix[yrecord][xrecord].character, "WG");
    strcpy(matrix[y_WG][x_WG].character, input);
}
void special_IL(struct tile **matrix, int x, int y, struct Escape *Gates)
{
    int flag = 1;
    char input[10];
    int store;
    while (flag == 1)
    {
        printf("\nWhat gate would you like to lift ?\n");
        for (int i = 0; i < 4; i++)
        {
            if (Gates[i].mode == 0)
            {
                printf("%s ", Gates[i].place);
            }
        }
        printf("\n");
        scanf("%s", input);
        for (int i = 0; i < 4; i++)
        {
            if (strcmp(input, Gates[i].place) == 0 && Gates[i].mode == 0)
            {
                store = i;
                flag = 0;
            }
        }
        if (flag == 1)
        {
            printf("Wrong input!");
        }
    }
    flag = 1;
    while (flag == 1)
    {
        printf("\nWhat gate would you like to place ?\n");
        for (int i = 0; i < 4; i++)
        {
            if (Gates[i].mode == 1)
            {
                printf("%s ", Gates[i].place);
            }
        }
        printf("\n");
        scanf("%s", input);
        for (int i = 0; i < 4; i++)
        {
            if (strcmp(input, Gates[i].place) == 0 && Gates[i].mode == 1)
            {
                flag = 0;
                matrix[(int)(Gates[i].gate1)[0]-64][atoi(Gates[i].gate1 + 1)].type = 0;
                matrix[(int)(Gates[i].gate2)[0]-64][atoi(Gates[i].gate2 + 1)].type = 0;
            }
        }
        if (flag == 1)
        {
            printf("Wrong input!");
        }
    }
    matrix[(int)(Gates[store].gate1)[0]-64][atoi(Gates[store].gate1 + 1)].type = 1;
    matrix[(int)(Gates[store].gate2)[0]-64][atoi(Gates[store].gate2 + 1)].type = 1;
}
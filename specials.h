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
            x_lift= x_index;
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
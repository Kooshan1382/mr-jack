#include "map.h"
struct position
{
    char y;
    int x;
    struct position *next;
};

struct position *possible_moves(char name[], struct tile **matrix, int x, int y, int move_status)
{
    int xrecord, yrecord;
    for (int i = 0; i < y + 2; i++)
    {
        for (int j = 0; j < x + 2; j++)
        {
            if (strcmp(matrix[i][j].character, name) == 0)
            {
                yrecord = i;
                xrecord = j;
            }
        }
    }
    struct position *head, *current;
    head = current = (struct position *)malloc(sizeof(struct position));
    head->next = NULL;
    if (matrix[yrecord][xrecord + 1].type != 0 || (strcmp(name, "MS") == 0 && move_status != 1))
    {
        current->y = (char)(yrecord + 64);
        current->x = xrecord + 1;
        current->next = (struct position *)malloc(sizeof(struct position));
        current = current->next;
        current->next = NULL;
    }
    if (matrix[yrecord][xrecord - 1].type != 0 || (strcmp(name, "MS") == 0 && move_status != 1))
    {
        current->y = (char)(yrecord + 64);
        current->x = xrecord - 1;
        current->next = (struct position *)malloc(sizeof(struct position));
        current = current->next;
        current->next = NULL;
    }
    if (matrix[yrecord + 1][xrecord].type != 0 || (strcmp(name, "MS") == 0 && move_status != 1))
    {
        current->y = (char)(yrecord + 64 + 1);
        current->x = xrecord;
        current->next = (struct position *)malloc(sizeof(struct position));
        current = current->next;
        current->next = NULL;
    }
    if (matrix[yrecord - 1][xrecord].type != 0 || (strcmp(name, "MS") == 0 && move_status != 1))
    {
        current->y = (char)(yrecord + 64 - 1);
        current->x = xrecord;
        current->next = (struct position *)malloc(sizeof(struct position));
        current = current->next;
        current->next = NULL;
    }
    if (x % 2 == 1)
    {
        if (matrix[yrecord + 1][xrecord + 1].type != 0 || (strcmp(name, "MS") == 0 && move_status != 1))
        {
            current->y = (char)(yrecord + 64 + 1);
            current->x = xrecord + 1;
            current->next = (struct position *)malloc(sizeof(struct position));
            current = current->next;
            current->next = NULL;
        }
        if (matrix[yrecord + 1][xrecord - 1].type != 0 || (strcmp(name, "MS") == 0 && move_status != 1))
        {
            current->y = (char)(yrecord + 64 + 1);
            current->x = xrecord - 1;
            current->next = (struct position *)malloc(sizeof(struct position));
            current = current->next;
            current->next = NULL;
        }
    }
    else
    {
        if (matrix[yrecord - 1][xrecord + 1].type != 0 || (strcmp(name, "MS") == 0 && move_status != 1))
        {
            current->y = (char)(yrecord + 64 - 1);
            current->x = xrecord + 1;
            current->next = (struct position *)malloc(sizeof(struct position));
            current = current->next;
            current->next = NULL;
        }
        if (matrix[yrecord - 1][xrecord - 1].type != 0 || (strcmp(name, "MS") == 0 && move_status != 1))
            ;
        {
            current->y = (char)(yrecord + 64 - 1);
            current->x = xrecord - 1;
            current->next = (struct position *)malloc(sizeof(struct position));
            current = current->next;
            current->next = NULL;
        }
    }
    return head;
}
void move_player(char name[], struct tile **matrix, int x, int y)
{
    int n;
    int status = 0;
    printf("\nhow many steps would you like to move? ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1 && strcmp(name, "MS") == 0)
        {
            status = 1;
        }
        struct position *posibble = possible_moves(name, matrix, x, y, status);
        struct position *current;
        int flag = 1;
        char input[10];
        while (flag == 1)
        {
            char y_index;
            int x_index;
            current = posibble;
            printf("possible step(s) are : ");
            while (current->next != NULL)
            {
                printf("%c%d ", current->y, current->x);
                current = current->next;
            }
            printf("\nwhere would you like to go? ");
            scanf("%s", input);
            y_index = input[0];
            x_index = atoi(input + 1);
            current = posibble;
            while (current->next != NULL)
            {
                if (y_index == current->y && x_index == current->x)
                {
                    flag = 0;
                    break;
                }
                current = current->next;
            }
            if (flag == 1)
            {
                printf("wrong step!\n");
            }
            else
            {
                int xrecord, yrecord;
                for (int i = 0; i < y + 2; i++)
                {
                    for (int j = 0; j < x + 2; j++)
                    {
                        if (strcmp(matrix[i][j].character, name) == 0)
                        {
                            yrecord = i;
                            xrecord = j;
                        }
                    }
                }
                strcpy(matrix[(int)(y_index)-64][x_index].character, name);
                strcpy(matrix[yrecord][xrecord].character, "NA");
            }
        }
    }
}
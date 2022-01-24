#include "specials.h"

char CARDS_for_SH[][10] = {"SH", "JW", "JS", "IL", "MS", "SG", "WG", "JB"};
void inocent_List(struct tile **matrix, int x, int y, char mrjack[10])
{
    int state = if_visible(matrix, x, y, mrjack);
    for (int i = 0; i < y + 2; i++)
    {
        for (int j = 0; j < x + 2; j++)
        {

            for (int k = 0; k < 8; k++)
            {
                if (strcmp(CARDS[k], matrix[i][j].character) == 0)
                {
                    if (matrix[i][j].visibility != state)
                    {
                        inocent[k] = 0;
                    }
                }
            }
        }
    }
}

void SH(struct tile **matrix, int x, int y, char mrjack[10])
{
    move_player("SH", matrix, x, y);
    int flag = 1;
    for (int i = 0; i < 8; i++)
    {
        if (strcmp(mrjack, CARDS_for_SH[i]) == 0)
        {
            strcpy(CARDS_for_SH[i], "\0");
        }
    }
    while (flag == 1)
    {
        srand(clock());
        int random = rand();
        random = random % 8;
        if (strcmp("\0", CARDS_for_SH[random]) != 0)
        {
            printf("%s is not Mr. Jack\n", CARDS_for_SH[random]);
            strcpy(CARDS_for_SH[random], "\0");
            flag = 0;
        }
    }
}

void JB(struct tile **matrix, int x, int y)
{
    printf("\nwhich to do first special or move? \n");
    char input[10];
    scanf("%s", input);
    if (strcmp(input, "special") == 0)
    {
        special_JB(matrix, x, y);
        move_player("JB", matrix, x, y);
    }
    else
    {
        move_player("JB", matrix, x, y);
        special_JB(matrix, x, y);
    }
}
void JS(struct tile **matrix, int x, int y)
{
    printf("\nwhich to do first special or move? \n");
    char input[10];
    scanf("%s", input);
    if (strcmp(input, "special") == 0)
    {
        special_JS(matrix, x, y);
        move_player("JS", matrix, x, y);
    }
    else
    {
        move_player("JS", matrix, x, y);
        special_JS(matrix, x, y);
    }
}
void WG(struct tile **matrix, int x, int y)
{
    printf("\nwhich to do special or move? \n");
    char input[10];
    scanf("%s", input);
    if (strcmp(input, "special") == 0)
    {
        special_WG(matrix, x, y);
    }
    else
    {
        move_player("WG", matrix, x, y);
    }
}
void MS(struct tile **matrix, int x, int y)
{
    move_player("MS", matrix, x, y);
}
void IL(struct tile **matrix, int x, int y, struct Escape *Gates)
{
    printf("\nwhich to do first special or move? \n");
    char input[10];
    scanf("%s", input);
    if (strcmp(input, "special") == 0)
    {
        special_IL(matrix, x, y, Gates);
        move_player("IL", matrix, x, y);
    }
    else
    {
        move_player("IL", matrix, x, y);
        special_IL(matrix, x, y, Gates);
    }
}
void JW(struct tile **matrix, int x, int y)
{
    move_player("JW", matrix, x, y);
    special_JW(matrix, x, y);
}
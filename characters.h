#include "specials.h"

void JB(struct tile **matrix, int x, int y)
{
    printf("\nwhich to do first special or move? \n");
    char input[10];
    scanf("%s", input);
    if (strcmp(input, "special") == 0)
    {
        special_JB(matrix,x,y);
        move_player("JB", matrix, x, y);
    }    
    else
    {
        move_player("JB", matrix, x, y);
        special_JB(matrix,x,y);
    }
}
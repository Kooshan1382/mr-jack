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
void JS(struct tile **matrix, int x, int y)
{
    printf("\nwhich to do first special or move? \n");
    char input[10];
    scanf("%s", input);
    if (strcmp(input, "special") == 0)
    {
        special_JS(matrix,x,y);
        move_player("JS", matrix, x, y);
    }    
    else
    {
        move_player("JS", matrix, x, y);
        special_JS(matrix,x,y);
    }
}
void WG(struct tile **matrix, int x, int y)
{
    printf("\nwhich to do special or move? \n");
    char input[10];
    scanf("%s", input);
    if (strcmp(input, "special") == 0)
    {
        special_WG(matrix,x,y);     
    }    
    else
    {
        move_player("WG", matrix, x, y);
    }
}
void IL(struct tile **matrix, int x, int y,struct Escape * Gates)
{
    printf("\nwhich to do first special or move? \n");
    char input[10];
    scanf("%s", input);
    if (strcmp(input, "special") == 0)
    {
        special_IL(matrix,x,y,Gates);
        move_player("IL", matrix, x, y);
    }    
    else
    {
        move_player("IL", matrix, x, y);
        special_IL(matrix,x,y,Gates);
    }
}
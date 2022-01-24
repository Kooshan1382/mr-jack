#include "characters.h"

void PLAY(char character[], struct tile **matrix, int x, int y, struct Escape *Gates, char mrjack[10])
{
    if (strcmp(character, "JB") == 0)
    {
        JB(matrix, x, y);
    }
    if (strcmp(character, "WG") == 0)
    {
        WG(matrix, x, y);
    }
    if (strcmp(character, "SG") == 0)
    {
        SG(matrix,x,y);
    }
    if (strcmp(character, "MS") == 0)
    {
        MS(matrix, x, y);
    }
    if (strcmp(character, "IL") == 0)
    {
        IL(matrix, x, y, Gates);
    }
    if (strcmp(character, "JS") == 0)
    {
        JS(matrix, x, y);
    }
    if (strcmp(character, "JW") == 0)
    {
        JW(matrix, x, y);
    }
    if (strcmp(character, "SH") == 0)
    {
        SH(matrix, x, y, mrjack);
    }
}
struct Deck
{
    char card[10];
    struct Deck *next;
};

struct seperate_Deck
{
    struct Deck *head1;
    struct Deck *head2;
};

struct seperate_Deck *card_generator()
{
    struct seperate_Deck *Deck;
    Deck = (struct seperate_Deck *)malloc(sizeof(struct seperate_Deck));
    int card_check[8] = {0};
    struct Deck *head, *current;
    head = current = (struct Deck *)malloc(sizeof(struct Deck));
    current->next = NULL;
    for (int i = 0; i < 8; i++)
    {
        int random = 0;
        int flag = 1;
        while (flag == 1)
        {
            srand(clock() + i);
            random = rand();
            random = random % 8;
            if (card_check[random] == 0)
            {
                card_check[random] = 1;
                strcpy(current->card, CARDS[random]);
                current->next = (struct Deck *)malloc(sizeof(struct Deck));
                current = current->next;
                current->next = NULL;
                flag = 0;
            }
        }
    }
    Deck->head1 = head;
    for (int i = 0; i < 3; i++)
    {
        head = head->next;
    }
    Deck->head2 = head->next;
    head->next = (struct Deck *)malloc(sizeof(struct Deck));
    head = head->next;
    head->next = NULL;

    return Deck;
}
int main()
{

    FILE *map;
    FILE *base;
    map = fopen("map.txt", "a+");
    base = fopen("base.txt", "a+");
    int x, y;
    fscanf(base, "%d %d\n", &x, &y);
    struct tile **matrix = LoadMap(base, x, y);
    char *hexagonal = CreateMap(map);
    int win_status = 0;
    struct seperate_Deck *Playable;
    struct Deck *current;
    srand(time(NULL));
    int random = rand();
    random = random % 8;
    char mrjack[10];
    strcpy(mrjack, CARDS[random]);
    printf("Mr Jack is : %s\n", mrjack);
    DisplayMap(hexagonal, matrix, x, y);
    struct Escape *Gates = Load_Escape(base);
    char character[10];
    Clear_Visibility(matrix, x, y);
    for (int i = 0; i < 16 && win_status == 0; i++)
    {
        if (i % 2 == 0)
        {
            Playable = card_generator();
        }
        for (int j = 0; j < 4; j++)
        {

            int flag = 0;
            while (flag == 0)
            {
                if (i % 2 == 0)
                {

                    current = Playable->head1;
                }
                else
                {
                    current = Playable->head2;
                }
                printf("playable cards are : ");
                while (current->next != NULL)
                {
                    if (strcmp(current->card, "\0") != 0)
                    {
                        printf("%s ", current->card);
                    }
                    current = current->next;
                }
                printf("\n");
                printf("who would you like to play with? ");
                scanf("%s", character);
                if (i % 2 == 0)
                {

                    current = Playable->head1;
                }
                else
                {
                    current = Playable->head2;
                }
                while (current->next != NULL)
                {

                    if (strcmp(current->card, character) == 0 && strcmp(current->card, "\0") != 0)
                    {
                        strcpy(current->card, "\0");
                        PLAY(character, matrix, x, y, Gates, mrjack);
                        check_Visibility(matrix, x, y);
                        inocent_List(matrix, x, y, mrjack);
                        //system("cls");
                        DisplayMap(hexagonal, matrix, x, y);
                        
                        flag = 1;
                    }
                    current = current->next;
                }
                if (flag == 0)
                {
                    printf("wrong character!");
                }
            }
        }
    }

    fclose(map);
    fclose(base); 
}
#include "characters.h"

char CARDS[][10] = {"SH", "JW", "JS", "IL", "MS", "SG", "WG", "JB"};

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
    head->next = NULL;

    return Deck;
}
int main()
{
    struct seperate_Deck *Deck;
    srand(time(NULL));
    int random = rand();
    random = random % 8;
    char mrjack[10];
    strcpy(mrjack, CARDS[random]);
    printf("Mr Jack is : %s\n",mrjack);
    
    Deck = card_generator();
    while (Deck->head1 != NULL)
    {
        printf("%s %s\n", Deck->head1->card, Deck->head2->card);
        Deck->head1 = Deck->head1->next;
        Deck->head2 = Deck->head2->next;
    }
    /* FILE *map;
    FILE *base;
    map = fopen("map.txt", "a+");
    base = fopen("base.txt", "a+");
    int x, y;
    fscanf(base, "%d %d\n", &x, &y);
    printf("%d %d\n", x, y);
    struct tile **matrix = LoadMap(base, x, y);
    char *hexagonal = CreateMap(map);
    DisplayMap(hexagonal, matrix, x, y);
    struct Escape *Gates = Load_Escape(base);
    IL(matrix, x, y, Gates);
    system("cls");
    DisplayMap(hexagonal, matrix, x, y);
    fclose(map);
    fclose(base); */
}
#include "characters.h"
void Load(struct tile **matrix, int *xread, int *yread, char mrjack[], struct Escape *Gates)
{
    FILE *save;
    save = fopen("save.txt", "a+b");
    fread(xread, sizeof(int), 1, save);
    fread(yread, sizeof(int), 1, save);
    int x = *xread;
    int y = *yread;
    for (int i = 0; i < y + 2; i++)
    {
        for (int j = 0; j < x + 2; j++)
        {
            fread(&matrix[i][j].type, sizeof(int), 1, save);
        }
    }
    for (int i = 0; i < y + 2; i++)
    {
        for (int j = 0; j < x + 2; j++)
        {
            fread(&matrix[i][j].character, sizeof(char), 3, save);
        }
    }
    for (int i = 0; i < y + 2; i++)
    {
        for (int j = 0; j < x + 2; j++)
        {
            fread(&matrix[i][j].visibility, sizeof(int), 1, save);
        }
    }
    fread(mrjack, sizeof(char), 3, save);
    for (int i = 0; i < 4; i++)
    {
        fread(&Gates[i].place, sizeof(char), 3, save);
        fread(&Gates[i].mode, sizeof(int), 1, save);
        fread(&Gates[i].gate1, sizeof(char), 4, save);
        fread(&Gates[i].gate2, sizeof(char), 4, save);
    }
    fwrite(JW_direction, sizeof(char), 3, save);
    for (int i = 0; i < 8; i++)
    {
        fread(&inocent[i], sizeof(int), 1, save);
    }
    fclose(save);
}
void save(int x, int y, struct tile **matrix, char mrjack[], struct Escape *Gates)
{
    FILE *save;
    save = fopen("save.txt", "w+b");
    fwrite(&x, sizeof(int), 1, save);
    fwrite(&y, sizeof(int), 1, save);

    for (int i = 0; i < y + 2; i++)
    {
        for (int j = 0; j < x + 2; j++)
        {
            fwrite(&matrix[i][j].type, sizeof(int), 1, save);
        }
    }
    for (int i = 0; i < y + 2; i++)
    {
        for (int j = 0; j < x + 2; j++)
        {
            fwrite(&matrix[i][j].character, sizeof(char), 3, save);
        }
    }
    for (int i = 0; i < y + 2; i++)
    {
        for (int j = 0; j < x + 2; j++)
        {
            fwrite(&matrix[i][j].visibility, sizeof(int), 1, save);
        }
    }
    fwrite(mrjack, sizeof(char), 3, save);
    for (int i = 0; i < 4; i++)
    {
        fwrite(&(Gates[i].place), sizeof(char), 3, save);
        fwrite(&(Gates[i].mode), sizeof(int), 1, save);
        fwrite(&(Gates[i].gate1), sizeof(char), 4, save);
        fwrite(&(Gates[i].gate2), sizeof(char), 4, save);
    }
    fwrite(JW_direction, sizeof(char), 3, save);
    for (int i = 0; i < 8; i++)
    {
        fwrite(&inocent[i], sizeof(int), 1, save);
    }
    fclose(save);
}
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
        SG(matrix, x, y);
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
struct Suspect
{
    char character[10];
    struct Suspect *next;
};
struct Suspect *check_arrest(char character[], struct tile **matrix, int x, int y)
{
    int xrecord, yrecord;
    for (int i = 0; i < y + 2; i++)
    {
        for (int j = 0; j < x + 2; j++)
        {
            if (strcmp(character, matrix[i][j].character) == 0)
            {
                yrecord = i;
                xrecord = j;
            }
        }
    }
    struct Suspect *head, *current;
    head = current = (struct Suspect *)malloc(sizeof(struct Suspect));
    current->next = NULL;
    if (strcmp(matrix[yrecord][xrecord + 1].character, "NA") != 0)
    {
        strcpy(current->character, matrix[yrecord][xrecord + 1].character);
        current->next = (struct Suspect *)malloc(sizeof(struct Suspect));
        current = current->next;
        current->next = NULL;
    }
    if (strcmp(matrix[yrecord][xrecord - 1].character, "NA") != 0)
    {
        strcpy(current->character, matrix[yrecord][xrecord - 1].character);
        current->next = (struct Suspect *)malloc(sizeof(struct Suspect));
        current = current->next;
        current->next = NULL;
    }
    if (strcmp(matrix[yrecord - 1][xrecord].character, "NA") != 0)
    {
        strcpy(current->character, matrix[yrecord - 1][xrecord].character);
        current->next = (struct Suspect *)malloc(sizeof(struct Suspect));
        current = current->next;
        current->next = NULL;
    }
    if (strcmp(matrix[yrecord + 1][xrecord].character, "NA") != 0)
    {
        strcpy(current->character, matrix[yrecord + 1][xrecord].character);
        current->next = (struct Suspect *)malloc(sizeof(struct Suspect));
        current = current->next;
        current->next = NULL;
    }
    if (x % 2 == 0)
    {
        if (strcmp(matrix[yrecord - 1][xrecord + 1].character, "NA") != 0)
        {
            strcpy(current->character, matrix[yrecord - 1][xrecord + 1].character);
            current->next = (struct Suspect *)malloc(sizeof(struct Suspect));
            current = current->next;
            current->next = NULL;
        }
        if (strcmp(matrix[yrecord - 1][xrecord - 1].character, "NA") != 0)
        {
            strcpy(current->character, matrix[yrecord - 1][xrecord - 1].character);
            current->next = (struct Suspect *)malloc(sizeof(struct Suspect));
            current = current->next;
            current->next = NULL;
        }
    }
    else
    {
        if (strcmp(matrix[yrecord + 1][xrecord + 1].character, "NA") != 0)
        {
            strcpy(current->character, matrix[yrecord + 1][xrecord + 1].character);
            current->next = (struct Suspect *)malloc(sizeof(struct Suspect));
            current = current->next;
            current->next = NULL;
        }
        if (strcmp(matrix[yrecord + 1][xrecord - 1].character, "NA") != 0)
        {
            strcpy(current->character, matrix[yrecord + 1][xrecord - 1].character);
            current->next = (struct Suspect *)malloc(sizeof(struct Suspect));
            current = current->next;
            current->next = NULL;
        }
    }
    return head;
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
    int turn = 0; //0 for detective and 1 for mr-jack
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
    struct Escape *Gates = Load_Escape(base);

    printf("would you like to play new game or load ? ");

    char choice[10];
    scanf("%s", choice);
    if (strcmp(choice, "Load") == 0)
    {
        Load(matrix, &x, &y, mrjack, Gates);
    }
    printf("Mr Jack is : %s\n", mrjack);
    DisplayMap(hexagonal, matrix, x, y);

    char character[10];

    for (int i = 0; i < 16 && win_status == 0; i++)
    {
        Clear_Visibility(matrix, x, y);
        if (i % 2 == 0)
        {
            if (i != 0)
            {
                printf("would you like to save?\n");
                char choice[10];
                scanf("%s", choice);
                if (strcmp(choice, "yes") == 0)
                {
                    save(x, y, matrix, mrjack, Gates);
                }
            }
            Playable = card_generator();
        }
        for (int j = 0; j < 4 && win_status == 0; j++)
        {
            int flag = 0;
            while (flag == 0)
            {
                if (i % 2 == 0)
                {
                    current = Playable->head1;
                    if (j == 3 || j == 0)
                    {
                        turn = 0;
                    }
                    else
                    {
                        turn = 1;
                    }
                }
                else
                {

                    current = Playable->head2;
                    if (j == 3 || j == 0)
                    {
                        turn = 1;
                    }
                    else
                    {
                        turn = 0;
                    }
                }
                if (turn == 0)
                {
                    printf("Detective's turn\n");
                }
                else
                {
                    printf("Mr Jack's turn\n");
                }
                printf("playable cards are : \n");
                while (current->next != NULL)
                {
                    if (strcmp(current->card, "\0") != 0)
                    {
                        printf("%s ", current->card);
                        Description(current->card);
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
                        if (turn == 0)
                        {
                            struct Suspect *head_suspect;
                            head_suspect = check_arrest(character, matrix, x, y);
                            if (head_suspect->next != NULL)
                            {
                                int flag_print = 1;
                                char arrest[10];
                                while (flag_print == 1)
                                {
                                    printf("You Can Arrest : ");
                                    while (head_suspect->next != NULL)
                                    {
                                        printf("%s ", head_suspect->character);
                                        head_suspect = head_suspect->next;
                                    }
                                    printf("\n");
                                    printf("Input None if you dont want to arrest anybody\n");
                                    scanf("%s",arrest);
                                    if(strcmp(arrest,"None")){
                                        flag=0;
                                    }
                                    head_suspect = check_arrest(character, matrix, x, y);
                                    while(head_suspect->next!=NULL){
                                        if(strcmp(head_suspect->character,arrest)==0){
                                            flag_print=0;
                                            win_status=1;
                                            if(strcmp(arrest,mrjack)==0){
                                                printf("Detective Won!\n");
                                            }
                                            else{
                                                printf("MR JACK WON!\n");
                                            }
                                            
                                        }
                                        head_suspect=head_suspect->next;
                                    }
                                }
                            }
                        }
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
            for (int m = 0; m < 4; m++)
            {
                int ycheck, xcheck;
                ycheck = (int)(Gates[m].gate1[0]) - 64;
                xcheck = atoi(Gates[m].gate1 + 1);
                for (int l = 0; l < y + 2; l++)
                {
                    for (int p = 0; p < x + 2; p++)
                    {
                        if (strcmp(matrix[l][p].character, mrjack) == 0)
                        {
                            if (ycheck == l && xcheck == p)
                            {
                                printf("MR JACK WON!\n");
                                win_status = 1;
                            }
                        }
                    }
                }
                ycheck = (int)(Gates[m].gate2[0]) - 64;
                xcheck = atoi(Gates[m].gate2 + 1);
                for (int l = 0; l < y + 2; l++)
                {
                    for (int p = 0; p < x + 2; p++)
                    {
                        if (strcmp(matrix[l][p].character, mrjack) == 0)
                        {
                            if (ycheck == l && xcheck == p)
                            {
                                printf("MR JACK WON!\n");
                                win_status = 1;
                            }
                        }
                    }
                }
            }
        }

        for (int l = 0; l < y + 2; l++)
        {
            for (int p = 0; p < x + 2; p++)
            {
                if (strcmp(matrix[l][p].character, "JW") == 0)
                {
                    make_visible(matrix, l, p, x, y, JW_direction);
                }
            }
        }
        check_Visibility(matrix, x, y);
        inocent_List(matrix, x, y, mrjack);
    }
    fclose(map);
    fclose(base);
}
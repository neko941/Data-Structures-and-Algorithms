#include <stdio.h>

int choice;
int money;
int value[] = {1, 10, 25, 100};
int value_size = sizeof(value) / sizeof(int);
int table[4][100000];
int result;
char coinType[4][15] = {"pennie(s)", "dime(s)  ", "quater(s)", "dollar(s)"};
int i;
int j;

int min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

void fill_table()
{
    for (i = 0; i < value_size; i++)
    {
        for (j = 1; j <= money; j++)
        {
            if (i == 0)
                table[i][j] = table[i][j - value[i]] + 1;
            else if (j < value[i])
                table[i][j] = table[i - 1][j];
            else
                table[i][j] = min(table[i - 1][j], table[i][j - value[i]] + 1);
        }
    }
}

void num_of_coin()
{
    result = table[value_size - 1][money];
    int kind[4] = {0, 0, 0, 0};
    printf("\nThe smallest amount of coins needed to pay back %d cents: %d", money, result);
    i = value_size - 1;
    j = money;
    while (j > 0)
    {
        if (i != 0 && table[i][j] == table[i - 1][j])
        {
            i = i - 1;
            continue;
        }
        kind[i]++;
        j -= value[i];
    }
    for (i = 0; i < value_size; i++)
    {
        printf("\n%s: %d", coinType[i], kind[i]);
    }
}

void print_table_vertically()
{
    printf("\n\nResult Table:");

    for (i = 0; i <= 40; i++)
    {
        if (i == 0)
        {
            printf("\n\t%c", 218);
        }
        else if (i == 40)
        {
            printf("%c\t\n", 191);
        }
        else if (i % 8 == 0)
        {
            printf("%c", 194);
        }
        else
        {
            printf("%c", 196);
        }
    }
    printf("\t%c0", 179);
    for (i = 0; i < value_size; i++)
    {
        if (i == value_size - 1)
        {
            printf("\t%c%d\t%c", 179, value[i], 179);
            continue;
        }
        printf("\t%c%d", 179, value[i]);
    }
    for (i = 0; i <= 40; i++)
    {
        if (i == 0)
        {
            printf("\n\t%c", 195);
        }
        else if (i == 40)
        {
            printf("%c\t", 180);
        }
        else if (i % 8 == 0)
        {
            printf("%c", 197);
        }
        else
        {
            printf("%c", 196);
        }
    }

    for (i = 0; i < money + 1; i++)
    {
        printf("\n\t%c%d\t", 179, i);
        for (int j = 0; j < value_size; j++)
        {
            if (j == value_size - 1)
            {
                printf("%c%d\t%c", 179, table[j][i], 179);
                continue;
            }
            printf("%c%d\t", 179, table[j][i]);
        }
    }
    for (i = 0; i <= 40; i++)
    {
        if (i == 0)
        {
            printf("\n\t%c", 192);
        }
        else if (i == 40)
        {
            printf("%c\t\n", 217);
        }
        else if (i % 8 == 0)
        {
            if (i == 16)
            {
                printf("%c", 196);
            }
            else
            {
                printf("%c", 193);
            }
        }
        else
        {
            printf("%c", 196);
        }
    }
}

void print_table_horizontally()
{
    printf("\n\nResult Table:");

    printf("\n\t%c", 2522);
    for (i = 1; i < 9 * (money + 1) - (int)((money + 1) / 5 * 3) - 1; i++)
    {
        if (i == 8)
        {
            printf("%c", 194);
            continue;
        }
        printf("%c", 196);
    }
    printf("%c", 191);

    printf("\n\t%c0\t%c0\t", 179, 179);
    for (i = 1; i < money + 1; i++)
    {
        printf("%d\t", i);
    }

    printf("\n\t%c", 195);
    for (i = 1; i < 9 * (money + 1) - (int)((money + 1) / 5 * 3) - 1; i++)
    {
        if (i == 8)
        {
            printf("%c", 197);
            continue;
        }
        printf("%c", 196);
    }
    printf("%c", 180);

    for (i = 0; i < value_size; i++)
    {
        puts("");
        printf("\t%c%d\t", 179, value[i]);
        for (j = 0; j < money + 1; j++)
        {
            if (j == 0)
            {
                printf("%c%d\t", 179, table[i][j]);
                continue;
            }
            printf("%d\t", table[i][j]);
        }
    }

    printf("\n\t%c", 192);
    for (i = 1; i < 9 * (money + 1) - (int)((money + 1) / 5 * 3) - 1; i++)
    {
        if (i == 8)
        {
            printf("%c", 193);
            continue;
        }
        printf("%c", 196);
    }
    printf("%c", 217);
}

implementation()
{
    while (1)
    {
        printf("%c%c%c%c%c%c%c%c%c%c   MENU   %c%c%c%c%c%c%c%c%c%c\n", 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17);
        printf("\t1. Continue\n");
        printf("\t0. Exit\n");
        printf(">> ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            return;
        case 1:
            printf("----------------------");
            printf("\nEnter number of money\n");
            printf(">> ");
            scanf("%d", &money);
            printf("----------------------");

            fill_table();
            num_of_coin();
            if (money < 11)
            {
                print_table_horizontally();
            }
            else
            {
                print_table_vertically();
            }
            printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        }
    }
}

int main()
{
    printf("\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\t\t\t\t\t|Neko941's Coin Change Problem|\n");
    printf("\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    implementation();
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
}

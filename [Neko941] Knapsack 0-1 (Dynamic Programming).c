#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int quantity;
int capacity;
int choice;
int fill_data;
int *weight;
int *value;
int **result;
int result_row;
int result_col;
int i;
int j;
int w;
int k;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void print_result_table()
{
    printf("\n\nResult Table:");
    printf("\n\t%c", 2522);
    for (int i = 1; i < 9 * capacity - (int)(capacity / 5 * 3) - 1; i++)
    {
        if (i == 8)
        {
            printf("%c", 194);
            continue;
        }
        printf("%c", 196);
    }
    printf("%c", 191);

    for (i = 0; i < result_row; i++)
    {
        result[i][0] = i;
        for (int j = 0; j < result_col; j++)
        {
            result[0][j] = j;
        }
    }

    for (i = 0; i < result_row; i++)
    {
        printf("\n\t%c", 179);
        for (j = 0; j < result_col; j++)
        {
            if (j == 1)
            {
                printf("%c%d\t", 179, result[i][j]);
                continue;
            }

            printf("%d\t", result[i][j]);
        }
        if (i == 0)
        {
            printf("\n\t%c", 195);
            for (int i = 1; i < 9 * capacity - (int)(capacity / 5 * 3) - 1; i++)
            {
                if (i == 8)
                {
                    printf("%c", 197);
                    continue;
                }
                printf("%c", 196);
            }
            printf("%c", 180);
        }
    }

    printf("\n\t%c", 192);
    for (int i = 1; i < 9 * capacity - (int)(capacity / 5 * 3) - 1; i++)
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

void knapsack()
{
    for (i = 0; i < result_row; i++)
    {
        for (w = 0; w < result_col; w++)
        {
            if (i == 0 || w == 0)
            {
                result[i][w] = 0;
            }

            else if (weight[i - 1] <= w)
            {
                result[i][w] = max(value[i - 1] + result[i - 1][w - weight[i - 1]], result[i - 1][w]);
            }

            else
            {
                result[i][w] = result[i - 1][w];
            }
        }
    }
    printf("\n\nOptimal Solution Value: %d", result[quantity][capacity]);
    printf("\nOptimal Solution: ");
    k = capacity;
    for (i = quantity; i >= 0; i--)
    {
        if (i != 0)
        {
            if (result[i][k] != result[i - 1][k])
            {
                printf("%d\t", i);
                k -= weight[i - 1];
            }
        }
        else // i == 0
            if (result[i][k] != 0)
            printf("%d\t", i);
    }
}

void print_data_table()
{
    printf("\nData Table:");
    printf("\n\t%c", 2522);
    for (int i = 1; i < 9 * quantity - (int)(quantity / 5 * 3) - 1; i++)
    {
        if (i == 8)
        {
            printf("%c", 194);
            continue;
        }
        printf("%c", 196);
    }
    printf("%c", 191);

    printf("\n\t%ci\t%c", 179, 179);
    for (i = 1; i < quantity + 1; i++)
    {
        if (i == quantity)
        {
            printf("%d", i);
            continue;
        }
        printf("%d\t", i);
    }

    printf("\n\t%c", 195);
    for (int i = 1; i < 9 * quantity - (int)(quantity / 5 * 3) - 1; i++)
    {
        if (i == 8)
        {
            printf("%c", 197);
            continue;
        }
        printf("%c", 196);
    }
    printf("%c", 180);

    printf("\n\t%cWeight\t%c", 179, 179);
    for (i = 0; i < quantity; i++)
    {
        if (i == quantity - 1)
        {
            printf("%d", weight[i]);
            continue;
        }
        printf("%d\t", weight[i]);
    }

    printf("\n\t%cValue\t%c", 179, 179);
    for (i = 0; i < quantity; i++)
    {
        if (i == quantity - 1)
        {
            printf("%d", value[i]);
            continue;
        }
        printf("%d\t", value[i]);
    }

    printf("\n\t%c", 192);
    for (int i = 1; i < 9 * quantity - (int)(quantity / 5 * 3) - 1; i++)
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

void initializer_data()
{
    result_row = quantity + 1;
    result_col = capacity + 1;

    result = (int **)malloc(result_row * sizeof(int *));
    for (i = 0; i < result_col; i++)
        result[i] = (int *)malloc((capacity + 1) * sizeof(int));

    value = malloc(quantity);
    weight = malloc(quantity);
}

void request()
{
    printf("Quantity: ");
    scanf("%d", &quantity);
    printf("Capacty : ");
    scanf("%d", &capacity);
}

void fill_table()
{
    switch (fill_data)
    {
    case 1:
        quantity = 6;
        capacity = 10;

        initializer_data();

        weight[0] = 3;
        weight[1] = 2;
        weight[2] = 6;
        weight[3] = 1;
        weight[4] = 7;
        weight[5] = 4;
        value[0] = 7;
        value[1] = 10;
        value[2] = 2;
        value[3] = 3;
        value[4] = 2;
        value[5] = 6;

        print_data_table();
        knapsack();
        print_result_table();
        break;

    case 2:
        request();
        initializer_data();

        for (i = 0; i < quantity; i++)
        {
            printf("\nweight[%d] = ", i);
            scanf("%d", &weight[i]);
            printf("value[%d]  = ", i);
            scanf("%d", &value[i]);
        }

        print_data_table();
        knapsack();
        print_result_table();
        break;

    case 3:
        request();
        initializer_data();

        srand(time(NULL));
        for (i = 0; i < quantity; i++)
        {
            weight[i] = rand() % 10;
            value[i] = rand() % 10;
        }

        print_data_table();
        knapsack();
        print_result_table();
        break;
    }
}

void implementation()
{
    while (1)
    {
        printf("%c%c%c%c%c%c%c%c%c%c   MENU   %c%c%c%c%c%c%c%c%c%c\n", 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17);
        printf("\t1. Continue\n");
        printf("\t0. Exit\n");
        printf(">> ");
        scanf("%d", &choice);
        printf("----------------------");

        switch (choice)
        {
        case 0:
            return;
        case 1:
            printf("\nFill data:\n");
            printf("\t1. Default\n");
            printf("\t2. Manual\n");
            printf("\t3. Random\n");
            printf(">> ");
            scanf("%d", &fill_data);
            printf("----------------------");

            fill_table();

            printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        }
    }
}

int main()
{
    printf("\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\t\t\t\t\t|Neko941's Knapsack Problem|\n");
    printf("\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    implementation();

    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
}

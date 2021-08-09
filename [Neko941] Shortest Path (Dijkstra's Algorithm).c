#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define INFINITY 9999
#define MAX 100

int graph[MAX][MAX];
int cost[MAX][MAX];
int distance[MAX];
int predecessor[MAX];
int visited[MAX];
int count;
int min_distance;
int nextnode;
int i;
int j;
int startnode;
int num_vertices;
int fill_data;

void dijkstra()
{
    for (i = 0; i < num_vertices; i++)
    {
        for (j = 0; j < num_vertices; j++)
        {
            if (graph[i][j] == 0)
            {
                cost[i][j] = INFINITY;
            }
            else
            {
                cost[i][j] = graph[i][j];
            }
        }
    }

    for (i = 0; i < num_vertices; i++)
    {
        distance[i] = cost[startnode][i];
        predecessor[i] = startnode;
        visited[i] = 0;
    }

    distance[startnode] = 0;
    visited[startnode] = 1;
    count = 0;

    while (count < num_vertices)
    {
        min_distance = INFINITY;
        for (i = 0; i < num_vertices; i++)
        {
            if (distance[i] < min_distance && !visited[i])
            {
                min_distance = distance[i];
                nextnode = i;
            }
        }
        visited[nextnode] = 1;
        for (i = 0; i < num_vertices; i++)
        {
            if (!visited[i])
            {
                if (min_distance + cost[nextnode][i] < distance[i])
                {
                    distance[i] = min_distance + cost[nextnode][i];
                    predecessor[i] = nextnode;
                }
                count++;
            }
        }
    }
}

void print_result()
{
    printf("\nResult Table:");

    for (i = 0; i < 40; i++)
    {
        if (i == 0)
        {
            printf("\n\t%c", 218);
        }
        else if (i == 8 || i == 16)
        {
            printf("%c", 194);
            continue;
        }
        else if (i == 39)
        {
            printf("%c", 191);
        }
        else
        {
            printf("%c", 196);
        }
    }

    printf("\n\t%cNode\t%cResult\t%cPath", 179, 179, 179);

    for (i = 0; i < 40; i++)
    {
        if (i == 0)
        {
            printf("\n\t%c", 195);
        }
        else if (i == 8 || i == 16)
        {
            printf("%c", 197);
            continue;
        }
        else if (i == 39)
        {
            printf("%c", 180);
        }
        else
        {
            printf("%c", 196);
        }
    }

    for (i = 0; i < num_vertices; i++)
    {
        printf("\n\t%c%d", 179, i);
        printf("\t%c%d\t%c", 179, distance[i], 179);
        j = i;
        printf("%d", i);
        while (j != startnode)
        {
            j = predecessor[j];
            printf(" %c %d", 27, j);
        }
    }

    for (i = 0; i < 40; i++)
    {
        if (i == 0)
        {
            printf("\n\t%c", 192);
        }
        else if (i == 8 || i == 16)
        {
            printf("%c", 193);
            continue;
        }
        else if (i == 39)
        {
            printf("%c", 217);
        }
        else
        {
            printf("%c", 196);
        }
    }
}

void print_data()
{
    printf("Data Table:");

    for (i = 0; i < 8 * (num_vertices + 1); i++)
    {
        if (i == 0)
        {
            printf("\n\t%c", 218);
        }
        else if (i == 8)
        {
            printf("%c", 194);
            continue;
        }
        else if (i == 8 * (num_vertices + 1) - 1)
        {
            printf("%c", 191);
        }
        else
        {
            printf("%c", 196);
        }
    }

    printf("\n\t%c\t", 179);
    for (i = 0; i < num_vertices; i++)
    {
        if (i == 0)
        {
            printf("%c%d\t", 179, i);
        }
        else
        {
            printf(" %d\t", i);
        }
    }

    for (i = 0; i < 8 * (num_vertices + 1); i++)
    {
        if (i == 0)
        {
            printf("\n\t%c", 195);
        }
        else if (i == 8)
        {
            printf("%c", 197);
            continue;
        }
        else if (i == 8 * (num_vertices + 1) - 1)
        {
            printf("%c", 180);
        }
        else
        {
            printf("%c", 196);
        }
    }

    for (i = 0; i < num_vertices; i++)
    {
        printf("\n\t%c%d\t", 179, i);
        for (j = 0; j < num_vertices; j++)
        {
            if (j == 0)
            {
                printf("%c%d\t", 179, graph[i][j]);
            }
            else
            {
                printf(" %d\t", graph[i][j]);
            }
        }
    }

    for (int i = 0; i < 8 * (num_vertices + 1); i++)
    {
        if (i == 0)
        {
            printf("\n\t%c", 192);
        }
        else if (i == 8)
        {
            printf("%c", 193);
            continue;
        }
        else if (i == 8 * (num_vertices + 1) - 1)
        {
            printf("%c", 217);
        }
        else
        {
            printf("%c", 196);
        }
    }
}

void implementation()
{
    while (1)
    {
        printf("%c%c%c%c%c%c%c%c%c%c   MENU   %c%c%c%c%c%c%c%c%c%c\n", 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17);
        printf("\t1. Default (9v - Undirected)\n");
        printf("\t2. Default (5v - Directed)\n");
        printf("\t3. Manual\n");
        printf("\t4. Random (Undirected)\n");
        printf("\t5. Random (Directed)\n");
        printf("\t0. Exit\n");
        printf(">> ");
        scanf("%d", &fill_data);
        printf("----------------------\n");

        switch (fill_data)
        {
        case 0:
            return;
        case 1:
            num_vertices = 9;

            graph[0][1] = 4;
            graph[0][7] = 8;
            graph[1][0] = 4;
            graph[1][2] = 8;
            graph[1][7] = 11;
            graph[2][1] = 8;
            graph[2][3] = 7;
            graph[2][5] = 4;
            graph[2][8] = 2;
            graph[3][2] = 7;
            graph[3][4] = 9;
            graph[3][5] = 14;
            graph[4][3] = 9;
            graph[4][5] = 10;
            graph[5][2] = 4;
            graph[5][3] = 14;
            graph[5][4] = 10;
            graph[5][6] = 2;
            graph[6][5] = 2;
            graph[6][7] = 1;
            graph[6][8] = 6;
            graph[7][0] = 8;
            graph[7][1] = 11;
            graph[7][6] = 1;
            graph[7][8] = 7;
            graph[8][2] = 2;
            graph[8][6] = 6;
            graph[8][7] = 7;

            print_data();

            printf("\n\nEnter the starting node:\n>> ");
            scanf("%d", &startnode);
            dijkstra();
            print_result();
            break;
        case 2:
            num_vertices = 5;

            graph[0][1] = 10; // s -> t
            graph[0][2] = 5; // s -> y
            graph[1][3] = 1; // t -> x
            graph[1][2] = 2; // t -> y
            graph[3][4] = 4; // x -> z
            graph[2][1] = 3; // y -> t
            graph[2][3] = 9; // y -> x
            graph[2][4] = 2; // y -> z
            graph[4][3] = 6; // z ->
            graph[4][0] = 7; // z -> s

            print_data();

            printf("\n\nEnter the starting node:\n>> ");
            scanf("%d", &startnode);
            dijkstra();
            print_result();
            break;
        case 3:
            printf("Enter number of vertices:\n>> ");
            scanf("%d", &num_vertices);

            for (i = 0; i < num_vertices; i++)
            {
                for (j = 0; j < num_vertices; j++)
                {
                    printf("graph[%d][%d] = ", i, j);
                    scanf("%d", &graph[i][j]);
                }
            }

            print_data();

            printf("\n\nEnter the starting node:\n>> ");
            scanf("%d", &startnode);
            dijkstra();
            print_result();
            break;
        case 4:
            printf("Enter number of vertices:\n>> ");
            scanf("%d", &num_vertices);

            srand(time(NULL));
            for (i = 0; i < num_vertices; i++)
            {
                for (j = 0; j < num_vertices; j++)
                {
                    if (i == j)
                    {
                        graph[i][j] = 0;
                    }
                    else
                    {
                        graph[i][j] = graph[j][i] = rand() % 10;
                    }
                }
            }

            print_data();

            printf("\n\nEnter the starting node:\n>> ");
            scanf("%d", &startnode);
            dijkstra();
            print_result();
            break;
        case 5:
            printf("Enter number of vertices:\n>> ");
            scanf("%d", &num_vertices);

            srand(time(NULL));
            for (i = 0; i < num_vertices; i++)
            {
                for (j = 0; j < num_vertices; j++)
                {
                    if (i == j)
                    {
                        graph[i][j] = 0;
                    }
                    else
                    {
                        graph[i][j] = rand() % 10;
                    }
                }
            }

            print_data();

            printf("\n\nEnter the starting node:\n>> ");
            scanf("%d", &startnode);
            dijkstra();
            print_result();
            break;
        }
        printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    }
}

int main()
{
    printf("\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\t\t\t\t\t|Neko941's Shortest Path (Dijkstra's Algraphorithm)|\n");
    printf("\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    implementation();

    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
}

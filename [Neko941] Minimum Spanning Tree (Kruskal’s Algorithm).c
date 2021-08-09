#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int choice;
int num_vertices;
int num_edges;
struct Graph *graph;
int lower = 0;
int upper = 20;
int i;
int j;
int e;
int v;

struct Edge
{
    int source;
    int destination;
    int weight;
};

struct Graph
{
    int num_vertices;
    int num_edges;
    struct Edge *edge;
};

struct Graph *create_graph(int num_vertices, int num_edges)
{
    struct Graph *graph = (struct Graph *)(malloc(sizeof(struct Graph)));
    graph->num_vertices = num_vertices;
    graph->num_edges = num_edges;

    graph->edge = (struct Edge *)malloc(sizeof(struct Edge) * num_edges);

    return graph;
}

struct subset
{
    int parent;
    int rank;
};

void print_table(struct Graph *graph)
{
    for (i = 0; i <= 32; i++)
    {
        if (i == 0)
        {
            printf("\n\t%c", 218);
        }
        else if (i == 32)
        {
            printf("%c\t\n", 191);
        }
        else if (i % 8 == 0)
        {
            if (i == 16)
            {
                printf("%c", 196);
            }
            else
            {
                printf("%c", 194);
            }
        }
        else
        {
            printf("%c", 196);
        }
    }

    printf("\t%cSource\t%cDestination\t%cWeight\t%c", 179, 179, 179, 179);

    for (i = 0; i <= 32; i++)
    {
        if (i == 0)
        {
            printf("\n\t%c", 195);
        }
        else if (i == 32)
        {
            printf("%c\t", 180);
        }
        else if (i % 8 == 0)
        {
            if (i == 16)
            {
                printf("%c", 196);
            }
            else
            {
                printf("%c", 197);
            }
        }
        else
        {
            printf("%c", 196);
        }
    }

    for (i = 0; i < num_edges; i++)
    {
        if (graph->edge[i].weight > lower && graph->edge[i].weight < upper)
        {
            printf("\n\t%c%d\t%c%d\t\t%c%d\t%c", 179, graph->edge[i].source, 179, graph->edge[i].destination, 179, graph->edge[i].weight, 179);
        }
    }

    for (i = 0; i <= 32; i++)
    {
        if (i == 0)
        {
            printf("\n\t%c", 192);
        }
        else if (i == 32)
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

    puts("");
}

void sort(struct Graph *graph)
{
    struct Edge temp;

    for (i = 0; i < num_edges; i++)
    {
        for (j = 0; j < num_edges - i - 1; j++)
        {
            if (graph->edge[j].weight > graph->edge[j + 1].weight)
            {
                temp = graph->edge[j];
                graph->edge[j] = graph->edge[j + 1];
                graph->edge[j + 1] = temp;
            }
        }
    }
}

int find(struct subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;

    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

void MST_Kruskal(struct Graph *graph)
{
    struct Graph *result = create_graph(graph->num_vertices, graph->num_edges);

    sort(graph);
    printf("Sorted Data Table:");
    print_table(graph);

    struct subset *subsets = (struct subset *)malloc(graph->num_vertices * sizeof(struct subset));

    for (v = 0; v < graph->num_vertices; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    e = 0;
    i = 0;
    while (e < graph->num_vertices - 1 && i < graph->num_edges)
    {
        struct Edge next_edge = graph->edge[i++];

        int x = find(subsets, next_edge.source);
        int y = find(subsets, next_edge.destination);

        if (x != y)
        {
            result->edge[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    int minimumCost = 0;
    printf("Minimum Spanning Tree:");
    print_table(result);
    for (int i = 0; i < graph->num_vertices; i++)
    {
        if (result->edge[i].weight > lower && result->edge[i].weight < upper)
        {
            minimumCost += result->edge[i].weight;
        }
    }
    printf("Minimum Cost: %d", minimumCost);
}

void implementation()
{
    while (1)
    {
        printf("%c%c%c%c%c%c%c%c%c%c   MENU   %c%c%c%c%c%c%c%c%c%c\n", 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17);
        printf("\t1. Default 1 (4v-5e)\n");
        printf("\t2. Default 2 (9v-14e)\n");
        printf("\t3. Default 3 (8v-14e)\n");
        printf("\t4. Manual\n");
        printf("\t0. Exit\n");
        printf(">> ");
        scanf("%d", &choice);
        printf("----------------------");

        switch (choice)
        {
        case 0:
            return;
        case 1:
            num_vertices = 4;
            num_edges = 5;
            graph = create_graph(num_vertices, num_edges);

            // edge 0-1
            graph->edge[0].source = 0;
            graph->edge[0].destination = 1;
            graph->edge[0].weight = 10;

            // edge 0-2
            graph->edge[1].source = 0;
            graph->edge[1].destination = 2;
            graph->edge[1].weight = 6;

            // edge 0-3
            graph->edge[2].source = 0;
            graph->edge[2].destination = 3;
            graph->edge[2].weight = 5;

            // edge 1-3
            graph->edge[3].source = 1;
            graph->edge[3].destination = 3;
            graph->edge[3].weight = 15;

            // edge 2-3
            graph->edge[4].source = 2;
            graph->edge[4].destination = 3;
            graph->edge[4].weight = 4;

            printf("\nData Table:");
            print_table(graph);
            MST_Kruskal(graph);
            break;

        case 2:
            num_vertices = 9;
            num_edges = 14;
            graph = create_graph(num_vertices, num_edges);

            // 0-1
            graph->edge[0].source = 0;
            graph->edge[0].destination = 1;
            graph->edge[0].weight = 4;

            // 0-7
            graph->edge[1].source = 0;
            graph->edge[1].destination = 7;
            graph->edge[1].weight = 8;

            // 1-2
            graph->edge[2].source = 1;
            graph->edge[2].destination = 2;
            graph->edge[2].weight = 8;

            // 1-7
            graph->edge[3].source = 1;
            graph->edge[3].destination = 7;
            graph->edge[3].weight = 11;

            // 2-3
            graph->edge[4].source = 2;
            graph->edge[4].destination = 3;
            graph->edge[4].weight = 7;

            // 2-8
            graph->edge[5].source = 2;
            graph->edge[5].destination = 8;
            graph->edge[5].weight = 2;

            // 2-5
            graph->edge[6].source = 2;
            graph->edge[6].destination = 5;
            graph->edge[6].weight = 4;

            // 3-4
            graph->edge[7].source = 3;
            graph->edge[7].destination = 4;
            graph->edge[7].weight = 9;

            // 3-5
            graph->edge[8].source = 3;
            graph->edge[8].destination = 5;
            graph->edge[8].weight = 14;

            // 4-5
            graph->edge[9].source = 4;
            graph->edge[9].destination = 5;
            graph->edge[9].weight = 10;

            // 5-6
            graph->edge[10].source = 5;
            graph->edge[10].destination = 6;
            graph->edge[10].weight = 2;

            // 6-7
            graph->edge[11].source = 6;
            graph->edge[11].destination = 7;
            graph->edge[11].weight = 1;

            // 6-8
            graph->edge[12].source = 6;
            graph->edge[12].destination = 8;
            graph->edge[12].weight = 6;

            // 7-8
            graph->edge[13].source = 7;
            graph->edge[13].destination = 8;
            graph->edge[13].weight = 7;

            printf("\nData Table:");
            print_table(graph);
            MST_Kruskal(graph);
            free(graph);
            break;
        case 3:
            num_vertices = 8;
            num_edges = 14;
            graph = create_graph(num_vertices, num_edges);

            // A-C
            graph->edge[0].source = 0;
            graph->edge[0].destination = 2;
            graph->edge[0].weight = 5;
            // A-B
            graph->edge[1].source = 0;
            graph->edge[1].destination = 1;
            graph->edge[1].weight = 12;
            //A-D
            graph->edge[2].source = 0;
            graph->edge[2].destination = 3;
            graph->edge[2].weight = 4;
            //B-D
            graph->edge[3].source = 1;
            graph->edge[3].destination = 3;
            graph->edge[3].weight = 11;
            //B-C
            graph->edge[4].source = 1;
            graph->edge[4].destination = 2;
            graph->edge[4].weight = 9;
            //C-D
            graph->edge[5].source = 2;
            graph->edge[5].destination = 3;
            graph->edge[5].weight = 2;
            //C-F
            graph->edge[6].source = 2;
            graph->edge[6].destination = 5;
            graph->edge[6].weight = 4;
            //D-G
            graph->edge[7].source = 3;
            graph->edge[7].destination = 6;
            graph->edge[7].weight = 1;
            //E-C
            graph->edge[8].source = 4;
            graph->edge[8].destination = 2;
            graph->edge[8].weight = 2;
            //E-D
            graph->edge[9].source = 4;
            graph->edge[9].destination = 3;
            graph->edge[9].weight = 7;
            //E-H
            graph->edge[10].source = 4;
            graph->edge[10].destination = 7;
            graph->edge[10].weight = 6;
            //E-G
            graph->edge[11].source = 4;
            graph->edge[11].destination = 6;
            graph->edge[11].weight = 3;
            //F-G
            graph->edge[12].source = 5;
            graph->edge[12].destination = 6;
            graph->edge[12].weight = 8;
            //F-H
            graph->edge[13].source = 5;
            graph->edge[13].destination = 7;
            graph->edge[13].weight = 1;

            printf("\nData Table:");
            print_table(graph);
            MST_Kruskal(graph);
            free(graph);
            break;
        case 4:
            printf("\nEnter number of vertices:\n>> ");
            scanf("%d", &num_vertices);

            printf("Enter number of edges:\n>> ");
            scanf("%d", &num_edges);

            graph = create_graph(num_vertices, num_edges);

            for (i = 0; i < num_edges; i++)
            {
                printf("graph->edge[%d].source      = ", i);
                scanf("%d", &graph->edge[i].source);
                printf("graph->edge[%d].destination = ", i);
                scanf("%d", &graph->edge[i].destination);
                printf("graph->edge[%d].weight      = ", i);
                scanf("%d", &graph->edge[i].weight);
                puts("");
            }
            printf("\nData Table:");
            print_table(graph);
            MST_Kruskal(graph);
            free(graph);
        }

        printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    }
}

int main()
{
    printf("\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\t\t\t\t\t|Neko941's Minimum Spanning Tree (Kruskal's Algorithm)|\n");
    printf("\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    implementation();

    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
}

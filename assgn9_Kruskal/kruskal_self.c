#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
int n;
int graph[10][10];

typedef struct Edge
{
    int v1;
    int v2;
    int wt;
} edge;
int parent[4];

int simpleFind(int p[], int v){
    if (p[v]==v)
    {
        return v;
    }
    p[v]=simpleFind(p,p[v]);
}
void simpleunion(int p[], int v1, int v2){
    
    int u=simpleFind(p,v1);
    int v=simpleFind(p,v2);
    p[u]=v;
}
void swap(edge *a, edge *b)
{
    edge temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
edge elist[10];
edge mstSet[10];
void readGraph()
{
    FILE *fp;
    fp = fopen("test.txt", "r");
    if (fp == NULL)
    {
        printf("\nError to open the file\n");
        exit(1);
    }
    fscanf(fp, "%d", &n);
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            fscanf(fp, "%d", &graph[i][j]);
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%3d", graph[i][j]);
        }
        printf("\n");
    }
    fclose(fp);
}
// Edge count
int count = 0;
void addEdge()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] > 0)
            {
                elist[count].v1 = i;
                elist[count].v2 = j;
                elist[count].wt = graph[i][j];
                count++;
            }
        }
    }
}
void bubbleSort(edge a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (n - i - 1); j++)
        {
            if (a[j].wt > a[j + 1].wt)
            {
                swap(&a[j], &a[j + 1]);
            }
        }
    }
}

int mstcount=0;
void kruskal(){
    for (int i = 0; i < n; i++)
    {
        parent[i]=i;
    }
    for (int i = 0; i < count; i++)
    {
        printf("v1: %c; v2: %c\n",simpleFind(parent,elist[i].v1)+'A',simpleFind(parent,elist[i].v2)+'A');
        //printf("v1: %c; v2: %c\n",elist[i].v1+'A',elist[i].v2+'A');
        if (simpleFind(parent,elist[i].v1)!=simpleFind(parent,elist[i].v2))
        {
            //printf("Iteration caught: %d\n",i);
            mstSet[mstcount].v1=elist[i].v1;
            mstSet[mstcount].v2=elist[i].v2;
            mstSet[mstcount].wt=elist[i].wt;
            mstcount++;
            simpleunion(parent,elist[i].v1,elist[i].v2);
        }   
    }
}
void showEdge(edge a[],int c)
{
    for (int i = 0; i < c; i++)
    {
        printf("(%c,%c)->%d\n", a[i].v1+'A', a[i].v2+'A', a[i].wt);
    }
}
int main(void)
{
    
    readGraph();
    addEdge();
    bubbleSort(elist, count);
    printf("All Edges in sorted order:\n");
    showEdge(elist,count);
    kruskal();
    printf("MST Edges:\n");
    showEdge(mstSet,mstcount);
    int mstCost=0;
    for (int i = 0; i < mstcount; i++)
    {
        mstCost+=mstSet[i].wt;
    }
    printf("MST Cost: %d\n",mstCost);
    //printf("\nmst%d,%d,%d",mstSet[0].v1,mstSet[0].v2,mstSet[0].wt);
    //printf("\nmstcount:%d\n",mstcount);
    return 0;
}

//Status: Complete

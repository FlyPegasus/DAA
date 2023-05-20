#include<stdio.h>


//Simple Find function finds the ultimate parent of the vertex.
int simpleFind(int p[], int v){
    if (p[v]==v)
    {
        return v;
    }
    p[v]=simpleFind(p,p[v]);
}
//Simple union connects two vertices to the same parent vertex. 
void simpleunion(int p[], int v1, int v2){
    int u=simpleFind(p,v1);
    int v=simpleFind(p,v2);
    p[u]=v;
}

int main(void){
    int n;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    int parent[n];
    //Parent initialisation; each vertex is its own parent
    for (int i = 0; i < n; i++)
    {
        parent[i]=i;
    }
    int a;
    printf("Enter vertex: ");
    scanf("%d",&a);
    /*
    simpleunion(parent,1,2);
    simpleunion(parent,2,3);
    simpleunion(parent,4,5);
    simpleunion(parent,6,7);
    simpleunion(parent,4,7);
    */
    printf("Parent of %d is %d\n",a,simpleFind(parent,a));
    printf("Enter vertex: ");
    scanf("%d",&a);
    printf("Parent of %d is %d\n",a,simpleFind(parent,a));
    for (int i = 0; i < n; i++)
    {
        printf("%3d",parent[i]);
    }
    printf("\n");
    return 0;
}

//Status: Complete(While loop implementation left.)
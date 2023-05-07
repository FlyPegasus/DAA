#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 9999
int g=5;
int noedge=9;


//Edge set constructor
struct Edgeset
{
    int v1;
    int v2;
    int weight;
};

struct Dijkstra
{
    int dist;
    int pred;
    bool sptset;
};


//Egde counter
int edge_counter(int arr[g][g],int g){
	int count=0;
	for(int i=0;i<g;i++){
		for(int j=0;j<g;j++){
			if(arr[i][j]>0){
				count++;
			}
		}
	}
	return count;
}
//Make edge array
void edgearr(int arr[g][g],struct Edgeset edges[noedge],int g){
    int count=0;
	for(int i=0;i<g;i++){
		for(int j=0;j<g;j++){
			if(arr[i][j]>0){
				edges[count].v1=i;
                edges[count].v2=j;
                edges[count].weight=arr[i][j];
                count++;
			}
		}
	}
}
//Print edge array
void display(struct Edgeset edges[noedge],int noedge){
    for (int i = 0; i < noedge; i++)
    {
        printf("(%c,%c) --> %d\n",edges[i].v1+'A',edges[i].v2+'A',edges[i].weight);
    }
    
}

//Initialisation
void init(struct Dijkstra best[g],int n){
    for (int i = 0; i < n; i++)
    {
        best[i].dist=MAX;
        best[i].pred=NULL;
        best[i].sptset=false;
    }
    
}

void displayD(struct Dijkstra best[g],int n){
    for (int i = 0; i < n; i++)
    {
        printf("Distance from source to %c is %d, pred is %c, sptset is %d\n",i+'A',best[i].dist,best[i].pred+'A',best[i].sptset);
    }
}
//Shortest path updater
void dijkstra(struct Edgeset edges[noedge],struct Dijkstra best[g],int arr[g][g],int n){
    best[0].dist=0;
    
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j]>0 && arr)
            {
                /* code */
            }
            
        }
        
    }
    
}


int main(void){
    FILE *fp;
	fp=fopen("dread.txt","r");
	if(fp==NULL){
		printf("\nError to open the file\n");
		exit(1);
	}
	int n;
	fscanf(fp,"%d",&n);
	int graph[n][n];
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			fscanf(fp,"%d",&graph[i][j]);
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%3d",graph[i][j]);
		}
		printf("\n");
	}
	fclose(fp);
    int noe=edge_counter(graph,5);
    printf("Number of edges is: %d\n",noe);
    struct Edgeset edges[noe];
    struct Dijkstra best[5];
    edgearr(graph,edges,5);
    display(edges,9);
    init(best,5);
    displayD(best,5);
    //dijkstra(0);
    return 0;
}
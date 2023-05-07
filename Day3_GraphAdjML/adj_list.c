#include<stdio.h>
#include<stdlib.h>
int g=4;
int graph[4][4];
void readGraph(int graph[g][g]){
	FILE *fp;
	fp=fopen("Ex.txt","r");
	if(fp==NULL){
		printf("\nError to open the file\n");
		exit(1);
	}
	int n;
	fscanf(fp,"%d",&n);
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			fscanf(fp,"%d",&graph[i][j]);
		}
	}
	
	fclose(fp);
}
void display(){
	for(int i=0;i<g;i++){
		for(int j=0;j<g;j++){
			printf("%3d",graph[i][j]);
		}
		printf("\n");
	}
}

struct Node{
	int vertex;
	struct Node* next;
};

struct Node* v[4];

void makeAdj(){
	for(int i=0;i<g;i++){
		for(int j=0;j<g;j++){
			if (graph[i][j]==1)
			{
				v[i]->vertex=j;
			}
			
		}
		printf("\n");
	}
}

int main(){
	readGraph(graph);
	for (int i = 0; i < g; i++)
	{
		v[i]=NULL;
	}
	
	display();
	return 0;
}

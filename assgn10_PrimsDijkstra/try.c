#include<stdio.h>
#include<stdlib.h>
#define MAX 9999

int v=6;

int key[6];
int parent[6];
int mstSet[6];

void Prims(){
    for (int i = 0; i < v; i++)
    {
        key[i]=MAX;
        parent[i]=NULL;
        mstSet[i]=0;
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
}
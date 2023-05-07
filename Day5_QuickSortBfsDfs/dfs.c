/*
DFS or Depth First Search traversal uses the backtracking method to traverse the graph until it reaches
the leaf vertex of the graph
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int mat[10][10];
bool visited[10];//array to keep track of visited vertices
int n;
void readGraph(){
    FILE *fp; //pointer to file
    fp=fopen("read.txt","r");
    if(fp==NULL){
        printf("\nError to open the file\n");
        exit(1);
    }
    //Reading a number from the file
    //int n;
    fscanf(fp,"%d",&n);
    //printf("\nThe number in the file is %d.\n",n);
    int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			fscanf(fp,"%d",&mat[i][j]);
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%3d",mat[i][j]);
		}
		printf("\n");
	}
    fclose(fp);
}
void dfs(int vrtx){
    visited[vrtx]=true;
    printf("%3d",vrtx);
    for (int i = 0; i < n; i++)
    {
        if (mat[vrtx][i]==1 && visited[i]==false)
        {
            dfs(i);
        }
    }
}
int main(void){
    for (int i = 0; i < n; i++)
    {
        visited[i]=false;
    }
    readGraph();
    printf("DFS traversal: \n");
    dfs(0);
    printf("\n");
    return 0;
}

//Status: Complete
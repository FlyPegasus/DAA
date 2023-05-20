/*
BFS or Breadth first search traversal technique traverses or visits the vertices level by level.
To avoid cycles mark vertices into visited and unvisited.
*/

#include<iostream>
#include<stdlib.h>
#include<queue>
#include<vector>
using namespace std;
int mat[6][6];
int g=6;
queue<int> q;
vector<int> flst;
void readGraph(){
    FILE *fp; //pointer to file
    fp=fopen("read.txt","r");
    if(fp==NULL){
        printf("\nError to open the file\n");
        exit(1);
    }
    //Reading a number from the file
    int n;
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

bool visited[6];   //Visited vertex tracker

void bfs(int v){
    for (int i = 0; i < g; i++)
    {
        visited[i]=false;
    }
    visited[v]=true;
    q.push(v);
    int u;
    while (!q.empty())
    {
        u=q.front();
        flst.push_back(u);
        q.pop();
    
        for (int i = 0; i < g; i++)
        {
            if (mat[u][i]==1){
                if(visited[i]==false){
                    visited[i]=true;
                    q.push(i);
                }
            }
        }
    }
}
void display(){
    for (auto it: flst)
    {
        cout<<it<<" ";
    }
    cout<<""<<endl;
}

int main(void){
    readGraph();
    bfs(3);
    display();
    return 0;
}

//Status: Complete(Version: CPP)
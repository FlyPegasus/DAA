//kruskal

#include<stdio.h>
#include<stdlib.h>
struct Edge{
	int vertex1;
	int vertex2;
	int weight;
};
struct Edge elist[9]={{0,1,7},{0,2,8},{1,2,3},{1,3,6},{2,3,4},{2,4,3},{3,5,5},{4,5,2},{3,4,2}};
int nov=6;
int noe=9;
void Sort(){
	for(int i=0;i<noe-1;i++){
		for(int j=0;j<noe-i-1;j++){
			if(elist[j].weight>elist[j+1].weight){
				struct Edge temp=elist[j];
				elist[j]=elist[j+1];
				if(elist[j].weight>elist[j+1].weight){
					struct Edge temp=elist[j];
					elist[j]=elist[j+1];
					elist[j+1]=temp;
				}
			}
		}
	}
}
void displayGraph(){
	for(int i=0;i<noe;i++){
		printf("(%c,%c)->%d\n",elist[i].vertex1+'A',elist[i].vertex2+'A',elist[i].weight);
	}
}
int parent[100];
int nEdge=0;
int spanning[100][3];

int find(int i){
	while(parent[i]>0){
		i=parent[i];
	}
	return i;
}
void simpleUnion(int i,int j){
	int u=find(i);
	int v=find(j);
	parent[u]=v;
}
void displayParent(){
	for(int i=0;i<nov;i++){
		printf("%4d",parent[i]);
	}
	printf("\n");
}
void kruskal(){
	Sort();
	printf("\n");
	displayGraph();
	for(int i=0;i<nov;i++){
		parent[i]=-1;
	}
	for(int i=0;i<noe;i++){
		displayParent();
		if(find(elist[i].vertex1)!=find(elist[i].vertex2)){
			spanning[nEdge][0]=elist[i].vertex1;
			spanning[nEdge][1]=elist[i].vertex2;
			spanning[nEdge++][2]=elist[i].weight;
			simpleUnion(elist[i].vertex1,elist[i].vertex2);
		}
	}
}
int main(void){
	kruskal();
	return 0;
}
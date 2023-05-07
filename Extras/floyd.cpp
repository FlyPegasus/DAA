#include<iostream>
#include<stdlib.h>
using namespace std;
int D[4][4];
int P[4][4];
int wt[4][4];
int n=4;
void readGraph(){
    FILE *fp; //pointer to file
    fp=fopen("grph.txt","r");
    if(fp==NULL){
        printf("\nError to open the file\n");
        exit(1);
    }
    //Reading a number from the file
    int n;
    fscanf(fp,"%d",&n);
    int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			fscanf(fp,"%d",&wt[i][j]);
		}
	}
    fclose(fp);
}
void display_edges(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(wt[i][j]!=0){
				printf("%d-->%d[%d]  ",i+1,j+1,wt[i][j]);
			}
		}
		printf("\n");
	}
}
//initialisation of distance matrix
void floydWarshall(){}
void apsp(){}
int main(void){
    readGraph();
    display_edges();
    return 0;
}

//Status: Incomplete
#include<stdio.h>
#include<stdlib.h>
int g=4;
char s[4]={'A','B','C','D'};
int degree_counter(int arr[g][g],int n){
	int count=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(arr[i][j]==1){
				count++;
			}
		}
	}
	return count;
}
void display_adj(int arr[g][g],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(arr[i][j]==1){
				arr[j][i]=0;
				printf("%c---%c  ",s[i],s[j]);
			}
		}
		printf("\n");
	}
}
int main(){
	FILE *fp;
	fp=fopen("Ex.txt","r");
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
	printf("Total Degree is: %d\n",degree_counter(graph,n));
	printf("No. of edges are: %d\n",degree_counter(graph,n)/2);
	printf("The graph representation is: \n");
	display_adj(graph,n);
	return 0;
}


#include<stdio.h>
#include<stdlib.h>

struct Edge{
	int vertex1;
	int vertex2;
	int weight;
};
int g=6;
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




int main(void){
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
    int mat[n][n];
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
    int h=degree_counter(mat,6);
    struct Edge edges[h];
    for (int i = 0; i < 6; i++)
    {
        /* code */
    }
    return 0;
}
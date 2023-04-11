#include<stdio.h>
#include<stdlib.h>
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
    
    return 0;
}
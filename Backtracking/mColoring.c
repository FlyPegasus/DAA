#include<stdio.h>
#include<stdlib.h>
int m=4;
int n;
int graph[10][10];
int arr[10]={0};
int count=0;
void readGraph(){
    FILE *fp;
	fp=fopen("read.txt","r");
	if(fp==NULL){
		printf("File open failed\n");
		return;
	}
	fscanf(fp,"%d",&n);
	int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			fscanf(fp,"%d",&graph[i][j]);
		}
	}
	fclose(fp);
    for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%2d",graph[i][j]);
		}
        printf("\n");
	}
}
void display(){
    for (int i = 1; i <= n; i++)
    {
        printf("%3d",arr[i]);
    }
    printf("\n");
}
void nextValue(int k){
    while(1){
        arr[k]=(arr[k]+1)%(m+1);//Assigning a new color out of m colors
        if (arr[k]==0)
        {
            return;
        }
        int i;
        for (i=1; i < k; i++)
        {
            if (graph[i][k]==1 && arr[i]==arr[k])
            {
                break;
            }
        }
        if (i==k)
        {
            return;
        }
        
    }
}
void mColoring(int k){
    while(1){
        nextValue(k);//Assigning a legal color to arr[k]
        if (arr[k]==0)//No new color possible
        {
            return;
        }
        if (k==n)
        {
            count++;
            display();//writing possible solution
        }
        else
        {
            mColoring(k+1);
        }
    }
}

int main(void){
    readGraph();
    mColoring(1);
    printf("Count: %d\n",count);
    return 0;
}
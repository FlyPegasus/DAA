#include<stdio.h>
#include<stdlib.h>
int m=5;
int n;
int graph[10][10];
int arr[10];
void readGraph(){
    FILE *fp;
	fp=fopen("read.txt","r");
	if(fp==NULL){
		printf("File open failed\n");
		return;
	}
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
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%3d",arr[i]);
    }
    printf("\n");
}
void nextValue(int k){
    while(1){
        arr[k]=(arr[k]+1)%m;
        if (arr[k]==0)
        {
            return;
            exit(0);
        }
        int i = 0;
        for (i; i < n; i++)
        {
            if (graph[i][k]==1 && arr[i]==arr[k])
            {
                break;
            }
            
        }
        if (i==k)
        {
            return;
            exit(0);
        }
        
    }
}
void mColoring(int k){
    while(1){
        nextValue(k);//Assigning a legal color to arr[k]
        if (arr[k]==0)//No new color possible
        {
            return;
            exit(0);
        }
        if (k==n-1)
        {
            display();//writing possible solution
        }
        //else
        //{
        mColoring(k+1);
        //}
    }
}

int main(void){
    for (int i = 0; i < n; i++)
    {
        arr[i]=0;
    }
    readGraph();
    mColoring(0);
    return 0;
}


/*
Time Complexity:

*/
/*
Priority Queue operations:
1) GetMin()
2) ExtractMin()
3) DecreaseKey()
4) InsertKey(key)
5) DeleteKey(i)
6) Display(arr)
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 9999


void swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int getMin(int *arr,int heapSize){
    if (heapSize==0)
    {
        return MAX;
    }
    else
    {
        return arr[0];
    }
}



//insertion has bugs!!
void insertKey(int *arr,int key,int heapSize){
    arr[heapSize]=key;
    heapSize=heapSize+1;
    int i=heapSize;
    while(i>1 && arr[i]<arr[i/2]){
        swap(&arr[i],&arr[i/2]);
        i=i/2;
    }
}

void deleteKey(){}

void display(int *a,int s){
    printf("\n");
    for (int i = 0; i < s; i++)
    {
        printf("%3d",a[i]);
    }
    printf("\n%d %lu %lu",s,sizeof(a),sizeof(int));
    //printf("\n");
}

int main(void){
    int heapSize=0;
    int *arr;
    int choice;
    while (1){
        arr=(int *)malloc((heapSize+1)*sizeof(int));
        printf("\n******MENU******\n1.GetMin\n2.InsertKey\n3.DeleteKey\n4.Display\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: getMin(arr,heapSize); break;
            case 2: int key; printf("Enter key: "); scanf("%d",&key); insertKey(arr,key,heapSize); break;
            case 3: deleteKey(); break;
            case 4: display(arr,sizeof(arr)/sizeof(int)); break;
            default: exit(0); break;
        }
    }
    return 0;
}
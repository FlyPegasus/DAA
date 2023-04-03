#include<stdio.h>

#include<stdlib.h>
int main(){
    int *arr=(int *)malloc(sizeof(int));
    for (int i = 0; i < 3; i++)
    {
        printf("Enter array element: ");
        scanf("%d",&arr[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        printf("%3d",arr[i]);
    }
    printf("\n");
    return 0;
}
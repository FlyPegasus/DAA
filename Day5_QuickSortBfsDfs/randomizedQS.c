//Randomized Quick Sort
#include<stdio.h>
void display(int arr[],int s){
    for (int i = 0; i < s; i++)
    {
        printf("%3d",arr[i]);
    }
    printf("\n");
}
int main(void){
    int size;
    printf("Enter array size: ");
    scanf("%d",&size);
    int arr[size];
    for(int i=0;i<size;i++){
        printf("Enter array elements: ");
        scanf("%d",&arr[i]);
    }
    display(arr,size);
    return 0;
}
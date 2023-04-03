#include<stdio.h>

void swap(int *a, int *b){  //swapping function
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int partitioning(){}

int main(void){  //main() function
    int size;
    printf("Enter array size: ");
    scanf("%d",&size);
    int arr[size];
    for(int i=0;i<size;i++){
        printf("Enter array elements: ");
        scanf("%d",&arr[i]);
    }
    printf("Array before sorting: \n");
    display(arr,size);
    Qsort(arr,0,size);
    printf("Array after sorting: \n");
    display(arr,size);
    return 0;
}
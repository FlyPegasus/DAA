/*
Lomuto partitioning system takes the last element as pivot
Time Complexity: O(n^2)
Space Complexity: O(1)
*/
#include<stdio.h>

void swap(int *a, int *b){  //swapping function
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int arr[],int low, int high){  //partitioning using Lomuto's Algorithm
    int pivot=arr[high];
    int i=low-1;
    for (int j = low; j < high; j++)
    {
        if (arr[j]<=pivot)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    i++;
    swap(&arr[i],&arr[high]);
    return i;  //partitioning function returns the high and low indices
}

void Qsort(int arr[],int low,int high){  //Quick Sort function
    if (low<high)
    {
        int j=partition(arr,low,high);  //high and low indices for the new partitions
        Qsort(arr,low,j-1);
        Qsort(arr,j+1,high);
    }
    return;
}

void display(int arr[],int s){  //Array display function
    for (int i = 0; i < s; i++)
    {
        printf("%3d",arr[i]);
    }
    printf("\n");
}

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
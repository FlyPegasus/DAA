#include<stdio.h>

void swap(int *a, int *b){  //swapping function
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int arr[], int low, int high){  //Hoare partitioning
    int i=low;
    int j=high+1;
    int pivot=arr[low];
    while (i<j)
    {
        while (i<=j && arr[i]<=pivot)
        {
            i++;
        }
        while (arr[j]>pivot)
        {
            j--;
        }
        if (i<j)
        {
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[low],&arr[j]);
    return j;
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
void display(int arr[],int s){
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
    Qsort(arr,0,size-1);
    printf("Array after sorting: \n");
    display(arr,size);
    return 0;
}
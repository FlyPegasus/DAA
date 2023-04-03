#include<stdio.h>
void terSearch(int arr[], int low, int high, int key){
    if (low<=high)
    {
        int mid1=low+(high-low)/3;
        int mid2=high-(high-low)/3;
        if (arr[mid1]==key)
        {
            printf("Item found at position %d.\n",mid1);
        }
        else if (arr[mid2]==key)
        {
            printf("Item found at position %d.\n",mid2);
        }
        else if (key<arr[mid1])
        {
            terSearch(arr,low,mid1-1,key);
        }
        else if (key>arr[mid2])
        {
            terSearch(arr,mid2+1,high,key);
        }
        else
        {
            terSearch(arr,mid1+1,mid2-1,key);
        }
    }
}
void display(int a[],int s){
    printf("\n");
    for (int i = 0; i < s; i++)
    {
        printf("%3d",a[i]);
    }
    printf("\n");
}
int main(void){
    int n;
    printf("Enter array length: ");
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter array element: ");
        scanf("%d",&arr[i]);
    }
    display(arr,n);
    int k;
    printf("Enter key to be searched: ");
    scanf("%d",&k);
    terSearch(arr,0,n-1,k);
    return 0;
}
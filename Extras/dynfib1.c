//Using the top down approach

#include<stdio.h>
int lookup[100];
int g=100;
void init(int arr[g]){
    for (int i = 0; i < g; i++)
    {
        arr[i]=-1;
    }
}
int fib(int n){
    if (n<=1)
    {
        lookup[n]=n;
    }
    else if (lookup[n]==-1)
    {
        lookup[n]=fib(n-1)+fib(n-2);
    }
    else{
        return lookup[n];
    }
}
void display(int n){
    for (int i = 0; i < n; i++)
    {
        printf("%3d",lookup[i]);
    }
    printf("\n");
}
int main(void){
    init(lookup);
    fib(5);
    display(5);
    return 0;
}


//Status: Wrong Answer
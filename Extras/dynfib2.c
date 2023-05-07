#include<stdio.h>
int table[100];
int fib(int n){
    table[0]=0;
    table[1]=1;
    for (int i = 2; i <= n; i++)
    {
        table[i]=table[i-1]+table[i-2];
    }
    return table[n];
}
int g=100;
void display(int n){
    for (int i = 0; i < n; i++)
    {
        printf("%3d",table[i]);
    }
    printf("\n");
}
int main(void){
    fib(6);
    display(6);
    return 0;
}

//Status: Complete
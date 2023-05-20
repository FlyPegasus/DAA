#include<stdio.h>
int items[3]={1,2,3};
int profit[3]={40,60,27};
int weight[3]={4,5,3};
int table[4][8];
//knapsack size m=7
//number of items n=3
int maxm(int a,int b){
    if (a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int knapsack(int m, int n){
    int maxprof=0;
    for (int i = 0; i < m+1; i++)
    {
        table[0][i]=0;
    }
    for (int i = 0; i < n+1; i++)
    {
        table[i][0]=0;
    }
    for (int i = 1; i < n; i++)
    {
        for (int w = 1; w < m; w++)
        {
            if (weight[i-1]>w)
            {
                table[i][w]=table[i-1][w];
            }
            else
            {
                table[i][w]=maxm(table[i-1][w],profit[i-1]+table[i-1][w-weight[i-1]]);
            }
            if (table[i][w]>maxprof)
            {
                maxprof=table[i][w];
            }
            
        }
        
    }
    return maxprof;
}


int main(void){
    printf("profit is %d",knapsack(8,4));
    printf("\n");
    return 0;
}

//Status: Working, still upadates required.
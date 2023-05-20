// Job scheduling using Greedy algorithm
#include <stdio.h>
#include<stdbool.h>

int profit[5];
bool slot[5];
struct Job
{
    int profit;
    int deadline;
    char id;
};
struct Job job[5] = {{50, 3, 'A'}, {30, 1, 'B'}, {40, 2, 'C'}, {20, 4, 'D'}, {10, 1, 'E'}};
void swap(struct Job *a, struct Job *b)
{
    struct Job temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(struct Job a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (n - i - 1); j++)
        {
            if (a[j].profit < a[j + 1].profit)
            {
                swap(&a[j], &a[j + 1]);
            }
        }
    }
}

void JSD(){
    for (int i = 0; i < 5; i++)
    {
        for (int j = job[i].deadline; j >0; j++)//Value of j will be min(deadline,n)
        {
            if (slot[j]==false)
            {
                slot[j]=true;
                profit[j]=j;
                break;
            }
        }
    }
}
int main(void)
{
    for (int i = 0; i < 5; i++)//Initialisation step
    {
        profit[i]=0;
        slot[i]=false;
    }
    bubbleSort(job, 5);
    JSD();
    for (int i = 0; i < 5; i++)
    {
        if (profit[i]!=0)
        {
            printf("%3c",job[profit[i]].id);
        }
        
        //printf("%3c: %d;", job[i].id, profit[i]);
    }
    printf("\n");
    
    
    return 0;
}
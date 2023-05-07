#include<stdio.h>
struct set
{
    int v1;
    int v2;
};
struct set arr[6]={{1,2},{1,3},{1,4},{2,3},{3,5},{4,7}};
simpleunion(){}
simpleFind(){}
int main(void){
    for (int i = 0; i < 6; i++)
    {
        printf("Edge%d :{%d,%d}\n",i,arr[i].v1,arr[i].v2);
    }
    
    return 0;
}

//Status: Incomplete
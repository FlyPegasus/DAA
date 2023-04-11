#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int randGiver(int s){
    srand(time(0));
    int num=rand()%s;
    return num;
}
int main(void){
    srand(time(0));//starting value
    printf("%d\n",rand());
    //int num=rand()%10;
    printf("%d\n",randGiver(10));
    return 0;
}
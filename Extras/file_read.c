#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE *fp; //pointer to file
    fp=fopen("test.txt","r");
    if(fp==NULL){
        printf("\nError to open the file\n");
        exit(1);
    }
    //Reading a number from the file
    int n;
    fscanf(fp,"%d",&n);
    printf("\nThe number in the file is %d.\n",n);
    fclose(fp);
    return 0;
}
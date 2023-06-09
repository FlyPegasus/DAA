#include<stdio.h>
#define MAX 9999
int n=3;
int M[10][10];//Cost storage matrix
//Phase testing
int S1[4][4]={{0,0,0,2},{0,0,1,2},{0,0,0,2},{0,0,0,0}};
int s[10][10];//APSP order storage matrix
int p[4]={10,30,5,60};

int tcost=0;//Total cost counter
void Mcm(){
    for (int i = 1; i <= n; i++)
    {
        M[i][i]=0;//Making the diagonals 0, for the cost of single matrix multiplication is 0
    }
    for (int ln = 1; ln < n; ln++)//As ln increases it deals with the bigger subproblems.
    {
        for (int i = 1; i <= n-ln; i++)//ln helps in the Bottom Up approach; it helps solve the smaller sub problems first.
        {
            int j=i+ln;//j stays close to i, therefore solving the base problems first.
            M[i][j]=MAX;
            for (int k = i; k < j; k++)
            {
                int cost=M[i][k]+M[k+1][j]+p[i-1]*p[k]*p[j];
                if (cost<M[i][j])
                {
                    //tcost-=M[i][j];
                    M[i][j]=cost;
                    tcost+=M[i][j];
                    s[i][j]=k;
                }
            }
        }
    }
}
void optimalOrder(int s[10][10],int i, int j){
    if (i==j)
    {
        printf("A%d",i);
        return;
    }
    else
    {
        printf("(");
        optimalOrder(s,i,s[i][j]);
        optimalOrder(s,s[i][j]+1,j);
        printf(")");
    }
}
int main(void){
    Mcm();
    optimalOrder(s,1,3);
    printf("\nTotal cost is: %d\n",M[1][n]);
    return 0;
}
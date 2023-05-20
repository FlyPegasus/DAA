//Making 5 Queens

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int board[5][5];//Chess board initialization
int x[5];//resulting position storage
int count=0;//possible combination counter
bool Place(int k, int l){//k is row no. and l is column no.
    for (int i = 0; i < k; i++)
    {
        if (x[i]==l || abs(x[i]-l)==abs(k-i))//checking for same row or diagonals(hint: dist b/w two points)
        {
            return false;
        }
    }
    return true;
}
void nQueens(int k, int n){//n is the #Queens and k is the row number.
    for (int i = 0; i < n; i++)//Loop for getting all the solutions by starting with each row position.
    {
        if (Place(k,i))//function checking for valid position to place next Queen in kth row and ith column.
        {
            x[k]=i;
            if (k==n-1)
            {
                for (int i = 0; i < 5; i++)
                {
                    printf("%3d",x[i]);
                }
                printf("\n");
                count++;
            }
            else{
                nQueens(k+1,n);//Backtracking recursive function checking solution for next row.
            }
        }   
    }
}

int main(void){
    for (int i = 0; i < 5; i++)//Making the chess board ready
    {
        for (int j = 0; j < 5; j++)
        {
            board[i][j]=0;
        }
    }
    nQueens(0,5);
    printf("Total combinations: %d\n",count);
    return 0;
}

/*
In this Backtracking problem (nQueens), the Place() function is our bounding function.
The bounding function helps us overlay some conditions on the Brute Forcing algorithm and reach specific solutions.
*/
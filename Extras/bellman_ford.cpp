#include<iostream>
#define MAX 9999;
using namespace std;
//int n;
struct Edge{
    int v1;
    int v2;
    int wt;
};
struct Edge edge_list[4]={{0,1,1},{1,2,2},{2,3,4},{3,4,3}};
int pred[5];
int dist[5];
//vertex count(|v|)=5
int vnum=5;
//edge_list size=4
int esize=4;
bool bellmanFord(int s){
    for (int i = 0; i < vnum; i++)
    {
        dist[i]=MAX;
        pred[i]=NULL;
    }
    dist[s]=0;
    for (int j = 1; j < vnum-1; j++)
    {
        for (int i = 0; i < esize; i++)
        {
            if(dist[edge_list[i].v1]+edge_list[i].wt<dist[edge_list[i].v2]){//Keep the weights of edges in a matrix
                dist[edge_list[i].v2]=dist[edge_list[i].v1]+edge_list[i].wt;
                pred[edge_list[i].v2]=i;
            }
        }
        
    }
    for (int i = 0; i < esize; i++)
    {
        if(dist[edge_list[i].v1]+edge_list[i].wt<dist[edge_list[i].v2]){
            return false;
        }
    }
    return true;
    
}
int main(void){
    int src=0;
    if(!bellmanFord(src)){
        cout<<"Negative edge loop present!"<<endl;
    }
    else{
        for (int i = 0; i < vnum; i++)
        {
            cout<<dist[i]<<" ";
        }
        cout<<""<<endl;
    }
    for (int i = 1; i < vnum; i++)
    {
        printf("%c-->%c\n",'A'+pred[i],'A'+i);
    }
    
    return 0;
}

//Status: Static[Incomplete]
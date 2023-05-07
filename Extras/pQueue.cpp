//Priority Queue implementation using CPP stl

#include<iostream>
#include<vector>
#define MAX 9999
#define HEAPCAPACITY 100
using namespace std;
vector<int> arr;

void swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int getMin(){
    if (arr.size()==0)
    {
        return MAX;
    }
    else
    {
        return arr[0];
    }
}
/*void adjustHeap(){
    int left;
    int right;
    if (i==0)
    {
        left=1;
        right=2;
    }
    else
    {
        left=2*i;
        right=2*i+1;
    }
    
}*/
int extractMin(){
    if (arr.size()==0)
    {
        return MAX;
    }
    else
    {
        int min=arr[0];
        arr[0]=arr[arr.size()-1];
        arr.pop_back();
        //adjustHeap();
        return min;
    }
    
}


void insert(int key){
    if(arr.size()==HEAPCAPACITY){
        cout<<"Overflow"<<endl;
        return;
    }
    arr.push_back(key);
    int i=arr.size()-1;
    while(i>0 && arr[i]<arr[i/2]){
        swap(&arr[i],&arr[i/2]);
        i=i/2;
    }
}
void display(){
    for (auto it: arr)
    {
        cout<<it<<" ";
    }
    cout<<""<<endl;
}
int main(void){
    int choice;
    while (1){
        printf("\n******MENU******\n1.GetMin\n2.InsertKey\n3.DeleteKey\n4.Display\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: cout<<getMin()<<endl; break;
            case 2: int key; printf("Enter key: "); scanf("%d",&key); insert(key); break;
            //case 3: deleteKey(); break;
            case 4: display(); break;
            default: exit(0); break;
        }
    }
    return 0;
}
/*
Priority Queue operations:
1) GetMin()
2) ExtractMin()
3) DecreaseKey()
4) InsertKey(key)
5) DeleteKey(i)
*/
#include<stdio.h>


int main(void){
    int choice;
    while (1){
        printf("\n******MENU******\n1.push\n2.pop\n3.display\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            default: exit(0); break;
        }
    }
    return 0;
}
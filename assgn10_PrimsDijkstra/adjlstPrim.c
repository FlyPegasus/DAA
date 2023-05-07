#include<stdio.h>
#include<stdlib.h>
int n,w[10][10];

int g=6;

int key[10];
int parent[10];
int mstSet[10];

void readGraph(){
	FILE *fp;
	fp=fopen("graph.txt","r");
	if(fp==NULL){
		printf("File open failed\n");
		return;
	}
	fscanf(fp,"%d",&n);
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			fscanf(fp,"%d",&w[i][j]);
		}
	}
	fclose(fp);
}

struct Node{
	struct Node* head;
	struct Node* next;
	char data;
};
struct Node *head=NULL;
void insertBeg(char item){
	struct Node* curr=(struct Node*)malloc(sizeof(struct Node));
	curr->data=item;
	curr->next=head;
	head=curr;
}

void display(){
	struct Node* temp=head;
	while(temp!=NULL){
		temp=temp->next;
		printf("%c--->",temp->data);
	}
	printf("\n");
}

void adj_list(int arr[g][g],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(arr[i][j]==1){
				insertBeg(s[j]);
			}
		}
		//printf("\n");
	}
	display();
}


int main(void){
    return 0;
}
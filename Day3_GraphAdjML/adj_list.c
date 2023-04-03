#include<stdio.h>
#include<stdlib.h>
int g=4;
char s[4]={'A','B','C','D'};

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

int main(){
	FILE *fp;
	fp=fopen("Ex.txt","r");
	if(fp==NULL){
		printf("\nError to open the file\n");
		exit(1);
	}
	int n;
	fscanf(fp,"%d",&n);
	int graph[n][n];
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			fscanf(fp,"%d",&graph[i][j]);
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%3d",graph[i][j]);
		}
		printf("\n");
	}
	fclose(fp);
	return 0;
}

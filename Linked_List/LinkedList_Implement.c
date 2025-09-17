#include<stdio.h>
#include<stdlib.h>

struct node{
	int data ;
	struct node *next;
};
typedef struct node Node;

Node* createLL(int arr[],int n){
	Node *head = malloc(sizeof(Node));
	head->data = arr[0];
	Node *temp = head;
	for (int i=1;i<n;i++ ){
		Node *newNode = malloc(sizeof(Node));
		temp->next = newNode;
		newNode->data = arr[i];
		temp = newNode;
	}
	return head;

}
Node*  insertFront(Node *head,int val){
	Node  *newNode = malloc(sizeof(Node));
	newNode->data = val;
	newNode->next = head;
	head=newNode;
	return head;
}
void printLL(Node * head){
	Node * temp = head;
	while (temp){
		printf("%d ",temp->data);
		temp = temp->next;
	}
}
void printLLrecur(Node *head){
	if (head == NULL){
		return;}
	printf("%d ",head->data);
	printLLrecur(head->next);
}
void printreverseRecur(Node *head){
	if (head==NULL)return;
	printreverseRecur(head->next);
	printf("%d ",head->data);
}
int main(){

	int arr[] = {1,2,3,4,5};
	int  n = sizeof(arr)/sizeof(int);
	Node *head = createLL(arr,n);
	printf("\n");
	printLL(head);
		
	head =insertFront(head,10);
	printf("\n");
	printLLrecur(head);
	printreverseRecur(head);
	return 0;

}

#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* pre;
	struct node* next;
};
typedef struct node node;
struct douList{
	struct node *head;
	struct node *tail;
};
typedef struct douList douList;
douList *createList(int x){
	douList *l = (douList*)malloc(sizeof(douList));
	l->head = (node*)malloc(sizeof(node));
	l->head->data = x;
	l->head->pre = NULL;
	l->head->next = NULL;
	l->tail = l->head;
	return l;
}
douList *addHead(douList *l, int x){
	node *temp = (node*)malloc(sizeof(node));
	temp->data = x;
	temp->pre = NULL;
	temp->next = l->head;
	l->head->pre = temp;
	l->head = temp;
	return l;
}
douList *addTail(douList *l, int x){
	node *temp = (node*)malloc(sizeof(node));
	temp->data = x;
	temp->next = NULL;
	temp->pre = l->tail;
	l->tail->next = temp;
	l->tail = temp;
	return l;
}
douList *deleteHead(douList *l){
	node *p = l->head->next;
	node *temp = l->head;
	p->pre = NULL;
	l->head = p;
	free(temp);
	return l;
}
douList *deleteTail(douList *l){
	node *p = l->tail->pre;
	node *temp = l->tail;
	p->next = NULL;
	l->tail = p;
	free(temp);
	return l;
}
void printList(douList *l){
	node *p = l->head;
	while (p != NULL){
		printf("%d ",p->data);
		p = p->next;
	}
}
void deleteList(douList *l){
	while(l->head != NULL){
		l = deleteHead(l);	 
	}
}
int size(douList *l){
	node *p = l->head;
	int dem = 0;
	while (p != NULL){
		dem++;
		p = p->next;
	}
}
int main(){
	int n,x;
	scanf("%d",&n);
	scanf("%d",&x);
	douList *l;
    l = createList(x);
    int i;
    for(i=1;i<n;i++){
        scanf("%d",&x);
        l = addTail(l,x);
    }
    printList(l);
}

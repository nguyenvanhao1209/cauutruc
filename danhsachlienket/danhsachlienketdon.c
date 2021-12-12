#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
typedef struct node node;
node *createNode(int x){
    node *temp = (node*)malloc(sizeof(node));
    temp->next = NULL;
    temp->data = x;
    return temp;
}
void printList(node *l){
	node *p = l;
	while (p != NULL){
		printf("%d ",p->data);
		p = p->next;
	}
}
node *addElement(node*p, int x){
	node *temp = createNode(x);
	p->next = temp;
	return temp;
}
node *addHead(node *l, int x){
	node *temp = (node*)malloc(sizeof(node));
	temp->data = x;
	temp->next = l;
	l = temp;
	return l;
}
node *addTail(node *l, int x){
	node *p = l;
	while (p->next != NULL){
		p= p->next;
	}
	node *temp = (node*)malloc(sizeof(node));
	temp->data = x;
	temp->next = NULL;
	p->next = temp;
	return l;
}
node *deleteHead(node *l){
	node *p = l;
	p = p->next;
	free(l);
	return p;
}
node *deleteTail(node *l){
	node *p = l;
	while (p->next->next != NULL){
		p = p->next;
	}
	free(p->next);
	p->next = NULL;
	return l;
}
void sort(node *l){
	node *p = l;
	node *p1;
	for(p = l;p != NULL; p = p->next){
		for(p1 = p->next; p1 != NULL; p1 = p1->next){
			if(p->data<p1->data){
				int temp = p->data;
				p->data = p1->data;
				p1->data = temp;
			}
		}
	}
}
node* prev(node* h, node* p){
	node* q = h;
	while(q != NULL){
		if(q->next == p) return q;
		q = q->next;
	}
	return NULL;
}
node *deleteNode(node *l,node*p){
	if(l == p){
		node *q = l;
		q = q->next;
		free(l);
		return q;
	}
	node *q = prev(l,p);
	q->next = p->next;
	free(p);
	return l;
}
node *searchNode(node *l,int x){
	node *p = l;
	while(p != NULL){
		if(p->data == x) return p;
		p = p->next;
	}
	return NULL;
}
node *l;
int main(){
	int n;
	int x;
	scanf("%d",&n);
	scanf("%d",&x);
	l = createNode(x);
	node *p = l;
	int i;
	for (i = 1; i < n; i++){
		scanf("%d",&x);
		p = addElement(p, x);
	}
	printList(l);
	int k;
	fflush(stdin);
	printf("\n");
	scanf("%d",&k);
	while(searchNode(l,k) != NULL){
		l = deleteNode(l,searchNode(l,k));
	}
	printList(l);
}

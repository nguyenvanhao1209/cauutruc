#include<stdio.h>
#include<stdlib.h>
struct Node{
 int value;
 struct Node* next;
};
typedef struct Node Node;
void printList(Node* h){
	Node* p = h;
	while(p != NULL){
		printf("%d ",p->value);
		p = p->next;
	}
}
Node* findLast(Node* h){
	Node* p = h;
	while(p != NULL){
		if(p->next == NULL) return p;
		p = p->next;
	}
	return NULL;
}
Node* makeNode(int x){
	Node* q = (Node*)malloc(sizeof(Node));
	q->value = x; q->next = NULL;
	return q;
}
Node *addElement(node*p, int x){
	node *temp = makeNode(x);
	p->next = temp;
	return temp;
}
Node* insertAfter(Node* h, Node* p, int x){
	if(p == NULL) return h;
	Node* q = makeNode(x);
	if(h == NULL) return q;
	q->next = p->next;
	p->next = q;
	return h;
}
Node* insertLast(Node* h, int x){
	Node* q = makeNode(x);
	if(h == NULL)
		return q;
	Node* p = h;
	while(p->next != NULL)
		p = p->next;
	p->next = q;
	return h;
}
Node* locate(Node* h, int x){
	Node* p = h;
	while(p != NULL){
		if(p->value == x) return p;
		p = p->next;
	}
	return NULL;
}
Node* prev(Node* h, Node* p){
	Node* q = h;
	while(q != NULL){
		if(q->next == p) return q;
		q = q->next;
	}
	return NULL;
}
Node* insertAt(Node* h, Node* p, int x){
	Node* pp = prev(h,p);
	if(pp == NULL && p != NULL) return h;
	Node* q =  (Node*)malloc(sizeof(Node));
	q->value = x; q->next = NULL;
	if(pp == NULL){
		if(h == NULL)
		return q;
		q->next = h;
		return q;
	}
	q->next = p; pp->next = q;
	return h;
}
Node* insertAtRecursive(Node* h, Node* p, int x){
	if(p == NULL) return h;
	if(h == NULL || p == h){
		return makeNode(x);
	}else{
		h->next = insertAtRecursive(h->next,p,x);
		return h;
	}
}
Node* remove(Node* h, Node* p){
	if(h == NULL || p == NULL) return h;
	if(h == p){
		h = h->next;
	 free(p);
	return h;
	}else{
		h->next = remove(h->next,p);
		return h;
	}
}
Node *removeHead(node *h){
	Node *p = h;
	p = p->next;
	free(l);
	return p;
}
Node *removeTail(node *h){
	Node *p = h;
	while (p->next->next != NULL){
		p = p->next;
	}
	delete(p->next);
	p->next = NULL;
	return h;
}

int main(){
	int n;
	int x;
	scanf("%d",&n);
	scanf("%d",&x);
	Node *head = makeNode(x);
	Node *p = head;
	int i;
	for(i=1;i<n;i++){
		scanf("%d",&x);
		p = addElement(p,x);
	}
	int a;
	scanf("%d",&a);
	insertLast(head,a);
	removeHead(head);
	removeTail(head);
	printList(head);
}

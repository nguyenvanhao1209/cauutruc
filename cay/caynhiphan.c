#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node node;
node *insertNode(node *t, int x){
	if (t == NULL){
		node *temp = (node*)malloc(sizeof(node));
		temp->data =x;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	} else{
		if (x < t->data){
			t->left = insertNode(t->left, x);
		} else{
			t->right = insertNode(t->right, x);
		}
	}
}
int countNode(node *t){
	if(t == NULL) return 0;
	else{
		int ld = countNode(t->left);
		int rd = countNode(t->right);
		return 1 + ld + rd;
	}
}
int depth(node *t){
	if(t == NULL) return 0;
	int ld = depth(t->left);
	int rd = depth(t->right);
	return 1 + (ld > rd ? ld : rd);
}
void printTree(node *t){
	if (t != NULL){
		printTree(t->left);
		printf("%d ",t->data);
		printTree(t->right);
	}
}
node *findNode(node *t,int x){
	node *p = t;
	while(p->data != x){
		if(p->data > x){
			p = p->left;
		}
		else{
			p = p->right;
		}
	}
	return p;
}
node *parent(node *t, node *p){
	node *q = t;
	while(q->left != p && q->right !=p){
		if(q->data > p->data){
			q = q->left;
		}
		else{
			q = q->right;
		}
	}
	return q;
}
int main(){
	int n,x;
	scanf("%d",&n);
	node *t = NULL;
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&x);
		t = insertNode(t,x);
	}
	printTree(t);
	printf("\n%d",countNode(t));
	printf("\n%d\n",depth(t));
	node *p = findNode(t,1);
	printf("%d",parent(t,p)->data);
}

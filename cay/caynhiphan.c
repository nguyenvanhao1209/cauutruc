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
node *searchNode(node *t,int x){
  if(t == NULL) return NULL;
  else if(t->data == x) return t;
  else if(t->data < x) return searchNode(t->right,x);
  else return searchNode(t->left,x);
}
node *left_most(node *t){
	if(t == NULL) return t;
	else{
		while(t->left != NULL){
			t = t->left;
		}
	}
	return t;
}
node *deleteNode(node *t,int x){
	if(t == NULL) return t;
	if(searchNode(t,x) != NULL){
		if(x == t->data){
			if(t->left == NULL){
				node *temp = t->right;
				free(t);
				return temp;
			}
			if(t->right == NULL){
				node *temp = t->left;
				free(t);
				return temp;
			}
			t->data = left_most(t->right)->data;
			t->right = deleteNode(t->right,t->data);
			return t;
		}
		else if(x.maso < t->data.maso){
			t->left = deleteNode(t->left,x);
		}
		else{
			t->right = deleteNode(t->right,x);
		}
	}else{
		printf("\nKhong ton tai gia tri can tim!");
	}
	return t;
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
int countX(node *t,int x){
	if(t == NULL) return 0;
	if(t->data.dochoi == x) return 1 + countX(t->left, x) + countX(t->right, x);
	return countX(t->left, x) + countX(t->right, x);
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
	node *p = searchNode(t,1);
	printf("%d",parent(t,p)->data);
}

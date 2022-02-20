#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct qua{
	int maso;
	char dochoi[31];
};
typedef struct qua qua;
struct node{
	qua data;
	struct node *left;
	struct node *right;
};
typedef struct node node;
node *insertNode(node *t, qua x){
	if(t == NULL){
		node *temp = (node*)malloc(sizeof(node));
		temp->data = x;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}else{
		if(x.maso < t->data.maso){
			t->left = insertNode(t->left,x);
		}
		else{
			t->right = insertNode(t->right, x);
		}
	}
}
node *searchNode(node *t,qua x){
	if(t == NULL ) return NULL;
	else if(x.maso == t->data.maso) return t;
	else if(x.maso < t->data.maso) return searchNode(t->left,x);
	else return searchNode(t->right,x);
}
void printTree(node *t){
	if(t != NULL){
		printTree(t->left);
		printf("%-10d\t%-30s\n",t->data.maso,t->data.dochoi);
		printTree(t->right);
	}
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
node *deleteNode(node *t,qua x){
	if(t == NULL) return t;
	if(searchNode(t,x) != NULL){
		if(x.maso == t->data.maso){
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
node *t = NULL;
char c;
void docfileA(){
	FILE *f;
	f = fopen("C:/Users/Administrator/Desktop/test.txt","r");
	qua x;
	while(!feof(f)){
		fscanf(f,"%d",&x.maso);
		fscanf(f,"%c",&c);
		if(c != '\t'){
			printf("nhap thong tin do choi: ");
			fflush(stdin);
			gets(x.dochoi);
		}
		else{
			fscanf(f,"%s\n",x.dochoi);
		}
		t = insertNode(t,x);
	}
	fclose(f);
	printTree(t);
}
qua mangB[100];
int n=0;
void docfileB(){
	FILE *f;
	f = fopen("C:/Users/Administrator/Desktop/dothi.txt","r");
	qua x;
		while(!feof(f)){
		fscanf(f,"%d",&x.maso);
		fscanf(f,"%c",&c);
		if(c != '\t' || feof(f)){
			printf("nhap thong tin do choi: ");
			fflush(stdin);
			gets(x.dochoi);
		}
		else{
			fscanf(f,"%s\n",x.dochoi);
		}
		mangB[n] = x;
		n++;
	}
	fclose(f);
	int i;
	for(i=0;i<n;i++){
		printf("%-10d\t%-30s\n",mangB[i].maso,mangB[i].dochoi);
	}
}
void timkiem(){
	int i;
	printf("thong tin bi xoa\n");
	for(i=0;i<n;i++){
		node *p = searchNode(t,mangB[i]);
		if(p != NULL){
			printf("%-10d\t%-30s\n",p->data.maso,p->data.dochoi);
			t = deleteNode(t,mangB[i]);
		}
	}
	printf("thong tin sau khi xoa\n");
	printTree(t);
}
void tonghop(){
	int i;
	for(i=0;i<n;i++){
		t = insertNode(t,mangB[i]);
	}
	printTree(t);
}
void thongke(){
	node *p = t;
	char mang[30][100];
	int dem[100];
	int m = 0;
	while(p != NULL){
		strcpy(mang[m],p->data.dochoi);
		m++;
		p = deleteNode(p,p->data);
	}
	int i,j;
	int b[100];
	for(i=0;i<m;i++){
		b[i] = 1;
	}
	for(i=0;i<m;i++){
		int count = 1;
		if(b[i]){
			b[i] = 0;
			for(j=i+1;j<m;j++){
				if(strcmp(mang[i],mang[j])==0){
					count++;
					b[j] = 0;
				}
			}
			printf("%-20s\t%-10d\n",mang[i],count);
		}
	}
}
void menu(){
	printf("1. docfileA\n");
	printf("2. docfileB\n");
	printf("3. timkiem\n");
	printf("4. tonghop\n");
	printf("5. thongke\n");
	printf("6. thoat\n");
}
int chonmenu(){
	int n=0;
	printf("\nchon chuc nang: ");
	scanf("%d",&n);
	if(n>0 || n<7) return n;
	else return chonmenu();
}
void xulymenu(){
	int chon = chonmenu();
	switch(chon){
		case 1:
			printf("1. docfileA\n");
			docfileA();
			break;
		case 2:
			printf("2. docfileB\n");
			docfileB();
			break;
		case 3:
			printf("3. timkiem\n");
			timkiem();
			break;
		case 4:
			printf("4. tonghop\n");
			tonghop();
			break;
		case 5:
			printf("5. thongke\n");
			thongke();
			break;
		case 6:
			printf("6. thoat\n");
			exit(1);
			break;
	}
}
int main(){
	menu();
	while(1){
		xulymenu();
		printf("\n");
		menu();
	}
	return 0;
}

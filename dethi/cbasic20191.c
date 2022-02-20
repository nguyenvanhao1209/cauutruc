#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct tudien{
	char anh[26];
	char viet[26];
};
typedef struct tudien tudien;
struct node{
	tudien data;
	struct node *left;
	struct node *right;
};
typedef struct node node;
typedef char chuoi[25];
node *insertNode(node *t, tudien x){
	if(t == NULL){
		node *temp = (node*)malloc(sizeof(node));
		temp->data = x;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}else{
		if(strcmp(x.anh,t->data.anh)<0){
			t->left = insertNode(t->left,x);
		}
		else{
			t->right = insertNode(t->right, x);
		}
	}
}
node *searchNode(node *t,tudien x){
  if(t == NULL) return NULL;
  else if(strcmp(t->data.anh,x.anh)==0) return t;
  else if(strcmp(x.anh,t->data.anh)>0) return searchNode(t->right,x);
  else return searchNode(t->left,x);
}
void printTree(node *t){
	if(t != NULL){
		printTree(t->left);
		printf("%-25s\t%-25s\n",t->data.anh,t->data.viet);
		printTree(t->right);
	}
}
void freeTree(node *t){
  if(t != NULL){
    freeTree(t->left);
    freeTree(t->right);
    free(t);
  }
}
node *t = NULL;
void naptudien(){
	FILE *f;
	f = fopen("C:/Users/Administrator/Desktop/test.txt","r");
	tudien x;
	while(!feof(f)){
		fscanf(f,"%s\t",x.anh);
		printf("%-25s\t",x.anh);
		fscanf(f,"%s\n",x.viet);
		printf("%-25s\n",x.viet);
		t = insertNode(t,x);
	}
}
void noidungtudien(){
	printTree(t);
}
void themsua(){
	tudien x;
	printf("nhap tu tieng anh: ");
	fflush(stdin);
	gets(x.anh);
	node *p = searchNode(t,x);
	if(p != NULL){
		char c;
		printf("ban co muon nhap noi dung moi ko(y/n): ");
		fflush(stdin);
		scanf("%c",&c);
		if(c == 'y'){
			printf("nhap noi dung moi: ");
			fflush(stdin);
			gets(p->data.viet);
		}
	}
	else{
		printf("nhap nghia cua tu: ");
		fflush(stdin);
		gets(x.viet);
		t = insertNode(t,x);
	}
}
void dichcau(){
	char dich[100];
	printf("nhap cau tieng anh: ");
	fflush(stdin);
	gets(dich);
	strlwr(dich); //chuyen chuoi hoa thanh thuong
	char *token = strtok(dich," "); // tach tu theo dau cach
	tudien str[10];
	int n=0;
	while(token != NULL){
		strcpy(str[n].anh,token);
		n++;
		token = strtok(NULL," ");
	}
	int i;
	for(i=0;i<n;i++){
		printf("%s\n",str[i]);
	}
	for(i=0;i<n;i++){
		node *p = searchNode(t,str[i]);
		if(p != NULL){
			printf("%s ",p->data.viet);
		}
		else{
			printf("<thieu tu> ");
		}
	}
}
void menu(){
	printf("1. naptudien\n");
	printf("2. noidungtudien\n");
	printf("3. them/sua\n");
	printf("4. dichcau\n");
	printf("5. thoat\n");
}
int chonmenu(){
	int n=0;
	printf("\nchon chuc nang: ");
	scanf("%d",&n);
	if(n>0 || n<6) return n;
	else return chonmenu();
}
void xulymenu(){
	int chon = chonmenu();
	switch(chon){
		case 1:
			printf("1. naptudien\n");
			naptudien();
			break;
		case 2:
			printf("2. noidungtudien\n");
			noidungtudien();
			break;
		case 3:
			printf("3. them/sua\n");
			themsua();
			break;
		case 4:
			printf("4. dichcau\n");
			dichcau();
			break;
		case 5:
			printf("5. thoat\n");
			freeTree(t);
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

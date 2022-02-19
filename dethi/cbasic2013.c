#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct doibong{
	char ten[10];
	int diem;
};
typedef struct doibong doibong;
struct node {
	doibong data;
	struct node *left;
	struct node *right;
};
typedef struct node node;
node *insertNode(node *t, doibong x){
	if(t == NULL){
		node *temp = (node*)malloc(sizeof(node));
		temp->data = x;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}else{
		if(strcmp(x.ten,t->data.ten)<0){
			t->left = insertNode(t->left,x);
		}
		else{
			t->right = insertNode(t->right, x);
		}
	}
}
node *searchNode(node *t,doibong x){
  if(t == NULL) return NULL;
  else if(strcmp(t->data.ten,x.ten)==0) return t;
  else if(strcmp(x.ten,t->data.ten)>0) return searchNode(t->right,x);
  else return searchNode(t->left,x);
}
void printTree(node *t){
	if(t != NULL){
		printTree(t->left);
		printf("%-25s\t%d\n",t->data.ten,t->data.diem);
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
int countNode(node *t){
	if(t == NULL) return 0;
	return 1 +  countNode(t->left) + countNode(t->right);
}
node *deleteNode(node *t,doibong x){
	if(t == NULL) return t;
	if(searchNode(t,x) != NULL){
		if(strcmp(x.ten,t->data.ten)==0){
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
		else if(strcmp(x.ten,t->data.ten)<0){
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
void printTen(node *t){
	if(t != NULL){
		printTen(t->left);
		if(countNode(t) == 1) printf("%s.",t->data.ten);
		else printf("%s, ",t->data.ten);
		printTen(t->right);
	}
}
node *t = NULL;
void taocay(){
	FILE *f;
	f = fopen("C:/Users/Administrator/Desktop/test.txt","r");
	if(f == NULL)
    {
    	perror("Khong the mo tep de doc.\n");
		return ;
    }
	doibong x;
	x.diem = 0;
	doibong y;
	y.diem = 0;
	int diemx;
	int diemy;
	while(!feof(f)){
		fscanf(f,"%s\t",x.ten);
		fscanf(f,"%s\t",y.ten);
		fscanf(f,"%d\t",&diemx);
		fscanf(f,"%d\n",&diemy);
		if(diemx>diemy){
			x.diem += 3;
			y.diem += 0;
			if(searchNode(t,x) == NULL){
				t = insertNode(t,x);
			}
			else{
				searchNode(t,x)->data.diem += 3;
			}
			if(searchNode(t,y) == NULL){
				t = insertNode(t,y);
			}
			else{
				searchNode(t,y)->data.diem += 0;
			}
		}
		else if(diemx<diemy){
			x.diem += 0;
			y.diem += 3;
			if(searchNode(t,x) == NULL){
				t = insertNode(t,x);
			}
			else{
				searchNode(t,x)->data.diem += 0;
			}
			if(searchNode(t,y) == NULL){
				t = insertNode(t,y);
			}
			else{
				searchNode(t,y)->data.diem += 3;
			}
		}
		else{
			x.diem += 1;
			y.diem += 1;
			if(searchNode(t,x) == NULL){
				t = insertNode(t,x);
			}
			else{
				searchNode(t,x)->data.diem += 1;
			}
			if(searchNode(t,y) == NULL){
				t = insertNode(t,y);
			}
			else{
				searchNode(t,y)->data.diem += 1;
			}
		}
	}
	fclose(f);
	printTree(t);
}
void ketqua(){
	printTree(t);
}
void timkiem(){
	doibong tim;
	printf("nhap ma doi can tim: ");
	fflush(stdin);
	scanf("%s",tim.ten);
	if(searchNode(t,tim) == NULL){
		printf("khong tim thay\n");
	}
	else{
		printf("diem cua doi %s la %d\n",searchNode(t,tim)->data.ten,searchNode(t,tim)->data.diem);
	}
}
node *n = NULL;
void duyet(node *t,doibong x){
	if(t != NULL){
		if(t->data.diem<x.diem){
			strcpy(x.ten,t->data.ten);
			n = insertNode(n,x);
		}
		duyet(t->left,x);
		duyet(t->right,x);
	}
}
void xoa(node *n,node *t){
	if(n != NULL){
		t = deleteNode(t,n->data);
		xoa(n->left,t);
		xoa(n->right,t);
	}
}
void xuonghang(){
	doibong x;
	printf("nhap diem: ");
	fflush(stdin);
	scanf("%d",&x.diem);
	duyet(t,x);
	printf("cac doi bi xuong hang: ");
	printTen(n);
	xoa(n,t);
	printf("\ncac doi con lai\n");
	printTree(t);
}
void menu(){
	printf("1. taocay\n");
	printf("2. ketqua\n");
	printf("3. timkiem\n");
	printf("4. xuonghang\n");
	printf("5. thoat\n");
}
int chonmenu(){
	int n=0;
	printf("\nchon chuc nang: ");
	scanf("%d",&n);
	if(n>0 && n<6) return n;
	else return chonmenu();
}
void xulymenu(){
	int chon = chonmenu();
	switch(chon){
		case 1:
			printf("1. taocay\n");
			taocay();
			break;
		case 2:
			printf("2. ketqua\n");
			ketqua();
			break;
		case 3:
			printf("3. timkiem\n");
			timkiem();
			break;
		case 4:
			printf("4. xuonghang\n");
			xuonghang();
			break;
		case 5:
			printf("5. thoat\n");
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

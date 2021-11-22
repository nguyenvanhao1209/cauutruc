#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct sinhvien{
	char username[20];
	char password[20];
	int diem;
};
typedef struct sinhvien sinhvien;
struct node{
	sinhvien data;
	struct node *left;
	struct node *right;
};
typedef struct node node;
node *insertNode(node *t, sinhvien x){
	if(t == NULL){
		node *temp = (node*)malloc(sizeof(node));
		temp->data = x;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}else{
		if(strcmp(x.username,t->data.username)<0){
			t->left = insertNode(t->left,x);
		}
		else{
			t->right = insertNode(t->right, x);
		}
	}
}
node *searchNode(node *t,sinhvien x){
	if(t == NULL ) return NULL;
	else if(strcmp(x.username,t->data.username)==0 && strcmp(x.password,t->data.password)==0) return t;
	else if(strcmp(x.username,t->data.username)<0) return searchNode(t->left,x);
	else return searchNode(t->right,x);
}
void printTree(node *t){
	if(t != NULL){
		printTree(t->left);
		printf("%-20s\t%-20s\t%d\n",t->data.username,t->data.password,t->data.diem);
		printTree(t->right);
	}
}
node *findNode(node *t,sinhvien x){
	if(t == NULL ) return NULL;
	else if(strcmp(x.username,t->data.username)==0) return t;
	else if(strcmp(x.username,t->data.username)<0) return findNode(t->left,x);
	else return findNode(t->right,x);
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
node *deleteNode(node *t,sinhvien x){
	if(t == NULL) return t;
	if(findNode(t,x) != NULL){
		if(strcmp(x.username,t->data.username)==0){
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
		else if(strcmp(x.username,t->data.username)<0){
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
void xemdiem(node *p){
	printf("%d\n",p->data.diem);
}
void doimatkhau(node *p){
	char mk[20];
	printf("nhap mat khau moi: ");
	fflush(stdin);
	gets(mk);
	char mkl[20];
	printf("nhap lai mat khau: ");
	fflush(stdin);
	gets(mkl);
	while(strcmp(mk,mkl) !=0){
		printf("nhap lai mat khau: ");
		fflush(stdin);
		gets(mkl);
	}
	strcpy(p->data.password,mk);
}
void ghilaithongtinsv(node *p){
	FILE *f;
	f = fopen("C:/Users/Administrator/Desktop/test.txt","w");
	node *cur = p;
	node *pre;
		while(cur != NULL){
		if(cur->left == NULL){
			fprintf(f,"%s\t%s\t%d\n",cur->data.username,cur->data.password,cur->data.diem);
			cur = cur->right;
		}
		else{
			pre = cur->left;
			while(pre->right != NULL && pre->right != cur){
				pre = pre->right;
			}
			if(pre->right == NULL){
				pre->right = cur;
				cur = cur->left;
			}
			else{
                pre->right = NULL;
				fprintf(f,"%s\t%s\t%d\n",cur->data.username,cur->data.password,cur->data.diem);
				cur = cur->right;
			}
		}
	}
	fclose(f);
}
void menusv(){
	printf("1. xemdiem\n");
	printf("2. doimatkhau\n");
	printf("3. ghilaithongtinsv\n");
}
int chonmenusv(){
	int n=0;
	printf("\nchon chuc nang: ");
	scanf("%d",&n);
	if(n>0 || n<4) return n;
	else return chonmenusv();
}
int xulymenusv(node *p){
	int chon = chonmenusv();
	switch(chon){
		case 1:
			printf("1. xemdiem\n");
			xemdiem(p);
			break;
		case 2:
			printf("2. doimatkhau\n");
			doimatkhau(p);
			break;
		case 3:
			printf("3. ghilaithongtinsv\n");
			ghilaithongtinsv(t);
			break;
	}
	return chon;
}
void themsinhvien(node *p){
	sinhvien x;
	printf("nhap username: ");
	fflush(stdin);
	scanf("%s",x.username);
	while(findNode(p,x) != NULL){
		printf("username da ton tai\n");
		printf("nhap username: ");
		fflush(stdin);
		scanf("%s",x.username);
	}
	printf("nhap password: ");
	fflush(stdin);
	gets(x.password);
	printf("nhap diem: ");
	fflush(stdin);
	scanf("%d",&x.diem);
	p = insertNode(p,x);
}
void indanhsach(node *p){
	node *cur = p;
	node *pre;
		while(cur != NULL){
		if(cur->left == NULL){
			if(strcmp(cur->data.username,"Admin") != 0)
				printf("%s\t%s\t%d\n",cur->data.username,cur->data.password,cur->data.diem);
			cur = cur->right;
		}
		else{
			pre = cur->left;
			while(pre->right != NULL && pre->right != cur){
				pre = pre->right;
			}
			if(pre->right == NULL){
				pre->right = cur;
				cur = cur->left;
			}
			else{
                pre->right = NULL;
				if(strcmp(cur->data.username,"Admin") != 0)
					printf("%s\t%s\t%d\n",cur->data.username,cur->data.password,cur->data.diem);
				cur = cur->right;
			}
		}
	}
}
void xoasinhvien(node *p){
	sinhvien x;
	printf("nhap username can xoa: ");
	fflush(stdin);
	gets(x.username);
	node *q = findNode(p,x);
	printf("%s\t%s\t%d\n",q->data.username,q->data.password,q->data.diem);
	if(q != p){
		p = deleteNode(p,x);
	}
	else{
		printf("khong the xoa Admin\n");
	}
}
void menuad(){
	printf("1. themsinhvien\n");
	printf("2. indanhsach\n");
	printf("3. xoasinhvien\n");
	printf("4. ghilaithongtinad\n");
}
int chonmenuad(){
	int n=0;
	printf("\nchon chuc nang: ");
	scanf("%d",&n);
	if(n>0 || n<5) return n;
	else return chonmenuad();
}
int xulymenuad(node *p){
	int chon = chonmenuad();
	switch(chon){
		case 1:
			printf("1. themsinhvien\n");
			themsinhvien(t);
			break;
		case 2:
			printf("2. indanhsach\n");
			indanhsach(t);
			break;
		case 3:
			printf("3. xoasinhvien\n");
			xoasinhvien(t);
			break;
		case 4:
			printf("4. ghilaithongtinad\n");
			break;
	}
	return chon;
}
int soluong = 0;
void docfile(){
	FILE *f;
	f = fopen("C:/Users/Administrator/Desktop/cauhoi.txt","r");
	sinhvien x;
	while(!feof(f)){
		fscanf(f,"%s\t",x.username);
		fscanf(f,"%s\t",x.password);
		fscanf(f,"%d\n",&x.diem);
		t = insertNode(t, x);
	}
	fclose(f);
}
void dangnhap(){
	while(soluong == 0){
		docfile();
		soluong++;
	}
	printTree(t);
	sinhvien y;
	printf("nhap ten dang nhap: ");
	fflush(stdin);
	gets(y.username);
	printf("nhap mat khau: ");
	fflush(stdin);
	gets(y.password);
	int dem = 1;
	node *t1 = searchNode(t, y);
	while(t1 == NULL){
		if(dem > 3){
			printf("sai qua 3 lan\n");
			exit(1);
		}
		printf("sai ten dang nhap hoac mat khau\n");
		printf("nhap ten dang nhap: ");
		fflush(stdin);
		gets(y.username);
		printf("nhap mat khau: ");
		fflush(stdin);
		gets(y.password);
		dem++;
		node *t1 = searchNode(t, y);
	}
	if(strcmp(t1->data.username,"Admin")==0){
		menuad();
		while(xulymenuad(t1) != 4){
			printf("\n");
			menuad();
		}
	}
	else{
		menusv();
		while(xulymenusv(t1) != 3){
			printf("\n");
			menusv();
		}
	}
}
void menu(){
	printf("1. dang nhap\n");
	printf("2. thoat\n");
}
int chonmenu(){
	int n=0;
	printf("\nchon chuc nang: ");
	scanf("%d",&n);
	if(n>0 || n<3) return n;
	else return chonmenu();	
}
void xulymenu(){
	int chon = chonmenu();
	switch(chon){
		case 1:
			printf("1. dang nhap\n");
			dangnhap();
			break;
		case 2:
			printf("2. thoat\n");
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

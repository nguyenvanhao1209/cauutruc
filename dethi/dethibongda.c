#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct doibong{
	int id;
	char ten[30];
	int diem;
	int sothang;
	int sothua;
};
typedef struct doibong doibong;
struct node{
	doibong data;
	struct node *next;
};
typedef struct node node;
node *createNode(doibong x){
    node *temp = (node*)malloc(sizeof(node));
    temp->next = NULL;
    temp->data = x;
    return temp;
}
node *addElement(node*p, doibong x){
	if(p == NULL){
		p = createNode(x);
		return p;
	}
	node *temp = createNode(x);
	p->next = temp;
	return temp;
}
node *searchNode(node *l,int x){
	node *p = l;
	while(p != NULL){
		if(p->data.id == x){
			return p;
		}
		p = p->next;
	}
	return NULL;
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
void printLisft(node *l){
	node *p = l;
	while(p != NULL){
		printf("%-10d%-20s%-10d%-10d%-10d\n",p->data.id,p->data.ten,p->data.diem,p->data.sothang,p->data.sothua);
		p = p->next;
	}
}
struct vong{
	char vongdau[10];
	int doi1;
	int doi2;
	int doi3;
	int doi4;
};
typedef struct vong vong;
node *l;
vong vongthu[3];
void inthongtindoi(){
	FILE *f;
	f = fopen("C:/Users/Administrator/Desktop/cachtinh.txt","r");
	if(f == NULL)
    {
    	perror("Khong the mo tep de doc.\n");
		return ;
    }
    int n;
    fscanf(f,"%d\n",&n);
    doibong x;
    fscanf(f,"%d\t",&x.id);
    fscanf(f,"%s\n",x.ten);
    x.diem = 0;
    x.sothang = 0;
    x.sothua = 0;
    l = createNode(x);
    node *p = l;
    int i;
    for(i=1;i<n;i++){
    	fscanf(f,"%d\t",&x.id);
    	fscanf(f,"%s\n",x.ten);
    	p = addElement(p,x);
    }
    printLisft(l);
    int j = 0;
    while(!feof(f)){
    	fscanf(f,"%s\n",vongthu[j].vongdau);
    	fscanf(f,"%d\t",&vongthu[j].doi1);
    	fscanf(f,"%d\n",&vongthu[j].doi2);
    	fscanf(f,"%d\t",&vongthu[j].doi3);
    	fscanf(f,"%d\n",&vongthu[j].doi4);
    	j++;
    }
}
void inthongtinlich(){
	int i = 0;
	for(i=0;i<3;i++){
		printf("%s\n",vongthu[i].vongdau);
		printf("%s - ",searchNode(l,vongthu[i].doi1)->data.ten);
		printf("%s\n",searchNode(l,vongthu[i].doi2)->data.ten);
		printf("%s - ",searchNode(l,vongthu[i].doi3)->data.ten);
		printf("%s\n",searchNode(l,vongthu[i].doi4)->data.ten);
	}
}
int vong_dau = 0;
void capnhatketqua(){
	if(vong_dau == 3){
		printf("Khong the cap nhat them giai dau da ket thuc\n");
		return ;
	}
	printf("nhap ket qua vong thu %d: \n",vong_dau+1);
	printf("%s\n",vongthu[vong_dau].vongdau);
	printf("%s - %s: ",searchNode(l,vongthu[vong_dau].doi1)->data.ten,searchNode(l,vongthu[vong_dau].doi2)->data.ten);
	int soban1,soban2;
	scanf("%d - %d",&soban1,&soban2);
	searchNode(l,vongthu[vong_dau].doi1)->data.sothang += soban1;
	searchNode(l,vongthu[vong_dau].doi1)->data.sothua += soban2;
	searchNode(l,vongthu[vong_dau].doi2)->data.sothang += soban2;
	searchNode(l,vongthu[vong_dau].doi2)->data.sothua += soban1;
	if(soban1 > soban2){
		searchNode(l,vongthu[vong_dau].doi1)->data.diem += 3;
	}
	else if(soban1 < soban2){
		searchNode(l,vongthu[vong_dau].doi2)->data.diem += 3;
	}
	else{
		searchNode(l,vongthu[vong_dau].doi1)->data.diem += 1;
		searchNode(l,vongthu[vong_dau].doi2)->data.diem += 1;
	}
	printf("%s - %s: ",searchNode(l,vongthu[vong_dau].doi3)->data.ten,searchNode(l,vongthu[vong_dau].doi4)->data.ten);
	int soban3,soban4;
	scanf("%d - %d",&soban3,&soban4);
	searchNode(l,vongthu[vong_dau].doi3)->data.sothang += soban3;
	searchNode(l,vongthu[vong_dau].doi3)->data.sothua += soban4;
	searchNode(l,vongthu[vong_dau].doi4)->data.sothang += soban4;
	searchNode(l,vongthu[vong_dau].doi4)->data.sothua += soban3;
	if(soban3 > soban4){
		searchNode(l,vongthu[vong_dau].doi3)->data.diem += 3;
	}
	else if(soban3 < soban4){
		searchNode(l,vongthu[vong_dau].doi4)->data.diem += 3;
	}
	else{
		searchNode(l,vongthu[vong_dau].doi3)->data.diem += 1;
		searchNode(l,vongthu[vong_dau].doi4)->data.diem += 1;
	}
	printLisft(l);
	vong_dau++;
}
void thongke(){
	node *p = l;
	int min = 1000;
	while(p != NULL){
		if(p->data.diem < min){
			min = p->data.diem;
		}
		p = p->next;
	}
	node *q = l;
	printf("ten cac doi diem thap: \n");
	while(q != NULL){
		if(q->data.diem == min){
			printf("%-10d%-20s%-10d%-10d%-10d\n",q->data.id,q->data.ten,q->data.diem,q->data.sothang,q->data.sothua);
			l = deleteNode(l,q);
		}
		q = q->next;
	}
	printf("ten cac doi con lai: \n");
	printLisft(l);
}
void menu(){
	printf("1. inthongtindoi\n");
	printf("2. inthongtinlich\n");
	printf("3. capnhatketqua\n");
	printf("4. thongke\n");
	printf("5. Thoat\n");
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
		    printf("1.inthongtindoi\n");
			inthongtindoi();
			break;
		case 2:
			printf("2. inthongtinlich\n");
			inthongtinlich();
			break;
		case 3:
		    printf("3. timkiemdiadiem\n");
			capnhatketqua();
			break;
		case 4:
			printf("4. timkiemthoigian\n");
			thongke();
			break;
		case 5:
			printf("6. Thoat\n");
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

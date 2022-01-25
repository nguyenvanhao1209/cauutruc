#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct lichsu{
	char diadiem[41];
	int gio;
	int phut;
};
typedef struct lichsu lichsu;
struct node{
	lichsu data;
	struct node *next;
};
typedef struct node node;
node *createNode(lichsu x){
    node *temp = (node*)malloc(sizeof(node));
    temp->next = NULL;
    temp->data = x;
    return temp;
}
node *addElement(node*p, lichsu x){
	if(p == NULL){
		p = createNode(x);
		return p;
	}
	node *temp = createNode(x);
	p->next = temp;
	return temp;
}
void printLisft(node *l){
	node *p = l;
	while(p != NULL){
		printf("%-40s%-10d%-10d\n",p->data.diadiem,p->data.gio,p->data.phut);
		p = p->next;
	}
}
node *l;
void docfile(){
	FILE *f;
	f = fopen("C:/Users/Administrator/Desktop/new.txt","r");
	if(f == NULL)
    {
    	perror("Khong the mo tep de doc.\n");
		return ;
    }
    lichsu x;
    fscanf(f,"%s\t",x.diadiem);
    fscanf(f,"%d\t",&x.gio);
    fscanf(f,"%d\n",&x.phut);
    l = createNode(x);
    node *p = l;
    while(!feof(f)){
	    fscanf(f,"%s\t",x.diadiem);
	    fscanf(f,"%d\t",&x.gio);
	    fscanf(f,"%d\n",&x.phut);
	    p = addElement(p, x);
    }
    fclose(f);
    printf("doc du lieu thanh cong\n");
}
void inralichsu(){
	printLisft(l);
}
void timkiemdiadiem(){
	node *p = l;
	char diadiemtim[41];
	printf("nhap dia diem can tim: ");
	fflush(stdin);
	gets(diadiemtim);
	int dem = 0;
	while(p != NULL){
		if(strcmp(p->data.diadiem,diadiemtim) == 0){
			if(dem != 0){
				printf(",");
			}
			printf("%d:%d",p->data.gio,p->data.phut);
			dem++;
		}
		p = p->next;
	}
	if(dem == 0){
		printf("ban chua toi dia diem do\n");
	}
}
void timkiemthoigian(){
	int giotim,phuttim;
	printf("nhap gio, phut, 0<=gio<24, 0<=phut<=60: ");
	scanf("%d %d",&giotim,&phuttim);
	while((giotim<0 || giotim>=24) || (phuttim<0 || phuttim>60)){
		printf("nhap lai: ");
		scanf("%d %d",&giotim,&phuttim);
	}
	node *p = l;
	int dem = 0;
	while(p != NULL){
		if(p->next->data.gio > giotim || (p->next->data.gio == giotim && p->next->data.phut > phuttim)){
			printf("%s",p->data.diadiem);
			dem++;
			break;
		}
		p = p->next;
	}
	if(dem == 0){
		printf("khong tim thay lich su di chuyen\n");
	}
}
void kiemtratruyvet(){
	char diadiemtim[41];
	printf("nhap dia diem can tim: ");
	fflush(stdin);
	gets(diadiemtim);
	int giotim,phuttim;
	printf("nhap gio, phut, 0<=gio<24, 0<=phut<=60: ");
	fflush(stdin);
	scanf("%d %d",&giotim,&phuttim);
	while((giotim<0 || giotim>=24) || (phuttim<0 || phuttim>60)){
		printf("nhap lai: ");
		scanf("%d %d",&giotim,&phuttim);
	}
	node *p = l;
	int dem = 0;
	while(p != NULL){
		if(p->next->data.gio > giotim || (p->next->data.gio == giotim && p->next->data.phut > phuttim)){
			if(strcmp(p->data.diadiem,diadiemtim) == 0){
				printf("ban co kha nang bi lay covid\n");
				dem++;
			}
			else{
				printf("lich su di chuyen ok\n");
				dem++;
			}
			break;
		}
		p = p->next;
	}
	if(dem == 0){
		printf("lich su di chuyen ok\n");
	}
}
void menu(){
	printf("1. docfile\n");
	printf("2. inralichsu\n");
	printf("3. timkiemdiadiem\n");
	printf("4. timkiemthoigian\n");
	printf("5. kiemtratruyvet\n");
	printf("6. Thoat\n");
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
		    printf("1.docfile\n");
			docfile();
			break;
		case 2:
			printf("2. inralichsu\n");
			inralichsu();
			break;
		case 3:
		    printf("3. timkiemdiadiem\n");
			timkiemdiadiem();
			break;
		case 4:
			printf("4. timkiemthoigian\n");
			timkiemthoigian();
			break;
		case 5:
			printf("5. kiemtratruyvet\n");
			kiemtratruyvet();
			break;
		case 6:
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

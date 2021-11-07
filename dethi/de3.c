#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct sinhvien{
	char name[20];
	int diem;
};
typedef struct sinhvien sinhvien;
struct node{
	sinhvien data;
	struct node *next;
};
typedef struct node node;
node *createNode(sinhvien x){
    node *temp = (node*)malloc(sizeof(node)); 
    temp->next = NULL; 
    temp->data = x;  
    return temp;
}
node *addElement(node*p, sinhvien x){
	node *temp = createNode(x); 
	p->next = temp; 
	return temp; 
}
node *addHead(node *l, sinhvien x){
	node *temp = (node*)malloc(sizeof(node)); 
	temp->data = x;
	temp->next = l;
	l = temp;
	return l;
}
node *addTail(node *l, sinhvien x){
	if(l == NULL){
		l = createNode(x);
		return l;
	}
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
void printList(node *l){
	node *p = l;
	while (p != NULL){
		printf("%-20s\t%d\n",p->data.name,p->data.diem);
		p = p->next;
	}
}
node* first;
node* second; 
void docfile(){
	FILE *f;
	f = fopen("C:/Users/Administrator/Desktop/new.txt","r");
	if (f == NULL)
    {
    	perror("Khong the mo tep de doc.\n");
		return ;
    }
    printf("doc file thu nhat\n");
    sinhvien x;
    fscanf(f,"%s\n",x.name);
    fscanf(f,"%d\n",&x.diem);
    first = createNode(x);
    node *p = first;
    int dem = 0;
    while(!feof(f)){
    	fscanf(f,"%s\n",x.name);
    	dem++;
    	if(feof(f)){
    		p = addElement(p, x);
    		break;
    	}
    	fscanf(f,"%d\n",&x.diem);
    	dem++;
    	p = addElement(p, x);
    }
    if(dem%2==1){
    	p = first;
    	while(p->next != NULL){
    		p = p->next;
    	}
    	printf("nhap diem cua sinh vien cuoi: ");
    	int tmp;
    	scanf("%d",&tmp);
    	p->data.diem = tmp;
    }
    fclose(f);
    printList(first);
    f = fopen("C:/Users/Administrator/Desktop/dothi.txt","r");
	if (f == NULL)
    {
    	perror("Khong the mo tep de doc.\n");
		return ;
    }
    printf("doc file thu hai\n");
    fscanf(f,"%s\n",x.name);
    fscanf(f,"%d\n",&x.diem);
    second = createNode(x);
   	p = second;
    dem = 0;
    while(!feof(f)){
    	fscanf(f,"%s\n",x.name);
    	dem++;
    	if(feof(f)){
    		p = addElement(p, x);
    		break;
    	}
    	fscanf(f,"%d\n",&x.diem);
    	dem++;
    	p = addElement(p, x);
    }
    if(dem%2==1){
    	p = second;
    	while(p->next != NULL){
    		p = p->next;
    	}
    	printf("nhap diem cua sinh vien cuoi: ");
    	int tmp;
    	scanf("%d",&tmp);
    	p->data.diem = tmp;
    }
    fclose(f);
    printList(second);
}
void timkiem(){
	printf("nhap diem tim kiem: ");
	int x;
	scanf("%d",&x);
	node *p = first;
	int dem = 0;
	printf("===LOP THU NHAT===\n");
	while(p != NULL){
		if(p->data.diem>=x){
			printf("%-20s\t%d\n",p->data.name,p->data.diem);
			dem++;
		}
		p = p->next;
	}
	node *q = second;
	printf("===LOP THU HAI===\n");
	while(q != NULL){
		if(q->data.diem>=x){
			printf("%-20s\t%d\n",q->data.name,q->data.diem);
			dem++;
		}
		q = q->next;
	}
	if(dem == 0){
		printf("Khong co sinh vien nao trong hai lop co diem lon hon x");
	}	
}
node *excellent = NULL;
void danhsachxuatsac(){
	node *p =  first;
	while(p != NULL){
		if(p->data.diem >= 8){
			excellent = addTail(excellent,p->data);
		}
		p = p->next;
	}
	node *q = second;
	while(q != NULL){
		if(q->data.diem >= 8){
			excellent = addTail(excellent,q->data);
		}
		q = q->next;
	}	
	printList(excellent);
}
void ghifile(){
	FILE *f1;
	f1 = fopen("C:/Users/Administrator/Desktop/cauhoi.txt","w");
	node *p = excellent;
	while(p != NULL){
		fprintf(f1,"%s\t",p->data.name);
		fprintf(f1,"%d\n",p->data.diem);
		p = p->next;
	}
	fclose(f1);
}
void gopdanhsach(){
	node *p = first;
	node *p1;
	for(p = first;p != NULL; p = p->next){
		for(p1 = p->next; p1 != NULL; p1 = p1->next){
			if(p->data.diem<p1->data.diem){
				sinhvien temp = p->data;
				p->data = p1->data;
				p1->data = temp;				
			}
		}
	}
	node *q = second;
	node *q1;
	for(q = second;q != NULL; q = q->next){
		for(q1 = q->next; q1 != NULL; q1 = q1->next){
			if(q->data.diem<q1->data.diem){
				sinhvien temp = q->data;
				q->data = q1->data;
				q1->data = temp;				
			}
		}
	}
	node *moi = NULL;
	node *a = first;
	node *b = second;
	while(a != NULL || b != NULL){
		if(a == NULL){
			while(b != NULL){
				moi = addTail(moi,b->data);
				b = b->next;
			}
			break;
		}
		if(b == NULL){
			while(a != NULL){
				moi = addTail(moi,a->data);
				a = a->next;
			}
			break;
		}
		if(a->data.diem >= b->data.diem){
			moi = addTail(moi,a->data);
			a = deleteHead(a);
		}
		else{
			moi = addTail(moi,b->data);
			b = deleteHead(b);
		}
	}
	printList(moi);
	
}
void menu(){
	printf("1. docfile\n");
	printf("2. timkiem\n");
	printf("3. danhsachxuatsac\n");
	printf("4. ghifile\n");
	printf("5. gopdanhsach\n");
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
			printf("2. timkiem\n");
			timkiem();
			break;
		case 3:
		    printf("3. danhsachxuatsac\n");
		    danhsachxuatsac();
			break;
		case 4:
			printf("4. ghifile\n");
			ghifile();
			break;
		case 5:
			printf("5. gopdanhsach\n");
			gopdanhsach();
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

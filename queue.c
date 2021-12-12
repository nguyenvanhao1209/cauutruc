#include<stdio.h>
#include<stdlib.h>
struct queueNode{
	int data;
	struct queueNode *next;
};
typedef struct queueNode queueNode;
struct queue{
	queueNode *front;
	queueNode *rear;
};
typedef struct queue queue;
queueNode* createNode(int x){
	queueNode* temp = (queueNode*)malloc(sizeof(queueNode));
	temp->data = x;
	temp->next = NULL;
	return temp; 
}
queue* createQueue(){
	queue* q = (queue*)malloc(sizeof(queue));
	q->front = NULL;
	q->rear = NULL;
	return q;
}
void enQueue(queue* q, int x){
	queueNode* temp = createNode(x);
	if(q->rear == NULL){
		q->front = temp;
		q->rear = temp;
		return ;
	}
	q->rear->next = temp;
	q->rear = temp;
}
void deQueue(queue* q){
	if(q->front == NULL){
		q->rear = NULL;
		return ; 
	}
	queueNode* temp = q->front;
	q->front = q->front->next;
	free(temp);
}
int main(){
	queue *q = createQueue();
	int i;
	for(i=0;i<10;i++){
		enQueue(q,i);
	}
	while(q->front != NULL){
		printf("%d ",q->front->data);
		deQueue(q);
	}
}

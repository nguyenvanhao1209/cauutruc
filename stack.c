#include<stdio.h>
#include<stdlib.h>
struct stackNode{
	int data;
	struct stackNode *next;
};
typedef struct stackNode stackNode;
struct stack{
	stackNode *top;
};
typedef struct stack stack;
stack *stackConstruct(){
	stack *s;
	s = (stack *)malloc(sizeof(stack));
	if(s == NULL) return NULL;
	s->top = NULL;
	return s;
}
int stackEmpty(stack *s){
	return s->top == NULL;
}
void stackPush(stack *s,int x){
	stackNode *node;
	node = (stackNode *)malloc(sizeof(stackNode));
	node->data = x;
	node->next = s->top;
	s->top = node;
}
void stackPop(stack *s){
	stackNode *node;
	if(stackEmpty(s)){
		return;
	}
	node = s->top;
	s->top = node->next;
	free(node);
}
void stackDestroy(stack *s){
	while(!stackEmpty(s)){
		stackPop(s);
	}
	free(s);
}
int main(){
	stack *s = stackConstruct();
	int i;
	for(i=0;i<10;i++){
		stackPush(s,i);
	}
	while(!stackEmpty(s)){
		printf("%d ",s->top->data);
		stackPop(s);
	}
	stackDestroy(s);
}

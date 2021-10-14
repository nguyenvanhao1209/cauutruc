#include<stdio.h>
int x[100];
int m[100];
int n;
void printSolution(){
	int i;
	for(i = 1; i<= n; i++)
		printf("%d ",x[i]);
	printf("\n");
}

void TRY(int i) {
	int v;
	for(v = 1; v <= n; v++){
		if(!m[v]) {
		x[i] = v;
		m[v] = 1; 
		if(i == n)
			printSolution();
		else TRY(i+1);
		m[v] = 0;
		}
	}
}

int main() {
	int v;
	scanf("%d",&n);
	for(v = 1; v <= n; v++)
		m[v] = 0;
	TRY(1);
}

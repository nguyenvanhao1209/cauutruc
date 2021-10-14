#include<stdio.h>
#include<math.h>
int x[100];

int n=4;

void printSolution(){
	int i;
	for(i = 1; i<= n; i++)
		printf("%d ",x[i]);
	printf("\n");
}

int check(int v, int k) {
	int i;
	for(i = 1; i <= k-1; i++) {
		if(x[i] == v) return 0;
		if(fabs(v-x[i])==k-i) return 0;
	}
	return 1;
}

void TRY(int k) {
	int v;
	for(v = 1; v <= n; v++){
		if(check(v,k)) {
		x[k] = v;
		if(k == n)
			printSolution();
		else TRY(k+1);
		}
	}
}

int main() {
	int i;
	for(i = 1; i<= n; i++){
		x[i]=0;
	}
	TRY(1);
}

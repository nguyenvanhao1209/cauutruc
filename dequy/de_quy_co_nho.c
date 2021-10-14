#include<stdio.h>
#define MAX 200
int m[MAX][MAX];
int C(int k, int n) {
	if (k == 0 || k == n)
		m[k][n] = 1;
	else {
		if(m[k][n] < 0){
			m[k][n] = C(k-1,n-1) + C(k,n-1);
	}
	}
	return m[k][n];
}
int main() {
	int i,j;
	for(i = 0; i < MAX; i++)
		for(j = 0; j < MAX; j++)
			m[i][j] = -1;
	printf("%d\n",C(16,32));
}

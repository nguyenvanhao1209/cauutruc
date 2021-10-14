#include<stdio.h>
#include<math.h>
int x[100][100];

void printSolution(){
	int i,j;
	for(i = 0; i< 9; i++){
		printf("\n");
		for(j = 0; j < 9; j++)
			printf("%d ",x[i][j]);
	}	
	printf("\n");
}

int check(int v, int r,int c) {
	int m,n;
	for(m = 0; m <= r-1; m++)
		if(x[m][c] == v) return 0;
	for(n = 0; n <= c-1; n++)
		if(x[r][n] == v) return 0;
	int I = r/3;
	int J = c/3;
	int i = r - 3*I;
	int j = c - 3*J;
	int i1,j1;
	for(i1 = 0; i1 <= i-1; i1++)
		for(j1 = 0; j1 <= 2; j1++)
			if(x[3*I+i1][3*J+j1] == v) return 0;
	for(j1 = 0; j1 <= j-1; j1++)
		if(x[3*I+i][3*J+j1] == v)
			return 0;
	return 1;			
}

void TRY(int r, int c) {
	int v;
	for(v = 1; v <= 9; v++){
		if(check(v,r,c)) {
		x[r][c] = v;
		if(r == 8 && c == 8)
			printSolution();
		else {
			if(c == 8) TRY(r+1,0);
			else TRY(r,c+1);
		}
		}
	}
}

int main() {
	int i,j;
	for(i = 0; i<= 8; i++){
		for(j = 0; j<= 8; j++)
			x[i][j]=0;
	}
	TRY(0,0);
}

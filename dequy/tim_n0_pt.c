#include <stdio.h>
int x[3];
int a[3] = {1,2,1};
int m = 5,n = 3;
void solution(){
	int i;
	for(i = 0; i< n; i++)
		printf("%d ",x[i]);
	printf("\n");
}
void TRY(int i,int k){
	int j;
	for(j = 1; j <= m/a[i]; j++){
		x[i] = j;
		if(i == n){
			if(k == m){
				solution();
			}
			return ;
		}
	else TRY(i+1,k+x[i]*a[i]);
	}
}
int main(){
	TRY(0,0);
}

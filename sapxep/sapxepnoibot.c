#include<stdio.h>
void bubleSort(int A[],int n){
	int i,j;
	for(i=n-1;j>=0;i--){
		for(j=1;j<=i;j++){
			if(A[j-1]>A[j]){
				int temp = A[j-1];
				A[j-1] = A[j];
				A[j] = temp;
			}
		}	
	}
}
//tot nhat: 0 doi cho, n(n-1)/2 so sanh
//toi nhat: n(n-1)/2 doi cho va so sanh
//trung binh: n(n-1)/4 doi cho, n(n-1)/2 so sanh

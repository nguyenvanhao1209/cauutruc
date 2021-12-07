#include<stdio.h>
void insertionSort(int A[],int n){
	int i,j,last;
	for(i=1;i<n;i++){
		last = A[i];
		j = i;
		while((j>0) && (A[j-1]>last)){
			A[j] = A[j-1];
			j--;
		}
		A[j] = last;
	}
}
//tot nhat: 0 hoan doi, n-1 so sanh
//toi nhat: n(n-1)/2 hoan doi va so sanh
//trung binh: n(n-1)/4 hoan doi va so sanh

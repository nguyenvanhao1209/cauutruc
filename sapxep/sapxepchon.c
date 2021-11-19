#include<stdio.h>
void selectionSort(A[],int n){
	int i,j;
	int min;
	for(i=0;i<n;i++){
		min = i;
		for(j=i+1;i<n;j++){
			if(A[min]>A[j]) min = j;
		}
		int temp = A[min];
		A[min] = A[k];
		A[k] = temp;
	}
}

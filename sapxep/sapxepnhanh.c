#include<stdio.h>
void quickSort(int A[],int l,int r){
	int p = A[(l+r)/2];
	int i = l,j = r;
	while(i<j){
		while(A[i]<p){
			i++;
		}
		while(A[j]>p){
			j--;
		}
		if(i<=j){
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
			i++;
			j--;
		}
	}
	if(i<r){
		quickSort(A,i,r);
	}
	if(l<j){
		quickSort(A,l,j);''
	}
}
//trung binh: O(nlogn)
//toi nhat: O(n^2)

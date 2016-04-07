#include <stdio.h>
/*
1.Choose a pivot value. We take the value of the middle element as pivot value,
but it can be any value, which is in range of sorted values, even if it doesn't 
present in the array.

2.Partition. Rearrange elements in such a way, that all elements which are lesser 
than the pivot go to the left part of the array and all elements greater than the 
pivot, go to the right part of the array. Values equal to the pivot can stay in 
any part of the array. Notice, that array may be divided in non-equal parts.

3.Sort both parts. Apply quicksort algorithm recursively to the left and right parts.
*/
void swap(int *a,int *b){
	int t=*a;
	*a=*b;
	*b=t;
}

void quickSort(int *arr,int low,int high){
	int pivot=arr[(high+low)/2];
	int i=low,j=high;
	while(i<j){
		while(arr[i]<pivot) i++;
		while(arr[j]>pivot) j--;
		if(i<=j)
			swap(&arr[i++],&arr[j--]);
	}
	if(low<j)	quickSort(arr,low,j);
	if(i<high)	quickSort(arr,i,high);
}

int main(){
	int arr[]={1,3,7,3,5,9,0,1};
	int length=sizeof(arr)/sizeof(arr[0]);
	quickSort(arr,0,length-1);
	for (int i = 0; i < length; ++i){
		printf("%d,",arr[i] );
	}
}
#include <stdio.h>

void merge(int *arr,int left,int mid,int right){
	int sizeL=mid-left+1;
	int sizeR=right-mid;
	int subL[sizeL];
	int subR[sizeR];
	int k=left;
	for(int i=0;i<sizeL;i++) subL[i]=arr[k++];
	for(int i=0;i<sizeR;i++) subR[i]=arr[k++];

	int i=0,j=0;
	k=left;
	while (i < sizeL && j < sizeR) {
		if(subL[i]<=subR[j])
			arr[k++]=subL[i++];
		else
			arr[k++]=subR[j++];
	}
	while(i<sizeL) arr[k++]=subL[i++];
	while(j<sizeR) arr[k++]=subR[j++];
}

void mergeSort(int *arr,int left,int right){
	if(left<right){
		int mid=left+(right-left)/2;
		mergeSort(arr,left,mid);
		mergeSort(arr,mid+1,right);
		merge(arr,left,mid,right);
	}
}

int main(){
	int arr[]={9,3,6,2,8,4,7,0};
	int size=sizeof(arr)/sizeof(arr[0]);
	mergeSort(arr,0,size-1);
	for(int i=0;i<size;i++)
		printf("%d,",arr[i]);
}
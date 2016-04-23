#include <stdio.h>

static int counter=0;

void swap(int *a,int *b){
  int t=*a;
  *a=*b;
  *b=t;
  counter++;
}

inline int less(int a,int b){
  counter++;
  return a<b;
}

void sellSort(int a[],int size){
  // Magic increment sequence
  static int incs[]= { 1391376, 463792, 198768, 86961,33936, 13776,
                        4592, 1968, 861,336, 109, 41, 19, 5, 1 };
  int length=sizeof(incs)/sizeof(incs[0]);
  for (int k = 0; k < length; k++){
    int h = incs[k];
    for (int i = h; i < size; i++)
      for (int j = i; j >= h; j-= h)
        if (less(a[j],a[j-h]))
          swap(&a[j],&a[j-h]);
        else break;
  }
}

int main(){
  int arr[]={1,5,9,1,5,7,3,0,6,7,3,4,2};
  int size=sizeof(arr)/sizeof(arr[0]);
  sellSort(arr,size);
  for(int i=0;i<size;i++)
    printf("%d,",arr[i]);
  printf("\ncount=%d\n",counter);
}
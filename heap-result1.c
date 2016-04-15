#include <stdlib.h>
#include <math.h>
/////////////////Heap/////////////////////////
struct heap{
    int size;
    int capacity;
    int *data;
};

int initHeap(heap **h,int size)
{
    heap *temp=(heap *)malloc(sizeof(heap));
    if(temp==NULL)
        return 0;
    temp->capacity=size;
    temp->size=-1;
    temp->data=(int *)malloc(size*sizeof(int));
    if(temp->data==NULL)
        return 0;
    *h=temp;
    return 1;
}

int leftChild(int key)
{
    return key*2+1;
}

int rightChild(int key)
{
    return key*2+2;
}

int parent(int key)
{
    return (key-1)/2;
}

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void printHeap(heap *h)
{
    if(h==NULL||h->size==-1)
        return;

    printf("\nHeap:\n");
    int i,j=0;
    for(i=0;i<=h->size;i++)
    {
        printf("%d\t",h->data[i]);
        if(i==0||i==2||i==8)
            printf("\n");
    }
    printf("\n");
}
//heapify a subtree at a given index
int minHeapify(heap *h,int index)
{
    int left,right,min;
    if(h==NULL||index>=h->size)
        return 0;

    left=leftChild(index);
    right=rightChild(index);
    min=index;

    if(left<=h->size&&h->data[left]<h->data[min])
        min=left;
    if(right<=h->size&&h->data[right]<h->data[min])
        min=right;
    if(min==index)
        return 0;
    swap(&(h->data[index]),&(h->data[min]));
    minHeapify(h,min);
    return 1;
}


int extractHeapRoot(heap *h,int *data)
{
    if(h==NULL||h->size==-1)
        return 0;
    *data=h->data[0];
    h->data[0]=h->data[h->size--];
    //printf("---");
    //printHeap(h);
    minHeapify(h,0);
    return 1;
}

int insertHeap(heap *h,int data)
{
    if(h==NULL||h->size+1==h->capacity)
        return 0;
    h->size++;
    h->data[h->size]=data;
    int i=h->size;

    //if the value is smaller than its parent,
    //swap the value and maintain the min heap property
    while(i!=0&&h->data[i]<h->data[parent(i)])
    {
        swap(&h->data[i],&h->data[parent(i)]);
        i=parent(i);
    }
}

int changeHeapkey(heap *h,int key,int data)
{
    if(h==NULL||key>h->size)
        return 0;
    h->data[key]=data;

    int i=key;
    //if the value is smaller than its parent,
    //swap the value and maintain the min heap property
    while(i!=0&&h->data[i]<h->data[parent(i)])
    {
        swap(&h->data[i],&h->data[parent(i)]);
        i=parent(i);
    }
}

int deleteHeapKey(heap *h,int key)
{
    if(h==NULL||key>h->size)
        return 0;
    changeHeapkey(h,key,-1000);
    int temp;
    return extractHeapRoot(h,&temp);
}

int peekHeap(heap *h,int *data)
{
    if(h==NULL||h->size==-1)
        return 0;
    *data=h->data[0];
    return 1;
}


/////////////////Heap/////////////////////////

int main(int argc, char *argv[])
{
    heap *myHeap=NULL;
    initHeap(&myHeap,11);
    insertHeap(myHeap,3);
    insertHeap(myHeap,2);
    deleteHeapKey(myHeap,1);
    insertHeap(myHeap,15);
    insertHeap(myHeap,5);
    insertHeap(myHeap,4);
    insertHeap(myHeap,45);
    int temp;
    extractHeapRoot(myHeap,&temp);
    printf("%d ",temp);
    peekHeap(myHeap,&temp);
    printf("%d ",temp);
    changeHeapkey(myHeap,2,1);
    peekHeap(myHeap,&temp);
    printf("%d ",temp);
    /*
    extractHeapRoot(myHeap,&temp);
    printf("%d ",temp);
    extractHeapRoot(myHeap,&temp);
    printf("%d ",temp);
    extractHeapRoot(myHeap,&temp);
    printf("%d ",temp);
    extractHeapRoot(myHeap,&temp);
    printf("%d ",temp);
    extractHeapRoot(myHeap,&temp);
    printf("%d ",temp);
    */
}

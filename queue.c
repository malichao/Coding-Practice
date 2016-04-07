#include <stdlib.h>
#include <math.h>
/////////////////Queue/////////////////////////
struct queue
{
    int head,rear;
    unsigned int size;
    unsigned int capacity;
    int *data;
};

int initQueue(queue **q,unsigned int capacity)
{
    queue *temp=(queue *)malloc(sizeof(queue));
    if(temp==NULL)
        return 0;
    temp->head=-1;
    temp->rear=-1;
    temp->data=(int *)malloc(capacity*sizeof(int));
    if(temp->data==NULL)
        return 0;
    temp->size=0;
    temp->capacity=capacity;
    *q=temp;
    return 1;
}
int isQueueFull(queue *s)
{
    if(s==NULL)
    {
        printf("Queue is not initialized!\n");
        return -1;
    }
    if(s->size==s->capacity)
    {
        printf("Queue is full!\n");
        return 1;
    }
    qprintf("Queue is %d/%d\n",s->size,s->capacity);
    return 0;
}

int isQueueEmpty(queue *s)
{
    if(s==NULL)
    {
        printf("Queue is not initialized!\n");
        return -1;
    }
    if(s->size==0)
    {
        printf("Queue is empty!\n");
        return 1;
    }
    qprintf("Queue is %d/%d\n",s->size,s->capacity);
    return 0;
}

int enQueue(queue *q,int data)
{
    if(isQueueFull(q))
        return 0;
    q->rear=(q->rear+1)%q->capacity;
    q->size++;
    q->data[(q->rear)]=data;
    return 1;
}

int deQueue(queue *q,int *data)
{
    if(isQueueEmpty(q))
        return 0;
    q->head=(q->head+1)%q->capacity;
    q->size--;
    data[0]=q->data[q->head];
    return 1;
    //return q->data[q->head];
}
/////////////////Queue/////////////////////////

int main(int argc, char *argv[])
{
    
    queue *myQueue=NULL;
    int temp=0;
    initQueue(&myQueue,4);
    enQueue(myQueue,1);
    enQueue(myQueue,2);
    enQueue(myQueue,3);
    enQueue(myQueue,4);
    enQueue(myQueue,5);
    if(deQueue(myQueue,&temp)==1) printf("queue out %d\n",temp);
    if(deQueue(myQueue,&temp)==1) printf("queue out %d\n",temp);
    if(deQueue(myQueue,&temp)==1) printf("queue out %d\n",temp);
    if(deQueue(myQueue,&temp)==1) printf("queue out %d\n",temp);
    if(deQueue(myQueue,&temp)==1) printf("queue out %d\n",temp);
    
}
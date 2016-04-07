/////////////////Stack/////////////////////////
typedef struct stack
{
    int top;
    unsigned int size;
    int *data;
};

int initStack(stack ** s,unsigned int size)
{
    if(size==0)
        return 0;
    stack *temp=(stack*) malloc(sizeof(stack));
    temp->size=size;
    temp->top=-1;
    temp->data=(int*)malloc(size*sizeof(int));
    if(temp->data==NULL)
        return 0;
    *s=temp;
    return 1;
}
int isStackEmpty(stack *s)
{
    if(s==NULL)
    {
        qprintf("stack is not initialized!\n");
        return -1;
    }
    if(s->top==-1)
        qprintf("stack is empty.\n");
    else
        qprintf("stack is %d/%d\n",s->top+1,s->size);
    return (s->top==-1);
}
int isStackFull(stack *s)
{
    if(s==NULL)
    {
        qprintf("stack is not initialized!\n");
        return -1;
    }
    if(s->top+1==s->size)
        qprintf("stack is full.\n");
    else
        qprintf("stack is %d/%d\n",s->top+1,s->size);
    return (s->top+1==s->size);
}
int pushStack(stack *s,int data)
{
    if(s==NULL)
        return 0;
    if(isStackFull(s))
        return 0;
    s->data[++(s->top)]=data;
    return 1;
}
int popStack(stack *s)
{
    if(s==NULL)
        return 0;
    if(isStackEmpty(s))
        return 0;
    return s->data[(s->top)--];
}

int peekStack(stack *s)
{
    if(s==NULL)
        return 0;
    if(s->top==-1)
    {
        qprintf("warning:stack empty!\n");
        return 0;
    }
    return s->data[s->top];
}
/////////////////Stack/////////////////////////

int main(int argc, char *argv[])
{
    stack *myStack=NULL;
    unsigned int stackSize=5;
    int test=0;
    isStackEmpty(myStack);
    isStackFull(myStack);
    initStack(&myStack,stackSize);
    pushStack(myStack,1);
    pushStack(myStack,2);
    pushStack(myStack,3);

    test=peekStack(myStack);
    printf("popped %d\n",popStack(myStack));
    printf("popped %d\n",popStack(myStack));
    printf("popped %d\n",popStack(myStack));
    isStackEmpty(myStack);
    isStackFull(myStack);

}
/////////////////Linked List/////////////////////////
typedef struct node
{
  int data;
  struct node *next;
};

void printNode(struct node* n)
{
  while(n!=NULL)
  {
    qprintf("%d ",n->data);
    n=n->next;
  }
  qprintf("\n");
}

void appendNode(struct node** head_ref,int data)
{
  node *temp=(node *)malloc(sizeof(node));
  node *last=*head_ref;

  temp->data=data;
  temp->next=NULL;
  if(*head_ref==NULL)
  {
    *head_ref=temp;
    return;
  }
  while(last->next!=NULL)
  {
    last=last->next;
  }
  last->next=temp;
}

int deleteNode(node** head_ref,int position)
{
  node *temp=*head_ref,*prev;
  int count=0;
  if(position==0&& *head_ref!=NULL)
  {
    *head_ref=temp->next;
    free(temp);
    return 1;
  }
  count=1;
  prev=temp;
  temp=temp->next;
  while(temp->next!=NULL&&count<position)
  {
    count++;
    prev=temp;
    temp=temp->next;
  }

  if(count==position)
  {
    prev->next=temp->next;
    free(temp);
    return 1;
  }
  return -1;
}
/* Function to swap nodes x and y in linked list by
   changing links */
void swapNodes(struct node **head_ref, int x, int y)
{
   // Nothing to do if x and y are same
   if (x == y) return;

   // Search for x (keep track of prevX and CurrX
   struct node *prevX = NULL, *currX = *head_ref;
   while (currX && currX->data != x)
   {
       prevX = currX;
       currX = currX->next;
   }

   // Search for y (keep track of prevY and CurrY
   struct node *prevY = NULL, *currY = *head_ref;
   while (currY && currY->data != y)
   {
       prevY = currY;
       currY = currY->next;
   }

   // If either x or y is not present, nothing to do
   if (currX == NULL || currY == NULL)
       return;

   // If x is not head of linked list
   if (prevX != NULL)
       prevX->next = currY;
   else // Else make y as new head
       *head_ref = currY;

   // If y is not head of linked list
   if (prevY != NULL)
       prevY->next = currX;
   else  // Else make x as new head
       *head_ref = currX;

   // Swap next pointers
   struct node *temp = currY->next;
   currY->next = currX->next;
   currX->next  = temp;
}
void swapNode(node **head_ref,int nodeA,int nodeB)
{
  if(nodeA==nodeB)
    return ;
  node *temp=(node*)malloc(sizeof(node));//for swap
  node *prevA=NULL,*prevB=NULL;
  node *curA=NULL,*curB=NULL;
  int countA=0,countB=0;


    prevA=NULL;
    curA=*head_ref;
    while(countA<nodeA&&curA!=NULL)
    {
      countA++;
      prevA=curA;
      curA=curA->next;
    }

    //getchar();
    prevB=NULL;;
    curB=*head_ref;
    while(countB<nodeB&&curB!=NULL)
    {
      countB++;
      prevB=curB;
      curB=curB->next;
    }
        //qprintf("countA=%d,countB=%d\n",countA,countB);
    //getchar();

  if((countA>nodeA)||(countB>nodeB)||curA==NULL||curB==NULL)
    return;
  if(prevA==NULL)
    *head_ref=curB;
  else
    prevA->next=curB;
  if(prevB==NULL)
    *head_ref=curA;
  else
    prevB->next=curA;

  temp->next=curA->next;
  curA->next=curB->next;
  curB->next=temp->next;
}

int insertNodeAt(node** head_ref,int position,int data)
{
  node *temp=(node *)malloc(sizeof(node));
  node *prev=*head_ref;
  int count=0;

  temp->data=data;
  temp->next=NULL;
  if(*head_ref==NULL)
  {
    *head_ref=temp;
    return 1;
  }

  count=1;
  while(count<position&&prev->next!=NULL)
  {
    count++;
    prev=prev->next;
  }
  if(count==position)
  {
    temp->next=prev->next;
    prev->next=temp;
    return 1;
  }
  //otherwise,position doesn't exist
  return -1;
}

int invertNode(node **head_ref)
{
    if((*head_ref)==NULL or (*head_ref)->next==NULL)
        return 0;
    node *prev=NULL,*cur=NULL,*next=NULL;
    prev=*head_ref;
    cur=(*head_ref)->next;
    next=cur;
    prev->next=NULL;
    while(next!=NULL)
    {
        next=next->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    *head_ref=prev;
}
static void reverse(struct node** head_ref)
{
    struct node* prev   = NULL;
    struct node* current = *head_ref;
    struct node* next;
    while (current != NULL)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

void pushNode(struct node** head_ref,int data)
{
  node *temp=(node*)malloc (sizeof (node));
  temp->data=data;
  temp->next=*head_ref;
  *head_ref=temp;

}
/////////////////Linked List/////////////////////////

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    /*
    struct node *a=NULL;
    struct node *b=NULL;
    struct node *c=NULL;
    a=(struct node *)malloc(sizeof(struct node));
    b=(struct node *)malloc(sizeof(struct node));
    c=(struct node *)malloc(sizeof(struct node));
    a->data=1;
    a->next=b;
    b->data=2;
    b->next=c;
    c->data=3;
    c->next=NULL;
    printNode(a);
    */
    node *head=NULL;
    //append(&head,1);
    //push(&head,2);
    /*
    insertNodeAt(&head,0,2);
    insertNodeAt(&head,1,3);
    insertNodeAt(&head,2,4);
    insertNodeAt(&head,3,5);
    printNode(head);
    deleteNode(&head,0);
    printNode(head);
    */
    pushNode(&head, 1);
    pushNode(&head, 2);
    pushNode(&head, 3);
    pushNode(&head, 4);
    pushNode(&head, 5);
    printNode(head);
    //deleteNode(&head, 4);
    //swapNode(&head,5,4);
    //swapNodes(&head,7,1);
    invertNode(&head);
    printNode(head);
}
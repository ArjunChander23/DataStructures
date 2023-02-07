#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
};
typedef struct node *NODE;
NODE getnode()
{
    struct node * x;
    x=(NODE)malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("Memory not available\n");
        exit(0);
    }
    return x;
}
void ins_front(NODE head,int ele)
{
    NODE temp,next;
    temp=getnode();
    temp->info=ele;
    next=head->link;
    head->link=temp;
    temp->link=next;
}
void ins_rear(NODE head,int ele)
{
    NODE temp;
    NODE cur;
    cur=head;
    while(cur->link!=head)
    cur=cur->link;
    temp=getnode();
    temp->info=ele;
    cur->link=temp;
    temp->link=head;   
}
void del_front(NODE head)
{
    NODE first,next;
    if(head->link==head)
    {
        printf("Empty CLL with header\n");
        return;
    }
    first=head->link;
    next=first->link;
    printf("Element deleted is %d\n",first->info);
    free(first);
    head->link=next;

}
void del_rear(NODE head)
{
    NODE prev,cur;
    if(head->link==head)
    {
        printf("Empty CLL with header\n");
        return;
    }
    prev=NULL;
    cur=head;
    while(cur->link!=head)
    {
        prev=cur;
        cur=cur->link;
    }
    printf("Deleted element is %d\n",cur->info);
    free(cur);
    prev->link=head;
} 
void display(NODE head)
{
    NODE cur;
    if(head->link==head)
        printf("Circular SLL with header is empty\n");
    else
    {
        printf("Elements of CLL with header\n");
        cur=head->link;
        while(cur!=head)
        {
            printf("%d\n",cur->info);
            cur=cur->link;
        }

    }
}
int main()
{
    int ch,ele;
    NODE head;
    head=getnode();
    head->link=head;
    while(1)
    {
        printf("1.Insert Front 2.Insert Rear 3.Delete Front 4.Delete Rear 5.Display 6.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                    printf("Enter an element\n");
                    scanf("%d",&ele);
                    ins_front(head,ele);
                    break;
            case 2:
                    printf("Enter an element\n");
                    scanf("%d",&ele);
                    ins_rear(head,ele);
                    break;
            case 3:
                    del_front(head);
                    break;
            case 4:
                    del_rear(head);
                    break;
            case 5:
                    display(head);
                    break;
            default: 
                    exit(0);
        }
    }
    return 0;
}
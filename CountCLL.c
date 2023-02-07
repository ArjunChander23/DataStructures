#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node * getnode()
{
    struct node * x;
    x=(struct node *)malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("Memory not available");
        exit(0);
    }
    return x;
}
struct node * ins_front(struct node * last,int ele)
{
    struct node * temp;
    temp=getnode();
    temp->info=ele;
    if(last==NULL)
    last=temp;
    else
    temp->link=last->link;
    last->link=temp;
    return last;
}
int count_sll(struct node * last)
{
    int count=1;
    if(last==NULL)
    return count;
    if(last->link==NULL)
    {
        count++;
        return count;
    }
    struct node * first=last->link;
    while(first->link!=last)
    {
        count++;
        first->link=last->link;
    }
    count++;
    return count;
}
int main()
{
    struct node * last=NULL;
    int ch,ele,res;
    while(1)
    {
        printf("1.Insert Front 2.Count 3.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                    printf("Enter the element\n");
                    scanf("%d",&ele);
                    last=ins_front(last,ele);
                    break;
            case 2:
                    res=count_sll(last);
                    printf("Count=%d\n",res);
                    break;
            default:
                    exit(0);
                    
        }
    }
    return 0;
}


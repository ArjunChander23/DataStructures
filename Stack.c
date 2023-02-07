#include<stdio.h>
#include<stdlib.h>
#define max_size 4
void push(int s[max_size],int *top,int ele)
{
    if((*top)==max_size-1)
    {
        printf("Overflow\n");
        return;
    }
    (*top)++;
    s[*top]=ele;
}
void pop(int s[max_size],int *top)
{
    int ele;
    if((*top)==-1)
    {
        printf("Underflow\n");
        return;
    }
    ele=s[*top];
    printf("Deleted element is %d\n",ele);
    (*top)--;
}
void display(int s[max_size],int top)
{
    for(int i=0;i<=top;i++)
    printf("%d\n",s[i]);
}
int main()
{
    int s[max_size],top=-1,ch,ele;
    while(1)
    {
        printf("Enter 1.Push 2.Pop 3.Display 4.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                    printf("Enter the element to be pushed\n");
                    scanf("%d",&ele);
                    push(s,&top,ele);
                    break;
            case 2:
                    pop(s,&top);
                    break;
            case 3:
                    display(s,top);
                    break;
            default:
                    exit(0);
        }
    }
    return 0;
}
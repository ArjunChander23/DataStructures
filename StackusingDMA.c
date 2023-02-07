#include<stdio.h>
#include<stdlib.h>
void push(int *s,int *top,int ele)
{
    (*top)++;
    if((*top)==0)
    s[*top]=ele;
    else
    {
        s=(int *)realloc(s,sizeof(int)*((*top)+1));
        s[*top]=ele;
    }
}
void pop(int *s,int *top)
{
    int ele;
    if(*top==-1)
    {
        printf("Underflow\n");
        return;
    }
    ele=s[*top];
    (*top)--;
    if(*top==-1)
    return;
    s=(int *)realloc(s,sizeof(int)*((*top)+1));
}
void display(int *s,int top)
{
    for(int i=0;i<=top;i++)
    printf("%d\n",s[i]);
}
int main()
{
    int *s,top=-1,ch,ele;
    s=(int *)malloc(sizeof(int));
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
}

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct poly
{
    int cf,px,py,pz;
    struct poly *link;
};
typedef struct poly *P;
P getnode()
{
    P temp;
    temp=(P)malloc(sizeof(struct poly));
    if(temp==NULL)
    {
        printf("Memory not available\n");
        exit(0);
    }
    return temp;
}
void read_poly(P P1,int n)
{
    P temp,next;
    int i;
    for(i=1;i<=n;i++)
    {
        temp=getnode();
        printf("Enter cf,px,py,pz\n");
        scanf("%d %d %d %d",&(temp->cf),&(temp->px),&(temp->py),&(temp->pz));
        next=P1->link;
        P1->link=temp;
        temp->link=next;
    }
}
P compare(P term, P P2)
{
    P cur;
    cur=P2->link;
    while(cur!=P2)
    {
        if(cur->px==term->px&&cur->py==term->py&&cur->pz==term->pz)
        return cur;
        cur=cur->link;
    }
    return NULL;
}
void insert(P P3,int cf,int px,int py,int pz)
{
    P temp,next;
    temp=getnode();
    temp->cf=cf;
    temp->px=px;
    temp->py=py;
    temp->pz=pz;
    next=P3->link;
    P3->link=temp;
    temp->link=next;
}
void add_poly(P P1,P P2,P P3)
{
    P cur,res_pos;
    cur=P1->link;
    while(cur!=P1)
    {
        res_pos=compare(cur,P2);
        if(res_pos!=NULL)
        {
            insert(P3,cur->cf+res_pos->cf,cur->px,cur->py,cur->pz);
            //res_pos->cf=-999;
        }
        else
        insert(P3,cur->cf,cur->px,cur->py,cur->pz);
        cur=cur->link;
    }
    cur=P2->link;
    while(cur!=P2)
    {
        if(compare(cur,P1)==NULL)
        //if(cur->cf!=-999)
        insert(P3,cur->cf,cur->px,cur->py,cur->pz);
        cur=cur->link;
    }
}
int evaluate(P P1)
{
    int sum=0,x,y,z;
    P cur=P1->link;
    printf("Enter the value of x,y and z\n");
    scanf("%d %d %d",&x,&y,&z);
    while(cur!=P1)
    {
        sum=sum+cur->cf*pow(x,cur->px)*pow(y,cur->py)*pow(z,cur->pz);
        cur=cur->link;
    }
    return sum;
}
void display(P head)
{
    P cur;
    if(head->link==head)
    {
        printf("Polynomial is empty\n");
        return;
    }
    printf("Elements of polynomial are:\n");
    cur=head->link;
    while(cur!=head)
    {
        if(cur->cf>0)
        printf("+%dx^%dy^%dz^%d",cur->cf,cur->px,cur->py,cur->pz);
        else
        printf("%dx^%dy^%dz^%d",cur->cf,cur->px,cur->py,cur->pz);
        cur=cur->link;

    }
    printf("\n");
}
int main()
{   
    int m,n,sum;
    P P1,P2,P3;
    P1=getnode();
    P1->link=P1;
    P2=getnode();
    P2->link=P2;
    P3=getnode();
    P3->link=P3;
    printf("Enter the number of terms of poly p1\n");
    scanf("%d",&m);
    read_poly(P1,m);
    display(P1);
    printf("Enter the number of terms of poly p2\n");
    scanf("%d",&n);
    read_poly(P2,n);
    display(P2);
    add_poly(P1,P2,P3);
    display(P3);
    sum=evaluate(P3);
    printf("Sum=%d",sum);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct queue
{
    int f,r;
    int elements[MAX];
}q;
void insert();
void pop();
void display();

int main()
{
    q.f=q.r=-1;
    int ch;
    while(1)
    {
        printf("enter 1.insert,2.remove,3.display,4.exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insert();
                    break;
            case 2:pop();
                    break;
            case 3:display();
                    break;
            default:exit(0);
        }

    }
    return 0;
}

void insert(void)
{
    int ele;

    printf("enter the element to be insert:\n");
    scanf("%d",&ele);
    if(q.r==-1)
        q.f+=1;
    q.r+=1;
    if(q.r>MAX-1)
    {
        printf("queue is full\n");
        return;
    }
    q.elements[q.r]=ele;
    printf("inserted successfully\n");
}

void pop(void)
{
    int deleted_ele;
    if(q.f==-1)
    {
        printf("queue is empty\n");
        return;
    }
    deleted_ele=q.elements[q.f];
    if(q.f<q.r)
        q.f+=1;
    else
        q.f=q.r=-1;
    printf("%d is deleted successfully\n",deleted_ele);

}

void display(void)
{
    int i;
    if(q.f==-1)
    {
        printf("queue is empty\n");
        return;
    }
    for(i=q.f;i<=q.r;i++)
    {
        printf("%d\t\n",q.elements[i]);
    }
}

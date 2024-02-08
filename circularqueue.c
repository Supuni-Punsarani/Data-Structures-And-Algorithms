#include<stdio.h>
#include<stdlib.h>

#define MAXQUEUE 5
typedef int queueelement;

typedef struct
{
    queueelement items[MAXQUEUE];
    int front;
    int rear;
    int count;
} cqueue;

void createqueue(cqueue*q)
{
    q->front=0;
    q->rear=-1;
    q->count=0;
}

#define TRUE 1
#define FALSE 0

int isqueueempty(cqueue*q)
{
    return (q->count==0);
}

int isqueuefull(cqueue*q)
{
    return (q->count==MAXQUEUE);
}

void append(cqueue *q,queueelement x)
{
    if(isqueuefull(q))
    {
        printf("\nqueue is full");
    }
    else
    {
        q->rear=(q->rear+1)%MAXQUEUE;
        q->items[q->rear]=x;
        q->count++;
        printf("\nyou entered item is:%d",x);
    }
}

void serve(cqueue*q,queueelement*x)
{
    if(isqueueempty(q))
    {
        printf("\nqueue is empty");
        exit(1);
    }
    else
    {
        *x=q->items[q->front];
        q->front=(q->front+1)%MAXQUEUE;
        q->count--;
    }
}

void sort(queueelement*data,int len)
{
    int i,j, temp;
    for(i=0; i<len-1; i++)
    {
        for(j=0; j<len-i-1; j++)
        {
            if(data[j]>data[j+1])
            {
                temp=data[j];
                data[j]=data[j+1];
                data[j+1]=temp;
            }
        }
    }

}

void main()
{
    cqueue q;
    int p,len=0,data[len],x,i;
    createqueue(&q);
    do
    {
        printf("\n1.add value");
        printf("\n2.remove item");
        printf("\n3.sort items");
        printf("\n4.exit");
        printf("\n\nenter your choice:");
        scanf("%d",&p);
        len=q.count;
        switch(p)
        {
        case 1:
            printf("\nenter value:");
            scanf("%d",&x);
            append(&q,x);
            break;
        case 2:
            serve(&q,&x);
            printf("\nremoved item is:%d",x);
            break;
        case 3:
            for(i=0; i<len; i++)
            {
                serve(&q,&x);
                data[i]=x;
            }
            sort(data,len);
            printf("\nafter sorting:");
            for(i=0; i<len; i++)
            {
                append(&q,data[i]);
            }
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nyou entered wrong value" );
        }

    }
    while(1);
}

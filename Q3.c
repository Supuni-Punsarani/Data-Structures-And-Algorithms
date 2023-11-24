#include<stdio.h>
#include<stdlib.h>

#define MAXQUEUE 10
#define TRUE 1
#define FALSE 0


typedef int QueueElement;

typedef struct queue {

 	QueueElement items[MAXQUEUE];
 	int front;
 	int rear;
	int count;

} Cqueue;

void CreateCqueue(Cqueue *q){

    printf("\nCircular queue is created successfully!\n");
    q->count = 0;
    q->front = 0;
    q->rear = -1;

}

int IsQueueEmpty(const Cqueue *q){

    return (q->count == 0);

}

int IsQueueFull(const Cqueue *q){

	return (q->count == MAXQUEUE);

}

void Append( Cqueue *q, QueueElement x){

    if (IsQueueFull(q)){

        printf("Circular queue is full.you can't append elements.\n\n");
        exit(1);
   	}

   	else{

        printf("Appended %d successfully.\n");
        q->rear = (q->rear +1) % MAXQUEUE;
        q->items[(q->rear)] = x;
        q->count++;

   	 }
}

void Serve( Cqueue *q, QueueElement *x){

    if (IsQueueEmpty(q))
    {
        printf("Circular queue is empty.you can't serve elements.\n\n");
        exit(1);
    }

    else
    {
        *x = q->items[(q->front)];
        printf("Served item is %d",*x);
        q->front = (q->front+1) % MAXQUEUE;
        q->count--;
    }
}

int QueueSize(const Cqueue *q){

    return (q->count);

}

void main(){

    printf("\n---Functions of the circular queue---\n");

    Cqueue q;
    QueueElement appendItem;
    QueueElement servedItem;

    CreateCqueue(&q);

    for(int i = 0; i < 5; i++) {
        printf("\nEnter the integer:");
        scanf("%d", &appendItem);
        Append(&q, appendItem);
    }

    printf("\n");
    Serve(&q, &servedItem);
    printf("\n\n");
    Serve(&q, &servedItem);
    printf("\n\n");

    int count=QueueSize(&q);
    printf("Size of the circular queue is %d",count);


}




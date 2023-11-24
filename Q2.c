#include<stdio.h>
#include<stdlib.h>

#define MAXQUEUE 10
#define TRUE 1
#define FALSE 0

typedef char dequeueElement;

typedef struct dqueue {

    dequeueElement items[MAXQUEUE];
    int front;
    int rear;
    int count;

} Dqueue;

void createDqueue(Dqueue *q){

    q->count=0;
    q->front=0;
    q->rear=-1;
    printf("\nDequeue is created successfully.");

}

int IsDeQueueEmpty(Dqueue *q){

    if(q->rear < q->front)
        return TRUE;
    else
        return FALSE;

}

int IsDeQueueFull(Dqueue *q){

    if(q->rear == MAXQUEUE-1)
        return TRUE;
    else
        return FALSE;

}

void Appendfront(Dqueue *q, dequeueElement x){

    if (IsDeQueueFull(q)) {
        printf("Dequeue is full. You can't append the items.\n\n");
        exit(1);
    }

    else {
        printf("Appended %c successfully.", x);

        if(IsDeQueueEmpty(q)) {
            q->items[q->front] = x;
            q->rear++;
            q->count++;
        }

        else {
            if (q->front == 0) {

                for (int i = q->rear; i >= q->front; i--){
                    q->items[i+1] = q->items[i];
                }

                q->rear++;
                q->items[q->front] = x;

            }

            else
                q->items[--(q->front)] = x;
        }
        q->count++;
    }
}

int main() {
    printf("\n---Functions of the dequeue---\n");

    Dqueue q;
    dequeueElement ch;

    createDqueue(&q);

    for(int i = 0; i < 6; i++) {
        printf("\n\nEnter the character:");
        scanf(" %c", &ch);
        Appendfront(&q, ch);
    }

    printf("\n\n");
    Appendfront(&q, 'Z');
    printf("\n\n");
    Appendfront(&q, 'D');
    printf("\n\n");

    printf("Items of the dequeue: ");

    for(int i = q.front; i <= q.rear; i++) {
        printf("%c ", q.items[i]);
    }

    return 0;
}

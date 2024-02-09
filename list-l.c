#include<stdio.h>
#include<stdlib.h>

typedef enum
{
    FALSE,
    TRUE
} Boolean;

typedef int ListData;
typedef int Position;

typedef struct listnode
{
    ListData lData;
    struct listnode *next;
} ListNode;

typedef struct
{
    int count;
    Boolean full;
    ListNode*head;
} List;

void CreateList(List *l)
{
    l->count = 0;
    l->head = NULL;
    l->full = FALSE;
}

Boolean IsListEmpty(const List *l)
{
    return (l->head == NULL);
}

Boolean IsListFull(const List *l)
{
    return (l->full);
}

int ListSize(const List *l)
{
    return (l->count);
}

ListNode * MakeListNode(ListData x)
{
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    if (p)
    {
        p->lData = x;
        p->next = NULL;
    }
    return (p);
}

void SetPosition(Position p, List *l, ListNode **current)
{
    int count;
    ListNode *q;
    if ((p < 0) || (p > l->count))
        printf("Attempt to set a position not in the list\n");
    else
    {
        q = l->head;
        for (count = 1; count <= p; count++)
            q = q->next;
        *current = q;
    }
}

void InsertList(Position p, ListData x, List *l)
{
    ListNode *newnode = NULL, *current = NULL;
    if (p < 0 || p > ListSize(l))
        printf("Attempt to insert at a position not in the list\n");
    else
    {
        newnode = MakeListNode(x);
        if (newnode == NULL)
        {
            l->full = TRUE;
            printf("Not enough memory for additional node\n");
        }
        else
        {
            if (p == 0)
            {
                newnode->next = l->head;
                l->head = newnode;
            }
            else
            {
                SetPosition(p - 1, l, &current);
                newnode->next = current->next;
                current->next = newnode;
            }
            l->count++;
        }
    }
}

int main(){
    List mylist;
    CreateList(&mylist);

    InsertList(0, 5, &mylist);
    InsertList(1, 10, &mylist);
    InsertList(2, 15, &mylist);

    printf("List elements: ");
    ListNode *current = mylist.head;
    while (current != NULL) {
        printf("%d ", current->lData);
        current = current->next;
    }
    printf("\n");

    if (IsListEmpty(&mylist)) {
        printf("The list is empty.\n");
    } else {
        printf("The list is not empty.\n");
    }

    printf("Size of the list: %d\n", ListSize(&mylist));

    return 0;
}

#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void create(int arr[], int n)
{
    struct Node *t, *last;

    first = (struct Node *)malloc(sizeof(struct Node *));
    first->data = arr[0];
    first->next = NULL;
    last = first;

    for(int i=1; i<n; i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = arr[i]; 
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node *node){
    while(node != NULL){
        printf("%d ", node->data);
        node = node->next;
    }
}

void removeDuplicates(struct Node *node)
{
    if(node == NULL)
        return;

    struct Node *nextNode = node->next;
    while(nextNode != NULL)
    {
        if(node->data != nextNode->data)
        {
            node = node->next;
            nextNode = nextNode->next;
        }
        else
        {
            node->next = nextNode->next;
            nextNode = NULL;
            free(nextNode);
            nextNode = node->next;
        }
    }
}

void reverseLL(struct Node *node)
{
    struct Node *q=NULL, *r=NULL, *p=node;
    while(p != NULL)
    {
        r = q;
        q = p;
        p = p->next;

        q->next = r;
    }
    first = q;
}

void helper(struct Node *node, struct Node *prev)
{
    if(node == NULL)
    {
        first = prev;
        return;
    }

    helper(node->next, node);
    node->next = prev;

}

void recursiveReverseLL(struct Node *node)
{
    helper(node, NULL);
}

int main()
{
    int arr[] = {10,10,20,20,20,30,30,30,30};
    create(arr,9);
    display(first);
    printf("\n");

    removeDuplicates(first);
    display(first);
    printf("\n");

    reverseLL(first);
    display(first);
    printf("\n");

    recursiveReverseLL(first);
    display(first);
    printf("\n");
    
    return 0;
}

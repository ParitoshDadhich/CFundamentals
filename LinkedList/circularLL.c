#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


struct Node{
    int data;
    struct Node *next;
}*Head;

void create(int arr[], int n){
    struct Node *t, *last;
    Head = (struct Node *)malloc(sizeof(struct Node));
    Head->data = arr[0];
    Head->next = Head;
    last = Head;

    for(int i=1; i<n; i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = arr[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void display(struct Node *node){
    do{
        printf("%d ", node->data);
        node =  node->next;
    }while(node != Head);
}

void rDisplay(struct Node *node){
    static int flag = 0;
    if(node != Head || flag == 0){
        flag=1;
        printf("%d ", node->data);
        rDisplay(node->next);
    }
    flag=0;
}

int length(struct Node *node){
    int len = 0;
    do{
        len++;
        node = node->next;
    }while(node != Head);

    return len;
}

struct Node* getTheLastNode(struct Node *node){
    while(node->next != Head){
        node = node->next;
    }
    
    return node;
}

void insert(struct Node *node, int data, int pos){
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = data;
    t->next = NULL;

    int len = length(node);
    if(pos == 0){
        struct Node *lastNode = getTheLastNode(node);
        t->next = Head;
        lastNode->next = t;
        Head = t;
    } 
    else if(pos == len){
         struct Node *lastNode = getTheLastNode(node);
         t->next = Head;
         lastNode->next = t;
    } 
    else if(pos > len){
        struct Node *lastNode = getTheLastNode(node);
        while(len != pos){
            struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
            temp->data = 0;
            temp->next = Head;
            lastNode->next = temp;
            lastNode = temp;

            len++;
        }

         t->next = Head;
         lastNode->next = t;
    } 
    else{
        while(pos-1 != 0){
            node = node->next;
            pos--;
        }
        t->next = node->next;
        node->next = t;
    }

    printf("\nNew node has been inserted at position %d!\n", pos);
}

void delete(int pos){
    int len = length(Head);
    if(pos == 0 || pos > len){
        printf("\nPlease provide a valid input!\n");
        return;
    }

    if(pos == 1){
        struct Node *temp = getTheLastNode(Head);
        temp->next = Head->next;
        Head->next = NULL;
        free(Head);
        Head = temp->next;
    }
    else{
        struct Node *temp = Head;
        while(pos-2 != 0){
            temp = temp->next;
            pos--;
        }

        struct Node *nodeToBeDeleted = temp->next;
        temp->next = nodeToBeDeleted->next;
        nodeToBeDeleted->next = NULL;
        free(nodeToBeDeleted);
    }

    printf("Node has been deleted at pos %d\n", pos);
}

void reverse(struct Node *node){
    struct Node *InitialFirstNode = node;
    struct Node *InitialLastNode = getTheLastNode(node);
    // node->next = InitialLastNode;

    struct Node *r = NULL;
    struct Node *q = NULL;
    struct Node *p = InitialFirstNode;

    do{
        r = q;
        q = p;
        p = p->next;
        if(q == InitialFirstNode){
            q->next = InitialLastNode;
        }else{
            q->next = r;
        }
    }while(p != InitialFirstNode);
    Head = q;

    printf("Circular LL has been reversed!\n");
}

int main(){
    int arr[] = {1,2,3,4,5};
    create(arr, 5);
    rDisplay(Head);
    printf("\n******************************\n");
    printf("Length of LL: %d", length(Head));
    insert(Head, 10, 5);
    rDisplay(Head);
    printf("\n******************************\n");
    delete(4);
    rDisplay(Head);
    printf("\n******************************\n");
    reverse(Head);
    rDisplay(Head);
    printf("\n******************************\n");
}


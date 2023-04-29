#include<stdlib.h>
#include<stdio.h>
                  
struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}*Head = NULL;

void create(int arr[], int n){
    Head = (struct Node*)malloc(sizeof(struct Node));
    Head->data = arr[0];
    Head->prev = NULL;
    Head->next = NULL;

    struct Node *t, *last = Head;
    for(int i=1; i<n; i++){
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = arr[i];
        t->prev = last;
        last->next = t;
        t->next = NULL;
        last = t;
    }
}

void display(struct Node *node){
    while(node != NULL){
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int length(struct Node *node){
    int len = 0;
    while(node != NULL){
        node = node->next;
        len++;
    }

    return len;
}

struct Node * getTheLastNode(struct Node *node){
    while(node->next != NULL)
        node = node->next;
    
    return node;
}

void insert(struct Node *node, int pos, int data){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    int len = length(node);
    if(pos == 0){
        newNode->next = Head;
        Head->prev = newNode;
        Head = newNode;
    } 
    else if(pos > len){
        struct Node *lastNode = getTheLastNode(node);
        struct Node *temp;
        while(len != pos){
            temp =  (struct Node *)malloc(sizeof(struct Node));
            temp->data = 0;
            temp->next = NULL;
            temp->prev = lastNode;
            lastNode->next = temp;
            lastNode = temp;
        }

        lastNode->next = newNode;
        newNode->prev = lastNode;
    } 
    else{
        while(pos-1 != 0){
            node = node->next;
            pos--;
        }
        newNode->next = node->next;
        if(node->next)
            node->next->prev = newNode;
        node->next = newNode;
        newNode->prev = node;
    }
}

void delete(struct Node *node, int pos){
    int position = pos;
    int len = length(node);

    if(pos > len || pos <= 0){
        printf("Please provide a valid input!");
        return;
    }

    if(pos == 1){
        struct Node *temp = node;
        node = node->next;
        Head = node;
        temp->next = NULL;
        free(temp);

        printf("Node has been deleted at position %d \n", position);
        return;
    }

    while(pos-2 != 0){
        node = node->next;
        pos--;
    }
    struct Node *nodeToBeDeleted = node->next;

    node->next = nodeToBeDeleted->next;
    if(nodeToBeDeleted->next)
        nodeToBeDeleted->next->prev = node;
    nodeToBeDeleted->next = nodeToBeDeleted->prev = NULL;
    free(nodeToBeDeleted);

    printf("Node has been deleted at position %d", position);
}

// IN CASE OF REVERSE DLL WE JUST NEED TO SWAP PREV AND NEXT LINKS
void reverse(struct Node *p){
    struct Node *temp=NULL;
    while(p != NULL){
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;

        if(p != NULL && p->next == NULL)
            Head = p;
    }
}

int main(){
    int arr[] = {1,2,3,4,5};
    create(arr, 5);
    display(Head);
    insert(Head, 0, 10);
    display(Head);
    delete(Head, 1);
    printf("\n");
    display(Head);
    reverse(Head);
    display(Head);
}
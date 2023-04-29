#include <stdlib.h>
#include <stdio.h>

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
};

void create(struct Node **node, int arr[], int n){
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    (new_node)->data = arr[0];
    (new_node)->prev = (new_node)->next = new_node;
    *node = new_node;

    struct Node *last = *node, *t;
    for(int i=1; i<n; i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = arr[i];
        t->prev = last;
        last->next = t;
        last = t;
        last->next = (*node);
        (*node)->prev = last;
    }
}

void display(struct Node **node){
    struct Node *head_node = *node;
    do{
        printf("%d ",(*node)->data);
        (*node) = (*node)->next;
    }while((*node) != head_node);

    printf("\n");
}

int length(struct Node *node){
    int len = 0;
    struct Node *head_node = node;
    do{
        node = node->next;
        len++;
    }while(node != head_node);

    return len;
}

void insert(struct Node **node, int pos, int data){
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    // new_node->next = new_node->prev = NULL;

    int len = length(*node);
    if(pos == 0){
        struct Node *last_node = (*node)->prev;
        new_node->next = *node;
        new_node->prev = last_node;
        last_node->next = new_node;
        (*node)->prev = new_node;
        // last_node->next = new_node;
        // new_node->prev = last_node;

        *node = (new_node);
    }
    else if(pos == len){
        struct Node *last_node = (*node)->prev;
        last_node->next = new_node;
        new_node->prev = last_node;
        new_node->next = *node;
        (*node)->prev = new_node;
    } 
    else if(pos > len){
        struct Node *last_node = (*node)->prev;
        struct Node *t;
        while(len != pos){
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = 0;
            t->prev = last_node;
            last_node->next = t;
            last_node = t;
            last_node->next = (*node);
            (*node)->prev = last_node;
            
            len++;
        }

        last_node->next = new_node;
        new_node->prev = last_node;
        new_node->next = *node;
        (*node)->prev = new_node;
    }
    else{
        struct Node *temp;
        while(pos-1 != 0){
            temp = temp->next;
            pos--;
        }
        new_node->next = temp->next;
        if(temp->next)
            temp->next->prev = new_node;
        temp->next = new_node;
        new_node->prev = temp;
    }
}

void delete(struct Node **node, int pos){
    int len = length((*node));
    if(pos > len || pos <= 0){
        printf("Please enter valid input\n");
        return;
    }

    if(pos == 1){
        struct Node *lastNode = (*node)->prev;
        lastNode->next = (*node)->next;
        if((*node)->next)
            (*node)->next->prev = lastNode;
        (*node)->next = (*node)->prev = NULL;
        free(node);
        *node = lastNode->next;

        return;
    }

    struct Node *temp = *node;
    while(pos-2 != 0){
        temp = temp->next;
        pos--;
    }
    struct Node *nodeToBeDeleted = temp->next;
    temp->next = nodeToBeDeleted->next;
    if(nodeToBeDeleted->next)
        nodeToBeDeleted->next->prev = temp;
    nodeToBeDeleted->next = nodeToBeDeleted->prev = NULL;
    free(nodeToBeDeleted);
}

int main(){
    struct Node *Head = NULL;
    int arr[] = {1,2,3,4,5};
    create(&Head, arr, 5);
    display(&Head);
    insert(&Head, 3, 10);
    display(&Head);
    delete(&Head, 2);
    display(&Head);

    return 0;
}
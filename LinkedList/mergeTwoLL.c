#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct Node{
    int data;
    struct Node *next;
} *first=NULL, *second=NULL, *third=NULL;

extern bool flag = false;

void create(struct Node *node, int arr[], int n){
    node = (struct Node *)malloc(sizeof(struct Node));
    node->data = arr[0];
    node->next = NULL;

    // need to assign node to first
    if(!flag){
        first = node;
        flag = true;
    } else{
        second = node;
    }

    struct Node *t, *last=node;
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

void merge(struct Node *first, struct Node *second){
    struct Node *last;
    if(first->data < second->data){
        third = last = first;
        first = first->next;
        // third->next = NULL;
    }else{
        third = last = second;
        second = second->next;
        // third->next = NULL;
    }

    while(first && second){
        if(first->data < second->data){
            last->next = first;
            last = first;
            first = first->next;
            // last->next = NULL;
        }
        else{
            last->next = second;
            last = second;
            second = second->next;
            // last->next = NULL;
        }
    }

    if(first)
        last->next = first;
    if(second)
        last->next = second;

    return;
}

int main(){
    int arr1[] = {1,3,5};
    int arr2[] = {2,4,6,8,10};

    create(first, arr1, 3);
    display(first);
    printf("  ");
    create(second, arr2, 5);
    display(second);

    printf("                 ");
    merge(first, second);
    display(third);

    return 0;
}
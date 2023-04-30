#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

struct Node{
    int data;
    struct Node *next;
}*top = NULL;
static int len = 0;

void create(struct Node **st, int arr[], int n){
    struct Node *firstNode = (struct Node *)malloc(sizeof(struct Node));
    firstNode->data = arr[0];
    firstNode->next = NULL;
    len++;
    *st = top = firstNode;
    struct Node *temp;
    for(int i=1; i<n; i++){
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = arr[i];
        temp->next = top;
        top = temp;
        len++;
    }
    *st = top;
}

void display(struct Node **st){
    struct Node *temp = *st;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void push(struct Node **st, int value){
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    if(node == NULL){
        printf("Stack Overflow!\n");
        exit(1);
    }
    node->data = value;
    node->next = top;
    *st = top = node;

    len++;
}

int pop(struct Node **st){
    struct Node *temp = top;
    top = top->next;
    *st = top;
    int x = temp->data;
    temp->next = NULL;
    free(temp);

    len--;
    return x;
}

char *isEmpty(){
    return top == NULL ? "true" : "false";
}

int length(struct Node *st){
    struct Node *temp = st;
    int len = 0;
    while(temp !=0){
        temp = temp->next;
        len++;
    }
    return len;
}

int peek(struct Node **st, int pos){
    if(pos > length(*st) || pos <= 0){
        printf("Please enter a valid input!\n");
        exit(1);
    }

    struct Node *temp = *st;
    while(pos-1 != 0){
        temp = temp->next;
        pos--;
    }

    return temp ? temp->data : -1;
}

int main(){
    struct Node *st;
    int arr[] = {1, 2, 3, 4, 5};
    create(&st, arr, 5);
    display(&st);
    push(&st, 10);
    display(&st);
    printf("Popped off value %d \n", pop(&st));
    display(&st);
    printf("Element at position 4 is %d\n",peek(&st, 1));
    printf("is Stack is empty? %s\n",isEmpty());
    printf("Length of a stack is %d\n", len);
}
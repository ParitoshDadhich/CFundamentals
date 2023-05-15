#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
} *front=NULL, *rear=NULL;

void enqueue(int data){
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    if(t == NULL){
        printf("Stack overflow!\n");
        exit(1);
    }

    t->data = data;
    t->next = NULL;

    if(front == NULL){
        front = rear = t;
    }
    else{
        rear->next = t;
        rear = t;
    }
}

int dequeue(){
    if(front == NULL){
        printf("Queue is empty!\n");
        exit(1);
    }
    
    int value = front->data;
    struct Node *temp = front;
    front = front->next;
    free(temp);
    
    return value;
}

void display(){
    printf("Displaying queue elements!\n");
    struct Node *temp = front;

    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();

    dequeue();
    display();
}
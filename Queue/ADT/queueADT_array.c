#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Node {
    int size;
    int front;
    int rear;
    int *arr;
};

void enqueue(struct Node *queue, int data){
    if(queue->rear == queue->size){
        printf("Queue is full\n");
        exit(1);
    }

    queue->rear++;
    queue->arr[queue->rear] = data;
}

int dequeue(struct Node *queue){
    if(queue->front == queue->rear){
        printf("Queue is empty\n");
        exit(1);
    }

    queue->front++;
    int value = queue->arr[queue->front];
    return value;
}

void display(struct Node *queue){
    printf("Displaying all elements inside Queue\n");
    for(int i=queue->front+1; i<=queue->rear; i++){
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}

int main(){
    struct Node queue;
    printf("Enter the size of Queue\n");
    scanf("%d", &queue.size);
    queue.arr =  (int *)malloc(queue.size*sizeof(int));
    queue.front = queue.rear = -1;
    
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    enqueue(&queue, 4);
    enqueue(&queue, 5);
    display(&queue);

    dequeue(&queue);
    display(&queue);

    return 0;
}
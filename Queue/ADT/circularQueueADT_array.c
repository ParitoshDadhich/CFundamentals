#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Queue{
    int size;
    int front;
    int rear;
    int *arr;
};

void create(struct Queue *queue, int size){
    queue->arr = (int *)malloc((size+1)*sizeof(int));
    queue->rear = queue->front = 0;
}

void enqueue(struct Queue *queue, int data){
    if(queue->front == (queue->rear+1)%queue->size){
        printf("Queue is full\n");
        exit(1);
    }

    queue->rear = (queue->rear+1)%queue->size;
    queue->arr[queue->rear] = data;
}

int dequeue(struct Queue *queue){
    if(queue->front == queue->rear){
        printf("Queue is empty\n");
        exit(1);
    }

    queue->front = (queue->front+1)%queue->size;
    int value = queue->arr[queue->front];
    return value;
}

void display(struct Queue *queue){
    int i = queue->front+1;
    printf("Displaying elemnts inside circular queue\n");
    do{
        printf("%d ", queue->arr[i]);
        i = (i+1)%queue->size;
    } while(i != (queue->rear+1)%queue->size);
    printf("\n");
}

int main(){
    struct Queue queue;
    printf("Enter the size of queue\n");
    scanf("%d", &queue.size);
    create(&queue, queue.size);

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    enqueue(&queue, 4);
    enqueue(&queue, 5);
    display(&queue);

    dequeue(&queue);
    display(&queue);
}
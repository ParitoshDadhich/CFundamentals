#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *arr;
};

void create(struct Stack *st){
    printf("Enter the size of a stack: ");
    scanf("%d", &st->size);
    st->top = -1;
    st->arr = (int *)malloc(sizeof(st->size*sizeof(int)));
}

void display(struct Stack *st){
    printf("Elements of a stack are: ");
    for(int i=st->top; i>=0; i--){
        printf("%d ", st->arr[i]);
    }
    printf("\n");
}

void push(struct Stack *st, int value){
    if(st->top == st->size-1){
        printf("Stack Overflow!\n");
        return;
    }

    st->top++;
    st->arr[st->top] = value;
}

int pop(struct Stack *st){
    if(st->top == -1){
        printf("Stack Underflow!\n");
        return -1;
    }

    return st->arr[st->top--];
}

int peek(struct Stack *st, int index){
    if(st->top-index+1 < 0){
        printf("Invalid Index!\n");
        return -1;
    }

    return st->arr[st->top-index+1];
}

int isEmpty(struct Stack *st){
    return st->top == -1;
}

int isFull(struct Stack *st){
    return st->top == st->size-1;
}

int stackTop(struct Stack *st){
    if(!isEmpty(st))
        return st->arr[st->top];
    
    return -1;
}


int main(){
    struct Stack st;
    create(&st);

    push(&st, 1);
    push(&st, 2);
    push(&st, 3);
    push(&st, 4);
    push(&st, 5);

    printf("%d\n",pop(&st));
    display(&st);
    printf("Element at 2 position is %d \n",peek(&st,2));

    return 0;
}
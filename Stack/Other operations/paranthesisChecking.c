#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct Node{
    char data;
    struct Node *next;
} *top = NULL;
 

void push(char ch){
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    if(t == NULL){
        printf("Stack Overflow!\n");
        exit(1);
    }

    t->data = ch;
    t->next = top;
    top = t;
}

char pop(){
    struct Node *t;
    char x = -1;
    if(top == NULL){
        printf("Stack is empty!\n");
    } 
    else{
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }

    return x;
}

int isBalanced(char expression[]){
    struct Node st;

    int i=0;
    while(expression[i] != '\0'){
        if(expression[i] == '('){
            push(expression[i]);
        }
        else if(expression[i] == ')'){
            if(top == NULL)
                return 0;
            pop();
        }
        i++;
    }

        if(top == NULL)
            return 1;
        else    
            return 0;
}

int main(){
    char *exp = "((a+b)*(c-d))";
    int balanced = isBalanced(exp);
    printf("is the expression balanced? %d\n", balanced);

    return 0;
}
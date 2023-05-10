#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Node{
    char data;
    struct Node *next;
} *top = NULL;

void push(char data){
    // CREATING A NEW NODE
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    if(t == NULL){
        printf("Stack overflow LINE 15!\n");
        exit(1);
    }
    t->data = data;
    t->next = NULL;

    if(top == NULL){
        top = t;
    } else{
        t->next = top;
        top = t;
    }

    // t->next = top;
    // top = t;
}

int isEmpty(){
    return top == NULL ? 1 : 0;
}

char pop(){
    if(isEmpty()){
        printf("Stack is empty\n");
        exit(1);
    }

    char value = top->data;
    struct Node *temp = top;
    top = top->next;
    temp->next = NULL;
    free(temp);

    return value;
}

char stackTop(){
    if(top == NULL){
        printf("Stack is empty LINE\n");
        exit(1);
    }

    return top->data;
}

void display(){
    struct Node *temp = top;
    printf("Displaying all the elements\n");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    free(temp);
}

int isOperand(char character){
    if(character == '/' || character == '%' || character == '*' || character == '+' || character == '-')
        return 0;
    else    
        return 1;
}

int precedence(char character){
    if(character == '+' || character == '-')
        return 1;
    else if(character == '*' || character == '%' || character == '/')
        return 2;
    
    printf("Please enter a valid operator!\n");
    return -1;
}

char* infixToPostfix(char *expression){
    char *postfix = (char *)malloc((strlen(expression+1))*sizeof(char));
    
    int i = 0, j = 0;
    while(expression[i] != '\0'){
        char ch = expression[i];

        if(isOperand(ch)){
            postfix[j++] = ch;
            i++;
        }
        else{
            if(isEmpty() || (precedence(ch) > precedence(stackTop()))){
                push(ch);
                i++;
            }
            else{
                postfix[j++] = pop();
            }
        }
    }

    while(!isEmpty()){
        postfix[j++] = pop();
    }
    postfix[j] = '\0';

    return postfix;
}

int main(){
    char *expression = "a+b*c-d/e";
    printf("Infix expression: %s\n", expression);
    printf("Infix to Postfix: %s\n", infixToPostfix(expression));
}
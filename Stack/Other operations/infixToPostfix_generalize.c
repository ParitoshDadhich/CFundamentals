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
        printf("Stack overflow!\n");
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
        printf("Stack is empty\n");
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
    if(character == '/' || character == '%' || character == '*' || character == '+' || character == '-' || character == '(' || character == ')' || character == '^')
        return 0;
    else    
        return 1;
}

int precedence_outsideStack(char character){
    if(character == '+' || character == '-')
        return 1;
    else if(character == '*' || character == '%' || character == '/')
        return 3;
    else if(character == '^')
        return 6;
    else if(character == '(')
        return 7;
    else if(character == ')')
        return 0;
    
    printf("Please enter a valid operator!\n");
    exit(1);
}

// precedences of operators having associty L-R -> increased by 1
// precedences of operators having associty R-L -> decreased by 1
int precedence_insideStack(char character){
    if(character == '+' || character == '-')
        return 2;
    else if(character == '*' || character == '%' || character == '/')
        return 4;
    else if(character == '^')
        return 5;
    else if(character == '(')
        return 0;
    
    printf("Please enter a valid operator!\n");
    exit(1);
}

char* infixToPostFix(char* expression){
    int len = strlen(expression);
    char* postfix = (char *)malloc(sizeof(char)*(len+1));
    
    int i=0, j=0;
    while(expression[i] != '\0'){
        char ch_outsideStack = expression[i];
        if(isOperand(ch_outsideStack)){
            postfix[j] = ch_outsideStack;
            j++;
            i++;
        } 
        else{
            // WHEN STACK IS EMPTY
            if(isEmpty()){
                if(expression[i] == ')'){
                    exit(1);
                }
                else{
                    push(ch_outsideStack);
                    i++;
                }
            }
            else{
                char ch_topOfStack = stackTop();
                if(precedence_outsideStack(ch_outsideStack) > precedence_insideStack(ch_topOfStack)){
                    push(ch_outsideStack);
                    i++;
                }
                else if(precedence_outsideStack(ch_outsideStack) == precedence_insideStack(ch_topOfStack)){
                    if(ch_outsideStack == ')' && ch_topOfStack == '('){
                        pop();
                        i++;
                    }
                }
                else{
                    if(ch_topOfStack == '('){
                        pop();
                    }
                    else{
                        postfix[j] = pop();
                        j++;
                    }
                }
            }
        }
    }

    while(!isEmpty()){
        postfix[j] = pop();
        j++;
    }

    postfix[j] = '\0';
    return postfix;
}
 
int evaulatePostfixExpression(char* expression){
    struct Node *st = (struct Node *)malloc(sizeof(struct Node));
    
    // logic
    int i=0;
    while(expression[i] != '\0'){
        char ch = expression[i];
        if(isOperand(ch)){
            push(ch - '0');
        }
        else{
            int x2 = pop();
            int x1 = pop();

            switch (ch)
            {
            case '+': push(x1 + x2); break;
            case '-': push(x1 - x2); break;
            case '*': push(x1 * x2); break;
            case '/': push(x1 / x2); break;
            case '^': push(x1 ^ x2); break;
            }
        }
        i++;
    }

    return stackTop();
}


int main(){
    // char *expression = "a+b*c-d/e";
    char *exp = "a+b*c-d^e^f";
    printf("Infix expression: %s\n", exp);
    char* expression = infixToPostFix(exp);
    printf("Infix to Postfix: %s\n", expression);
    printf("Postfix expression value: %d\n", evaulatePostfixExpression("342+*5*"));
}
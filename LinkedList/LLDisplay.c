#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node *next;
} *first=NULL;

void create(int arr[], int n) {
    struct Node *t = NULL, *last = NULL;

    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = arr[0];
    first->next = NULL;

    last = first;

    for(int i=1; i<n; i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = arr[i];
        t->next = NULL;

        last->next = t;
        last = t;
    }
}

void display(struct Node *node) {
    while(node != NULL){
        printf("%d ", node->data);
        node = node->next;
    }
}

void recursiveDisplay(struct Node *node) {
    if(node == NULL)
        return;
    
    printf("%d ", node->data);
    recursiveDisplay(node->next);
}

int countNodes(struct Node *node) {
    int count = 0;
    while(node != NULL){
        count++;
        node = node->next;
    }
    
    return count;
}

int countNodesRecursive(struct Node *node) {
    if(node == NULL)
        return 0;
    else
        return 1 + countNodesRecursive(node->next);
}

void maxAndMin(struct Node *node){
    int max = node->data;
    int min = node->data;

    while(node != NULL){
        if(max < node->data)
            max = node->data;
        else if(min > node->data){
            min = node->data;
        }

        node = node->next;
    }

    printf("%d, %d", max, min);
}

struct Node* findNode(struct Node *node, int key){
    if(node->data == key)
        return node;

    struct Node *prev = NULL;
    while(node != NULL){
        if(node->data == key){
            prev->next = node->next;
            node->next = first;
            first = node;

            return first;
        }
    prev = node;
    node = node->next;
    }

    return NULL;
}

struct Node* helper(struct Node *node, struct Node *prev, int key){
    if(node == NULL)
        return NULL;
    
    if(node->data == key){
       if(node == first) 
            return node;
        else{
            prev->next = node->next;
            node->next = first;
            first = node;

            return first;
        }
    }
    
    prev = node;
    return helper(node->next, prev,  key);
}

struct Node* findNodeRecursive(struct Node *node, int key){
    return helper(first, NULL, key);
}


struct Node* creatNewNode(int data){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void insert(struct Node *node, int pos, int value){
    int len = countNodes(node);

    // INSERT AT POSITION GREATER THAN LENGTH
    if(pos > len ){
        struct Node *prev = node;
        while(node != NULL){
            prev = node;
            node = node->next;
        }

        while(len != pos){
            struct Node *newNode = creatNewNode(0);
            prev->next = newNode;
            prev = newNode;
            len++;
        }

        struct Node *newNode = creatNewNode(value);
        prev->next = newNode;
        prev = newNode;

        return;
    }

    // INSERT AT FIRST POSITION
    if(pos == 0){
        struct Node *newNode = creatNewNode(value);
        newNode->next = first;
        first = newNode;
        
        return;
    }

    // INSERT AT LAST AND ANY POSITION
    struct Node *prev = NULL;
    while(pos > 0){
        prev = node;
        node = node->next;

        pos--;
    }

    struct Node *newNode = creatNewNode(value);
    prev->next = newNode;
    newNode->next = node;

    return;
}

void delete(struct Node *node, int ele){
    struct Node *prev = NULL;
    while(node != NULL){
        if(node->data == ele){
                if(prev != NULL){
                prev->next = node->next;

                printf("\n%d value node has been deleted from the memory.\n", node->data);
                node = NULL;
                free(node);
                return;
            } else{
                prev = first;
                printf("\n%d value node has been deleted from the memory.\n", first->data);
                first = first->next;
                prev = NULL;
                free(prev);
            }
        }
        prev = node;
        node = node->next;
    }
    printf("\nValue is not present in LL\n");
    return;
}

int main() {
    int arr[] = {1,2,3,4,5};

    create(arr, 5);
    display(first);
    printf("\n");
    recursiveDisplay(first);
    int len = countNodes(first);
    printf("\nNumber of nodes in LL are: %d", len);
    printf("\nNumber of nodes in LL via recursive sol are: %d", countNodesRecursive(first));
    printf("\nMax and Min element in LL ");
    maxAndMin(first);

    struct Node *node = findNode(first, 1);
    if(node != NULL)
        printf("\nSearched value is %d\n", node->data);
    else    
        printf("\nValue is not present in LL\n");
    display(first);

    struct Node *searchedNode = findNodeRecursive(first, 1);
     if(searchedNode != NULL)
        printf("\nSearched value is %d\n", searchedNode->data);
    else    
        printf("\nValue is not present in LL\n");
    display(first);

    printf("\nInsert a position where you want to insert an element\n");
    int pos;
    scanf("%d", pos);
    insert(first, 5, 10);
    display(first);

    delete(first, 10);
    display(first);



    first = NULL;
    free(first);

    return 0;
}
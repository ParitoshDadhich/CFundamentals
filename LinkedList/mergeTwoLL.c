#include <stdlib.h>
#include <stdio.h>

typedef struct Node Node;
void createList(int arr[], int n, Node **header);
void displayList(Node *node);
void merge(Node *first, Node *second);
void displayList(Node *node);


struct Node {
    int data;
    Node *next;
} *first = NULL, *second = NULL, *third = NULL;


int main() {
    int arr1[] = {1,3,5,7};
    int arr2[] = {2,4,6,8,9,10};
    createList(arr1, 4, &first);
    displayList(first);
    createList(arr2, 6, &second);
    displayList(second);
    printf("first %d , second %d", first->data, second->data);
    merge(first, second);
    displayList(third);
}

Node *createNode(int val) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = val;
    node->next = NULL;
    return node;
}

void createList(int arr[], int n, Node **header) {
    *header = createNode(arr[0]);
    
    Node *temp = *header;
    for(int i=1; i<n; i++){
        Node *tempNode = createNode(arr[i]);
        temp->next = tempNode;
        temp = tempNode;
    }
    printf("List created!\n");
}

void merge(Node *first, Node *second) {
    Node *temp = NULL;
    
    if(first->data > second->data) {
        third = second;
        temp = second;
        second = second->next;
        temp->next = NULL;
    } else {
        third = first;
        temp = first;
        first = first->next;
        temp->next = NULL;
    }
    
    while(first != NULL && second != NULL) {
        if(first->data > second->data) {
            temp->next = second;
            temp = second;
            second = second->next;
            temp->next = NULL;
        } else {
            temp->next = first;
            temp = first;
            first = first->next;
            temp->next = NULL;
        }
    }
    
    while(first != NULL) {
        temp->next = first;
        temp = first;
        first = first->next;
        temp->next = NULL;
    }
    
     while(second != NULL) {
        temp->next = second;
        temp = second;
        second = second->next;
        temp->next = NULL;
    }
    
    printf("Merging process completed!\n");
}

void displayList(Node *node) {
    printf("Displaying linked list!\n");
    while(node != NULL) {
        printf("%d\n", node->data);
        node = node->next;
    }
    printf("Displayed all elements!\n");
}

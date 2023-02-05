#include <stdio.h>
#include<stdlib.h>

struct Array{
    int *A;
    int length;
    int size;
};

                    
struct Array* Union(struct Array *arr1, struct Array *arr2){
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    arr3->A = (int *)malloc((arr1->length + arr2->length)*sizeof(int));
    arr3->length = 0;
    arr3->size = arr1->length + arr2->length;
    
    int i,j,k;
    i=j=k=0;
    while(i < arr1->length && j < arr2->length){
        if(arr1->A[i] == arr2->A[j]){
            arr3->A[k++] = arr1->A[i];
            i++;
            j++;
        }
        else if(arr1->A[i] > arr2->A[j]){
            arr3->A[k++] = arr2->A[j];
            j++;
        }
        else{
            arr3->A[k++] = arr1->A[i];
            i++;
        }
    }
    
    for(;i < arr1->length; i++){
        arr3->A[k++] = arr1->A[i];
    }
    
    for(; j < arr2->length; j++){
        arr3->A[k++] = arr2->A[j];
    }
    
    arr3->length = k;
    
    return arr3;
}

struct Array* Interaction(struct Array *arr1, struct Array *arr2){
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    arr3->A = (int *)malloc((arr1->length + arr2->length)*sizeof(int));
    arr3->length = 0;
    arr3->size = arr1->length + arr2->length;
    
    int i,j,k;
    i=j=k=0;
    while(i < arr1->length && j < arr2->length){
        if(arr1->A[i] == arr2->A[j]){
            arr3->A[k++] = arr1->A[i];
            i++;
            j++;
        }
        else if(arr1->A[i] > arr2->A[j]){
            j++;
        }
        else{
            i++;
        }
    }
    
    arr3->length = k;
    return arr3;
}

// A-B

struct Array* Difference(struct Array *arr1, struct Array *arr2){
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    arr3->A = (int *)malloc((arr1->length + arr2->length)*sizeof(int));
    arr3->length = 0;
    arr3->size = arr1->length + arr2->length;
    
    int i,j,k;
    i=j=k=0;
    while(i < arr1->length && j < arr2->length){
        if(arr1->A[i] == arr2->A[j]){
            i++;
            j++;
        }
        else if(arr1->A[i] > arr2->A[j]){
            j++;
        }
        else{
            arr3->A[k++] = arr1->A[i];
            i++;
        }
    }
    
    for(;i < arr1->length; i++){
        arr3->A[k++] = arr1->A[i];
    }
 
    arr3->length = k;
    return arr3;
}

void display(struct Array *arr){
    printf("Displaying all the elements of an array\n");
    printf("%d ", arr->length);
    for(int i=0; i < arr->length; i++){
        printf("%d ", arr->A[i]);
    }
    printf("\nAll the elements have been printed!\n");
}

int main()
{
    printf("Enter the size of first array\n");
    int m;
    scanf("%d", &m);
    struct Array arr1;
    arr1.A = (int *)malloc(m*sizeof(int));
    arr1.length = 0;
    arr1.size = m;
    
    printf("Enter the size of second array\n");
    int n;
    scanf("%d", &n);
    struct Array arr2;
    arr2.A = (int *)malloc(m*sizeof(int));
    arr2.length = 0;
    arr2.size = n;
    
    printf("Enter the number of numbers of first array\n");
    int num;
    scanf("%d", &num);
    printf("Enter the elements of first array\n");
    for(int i=0; i<num; i++){
        scanf("%d", &arr1.A[i]);
    }
    
    printf("Enter the number of numbers of second array\n");
    scanf("%d", &num);
    printf("Enter the elements of second array\n");
    for(int i=0; i<num; i++){
        scanf("%d", &arr2.A[i]);
    }
    
    
    printf("******************OPERATIONS********************\n\n");
    printf("UNION\n");
    struct Array *arr = Union(&arr1, &arr2);
    printf("Displaying union of two elements!\n");
    display(arr);
    
    printf("\nINTERACTION\n");
    arr = Interaction(&arr1, &arr2);
    printf("Displaying interaction of two elements!\n");
    display(arr);
    
    printf("\nDIFFERENCE\n");
    arr = Difference(&arr1, &arr2);
    printf("Displaying difference of two elements!\n");
    display(arr);

    return 0;
}

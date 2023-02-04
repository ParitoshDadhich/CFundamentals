#include<stdio.h>
#include<stdlib.h>

int main(){

    int n = 5;
    int *arr = (int*)malloc(n*sizeof(int));
    
    for(int i=0; i<n; i++){
        arr[i] = i;
    }

    printf("values\n");
    for(int i=0; i<n; i++){
        printf("%d ", *(arr+i));
    }

    printf("\naddresses\n");
    for(int i=0; i<n; i++){
        printf("%u ", (arr+i));
    }


    free(arr);
    arr = NULL;
    return 0;
}
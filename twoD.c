#include<stdio.h>
#include<stdlib.h>

int main(){
    int n = 5;

    printf("Creating an array with an interger pointer\n");

    int *arr[n];
    for(int i=0; i<n; i++){
       arr[i] = (int*)malloc((i+1)*sizeof(int));
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            arr[i][j] = i + j + 1;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    free(arr);
    *arr = NULL;

    printf("\n\nCreating an array with two pointer integer\n");

    int **a = (int **)malloc(n*sizeof(int));
    for(int i=0; i<n; i++){
        a[i] = (int *)malloc((i+1)*sizeof(int));
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            a[i][j] = i + j + 10;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    free(a);
    a = NULL;

}
# include <stdio.h>
# include <stdlib.h>


int* counting_sort(int A[], int n , int k){
    int* B = malloc(n*sizeof(int));
    int* C = calloc(k+1, sizeof(int));

    if (!B || !C){
        free(B);
        free(C);
        return NULL;
    }

    for(int i = 0; i < n; i++){
        C[A[i]]++;
    }

    for(int j = 0; j < k; j++){
        C[j+1] += C[j];
    }

    for(int i = n - 1; i >= 0; i--){
        B[C[A[i]] - 1] = A[i];
        C[A[i]]--;
    }
    
    free(C);
    return B;
}

void print_array(int A[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n\n");
}

int main(){
    int A[] = {10,5,9,3,6,7,8,1,4,2,0,4,5,6};
    int n = sizeof(A) / sizeof(int);
    int k = 10;
    printf("Array before sorting:\n");
    print_array(A , n);

    int* B = counting_sort(A, n ,k);
    printf("Array after sorting:\n");
    print_array(B, n);
    free(B);
    return 0;
}
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

int* create_array(int A[], int p, int q){
    int n = q - p + 1;
    int* B = malloc((n + 1)*sizeof(int));
    if (B == NULL){
        return NULL;
    }
    for (int i = 0; i < n; i++){
        B[i] = A[p + i];
    }
    B[n] = INT_MAX;
    return B;
}

void merge(int A[], int p, int q, int r){
    int* left = create_array(A, p, q);
    int* right = create_array(A, q+1, r);

    int i = 0, j = 0;
    for (int k = p; k <= r; k++){
        if (left[i] <= right[j]){
            A[k] = left[i];
            i++;
        }
        else{
            A[k] = right[j];
            j++;
        }

    }
    free(left);
    free(right);
}

void merge_sort(int A[], int p, int r){
    if (p < r){
        int q = (p + r)/ 2;
        merge_sort(A, p, q);
        merge_sort(A, q+1, r);
        merge(A, p , q, r);
    }
}

void print_array(int A[], int n){
    for(int i = 0; i < n; i++){
        printf("%i ", A[i]);
    }
    printf("\n");
}

int main(){
    int A[] = {10, 56, 47, 39, 31, 80, 48, 127, 22, 0, 4, 1, 8, 6, 3, 5};
    int n = sizeof(A) / sizeof(A[0]);
    printf("Array before sorting:\n");
    print_array(A, n);

    merge_sort(A, 0, n-1);
    printf("Array after sorting:\n");
    print_array(A, n);

    return 0;
}
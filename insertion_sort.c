# include <stdio.h>
# include <stdlib.h>

void insertion_sort(int A[], int n){
    for (int i = 1; i < n; i ++){
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key){
            A[j + 1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}

void print_array(int A[], int n){
    for(int i = 0; i < n; i++){
        printf("%i ", A[i]);
    }
    printf("\n");
}

int main(){
    int A[] = {10, 56, 47, 39, 31, 80, 48, 127, 22, 0, 4, 1, 8, 6, 3, 4};
    int n = sizeof(A) / sizeof(A[0]);
    printf("Array before sorting:\n");
    print_array(A, n);

    insertion_sort(A, n);
    printf("Array after sorting:\n");
    print_array(A, n);

    return 0;
}
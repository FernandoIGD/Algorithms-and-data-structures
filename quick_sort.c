# include <stdio.h>
# include <stdlib.h>
# include <time.h>
 
void swap(int A[], int j, int i){
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int partition(int A[], int p, int r){
    int pivot = A[r];
    int j = p - 1;
    for(int i = p; i < r; i++){
        if (A[i] <= pivot){
            j ++;
            swap(A, j, i);
        }
    }
    swap(A, j + 1, r);
    return j + 1;
}

int random_partition(int A[], int p, int r){
    int random_pivot = rand()%(r - p + 1) + p;
    swap(A, random_pivot, r);
    return partition(A, p, r);
}

void quick_sort(int A[], int p, int r){
    int q;
    if (p < r){
        q = random_partition(A, p, r);
        quick_sort(A, p, q-1);
        quick_sort(A, q+1, r);
    }
}

void print_array(int A[], int n){
    for(int i = 0; i < n; i++){
        printf("%i ", A[i]);
    }
    printf("\n");
}

int main(){
    srand(time(NULL));
    int A[] = {10, 56, 47, 39, 31, 80, 48, 127, 22, 0, 4, 1, 8, 6, 3, 4, 9};
    int n = sizeof(A) / sizeof(A[0]);
    printf("Array before sorting:\n");
    print_array(A, n);

    quick_sort(A, 0, n - 1);
    printf("Array after sorting:\n");
    print_array(A, n);

    return 0;
}
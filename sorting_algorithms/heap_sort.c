# include <stdio.h>
# include <stdlib.h>


void swap(int a[], int i, int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void max_heapify (int a[], int i, int heap_size){
    int l, r;
    
    l = i*2 + 1;
    r = i*2 + 2;
    int largest = i;

    if (l < heap_size && a[l] > a[i]){
        largest = l;
    }

    if (r < heap_size && a[r] > a[largest]){
        largest = r;
    }

    if (largest != i){
        swap(a, i, largest);
        max_heapify(a, largest, heap_size);
    }
}

void build_max_heap(int a[], int n){
    int heap_size = n;

    int i = (n / 2) - 1;
    for(; i >= 0; i--){
        max_heapify(a, i, heap_size);
    }
}

void heap_sort(int a[], int n){
    build_max_heap(a, n);

    for(int i = n - 1; i >= 1; i--){
        swap(a, i, 0);
        max_heapify(a, 0, i);

    }
}

void print_array(int a[],int n){
    for(int i = 0; i < n; i++){
        printf("%i ", a[i]);
    }
    printf("\n");
}


int main(){
    printf("Array before sorting:\n");
    int a[] = {10, 8, 225, 3, 46, 82, 55,56,43,76,89,25,11,76,52};
    int n = sizeof(a) / sizeof(a[0]);

    print_array(a, n);
    heap_sort(a, n);

    printf("Array after sorting:\n");
     print_array(a, n);

    return 0;
}
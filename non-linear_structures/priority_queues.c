# include <stdio.h>
# include <stdlib.h>

typedef struct{
    int size;
    int capacity;
    int *array;
}PriorityQueue;

void swap(int array[], int i, int j){
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void min_heapify(int array[], int i, int size){
    int left = 2*i + 1;
    int right =  2*i + 2;
    int lowest = i;

    if( left < size && array[lowest] > array[left])
        lowest = left;

    if (right < size && array[lowest] > array[right])
        lowest = right;

    if (lowest != i){
        swap(array, i, lowest);
        min_heapify(array, lowest, size);
    }  
}

void growCapacity(PriorityQueue *pq){
    int newCapacity = pq->capacity * 2;
    
    int *temp = realloc(pq->array, newCapacity*sizeof(int));
    if (temp == NULL){
        fprintf(stderr, "Failed to reallocate memory\n");
        return;
    }

    pq->array = temp;
    pq->capacity = newCapacity;
}

void insert(PriorityQueue *pq, int newValue){
    if (pq->size == pq->capacity)
        growCapacity(pq);
    
    int i = pq->size;
    pq->array[i] = newValue;
    pq->size++;
    
    while (i != 0 && pq->array[i] < pq->array[(i - 1) / 2]){
        swap(pq->array, i , (i - 1) / 2);
        i = (i - 1) / 2;
    }
}

int extractMin(PriorityQueue *pq){
    if(pq->size <= 0){
        printf("Queue is empty\n");
        return -1;
    }
    int result = pq->array[0];
    pq->array[0] = pq->array[pq->size - 1];
    pq->size --;

    if (pq->size > 1)
        min_heapify(pq->array, 0, pq->size);

    return result;    
}

PriorityQueue *initQueue(int capacity) {
    PriorityQueue *newPQ = malloc(sizeof(PriorityQueue));
    
    if (newPQ == NULL) return NULL; 
    newPQ->capacity = capacity;
    newPQ->size = 0;
    newPQ->array = malloc(capacity * sizeof(int));
    
    if (newPQ->array == NULL) { 
        free(newPQ); 
        return NULL;
    }
    
    return newPQ;
}

void destroyQueue(PriorityQueue *pq){
    free(pq->array);
    free(pq);
}

int main() {
    return 0;
}
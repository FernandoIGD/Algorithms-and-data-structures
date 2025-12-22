# include <stdio.h>
# include <stdlib.h>

typedef struct {
    int top;
    unsigned capacity;
    int *array;
}Stack;

typedef struct{
    int front, rear;
    int size;
    unsigned capacity;
    int *array;
}Queue;

Stack *createStack(unsigned capacity){
    Stack *stack = malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = malloc(capacity * sizeof(int));

    return stack;
}

void push(Stack *stack, int item){
    if (stack->top == stack->capacity - 1){
        printf("Stack overflow");
        return;
    }
    stack->top ++;
    stack->array[stack->top] = item;
}

int pop(Stack *stack){
    if (stack->top == -1){
        printf("Stack underflow");
        return -1;
    } 

    int item = stack->array[stack->top];
    stack->top--;
    return item;   
}

Queue *createQueue(int capacity){
    Queue *queue = malloc(sizeof(Queue));
    queue->front = 0;
    queue->rear = capacity - 1;
    queue->capacity = capacity;
    queue->size = 0;
    queue->array = malloc(capacity * sizeof(int));

    return queue;
}

void enQueue(Queue *queue, int item){
    if (queue->size == queue->capacity){
        printf("Queue overflow");
        return;
    }

    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
}

int deQueue(Queue *queue){
    if(queue->size == 0){
        printf("Queue underflow");
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;

    return item;
}

int main(){
    return 0;
}
# include <stdio.h>
# include <stdlib.h>

//Single linked list
typedef struct{
    int value;
    Node *next;
}Node;

// Double linked list
typedef struct {
    int value;
    NodeDouble *next;
    NodeDouble *prev;
}NodeDouble;

//Queue
typedef struct{
    Node *front, *rear;
}Queue;

//Stack functions are just based on single nodes
void push(Node **headRef, int newValue){
    Node *newNode = malloc(sizeof(Node));
    
    newNode->value = newValue;
    newNode->next = *headRef;
    *headRef = newNode;
}

int pop(Node **headRef){
    if (*headRef == NULL){
        print("Stack underflow");
        return -1;
    }
    Node *tempPointer = *headRef;
    int value = (*headRef)->value;
    *headRef = (*headRef)->next;
    free(tempPointer);

    return value;
}

//Queue functions need a special wrapper structure 'Queue'
void enQueue(Queue *queue, int value){
    Node *temp = malloc(sizeof(Node));
    temp->value = value;
    temp->next = NULL;

    if (queue->rear == NULL){
        queue->front = queue->rear = temp;
        return;
    }
    
    queue->rear->next = temp; // The previous rear node now points to the new temp node
    queue->rear = temp; // The rear node now points to the temp node
}

int deQueue(Queue *queue){
    if (queue->front == NULL){
        printf("Queue underflow");
        return -1;
    }

    int value = queue->front->value;
    Node *tempNode = queue->front;
    queue->front = queue->front->next;
    if(queue->front == NULL){
        queue->rear = NULL;
    }
    free(tempNode);
    
    return value;
}

int main(){
    return 0;
}
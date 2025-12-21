# include <stdio.h>
# include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    int value;
    Node *next;
}Node;

typedef struct {
    int size;
    Node **table; // an array of pointers to Nodes
}hashTable;

unsigned int hashFunction(int size, char *key){
    unsigned int hash_value = 0;

    for(int i = 0; key[i] != '\0'; i++){
        hash_value += key[i];
    }
    return hash_value % size;
}

void insert(char *key, int value, hashTable *table){
    int index = hashFunction(table->size, key);
    Node *currentNode = table->table[index];

    while (currentNode != NULL){
        if (!strcmp(currentNode->key, key)){
            currentNode->value = value;
            return;
        }else{
            currentNode = currentNode->next;
        }
    }

    Node *newNode = malloc(sizeof(Node));
    newNode->next = table->table[index];
    newNode->key = strdup(key);
    newNode->value = value;
    table->table[index] = newNode;
}

int getValue(char *key, hashTable *table){
    int index = hashFunction(table->size, key);

    Node *currentNode = table->table[index];
    while(currentNode != NULL){
        if (!strcmp(key, currentNode->key)){
            return currentNode->value;
        }else{
            currentNode = currentNode->next;
        }
    }

    return -1;
}

void deletePair(char *key, hashTable *table){
    int index = hashFunction(table->size, key);

    Node *currentNode = table->table[index];
    Node *prevNode = NULL;
    while(currentNode != NULL){
        if (!strcmp(key, currentNode->key)){
            free(currentNode->key);
            if (prevNode == NULL){
                table->table[index] = currentNode->next;
                free(currentNode);
                return;
            }
            prevNode->next = currentNode->next;
            free(currentNode);
            return;
        }else{
            prevNode = currentNode;
            currentNode = currentNode->next;
        }
    }
}

void freeTable(hashTable *table) {
    for (int i = 0; i < table->size; i++) {
        Node *current = table->table[i];
        while (current != NULL) {
            Node *temp = current;
            current = current->next;

            free(temp->key);   
            free(temp);        
        }
    }
    
    free(table->table);
    free(table);
}

int main(){
    return 0;
}
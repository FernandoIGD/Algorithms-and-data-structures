# include <stdio.h>
# include <stdlib.h>

typedef struct{
    int value;
    Node *left;
    Node *right;
}Node;

Node *createNode(int value){
    Node *newNode = malloc(sizeof(Node));

    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void printInOrder(Node *root){
    if(root == NULL){
        return;
    }
    printInOrder(root->left);
    printf("%d", root->value);
    printInOrder(root->right);
}

Node *insert(Node *root, int value){
    if(root == NULL){
        return createNode(value);
    }

    if (value < root->value){
        root->left = insert(root->left, value);
    }else if (value > root->value){
        root->right = insert(root->right, value);
        
    }
    return root;
}

Node *minValueNode(Node *node){
    Node *currentNode = node;
   while (currentNode != NULL && currentNode->left != NULL){
    currentNode = currentNode->left;
   }
   return currentNode;
}

Node *deleteNode(Node *root, int value){
    if (root == NULL) return root;
    
    if (root->value < value)
        root->left = deleteNode(root->left, value);
    else if (root->value > value)
        root->right = deleteNode(root->left, value);
    else{
        if (root->left == NULL){
            Node *temp = root->right;
            free(root);
            return temp;
        }else if (root->right == NULL){
            Node *temp = root->left;
            free(root);
            return temp;
        }

        Node *temp = minValueNode(root->right);
        root->value = temp->value;
        root->right = deleteNode( root->right, temp->value);
    } 
    return root;
}

int main(){
    return 0;
}
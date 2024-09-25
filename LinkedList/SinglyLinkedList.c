#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node **head, int value){
    struct Node *newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node **head, int value){
    struct Node *newNode = createNode(value);
    if(*head == NULL){
        *head = newNode;
        return;
    }

    // we create a temporary variable to not lose the initial value of "head"
    struct Node* temp = *head;

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteNode(struct Node **head, int value){
    
    struct Node* temp = *head;
    struct Node* prev = NULL;

    if(temp != NULL && temp->data == value){
        *head = temp->next;
        free(temp);
        return;
    }
    while(temp != NULL && temp->data != value){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) return;
    prev->next = temp->next;
    free(temp);

}

void printList(struct Node *head){
    if(head == NULL){
        printf("NO ELEMENTS IN THE LINKEDLIST !\n");
        return;
    }
    struct Node* temp = head;
    while(temp != NULL){
        printf(" %d \t --> \t", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int search(struct Node *head, int value){
    struct Node *temp = head;
    while(temp != NULL){
        if(temp->data == value){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main(){
    struct Node *head = NULL;
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    printList(head);
    deleteNode(&head, 20);
    printf("\nFOUND : %d\n", search(head,10));
    printList(head);
    return 0;
}
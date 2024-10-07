#include <stdlib.h>
#include <stdio.h>



//node struct
struct Node{
    int data;
    struct Node* next;
};

//function to create nodes with data
struct Node* createNode (int data){ 

    struct Node* newNode = (struct Node*) malloc( sizeof(*newNode) );

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


//inserts a node at the beginning
//creates a node and inserts node at the beginning of the list 
void insertsAtBeginning(struct Node** head, int data){

    struct Node* newNode = createNode(data);

    //initialize head with  NULL
    newNode->next = *head;

    //head now points to newNode
    *head = newNode;
}


//creates a node and inserts at the end of the list
void insertAtEnd(struct Node** head, int data){

    struct Node* newNode = createNode(data);

    //head points to nothing, make newNode next
    if(*head == NULL){
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;

}

//delet a node by key
void deletNode(struct Node** head, int key){

    struct Node* temp = *head;
    struct Node* prev = NULL;


    //if first after head
    if(temp != NULL && temp->data == key){
        *head = temp->next;
        free(temp);
        return;
    }

    //search for node to delete
    while(temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }

    //key was not found
    if(temp == NULL){
        return;
    }

    //remove node from the list
    prev->next = temp->next;

    free(temp);
}


///print data in the list
void printList(struct Node* head){
    struct Node* temp = head;

    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}
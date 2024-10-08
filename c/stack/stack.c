//includes malloc
#include <stdlib.h>
#include <stdio.h>

/*
stack

operation
    push(v) => add v to the top of the stack
    pop() => remove and return topmost element on the stack 

This implementation uses linked list
*/

struct Node {
    int key;
    struct Node* next;
};

//head, tail, and temp
struct Node *head, *z, *t;

//initialize the stack structure
void stack_init(){

    head = (struct Node*) malloc(sizeof(*head));
    z = (struct Node*) malloc(sizeof(*z));

    head->next = z; head->key = 0;
    z->next = z;
}

void push(int v){

    t = (struct Node*) malloc(sizeof(*t));

    t->key = v; 
    //make new element the topmost element
    t->next = head->next;
    head->next = t;
}

int pop(){

    int x;
    t = head->next;
    //unlinking the topmost element
    head->next = t->next;
    x = t->key;
    free(t);
    
    return x;
}

//if stack is empty
int stack_empty(){
    return head->next == z;
}

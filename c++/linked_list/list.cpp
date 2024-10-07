#include <iostream>
#include <cstdlib>



typedef struct list {
    int item;
    struct list *next; 
} list;




list *search_list(list *l, int elem){
    if(l == NULL)
        return NULL;
    if(l->item == elem){
        return l;
    }
    return search_list(l->next, elem);
}

void insert_list(list **l, int x){

    list *p = (list *) malloc( sizeof(list) );

    p->item = x;
    p->next = *l;

    *l = p;
}

list *predecessor_list(list *l, int x){

    if((l == NULL) || (l->next == NULL)){
        std::cout <<"Error: predecessor element does not exist " << "\n";
        return NULL;
    }

    if((l->next)->item == x){
        return (l);
    }

    return ( predecessor_list(l->next, x) );
}


void delete_list(list **l, int x){
    
    list * p = search_list(*l, x);
    if(p != NULL){
        list * pred = predecessor_list(*l, x);
        if(pred == NULL){
            *l = p->next;
        }else{
            pred->next = p->next;
        }
        free(p);
    }
}
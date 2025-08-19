#include<stdio.h>

#define MAX 3

typedef struct{
    int data[MAX];
    int size;
}list;

void create(list *list){
    list->size = 0;
}

void insert(list *list,int value){
    if(list -> size == MAX){
        printf("list full.\n");
        return;
    }
    list->data[list->size] = value;
    list->size++;
}

void delete(list *list){
    if(list -> size == 0){
        printf("nothing to delete here.\n");
        return;
    }
    list -> size--;
}

void display(list *list){
    if(list->size == 0){
        printf("nothing to display here.\n");
        return;
    }
    for(int i = 0; i < list->size; i++){
    printf("list : %d",list->data[i]);
    printf("\n");
    }
    printf("\n");
 
}

int main(){
    list mylist;
    list guru;
    create(&mylist);
    create(&guru);

    insert(&mylist,123);
    insert(&mylist,12123);
    insert(&mylist,11223);
    insert(&mylist,11233);

    delete(&mylist);
    delete(&mylist);
    delete(&mylist);
    delete(&mylist);


    display(&mylist);
    display(&guru);


}
#include<stdio.h>

#define MAX 100

typedef struct{
    int data[MAX];
    int size;
}list;

void create(list *list){
    list->size = 0;
}

void insert(list *list ,int value){
    if(list->size == MAX){
        printf("List is full.No space to insert anything.\n");
        return;
    }
    list->data[list->size]=value;
    list->size++;
}

void delete(list *list){
    if(list->size == 0){
        printf("List is empty.Nothing to delete here.\n");
        return;
    }
    // list->data[list->size]; if we pass position here we can delete using like this
    list->size--;
}

void display(list *list){
    if(list->size == 0){
        printf("List is empty.Nothing to display here.\n");
        return;
    }
    for(int i = 0 ; i < list->size;i++){
        printf("%d ",list->data[i]);
    }
    printf("\n");
}

int main(){
    list mylist;
    create(&mylist);

    insert(&mylist, 10);
    insert(&mylist, 20);
    insert(&mylist, 30);

    display(&mylist);

    delete(&mylist);
    display(&mylist);

    return 0;
}
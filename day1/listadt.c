#include<stdio.h>

#define MAX 100 

typedef struct{
    int data[MAX];
    int size;
}list;

void createlist(list *list){
    list->size = 0;
    printf("%d\n",list->size);
}

void insert(list *list,int value){
    if(list->size == MAX){
        printf("List is full ! cannot insert.\n");
        return;
    }
    list->data[list->size] = value;
    list->size++;
    printf("%d\n",list->size);
    for(int i = 0 ;i < list->size;i++){
        printf("%d\n",i);
    }
    printf("%d",list->data[0]);
}

void delete(list *list){
    if(list->size == 0){
        printf("List is empty ! nothing to delete here.\n");
        return;
    }
    list->size--;
}


int main(){
    list mylist;
    createlist(&mylist);
    insert(&mylist,10);
    delete(&mylist,1);
    printf("2 : %d",mylist[0]);
}


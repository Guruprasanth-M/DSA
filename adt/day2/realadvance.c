#include<stdio.h>

#define MAX 100

typedef struct{
    int data[MAX];
    int size;
}list;

void create(list *list){
    list->size = 0;
}

void insert(list *list,int value,int pos){
    if(list -> size == MAX){
        printf("list full.\n");
        return;
    }
    if(pos<0 || pos > list->size){
        printf("insert invalid.\n");
        return;
    }
    for(int i = list->size; i > pos ; i--){
         list->data[i] = list->data[i-1];
    }
    list->data[pos] = value;
    list->size++;
}

void delete(list *list,int pos){
    if(list -> size == 0){
        printf("nothing to delete here.\n");
        return;
    }
    if(pos<0 || pos > list->size){
        printf("delete invalid.\n");
        return;
    }
    for(int i = pos; i < list->size -1; i++){
         list->data[i] = list->data[i+1];
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
    }
    printf("\n");
 
}
int count(list *list){
    return list->size;
}

int get(list *list,int pos){
    if(pos < 0 ||pos > list->size){
        printf(" get invalid.\n");
        return -1;
    }
    return list->data[pos];
}
int main(){
    // Create two lists
    list list1, list2;
    create(&list1);
    create(&list2);

    // Insert elements in list1
    insert(&list1, 10, 0); // insert 10 at position 0
    insert(&list1, 20, 1); // insert 20 at position 1
    insert(&list1, 15, 1); // insert 15 at position 1
    printf("List1 after insertions: ");
    display(&list1);  // 10 15 20
    printf("Count of List1: %d\n", count(&list1));

    // Insert elements in list2
    insert(&list2, 100, 0);
    insert(&list2, 200, 1);
    insert(&list2, 150, 1);
    printf("List2 after insertions: ");
    display(&list2); // 100 150 200
    printf("Count of List2: %d\n", count(&list2));

    // Delete elements
    delete(&list1, 1); // remove 15 from list1
    printf("List1 after deleting position 1: ");
    display(&list1);

    delete(&list2, 0); // remove 100 from list2
    printf("List2 after deleting position 0: ");
    display(&list2);

    // Get elements
    printf("Element at position 1 in List1: %d\n", get(&list1, 1));
    printf("Element at position 0 in List2: %d\n", get(&list2, 0));

    return 0;
}
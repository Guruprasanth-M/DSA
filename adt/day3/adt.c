#include <stdio.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int size;
} List;

// Create new list
void create(List *lst) {
    lst->size = 0;
}

// Insert at position
void insert(List *lst, int value, int pos) {
    if (lst->size == MAX) {
        printf("List is full.\n");
        return;
    }
    if (pos < 0 || pos > lst->size) {
        printf("Invalid position.\n");
        return;
    }
    for (int i = lst->size; i > pos; i--) {
        lst->data[i] = lst->data[i - 1];
    }
    lst->data[pos] = value;
    lst->size++;
}

// Insert at end
void insertEnd(List *lst, int value) {
    insert(lst, value, lst->size);
}

// Delete at position
void delete(List *lst, int pos) {
    if (lst->size == 0) {
        printf("List is empty.\n");
        return;
    }
    if (pos < 0 || pos >= lst->size) {
        printf("Invalid position.\n");
        return;
    }
    for (int i = pos; i < lst->size - 1; i++) {
        lst->data[i] = lst->data[i + 1];
    }
    lst->size--;
}

// Display list
void display(List *lst) {
    if (lst->size == 0) {
        printf("List is empty.\n");
        return;
    }
    printf("List: ");
    for (int i = 0; i < lst->size; i++) {
        printf("%d ", lst->data[i]);
    }
    printf("\n");
}

// Count elements
int count(List *lst) {
    return lst->size;
}

// Check empty/full
int isEmpty(List *lst) {
    return lst->size == 0;
}

int isFull(List *lst) {
    return lst->size == MAX;
}

// Clear list
void clear(List *lst) {
    lst->size = 0;
}

// Reverse list
void reverse(List *lst) {
    for (int i = 0, j = lst->size - 1; i < j; i++, j--) {
        int temp = lst->data[i];
        lst->data[i] = lst->data[j];
        lst->data[j] = temp;
    }
}

// Find maximum
int findMax(List *lst) {
    if (isEmpty(lst)) return -1;
    int max = lst->data[0];
    for (int i = 1; i < lst->size; i++) {
        if (lst->data[i] > max)
            max = lst->data[i];
    }
    return max;
}

// Find minimum
int findMin(List *lst) {
    if (isEmpty(lst)) return -1;
    int min = lst->data[0];
    for (int i = 1; i < lst->size; i++) {
        if (lst->data[i] < min)
            min = lst->data[i];
    }
    return min;
}

// Merge two lists
List merge(List *a, List *b) {
    List result;
    create(&result);

    for (int i = 0; i < a->size; i++) {
        insertEnd(&result, a->data[i]);
    }
    for (int i = 0; i < b->size; i++) {
        insertEnd(&result, b->data[i]);
    }
    return result;
}

int main() {
    List list1, list2, merged;
    create(&list1);
    create(&list2);

    insertEnd(&list1, 10);
    insertEnd(&list1, 20);
    insertEnd(&list1, 30);
    display(&list1);

    insertEnd(&list2, 40);
    insertEnd(&list2, 50);
    display(&list2);

    printf("Max in list1: %d\n", findMax(&list1));
    printf("Min in list2: %d\n", findMin(&list2));

    // reverse(&list1);
    // printf("List1 reversed: ");
    display(&list1);

    merged = merge(&list1, &list2);
    printf("Merged List: ");
    display(&merged);

    clear(&list1);
    printf("List1 after clear: ");
    display(&list1);

    return 0;
}

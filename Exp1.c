#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size, capacity;
} Array;

Array* initArray(int cap) {
    Array *a = malloc(sizeof(Array));
    a->data = malloc(cap * sizeof(int));
    a->size = 0;
    a->capacity = cap;
    return a;
}

void insert(Array *a, int pos, int val) {
    if (a->size == a->capacity) { printf("Array is Full!!\n"); return; }
    if (pos < 0 || pos > a->size) { printf("Invalid position\n"); return; }
    for (int i = a->size++; i > pos; i--) a->data[i] = a->data[i-1];
    a->data[pos] = val;
}

void delete(Array *a, int pos) {
    if (pos < 0 || pos >= a->size) { printf("Invalid position\n"); return; }
    for (int i = pos; i < --a->size; i++) a->data[i] = a->data[i+1];
}

void display(Array *a) {
    printf("Array: ");
    for (int i = 0; i < a->size; i++) printf("%d ", a->data[i]);
    printf("\n");
}

int main() {
    int n, choice, pos, val;
    printf("Enter the number of initial elements (up to 100): ");
    scanf("%d", &n);
    
    Array *arr = initArray(n > 100 ? 100 : n);
    
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr->data[i]);
    arr->size = n;
    
    while (1) {
        printf("\nMenu:\n1. Insert\n2. Delete\n3. Display\n4. Exit\nChoice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: 
                printf("Enter position and value: ");
                scanf("%d %d", &pos, &val);
                insert(arr, pos, val);
                break;
            case 2:
                printf("Enter position: ");
                scanf("%d", &pos);
                delete(arr, pos);
                break;
            case 3: display(arr); break;
            case 4: free(arr->data); free(arr); return 0;
            default: printf("Invalid choice\n");
        }
    }
}
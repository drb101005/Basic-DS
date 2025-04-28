#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
} *top = NULL;

void push() {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("\nEnter the number to be pushed on stack:");
    scanf("%d", &newNode->data);
    newNode->next = top;
    top = newNode;
}

void pop() {
    if (top == NULL) {
        printf("\nStack Underflow!\n");
        return;
    }
    struct Node* temp = top;
    printf("\nPopped: %d\n", temp->data);
    top = top->next;
    free(temp);
}

void peek() {
    if (top == NULL)
        printf("\nStack is empty!\n");
    else
        printf("\nTop element: %d\n", top->data);
}

void display() {
    if (top == NULL) {
        printf("\nStack is empty!\n");
        return;
    }
    struct Node* temp = top;
    printf("\nStack: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n***MAIN MENU****\n1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY\n5.EXIT\nEnter your option:");
        scanf("%d", &choice);
        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: exit(0);
            default: printf("\nInvalid option!\n");
        }
    }
    return 0;
}
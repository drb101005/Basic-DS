#include <stdio.h>
#include <stdlib.h>

// Definition of a Node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to push an element onto the stack
void push(Node** top, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

// Function to pop an element from the stack
int pop(Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    Node* temp = *top;
    int poppedValue = temp->data;
    *top = (*top)->next;
    free(temp);
    return poppedValue;
}

// Function to display the stack
void displayLinkedListStack(Node* top) {
    if (top == NULL) {
        printf("Stack is Empty\n");
    } else {
        printf("Stack Contents: ");
        Node* temp = top;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function to test the stack
int main() {
    Node* stackTop = NULL;

    push(&stackTop, 10);
    push(&stackTop, 20);
    push(&stackTop, 30);

    displayLinkedListStack(stackTop);

    printf("Popped: %d\n", pop(&stackTop));
    displayLinkedListStack(stackTop);

    return 0;
}

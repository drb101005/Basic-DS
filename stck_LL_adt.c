#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* top = NULL;

// Push operation
void push(int item) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = item;
    newNode->next = top;
    top = newNode;
    printf("%d pushed to stack\n", item);
}

// Pop operation
int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        Node* temp = top;
        int item = top->data;
        top = top->next;
        free(temp);
        return item;
    }
}

// Peek operation
int peek() {
    if (top == NULL) {
        printf("Stack is Empty\n");
        return -1;
    } else {
        return top->data;
    }
}

// Display stack
void display() {
    if (top == NULL) {
        printf("Stack is Empty\n");
    } else {
        printf("Stack: ");
        Node* temp = top;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    push(100); push(200); push(300);
    display();          // Output: Stack: 300 200 100
    printf("Top element: %d\n", peek()); // Output: 300
    printf("Popped: %d\n", pop());       // Output: 300
    display();          // Output: Stack: 200 100
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int stack[MAX], top = -1;

// Push operation
void push(int item) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = item;
        printf("%d pushed to stack\n", item);
    }
}

// Pop operation
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

// Peek operation
int peek() {
    if (top == -1) {
        printf("Stack is Empty\n");
        return -1;
    } else {
        return stack[top];
    }
}

// Display stack
void display() {
    if (top == -1) {
        printf("Stack is Empty\n");
    } else {
        printf("Stack: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    push(10); push(20); push(30);
    display();          // Output: Stack: 30 20 10
    printf("Top element: %d\n", peek()); // Output: 30
    printf("Popped: %d\n", pop());       // Output: 30
    display();          // Output: Stack: 20 10
    return 0;
}
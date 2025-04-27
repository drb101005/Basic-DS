#include <stdio.h>
#define MAX 5

int stack[MAX], top = -1;

void push() {
    if (top == MAX-1) printf("Stack Overflow!\n");
    else {
        int val;
        printf("Enter the value to be inserted: ");
        scanf("%d", &val);
        stack[++top] = val;
        printf("\nInsertion success!!!\n");
    }
}

void pop() {
    if (top == -1) printf("Stack Underflow!\n");
    else printf("Popped: %d\n", stack[top--]);
}

void display() {
    if (top == -1) printf("Stack is empty\n");
    else {
        printf("Stack: ");
        for (int i = top; i >= 0; i--) printf("%d ", stack[i]);
        printf("\n");
    }
}

void peek() {
    if (top == -1) printf("Stack is empty\n");
    else printf("Top element: %d\n", stack[top]);
}

int main() {
    int choice;
    while (1) {
        printf("\n***** MENU *****\n1. Push\n2. Pop\n3. Display\n4. Peek\n5. Exit\n\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: peek(); break;
            case 5: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
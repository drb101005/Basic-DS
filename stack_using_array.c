#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 5

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

// Function prototypes
void initializeStack(Stack *s);
bool isFull(Stack *s);
bool isEmpty(Stack *s);
void push(Stack *s);
void pop(Stack *s);
void display(Stack *s);
void peek(Stack *s);
void stackSize(Stack *s);
void clearStack(Stack *s);
void printMenu();

int main() {
    Stack myStack;
    initializeStack(&myStack);
    int choice;

    while (1) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(&myStack); break;
            case 2: pop(&myStack); break;
            case 3: display(&myStack); break;
            case 4: peek(&myStack); break;
            case 5: stackSize(&myStack); break;
            case 6: clearStack(&myStack); break;
            case 7: 
                clearStack(&myStack);
                printf("Exiting program.\n");
                exit(EXIT_SUCCESS);
            default: 
                printf("Invalid choice! Please try again.\n");
                while(getchar() != '\n'); // Clear input buffer
        }
    }

    return 0;
}

void initializeStack(Stack *s) {
    s->top = -1;
}

bool isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

bool isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push more elements.\n");
        return;
    }

    int value;
    printf("Enter value to push: ");
    if (scanf("%d", &value) != 1) {
        printf("Invalid input! Please enter an integer.\n");
        while(getchar() != '\n'); // Clear input buffer
        return;
    }

    s->data[++s->top] = value;
    printf("Successfully pushed %d onto the stack.\n", value);
}

void pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Cannot pop from empty stack.\n");
        return;
    }

    printf("Popped value: %d\n", s->data[s->top--]);
}

void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack contents (top to bottom):\n");
    for (int i = s->top; i >= 0; i--) {
        printf("[%d] %d\n", i, s->data[i]);
    }
}

void peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty. No top element.\n");
        return;
    }

    printf("Top element: %d\n", s->data[s->top]);
}

void stackSize(Stack *s) {
    printf("Current stack size: %d/%d\n", s->top + 1, MAX_SIZE);
}

void clearStack(Stack *s) {
    s->top = -1;
    printf("Stack cleared.\n");
}

void printMenu() {
    printf("\n========== STACK OPERATIONS ==========\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Display\n");
    printf("4. Peek (view top element)\n");
    printf("5. Check stack size\n");
    printf("6. Clear stack\n");
    printf("7. Exit\n");
    printf("=====================================\n");
}
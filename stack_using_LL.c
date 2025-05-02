#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* top = NULL;

// Function prototypes
void push();
void pop();
void peek();
void display();
void stackSize();
void clearStack();
bool isEmpty();
void printMenu();
Node* createNode(int value);
void freeStack();

int main() {
    int choice;
    
    while (1) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: stackSize(); break;
            case 6: clearStack(); break;
            case 7:
                freeStack();
                printf("Exiting program.\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice! Please try again.\n");
                while(getchar() != '\n'); // Clear input buffer
        }
    }
    
    return 0;
}

// Create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Check if stack is empty
bool isEmpty() {
    return top == NULL;
}

// Push element onto stack
void push() {
    int value;
    printf("Enter value to push: ");
    if (scanf("%d", &value) != 1) {
        printf("Invalid input! Please enter an integer.\n");
        while(getchar() != '\n'); // Clear input buffer
        return;
    }
    
    Node* newNode = createNode(value);
    newNode->next = top;
    top = newNode;
    printf("Successfully pushed %d onto the stack.\n", value);
}

// Pop element from stack
void pop() {
    if (isEmpty()) {
        printf("Stack Underflow! Cannot pop from empty stack.\n");
        return;
    }
    
    Node* temp = top;
    int poppedValue = temp->data;
    top = top->next;
    free(temp);
    printf("Popped value: %d\n", poppedValue);
}

// Peek at top element
void peek() {
    if (isEmpty()) {
        printf("Stack is empty. No top element.\n");
        return;
    }
    
    printf("Top element: %d\n", top->data);
}

// Display stack contents
void display() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return;
    }
    
    printf("Stack contents (top to bottom):\n");
    Node* current = top;
    int position = 0;
    
    while (current != NULL) {
        printf("[%d] %d\n", position++, current->data);
        current = current->next;
    }
}

// Get current stack size
void stackSize() {
    int count = 0;
    Node* current = top;
    
    while (current != NULL) {
        count++;
        current = current->next;
    }
    
    printf("Current stack size: %d elements\n", count);
}

// Clear the entire stack
void clearStack() {
    while (!isEmpty()) {
        Node* temp = top;
        top = top->next;
        free(temp);
    }
    printf("Stack cleared.\n");
}

// Free all stack memory before exit
void freeStack() {
    clearStack();
}

// Print menu options
void printMenu() {
    printf("\n========== STACK OPERATIONS ==========\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Peek (view top element)\n");
    printf("4. Display stack\n");
    printf("5. Check stack size\n");
    printf("6. Clear stack\n");
    printf("7. Exit\n");
    printf("=====================================\n");
}
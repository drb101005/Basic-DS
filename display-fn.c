#include <stdio.h>
#define MAX 100

// Function declarations
void push(int stack[], int *top, int value);
int pop(int stack[], int *top);
void displayArrayStack(int stack[], int top);

int main() {
    int stack[MAX];
    int top = -1;
    int choice, value;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (top == MAX - 1) {
                    printf("Stack Overflow\n");
                } else {
                    printf("Enter value to push: ");
                    scanf("%d", &value);
                    push(stack, &top, value);
                }
                break;
            case 2:
                if (top == -1) {
                    printf("Stack Underflow\n");
                } else {
                    value = pop(stack, &top);
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                displayArrayStack(stack, top);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

// Push function
void push(int stack[], int *top, int value) {
    (*top)++;
    stack[*top] = value;
}

// Pop function
int pop(int stack[], int *top) {
    int value = stack[*top];
    (*top)--;
    return value;
}

// Display function
void displayArrayStack(int stack[], int top) {
    if (top == -1) {
        printf("Stack is Empty\n");
    } else {
        printf("Stack Contents: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

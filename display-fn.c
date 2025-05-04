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
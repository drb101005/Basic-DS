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
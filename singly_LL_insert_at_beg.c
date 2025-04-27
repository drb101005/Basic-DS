#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void create() {
    int n, value;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    
    for(int i=0; i<n; i++) {
        printf("Enter value for node %d: ", i+1);
        scanf("%d", &value);
        
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }
}

void display() {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    struct Node* temp = head;
    printf("List: ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertAtBeginning() {
    int value;
    printf("Enter value to insert: ");
    scanf("%d", &value);
    
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    printf("Node inserted at beginning\n");
}

int main() {
    int choice;
    
    while(1) {
        printf("\n****MAIN MENU****\n");
        printf("1. Create a list\n");
        printf("2. Display the list\n");
        printf("3. Add a node at the beginning\n");
        printf("4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insertAtBeginning(); break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    
    return 0;
}
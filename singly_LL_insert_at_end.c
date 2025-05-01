#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure definition
struct Node {
    int data;
    struct Node* next;
};

// Global head pointer
struct Node* head = NULL;

// Function prototypes
void displayMenu();
void createList();
void displayList();
void insertAtBeginning(int value);
void insertAtEnd(int value);
void insertAtPosition(int value, int position);
void deleteFromBeginning();
void deleteFromEnd();
void deleteFromPosition(int position);
void searchElement(int value);
void reverseList();
void sortList();
void countNodes();
void deleteList();
struct Node* createNode(int value);
void printListDetails();

// Utility function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to display the menu
void displayMenu() {
    printf("\n========== LINKED LIST OPERATIONS ==========\n");
    printf("1. Create a new list\n");
    printf("2. Display the list\n");
    printf("3. Insert node at beginning\n");
    printf("4. Insert node at end\n");
    printf("5. Insert node at position\n");
    printf("6. Delete node from beginning\n");
    printf("7. Delete node from end\n");
    printf("8. Delete node from position\n");
    printf("9. Search for a value\n");
    printf("10. Reverse the list\n");
    printf("11. Sort the list\n");
    printf("12. Count nodes in list\n");
    printf("13. Delete entire list\n");
    printf("14. Print list details\n");
    printf("15. Exit\n");
    printf("==========================================\n");
}

// Function to create a linked list
void createList() {
    deleteList(); // Clear existing list if any
    
    int n, value;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Invalid number of nodes.\n");
        return;
    }
    
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        insertAtEnd(value);
    }
    printf("List created with %d nodes.\n", n);
}

// Function to display the linked list
void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct Node* temp = head;
    printf("Linked List: [");
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" -> ");
        }
        temp = temp->next;
    }
    printf("]\n");
}

// Function to insert a node at the beginning
void insertAtBeginning(int value) {
    struct Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
    printf("Node with value %d inserted at beginning.\n", value);
}

// Function to insert a node at the end
void insertAtEnd(int value) {
    struct Node* newNode = createNode(value);
    
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Node with value %d inserted at end.\n", value);
}

// Function to insert a node at specific position
void insertAtPosition(int value, int position) {
    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }
    
    if (position == 1) {
        insertAtBeginning(value);
        return;
    }
    
    struct Node* newNode = createNode(value);
    struct Node* temp = head;
    
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Position exceeds list length.\n");
        free(newNode);
        return;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
    
    printf("Node with value %d inserted at position %d.\n", value, position);
}

// Function to delete node from beginning
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is already empty.\n");
        return;
    }
    
    struct Node* temp = head;
    head = head->next;
    int deletedValue = temp->data;
    free(temp);
    
    printf("Node with value %d deleted from beginning.\n", deletedValue);
}

// Function to delete node from end
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is already empty.\n");
        return;
    }
    
    if (head->next == NULL) {
        int deletedValue = head->data;
        free(head);
        head = NULL;
        printf("Node with value %d deleted from end.\n", deletedValue);
        return;
    }
    
    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    
    int deletedValue = temp->next->data;
    free(temp->next);
    temp->next = NULL;
    
    printf("Node with value %d deleted from end.\n", deletedValue);
}

// Function to delete node from specific position
void deleteFromPosition(int position) {
    if (head == NULL) {
        printf("List is already empty.\n");
        return;
    }
    
    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }
    
    if (position == 1) {
        deleteFromBeginning();
        return;
    }
    
    struct Node* temp = head;
    struct Node* prev = NULL;
    
    for (int i = 1; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Position exceeds list length.\n");
        return;
    }
    
    prev->next = temp->next;
    int deletedValue = temp->data;
    free(temp);
    
    printf("Node with value %d deleted from position %d.\n", deletedValue, position);
}

// Function to search for an element
void searchElement(int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    int position = 1;
    bool found = false;
    struct Node* temp = head;
    
    while (temp != NULL) {
        if (temp->data == value) {
            printf("Value %d found at position %d.\n", value, position);
            found = true;
        }
        temp = temp->next;
        position++;
    }
    
    if (!found) {
        printf("Value %d not found in the list.\n", value);
    }
}

// Function to reverse the linked list
void reverseList() {
    if (head == NULL || head->next == NULL) {
        printf("List has less than 2 nodes, no reversal needed.\n");
        return;
    }
    
    struct Node *prev = NULL, *current = head, *next = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    head = prev;
    printf("List has been reversed.\n");
}

// Function to sort the linked list (bubble sort)
void sortList() {
    if (head == NULL || head->next == NULL) {
        printf("List has less than 2 nodes, no sorting needed.\n");
        return;
    }
    
    int swapped;
    struct Node *ptr1;
    struct Node *lptr = NULL;
    
    do {
        swapped = 0;
        ptr1 = head;
        
        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
    
    printf("List has been sorted in ascending order.\n");
}

// Function to count nodes in the list
void countNodes() {
    int count = 0;
    struct Node* temp = head;
    
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    
    printf("Number of nodes in the list: %d\n", count);
}

// Function to delete the entire list
void deleteList() {
    struct Node* current = head;
    struct Node* next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    
    head = NULL;
    printf("Entire list has been deleted.\n");
}

// Function to print detailed list information
void printListDetails() {
    countNodes();
    displayList();
    
    if (head != NULL) {
        printf("Head value: %d\n", head->data);
        
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        printf("Tail value: %d\n", temp->data);
    }
}

// Main function
int main() {
    int choice, value, position;
    
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createList();
                break;
            case 2:
                displayList();
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 4:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 5:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(value, position);
                break;
            case 6:
                deleteFromBeginning();
                break;
            case 7:
                deleteFromEnd();
                break;
            case 8:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteFromPosition(position);
                break;
            case 9:
                printf("Enter value to search: ");
                scanf("%d", &value);
                searchElement(value);
                break;
            case 10:
                reverseList();
                break;
            case 11:
                sortList();
                break;
            case 12:
                countNodes();
                break;
            case 13:
                deleteList();
                break;
            case 14:
                printListDetails();
                break;
            case 15:
                deleteList();
                printf("Exiting program.\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}
#include <stdio.h>
#define MAX 5

int queue[MAX], front = -1, rear = -1;

void insert() {
    if (rear == MAX-1) printf("Queue Overflow!\n");
    else {
        int val;
        printf("Insert the element in queue : ");
        scanf("%d", &val);
        if (front == -1) front = 0;
        queue[++rear] = val;
    }
}

void delete() {
    if (front == -1) printf("Queue Underflow!\n");
    else {
        printf("Deleted : %d\n", queue[front]);
        if (front == rear) front = rear = -1;
        else front++;
    }
}

void display() {
    if (front == -1) printf("Queue is empty\n");
    else {
        printf("Queue is :\n");
        for (int i = front; i <= rear; i++) printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Insert element to queue\n2. Delete element from queue\n3. Display all elements of queue\n4. Quit\nEnter your choice : ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
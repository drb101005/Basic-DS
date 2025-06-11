#include <stdio.h>
#define SIZE 5

int cq[SIZE], front=-1, rear=-1;
#this part is to check and insert a new number 

void insert() {
    if((rear+1)%SIZE == front) printf("Queue is full!\n");
    else {
        int n;
        printf("\nEnter number: ");
        scanf("%d", &n);
        rear = (rear+1)%SIZE;
        cq[rear] = n;
        if(front == -1) front = 0;
    }
}

void delete() {
    if(front == -1) printf("Queue is empty!\n");
    else {
        printf("Deleted: %d\n", cq[front]);
        if(front == rear) front = rear = -1;
        else front = (front+1)%SIZE;
    }
}

void display() {
    if(front == -1) printf("\nQueue is empty!\n");
    else {
        printf("\nQueue: ");
        int i = front;
        while(i != rear) {
            printf("%d ", cq[i]);
            i = (i+1)%SIZE;
        }
        printf("%d\n", cq[rear]);
    }
}

int main() {
    int ch;
    do {
        printf("\nCircular Queue:\n1. Insert\n2. Delete\n3. Display\n0. Exit\nEnter Choice 0-3? : ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
        }
    } while(ch != 0);
    return 0;
}
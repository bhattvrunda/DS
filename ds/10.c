#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

#define MAX_SIZE 100

typedef struct {
    int priority;
    int data;
} Element;

typedef struct {
    Element elements[MAX_SIZE];
    int size;
} PriorityQueue;

// Function prototypes
void initialize(PriorityQueue *pq);
int isEmpty(PriorityQueue *pq);
int isFull(PriorityQueue *pq);
void insert(PriorityQueue *pq, int data, int priority);
Element extractMax(PriorityQueue *pq);
void printQueue(PriorityQueue *pq);

void main() {

     int choice;
    int data, priority;

    PriorityQueue pq;
     clrscr();
    initialize(&pq);



    while (1) {
	printf("\nPriority Queue Menu:\n");
        printf("1. Insert Element\n");
        printf("2. Extract Maximum Element\n");
        printf("3. Print Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
	scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (isFull(&pq)) {
                    printf("Priority queue is full\n");
                    break;
                }
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter priority: ");
                scanf("%d", &priority);
                insert(&pq, data, priority);
		printf("Element inserted.\n");
                break;

            case 2:
                if (isEmpty(&pq)) {
                    printf("Priority queue is empty\n");
                    break;
                }
                {
                    Element max = extractMax(&pq);
                    printf("Extracted Max: %d with priority %d\n", max.data, max.priority);
                }
                break;

            case 3:
                if (isEmpty(&pq)) {
                    printf("Priority queue is empty\n");
                    break;
                }
                printQueue(&pq);
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

	    default:
		printf("Invalid choice. Please try again.\n");
	}
    }


}

void initialize(PriorityQueue *pq) {
    pq->size = 0;
}

int isEmpty(PriorityQueue *pq) {
    return pq->size == 0;
}

int isFull(PriorityQueue *pq) {
    return pq->size == MAX_SIZE;
}

void insert(PriorityQueue *pq, int data, int priority) {
    int i;
    Element newElement;
    newElement.data = data;
    newElement.priority = priority;

    // Find the correct position to insert

    for (i = pq->size - 1; i >= 0 && pq->elements[i].priority < priority; i--) {
        pq->elements[i + 1] = pq->elements[i];
    }
    pq->elements[i + 1] = newElement;
    pq->size++;
}

Element extractMax(PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("Priority queue is empty\n");
        exit(EXIT_FAILURE);
    }

    // The maximum element is at the start of the array
    return pq->elements[0];
}

void printQueue(PriorityQueue *pq) {
    printf("Priority Queue:\n");
    for (int i = 0; i < pq->size; i++) {
        printf("Data: %d, Priority: %d\n", pq->elements[i].data, pq->elements[i].priority);
    }
}

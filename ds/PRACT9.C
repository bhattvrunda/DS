#include <stdio.h>
#include <stdlib.h>

#define MAX 5


typedef struct {
    int processes[MAX];
    int front;
    int rear;
    int count;
} ProcessQueue;


void initializeQueue(ProcessQueue *q);
int isFull(ProcessQueue *q);
int isEmpty(ProcessQueue *q);
void enqueue(ProcessQueue *q, int processID);
void dequeue(ProcessQueue *q);
void display(ProcessQueue *q);

int main() {
int choice, processID;
    ProcessQueue q;
    initializeQueue(&q);



    do {
	printf("\nMenu:\n");
	printf("1. Enqueue Process\n");
	printf("2. Dequeue Process\n");
	printf("3. Display Queue\n");
	printf("4. Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);

	switch (choice) {
	    case 1:
		if (isFull(&q)) {
		    printf("Queue is full. Cannot enqueue process.\n");
		} else {
		    printf("Enter process ID to enqueue: ");
		    scanf("%d", &processID);
		    enqueue(&q, processID);
		}
		break;
	    case 2:
		if (isEmpty(&q)) {
		    printf("Queue is empty. Nothing to dequeue.\n");
		} else {
		    dequeue(&q);
		}
		break;
	    case 3:
		display(&q);
		break;
	    case 4:
		printf("Exiting...\n");
		break;
	    default:
		printf("Invalid choice. Please try again.\n");
	}
    } while (choice != 4);

    return 0;
}


void initializeQueue(ProcessQueue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}


int isFull(ProcessQueue *q) {
    return q->count == MAX;
}


int isEmpty(ProcessQueue *q) {
    return q->count == 0;
}


void enqueue(ProcessQueue *q, int processID) {
    q->rear = (q->rear + 1) % MAX;
    q->processes[q->rear] = processID;
    q->count++;
    printf("Process %d enqueued.\n", processID);
}


void dequeue(ProcessQueue *q) {
    int processID = q->processes[q->front];
    q->front = (q->front + 1) % MAX;
    q->count--;
    printf("Process %d dequeued.\n", processID);
}


void display(ProcessQueue *q) {
	  int i;
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
	return;
    }
    
    printf("Queue elements: ");

    for (i = 0; i < q->count; i++) {
        int index = (q->front + i) % MAX;
        printf("%d ", q->processes[index]);
    }
    printf("\n");
}

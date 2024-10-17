#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int data[MAX];
    int front;
    int rear;
    int count;
} CircularQueue;

void initializeQueue(CircularQueue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

int isFull(CircularQueue *q) {
    return q->count == MAX;
}

int isEmpty(CircularQueue *q) {
    return q->count == 0;
}

void insert(CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot insert %d\n", value);
    } else {
        q->rear = (q->rear + 1) % MAX;
        q->data[q->rear] = value;
        q->count++;
        printf("%d inserted into the queue\n", value);
    }
}

void delete(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Nothing to delete.\n");
    } else {
        printf("%d deleted from the queue\n", q->data[q->front]);
        q->front = (q->front + 1) % MAX;
	q->count--;
    }
}

void modify(CircularQueue *q, int index, int newValue) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot modify.\n");
    } else if (index < 0 || index >= q->count) {
        printf("Invalid index.\n");
    } else {
        int actualIndex = (q->front + index) % MAX;
        q->data[actualIndex] = newValue;
        printf("Value at index %d modified to %d\n", index, newValue);
    }
}

void display(CircularQueue *q) {
	int i;
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
	for ( i = 0; i < q->count; i++) {
            int actualIndex = (q->front + i) % MAX;
            printf("%d ", q->data[actualIndex]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value, index;
    CircularQueue q;
    initializeQueue(&q);


    do {
	printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
	printf("3. Modify\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(&q, value);
                break;
            case 2:
                delete(&q);
                break;
	    case 3:
                printf("Enter index to modify: ");
                scanf("%d", &index);
                printf("Enter new value: ");
                scanf("%d", &value);
		modify(&q, index, value);
                break;
            case 4:
                display(&q);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

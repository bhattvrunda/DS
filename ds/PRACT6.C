#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;
int i = 0;

void insert(int);
void delet();
void modify(int position, int value);
void display();

void main() {
    int choice, value, position;
    clrscr();
    while (1) {
	printf("\n\nSimple Queue Menu:\n");
	printf("1. Insert\n");
	printf("2. Delete\n");
	printf("3. Modify\n");
	printf("4. Display\n");
	printf("5. Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);

	switch (choice) {
	    case 1:
		printf("Enter the value to be inserted: ");
		scanf("%d", &value);
		insert(value);
		break;
	    case 2:
		delet();
		break;
	    case 3:
		printf("Enter the position to modify (1-based index): ");
		scanf("%d", &position);
		printf("Enter the new value: ");
		scanf("%d", &value);
		modify(position, value);
		break;
	    case 4:
		display();
		break;
	    case 5:
		return 0;
	    default:
		printf("Invalid choice! Please try again.\n");
	}
    }
}

void insert(int value) {
    if (rear == SIZE - 1) {
	printf("Queue is Full\n");
	return;
    } else if (front == -1) { // Insert first element
	front = rear = 0;
	queue[rear] = value;
    } else {
	rear++;
	queue[rear] = value;
    }
    printf("Inserted %d\n", value);
}

void delet() {
    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Deleted %d\n", queue[front]);

    if (front == rear) { 
        front = rear = -1;
    } else {
        front++;
    }
}

void modify(int position, int value) {
    int index = front + position - 1;
    if (front == -1) {
	printf("Queue is Empty\n");
        return;
    }


    if (index > rear || index < front) {
        printf("Invalid position! Please try again.\n");
    } else {
        queue[index] = value;
        printf("Modified position %d to %d\n", position, value);
    }
}

void display() {
    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue elements are: \n");
    for (i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}


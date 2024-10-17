#include <stdio.h>
#define SIZE 5

int queue1[SIZE], queue2[SIZE];
int front1 = -1, rear1 = -1;
int front2 = -1, rear2 = -1;
int i = 0;

void insertQueue1(int value);
void insertQueue2(int value);
void deleteQueue1();
void deleteQueue2();
void modifyQueue1(int position, int value);
void modifyQueue2(int position, int value);
void displayQueue1();
void displayQueue2();

int main() {
    int choice, value, position, queueChoice;
    clrscr();
    while (1) {
        printf("\n\nDouble Queue Menu:\n");
        printf("1. Insert in Queue 1\n");
        printf("2. Insert in Queue 2\n");
        printf("3. Delete from Queue 1\n");
        printf("4. Delete from Queue 2\n");
        printf("5. Modify in Queue 1\n");
        printf("6. Modify in Queue 2\n");
        printf("7. Display Queue 1\n");
        printf("8. Display Queue 2\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be inserted in Queue 1: ");
                scanf("%d", &value);
                insertQueue1(value);
                break;
            case 2:
                printf("Enter the value to be inserted in Queue 2: ");
                scanf("%d", &value);
                insertQueue2(value);
                break;
            case 3:
                deleteQueue1();
                break;
            case 4:
                deleteQueue2();
                break;
            case 5:
                printf("Enter the position to modify in Queue 1 (1-based index): ");
                scanf("%d", &position);
                printf("Enter the new value: ");
		scanf("%d", &value);
		modifyQueue1(position, value);
                break;
            case 6:
                printf("Enter the position to modify in Queue 2 (1-based index): ");
                scanf("%d", &position);
                printf("Enter the new value: ");
                scanf("%d", &value);
                modifyQueue2(position, value);
                break;
            case 7:
                displayQueue1();
                break;
            case 8:
                displayQueue2();
                break;
            case 9:
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

void insertQueue1(int value) {
    if (rear1 == SIZE - 1) {
        printf("Queue 1 is Full\n");
        return;
    } else if (front1 == -1) {
        front1 = rear1 = 0;
    } else {
        rear1++;
    }
    queue1[rear1] = value;
    printf("Inserted %d in Queue 1\n", value);
}

void insertQueue2(int value) {
    if (rear2 == SIZE - 1) {
        printf("Queue 2 is Full\n");
        return;
    } else if (front2 == -1) {
        front2 = rear2 = 0;
    } else {
        rear2++;
    }
    queue2[rear2] = value;
    printf("Inserted %d in Queue 2\n", value);
}

void deleteQueue1() {
    if (front1 == -1) {
        printf("Queue 1 is Empty\n");
        return;
    }

    printf("Deleted %d from Queue 1\n", queue1[front1]);

    if (front1 == rear1) {
        front1 = rear1 = -1;
    } else {
	front1++;
    }
}

void deleteQueue2() {
    if (front2 == -1) {
        printf("Queue 2 is Empty\n");
        return;
    }

    printf("Deleted %d from Queue 2\n", queue2[front2]);

    if (front2 == rear2) {
        front2 = rear2 = -1;
    } else {
        front2++;
    }
}

void modifyQueue1(int position, int value) {
    int front, index= position;
    if (front1 == -1) {
	printf("Queue 1 is Empty\n");
	return;
    }


    if (index > rear1 || index < front1) {
	printf("Invalid position! Please try again.\n");
    } else {
	queue1[index] = value;
	printf("Modified position %d in Queue 1 to %d\n", position, value);
    }
}

void modifyQueue2(int position, int value) {
    int front,index =position ;
    if (front2 == -1) {
	printf("Queue 2 is Empty\n");
	return;
    }


    if (index > rear2 || index < front2) {
	printf("Invalid position! Please try again.\n");
    } else {
        queue2[index] = value;
        printf("Modified position %d in Queue 2 to %d\n", position, value);
    }
}

void displayQueue1() {
    if (front1 == -1) {
        printf("Queue 1 is Empty\n");
        return;
    }

    printf("Queue 1 elements are: \n");
    for (i = front1; i <= rear1; i++) {
        printf("%d ", queue1[i]);
    }
    printf("\n");
}

void displayQueue2() {
    if (front2 == -1) {
        printf("Queue 2 is Empty\n");
        return;
    }

    printf("Queue 2 elements are: \n");
    for (i = front2; i <= rear2; i++) {
        printf("%d ", queue2[i]);
    }
    printf("\n");
}


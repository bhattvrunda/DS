#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];
int top1 = -1;
int top2 = MAX;

void push1(int value);
void push2(int value);
int pop1();
int pop2();
int peep1(int position);
int peep2(int position);
void modify1(int position, int value);
void modify2(int position, int value);
void display1();
void display2();

void main() {
    int choice, value, stackNumber, position;
     clrscr();
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Peep\n4. Modify\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter stack number (1 or 2): ");
                scanf("%d", &stackNumber);
                printf("Enter value to push: ");
                scanf("%d", &value);
                if (stackNumber == 1) {
                    push1(value);
                } else if (stackNumber == 2) {
                    push2(value);
                } else {
                    printf("Invalid stack number!\n");
                }
                break;
	    case 2:
                printf("Enter stack number (1 or 2): ");
                scanf("%d", &stackNumber);
                if (stackNumber == 1) {
                    value = pop1();
                    if (value != -1)
                        printf("Popped value from stack 1: %d\n", value);
                } else if (stackNumber == 2) {
                    value = pop2();
                    if (value != -1)
                        printf("Popped value from stack 2: %d\n", value);
                } else {
                    printf("Invalid stack number!\n");
                }
                break;
            case 3:
                printf("Enter stack number (1 or 2): ");
                scanf("%d", &stackNumber);
                printf("Enter position to peep: ");
                scanf("%d", &position);
		if (stackNumber == 1) {
                    value = peep1(position);
                    if (value != -1)
                        printf("Value at position %d in stack 1: %d\n", position, value);
                } else if (stackNumber == 2) {
                    value = peep2(position);
                    if (value != -1)
                        printf("Value at position %d in stack 2: %d\n", position, value);
                } else {
                    printf("Invalid stack number!\n");
                }
                break;
            case 4:
                printf("Enter stack number (1 or 2): ");
                scanf("%d", &stackNumber);
                printf("Enter position to modify: ");
                scanf("%d", &position);
                printf("Enter new value: ");
                scanf("%d", &value);
                if (stackNumber == 1) {
		    modify1(position, value);
                } else if (stackNumber == 2) {
                    modify2(position, value);
                } else {
                    printf("Invalid stack number!\n");
                }
                break;
            case 5:
                printf("Enter stack number (1 or 2): ");
                scanf("%d", &stackNumber);
                if (stackNumber == 1) {
                    display1();
                } else if (stackNumber == 2) {
                    display2();
                } else {
                    printf("Invalid stack number!\n");
                }
                break;
            case 6:
                exit(0);
	    default:
                printf("Invalid choice!\n");
        }
    }


}

void push1(int value) {
    if (top1 < top2 - 1) {
        stack[++top1] = value;
        printf("%d pushed onto stack 1\n", value);
    } else {
        printf("Stack 1 overflow! Unable to push %d\n", value);
    }
}

void push2(int value) {
    if (top1 < top2 - 1) {
        stack[--top2] = value;
	printf("%d pushed onto stack 2\n", value);
    } else {
        printf("Stack 2 overflow! Unable to push %d\n", value);
    }
}

int pop1() {
    if (top1 >= 0) {
        return stack[top1--];
    } else {
        printf("Stack 1 underflow! Unable to pop\n");
        return -1;
    }
}

int pop2() {
    if (top2 < MAX) {
        return stack[top2++];
    } else {
        printf("Stack 2 underflow! Unable to pop\n");
        return -1;
    }
}

int peep1(int position) {
    if (top1 - position + 1 >= 0) {
        return stack[top1 - position + 1];
    } else {
        printf("Invalid position in stack 1!\n");
        return -1;
    }
}

int peep2(int position) {
    if (top2 + position - 1 < MAX) {
        return stack[top2 + position - 1];
    } else {
        printf("Invalid position in stack 2!\n");
        return -1;
    }
}

void modify1(int position, int value) {
    if (top1 - position + 1 >= 0) {
        stack[top1 - position + 1] = value;
        printf("Value at position %d in stack 1 modified to %d\n", position, value);
    } else {
        printf("Invalid position in stack 1!\n");
    }
}

void modify2(int position, int value) {
    if (top2 + position - 1 < MAX) {
        stack[top2 + position - 1] = value;
        printf("Value at position %d in stack 2 modified to %d\n", position, value);
    } else {
        printf("Invalid position in stack 2!\n");
    }
}

void display1() {
	int i;
    if (top1 >= 0) {
        printf("Stack 1 elements: ");
	for ( i = 0; i <= top1; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    } else {
        printf("Stack 1 is empty\n");
    }
}

void display2() {
	int i;
    if (top2 < MAX) {

        printf("Stack 2 elements: ");
	for ( i = MAX - 1; i >= top2; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    } else {
        printf("Stack 2 is empty\n");
    }
}


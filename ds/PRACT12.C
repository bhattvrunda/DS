#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createNode(int data);
void insertEnd(Node **head, int data);
void deleteNode(Node **head, int data);
void displayList(Node *head);

void main() {
    Node *head = NULL; // Initialize the circular linked list as empty
    int choice, data;

    while (1) {
        printf("\nSingly Circular Linked List Menu:\n");
        printf("1. Insert at End\n");
        printf("2. Delete by Value\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertEnd(&head, data);
                printf("Element inserted.\n");
                break;

            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                printf("Element deleted if it was found.\n");
                break;

            case 3:
                printf("Displaying list:\n");
                displayList(head);
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

Node* createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(Node **head, int data) {
    Node *temp = *head;
    Node *newNode = createNode(data);
    if (*head == NULL) {
	newNode->next = newNode; // Point to itself for circular reference
	*head = newNode;
	return;
    }


    while (temp->next != *head) {
	temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head;
}

void deleteNode(Node **head, int data) {

    Node *temp = *head;

       Node *nodeToDelete = temp->next;
    if (*head == NULL) {
	printf("List is empty.\n");
	return;
    }



    // Check if the node to be deleted is the head
    if (temp->data == data) {
	 Node *last = *head;
	if (temp->next == *head) {
	    free(temp); // Only one node in the list
	    *head = NULL;
	    return;
	}
	// Find the last node

	while (last->next != *head) {
	    last = last->next;
	}
	*head = temp->next;
	last->next = *head;
	free(temp);
	return;
    }

    // Search for the node to be deleted
    while (temp->next != *head && temp->next->data != data) {
	temp = temp->next;
    }

    if (temp->next == *head) {
	printf("Element not found.\n");
	return;
    }


    temp->next = nodeToDelete->next;
    free(nodeToDelete);
}

void displayList(Node *head) {
  Node *temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }


    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

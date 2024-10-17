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
    Node *head = NULL; // Initialize the linked list as empty
    int choice, data;

    while (1) {
        printf("\nSingly Linked List Menu:\n");
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
        *head = newNode;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteNode(Node **head, int data) {
       Node *temp = *head;
       Node *prev = NULL;
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }




    if (temp != NULL && temp->data == data) {
        *head = temp->next; // Change head
        free(temp); // Free old head
        return;
    }

    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element not found.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void displayList(Node *head) {
    Node *temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }


    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

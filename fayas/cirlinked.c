#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

/* Insert at beginning */
void insertBeginning(int data) {
    struct node *newNode, *temp;

    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        temp = head;

        while (temp->next != head)
            temp = temp->next;

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
}

/* Insert at end */
void insertEnd(int data) {
    struct node *newNode, *temp;

    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        temp = head;

        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }
}

/* Delete a node */
void deleteNode(int data) {
    struct node *temp, *prev;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    /* Only one node */
    if (head->data == data && head->next == head) {
        free(head);
        head = NULL;
        printf("Node deleted.\n");
        return;
    }

    /* Delete first node */
    if (head->data == data) {
        temp = head;

        while (temp->next != head)
            temp = temp->next;

        temp->next = head->next;
        temp = head;
        head = head->next;

        free(temp);
        printf("Node deleted.\n");
        return;
    }

    prev = head;
    temp = head->next;

    while (temp != head && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == head) {
        printf("Node not found.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);

    printf("Node deleted.\n");
}

/* Display the list */
void display() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    printf("Circular Linked List: ");

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(HEAD)\n");
}

int main() {
    int choice, data;

    while (1) {
        printf("\n--- CIRCULAR LINKED LIST ---\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete a node\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertBeginning(data);
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertEnd(data);
                break;

            case 3:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNode(data);
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}


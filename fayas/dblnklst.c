#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

/* Create a new node */
struct node *createNode(int data) {
    struct node *newNode;

    newNode = (struct node *)malloc(sizeof(struct node));

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

/* i) Insert at beginning */
void insertBeginning(int data) {
    struct node *newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    printf("Node inserted at beginning.\n");
}

/* ii) Insert after a particular node */
void insertAfter(int item, int data) {
    struct node *temp = head;
	    struct node *newNode;

    while (temp != NULL && temp->data != item)
        temp = temp->next;

    if (temp == NULL) {
        printf("Node containing %d not found.\n", item);
        return;
    }

    newNode = createNode(data);

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;

    printf("Node inserted after %d.\n", item);
}

/* iii) Insert at end */
void insertEnd(int data) {
    struct node *newNode = createNode(data);
    struct node *temp;

    if (head == NULL) {
        head = newNode;
        printf("Node inserted at end.\n");
        return;
    }

    temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    printf("Node inserted at end.\n");
}

/* iv) Delete a node containing a particular item */
void deleteItem(int item) {
    struct node *temp = head;

    while (temp != NULL && temp->data != item)
        temp = temp->next;

    if (temp == NULL) {
        printf("Item %d not found.\n", item);
        return;
    }

    /* If node is the first node */
    if (temp->prev == NULL)
        head = temp->next;
    else
        temp->prev->next = temp->next;

    /* If node is not the last node */
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);

    printf("Node containing %d deleted.\n", item);
}

/* v) Delete node at a given position */
void deletePosition(int position) {
    struct node *temp = head;
    int i;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (position <= 0) {
        printf("Invalid position.\n");
        return;
    }

    /* Move to the required position */
    for (i = 1; i < position && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }

    /* If first node */
    if (temp->prev == NULL)
        head = temp->next;
    else
        temp->prev->next = temp->next;

    /* If not last node */
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);

    printf("Node at position %d deleted.\n", position);
}

/* Display the list */
void display() {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Doubly Linked List: ");

    while (temp != NULL) {
        printf("%d", temp->data);

        if (temp->next != NULL)
            printf(" <-> ");

        temp = temp->next;
    }

    printf("\n");
}

int main() {
    int choice;
    int data, item, position;

    while (1) {
        printf("\n----- DOUBLY LINKED LIST -----\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert after a particular node\n");
        printf("3. Insert at end\n");
        printf("4. Delete a node containing an item\n");
        printf("5. Delete a node at a given position\n");
        printf("6. Display\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertBeginning(data);
                break;

            case 2:
                printf("Enter the item after which to insert: ");
                scanf("%d", &item);

                printf("Enter data to insert: ");
                scanf("%d", &data);

                insertAfter(item, data);
                break;

            case 3:
                printf("Enter data: ");
                scanf("%d", &data);

                insertEnd(data);
                break;

            case 4:
                printf("Enter item to delete: ");
                scanf("%d", &item);

                deleteItem(item);
                break;

            case 5:
                printf("Enter position to delete: ");
                scanf("%d", &position);

                deletePosition(position);
                break;

            case 6:
                display();
                break;

            case 7:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}


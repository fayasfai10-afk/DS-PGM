#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;


void insertBeginning()
{
    struct node *newnode;

    newnode = malloc(sizeof(struct node));

    printf("Enter value: ");
    scanf("%d", &newnode->data);

    newnode->next = head;
    head = newnode;

    printf("Node inserted\n");
}


void insertAfter()
{
    struct node *newnode, *temp;
    int value, after;

    newnode = malloc(sizeof(struct node));

    printf("Enter value: ");
    scanf("%d", &value);

    printf("Insert after which value: ");
    scanf("%d", &after);

    newnode->data = value;

    temp = head;

    while (temp != NULL)
    {
        if (temp->data == after)
        {
            newnode->next = temp->next;
            temp->next = newnode;

            printf("Node inserted\n");
            return;
        }

        temp = temp->next;
    }

    printf("Node not found\n");
    free(newnode);
}


void insertEnd()
{
    struct node *newnode, *temp;

    newnode = malloc(sizeof(struct node));

    printf("Enter value: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
    }

    printf("Node inserted\n");
}


void deleteItem()
{
    struct node *temp, *prev;
    int value;

    printf("Enter value to delete: ");
    scanf("%d", &value);

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    /* If first node contains the value */
    if (head->data == value)
    {
        temp = head;
        head = head->next;
        free(temp);

        printf("Node deleted\n");
        return;
    }

    temp = head;

    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Value not found\n");
    }
    else
    {
        prev->next = temp->next;
        free(temp);

        printf("Node deleted\n");
    }
}


void deletePosition()
{
    struct node *temp, *del;
    int position, i;

    printf("Enter position: ");
    scanf("%d", &position);

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    /* Delete first node */
    if (position == 1)
    {
        temp = head;
        head = head->next;
        free(temp);

        printf("Node deleted\n");
        return;
    }

    temp = head;

    for (i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    del = temp->next;
    temp->next = del->next;

    free(del);

    printf("Node deleted\n");
}

/* Display list */
void display()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;

    printf("List: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

/* Main function */
int main()
{
    int choice;

    while (1)
    {
        printf("\n--- SINGLY LINKED LIST ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert After a Particular Node\n");
        printf("3. Insert at End\n");
        printf("4. Delete Particular Item\n");
        printf("5. Delete at Position\n");
        printf("6. Display\n");
        printf("7. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insertBeginning();
                break;

            case 2:
                insertAfter();
                break;

            case 3:
                insertEnd();
                break;

            case 4:
                deleteItem();
                break;

            case 5:
                deletePosition();
                break;

            case 6:
                display();
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}


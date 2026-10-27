
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char name[30];
    char cat[30];
    int pri;
    struct node *next;
};

struct node *front = NULL;

/* Function to assign priority */
int getpri(char cat[])
{
    if (strcmp(cat, "diff") == 0)
        return 1;

    if (strcmp(cat, "senior") == 0)
        return 2;

    if (strcmp(cat, "defence") == 0)
        return 3;

    return 4;   // ordinary
}

/* Insert customer according to priority */
void enque(char name[], char cat[])
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    strcpy(newnode->name, name);
    strcpy(newnode->cat, cat);

    newnode->pri = getpri(cat);
    newnode->next = NULL;

    /* Insert at front if queue is empty
       or new customer has higher priority */
    if (front == NULL || newnode->pri < front->pri)
    {
        newnode->next = front;
        front = newnode;
    }
    else
    {
        struct node *temp = front;

        /* Find the correct position */
        while (temp->next != NULL &&
               temp->next->pri <= newnode->pri)
        {
            temp = temp->next;
        }

        newnode->next = temp->next;
        temp->next = newnode;
    }
}

/* Delete customer from front */
void deque()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    struct node *temp = front;

    printf("Served: %s (%s)\n",
           temp->name, temp->cat);

    front = front->next;

    free(temp);
}

/* Display priority queue */
void display()
{
    struct node *temp = front;

    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("\nPriority Queue:\n");

    while (temp != NULL)
    {
        printf("%s -> %s [Priority %d]\n",
               temp->name,
               temp->cat,
               temp->pri);

        temp = temp->next;
    }
}

int main()
{
    int n, i;
    char name[30];
    char cat[30];

    printf("Enter number of customers: ");
    scanf("%d", &n);

    printf("\nCategory options:\n");
    printf("diff     - Differently abled\n");
    printf("senior   - Senior citizen\n");
    printf("defence  - Defence personnel\n");
    printf("ordinary - Ordinary person\n");

    for (i = 0; i < n; i++)
    {
        printf("\nEnter customer %d name: ", i + 1);
        scanf("%s", name);

        printf("Enter category: ");
        scanf("%s", cat);

        enque(name, cat);
    }

    display();

    printf("\nSequence of completion:\n");

    while (front != NULL)
    {
        deque();
    }

    return 0;
}


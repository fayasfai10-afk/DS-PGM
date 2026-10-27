#include <stdio.h>

#define MAX 5

int que[MAX];
int front = -1, rear = -1;


void insertfront(int x)
{
    if ((front == 0 && rear == MAX - 1) ||
        (front == rear + 1))
    {
        printf("Deque is full\n");
        return;
    }

    if (front == -1)
    {
        front = rear = 0;
    }
    else if (front == 0)
    {
        front = MAX - 1;
    }
    else
    {
        front--;
    }

    que[front] = x;
}


void insertrear(int x)	
{
    if ((front == 0 && rear == MAX - 1) ||
        (front == rear + 1))
    {
        printf("Deque is full\n");
        return;
    }

    if (front == -1)
    {
        front = rear = 0;
    }
    else if (rear == MAX - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }

    que[rear] = x;
}

// Delete from Front
void deletefront()
{
    if (front == -1)
    {
        printf("Deque is empty\n");
        return;
    }

    printf("Deleted %d\n", que[front]);

    if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == MAX - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}

// Delete from Rear
void deleterear()
{
    if (front == -1)
    {
        printf("Deque is empty\n");
        return;
    }

    printf("Deleted %d\n", que[rear]);

    if (front == rear)
    {
        front = rear = -1;
    }
    else if (rear == 0)
    {
        rear = MAX - 1;
    }
    else
    {
        rear--;
    }
}

// Display
void display()
{
    int i;

    if (front == -1)
    {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque: ");

    i = front;

    while (1)
    {
        printf("%d ", que[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

// Main
int main()
{
    int choice, x;

    while (1)
    {
        printf("\n--- CIRCULAR DOUBLE ENDED QUEUE ---\n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                insertfront(x);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &x);
                insertrear(x);
                break;

            case 3:
                deletefront();
                break;

            case 4:
                deleterear();
                break;

            case 5:
                display();
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

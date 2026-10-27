#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *top=NULL;

void push(){
	int item;
	struct node *newnode;
	
	newnode =(struct node*)malloc(sizeof(struct node));
	
	printf("enter the element:");
	scanf("%d",&item);
	
	newnode->data=item;
	newnode->next=top;
	top=newnode;
	
	printf("element pushed \n");
}	
void pop()
{
	struct node *temp;
	
	if(top==NULL)
	{
		printf("stack overflow");
	}else
	{
		temp=top;
		printf("popped element: %d\n",top->data);
		top=top->next;
		free(temp);
		}
	}


void display()
{
    struct node *temp;

    if (top == NULL)
    {
        printf("stack is empty\n");
    }else
    {

    temp = top;

    printf("stack element are:\n ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
	}
	}
	
int main()
{
    int choice;

    while (1)
    {
        printf("\n--- stack menu ---\n");
        printf("1. push\n");
        printf("2. pop\n");
        printf("3. display\n");
        printf("4. exit\n");
 

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
	
	

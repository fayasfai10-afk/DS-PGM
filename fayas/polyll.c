#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff, exp;
    struct node *next;
};

struct node *create(int c, int e) {
    struct node *new = malloc(sizeof(struct node));
    new->coeff = c;
    new->exp = e;
    new->next = NULL;
    return new;	
}

struct node *insert(struct node *head, int c, int e) {
    struct node *new = create(c, e);

    if (head == NULL)
        return new;

    struct node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = new;
    return head;
}

struct node *add(struct node *p1, struct node *p2) {
    struct node *result = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->exp == p2->exp) {
            result = insert(result, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->exp > p2->exp) {
            result = insert(result, p1->coeff, p1->exp);
            p1 = p1->next;
        }
        else {
            result = insert(result, p2->coeff, p2->exp);
            p2 = p2->next;
        }
    }
	
    while (p1 != NULL) {
        result = insert(result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        result = insert(result, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}

void display(struct node *p) {
    while (p != NULL) {
        printf("%dx^%d", p->coeff, p->exp);

        if (p->next != NULL)
            printf(" + ");

        p = p->next;
    }
    printf("\n");
}

int main() {
    struct node *p1 = NULL, *p2 = NULL, *sum = NULL;
    int n, c, e, i;

    printf("Enter number of terms in polynomial 1: ");
    scanf("%d", &n);

    printf("Enter coefficient and exponent:\n");
    for (i = 0; i < n; i++) {
        scanf("%d%d", &c, &e);
        p1 = insert(p1, c, e);
    }

    printf("Enter number of terms in polynomial 2: ");
    scanf("%d", &n);

    printf("Enter coefficient and exponent:\n");
    for (i = 0; i < n; i++) {
        scanf("%d%d", &c, &e);
        p2 = insert(p2, c, e);
    }

    printf("\nPolynomial 1: ");
    display(p1);

    printf("Polynomial 2: ");
    display(p2);

    sum = add(p1, p2);

    printf("Sum: ");
    display(sum);

    return 0;
}


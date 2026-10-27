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

/* Insert a term and combine terms having the same exponent */
struct node *insertTerm(struct node *head, int c, int e) {
    struct node *temp;

    if (c == 0)
        return head;

    if (head == NULL)
        return create(c, e);

    temp = head;

    while (temp != NULL) {
        if (temp->exp == e) {
            temp->coeff += c;
            return head;
        }

        temp = temp->next;
    }

    return insert(head, c, e);
}

/* Multiply two polynomials */
struct node *multiply(struct node *p1, struct node *p2) {
    struct node *result = NULL;
    struct node *temp1, *temp2;

    temp1 = p1;

    while (temp1 != NULL) {
        temp2 = p2;

        while (temp2 != NULL) {
            int coeff = temp1->coeff * temp2->coeff;
            int exp = temp1->exp + temp2->exp;

            result = insertTerm(result, coeff, exp);

            temp2 = temp2->next;
        }

        temp1 = temp1->next;
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
    struct node *p1 = NULL;
    struct node *p2 = NULL;
    struct node *product = NULL;

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

    product = multiply(p1, p2);

    printf("Product: ");
    display(product);

    return 0;
}



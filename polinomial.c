#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure for polynomial node
struct Node {
    int coeff;
    int pow;
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(int coeff, int pow) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}

// Function to insert node at end
struct Node* insertEnd(struct Node* head, int coeff, int pow) {
    struct Node* newNode = createNode(coeff, pow);
    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

// Function to display polynomial
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->pow);
        if (temp->next != NULL)
            printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}

// Function to evaluate polynomial
double evaluate(struct Node* head, double x) {
    double result = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        result += temp->coeff * pow(x, temp->pow);
        temp = temp->next;
    }
    return result;
}

// Main function
int main() {
    struct Node* poly = NULL;
    int degree, coeff, i;
    double x, result;

    printf("Enter the degree of the polynomial: ");
    scanf("%d", &degree);

    for (i = degree; i >= 0; i--) {
        printf("Enter the coefficient for x^%d: ", i);
        scanf("%d", &coeff);
        poly = insertEnd(poly, coeff, i);
    }

    printf("\nPolynomial entered: ");
    display(poly);

    printf("\nEnter the value of x: ");
    scanf("%lf", &x);

    result = evaluate(poly, x);
    printf("\nResult of polynomial evaluation: %.2lf\n", result);

    return 0;
}
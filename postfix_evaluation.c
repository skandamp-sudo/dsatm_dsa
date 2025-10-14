#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define MAX 100

struct Stack {
    int arr[MAX];
    int top;
};

void init(struct Stack *s) {
    s->top = -1;
}

int isEmpty(struct Stack *s) {
    return (s->top == -1);
}

void push(struct Stack *s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++s->top] = value;
}

int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->arr[s->top--];
}

int evaluatePostfix(char *exp) {
    struct Stack s;
    init(&s);
    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];
        if (isdigit(ch)) {
            push(&s, ch - '0');
        } else {
            int op2 = pop(&s);
            int op1 = pop(&s);
            int result;
            switch (ch) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '%': result = op1 % op2; break;
                case '^': result = pow(op1, op2); break;
                default: printf("Invalid Operator\n"); exit(1);
            }
            push(&s, result);
        }
    }
    return pop(&s);
}

int main() {
    char exp[MAX];
    printf("Enter a Postfix Expression: ");
    scanf("%s", exp);
    int result = evaluatePostfix(exp);
    printf("Result of Postfix Evaluation: %d\n", result);
    return 0;
}

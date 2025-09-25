//Stack program(Static memory Allocation using Array)

#include <stdio.h>
#define MAX 5

int stack[MAX], top = -1;

void push(int x) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
    } else {
        stack[++top] = x;
        printf("%d pushed to stack\n", x);
    }
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return -1;
    } else {
        return stack[top--];
    }
}

int peek() {
    if (top == -1) {
        printf("Stack is Empty!\n");
        return -1;
    } else {
        return stack[top];
    }
}

int main() {
    push(10);
    push(20);
    push(30);

    printf("Top element: %d\n", peek());
    printf("Popped: %d\n", pop());
    printf("Popped: %d\n", pop());
    printf("Popped: %d\n", pop());
    printf("Popped: %d\n", pop()); // underflow

    return 0;
}

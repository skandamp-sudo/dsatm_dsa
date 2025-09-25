//Dynamic Memory Allocation for Stack in C


#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int *arr;
    int top;
    int capacity;
};

void initStack(struct Stack *s, int capacity) {
    s->capacity = capacity;
    s->top = -1;
    s->arr = (int*) malloc(capacity * sizeof(int));
    if (!s->arr) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
}

void push(struct Stack *s, int value) {
    if (s->top == s->capacity - 1) {
        s->capacity *= 2;
        int *newArr = (int*) realloc(s->arr, s->capacity * sizeof(int));
        if (!newArr) {
            printf("Memory reallocation failed!\n");
            free(s->arr);
            exit(1);
        }
        s->arr = newArr;
        printf("Stack resized to %d\n", s->capacity);
    }
    s->arr[++(s->top)] = value;
    printf("%d pushed\n", value);
}

int pop(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return s->arr[(s->top)--];
}

int peek(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack is Empty!\n");
        return -1;
    }
    return s->arr[s->top];
}

int main() {
    struct Stack s;
    initStack(&s, 2); // initial capacity

    push(&s, 10);
    push(&s, 20);
    push(&s, 30); // triggers resize

    printf("Top element: %d\n", peek(&s));

    printf("Popped: %d\n", pop(&s));
    printf("Popped: %d\n", pop(&s));
    printf("Popped: %d\n", pop(&s));
    printf("Popped: %d\n", pop(&s)); // underflow

    free(s.arr);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct CQueue {
    int *arr;
    int front, rear, capacity;
};

void initQueue(struct CQueue *q, int capacity) {
    q->capacity = capacity;
    q->front = q->rear = -1;
    q->arr = (int*) malloc(capacity * sizeof(int));
}

int isEmpty(struct CQueue *q) {
    return (q->front == -1);
}

int isFull(struct CQueue *q) {
    return ((q->rear + 1) % q->capacity == q->front);
}

void resize(struct CQueue *q) {
    int newCap = q->capacity * 2;
    int *newArr = (int*) malloc(newCap * sizeof(int));

    int i = q->front, j = 0;
    do {
        newArr[j++] = q->arr[i];
        i = (i + 1) % q->capacity;
    } while (i != (q->rear + 1) % q->capacity);

    free(q->arr);
    q->arr = newArr;
    q->capacity = newCap;
    q->front = 0;
    q->rear = j - 1;
    printf("Queue resized to %d\n", newCap);
}

void enqueue(struct CQueue *q, int value) {
    if(isFull(q)) resize(q);

    if(isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % q->capacity;
    }
    q->arr[q->rear] = value;
    printf("%d enqueued\n", value);
}

int dequeue(struct CQueue *q) {
    if(isEmpty(q)) {
        printf("Queue Underflow!\n");
        return -1;
    }

    int val = q->arr[q->front];
    if(q->front == q->rear) {
        q->front = q->rear = -1; // queue becomes empty
    } else {
        q->front = (q->front + 1) % q->capacity;
    }
    return val;
}

int peek(struct CQueue *q) {
    if(isEmpty(q)) {
        printf("Queue is Empty!\n");
        return -1;
    }
    return q->arr[q->front];
}

int main() {
    struct CQueue q;
    initQueue(&q, 3);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40); // triggers resize

    printf("Front element: %d\n", peek(&q));

    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));

    enqueue(&q, 50);
    enqueue(&q, 60);

    printf("Front element: %d\n", peek(&q));

    return 0;
}

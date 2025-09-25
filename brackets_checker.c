//Balanced Parantheses Checker using Stack in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Define stack structure
#define MAX 100
struct Stack {
char arr[MAX];
int top;
};
// Initialize stack
void init(struct Stack* s) {
s->top = -1;
}
// Check if stack is empty
int isEmpty(struct Stack* s) {
return (s->top == -1);
}
// Push element onto stack
void push(struct Stack* s, char ch) {
if (s->top == MAX - 1) {
printf("Stack Overflow\n");
return;
}
s->arr[++s->top] = ch;
}
// Pop element from stack
char pop(struct Stack* s) {
if (isEmpty(s)) {
return '\0'; // Empty stack
}
return s->arr[s->top--];
}
// Function to check matching brackets
int isMatchingPair(char open, char close) {
return ((open == '(' && close == ')') ||
(open == '{' && close == '}') ||
(open == '[' && close == ']'));
}
// Function to check balanced parentheses

int isBalanced(char* exp) {
struct Stack s;
init(&s);
for (int i = 0; exp[i] != '\0'; i++) {
char ch = exp[i];
// If opening bracket, push
if (ch == '(' || ch == '{' || ch == '[') {
push(&s, ch);
}
// If closing bracket, check stack
else if (ch == ')' || ch == '}' || ch == ']') {
if (isEmpty(&s)) {
return 0; // Unbalanced
}
char top = pop(&s);
if (!isMatchingPair(top, ch)) {
return 0; // Not matching
}
}
}
// If stack empty, expression balanced
return isEmpty(&s);
}
// Main function
int main() {
char exp[100];
printf("Enter a mathematical expression: ");
scanf("%s", exp);
if (isBalanced(exp)) {
printf("The expression is Balanced.\n");
} else {
printf("The expression is NOT Balanced.\n");
}
return 0;
}
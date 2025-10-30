#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a student node
struct Student {
    char name[50];
    char usn[20];
    int sem;
    float cgpa;
    struct Student *prev, *next;
};

struct Student *head = NULL;

// Function to create a new student node
struct Student* createNode() {
    struct Student *newNode = (struct Student*)malloc(sizeof(struct Student));
    printf("Enter Name: ");
    scanf("%s", newNode->name);
    printf("Enter USN: ");
    scanf("%s", newNode->usn);
    printf("Enter Semester: ");
    scanf("%d", &newNode->sem);
    printf("Enter CGPA: ");
    scanf("%f", &newNode->cgpa);
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Insert at front
void insertFront() {
    struct Student *newNode = createNode();
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("\nStudent inserted at front successfully.\n");
}

// Insert at end
void insertEnd() {
    struct Student *newNode = createNode();
    if (head == NULL) {
        head = newNode;
    } else {
        struct Student *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("\nStudent inserted at end successfully.\n");
}

// Delete from front
void deleteFront() {
    if (head == NULL) {
        printf("\nList is empty. Nothing to delete.\n");
        return;
    }
    struct Student *temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    printf("\nDeleted student: %s (%s)\n", temp->name, temp->usn);
    free(temp);
}

// Delete from end
void deleteEnd() {
    if (head == NULL) {
        printf("\nList is empty. Nothing to delete.\n");
        return;
    }
    struct Student *temp = head;
    if (temp->next == NULL) {
        printf("\nDeleted student: %s (%s)\n", temp->name, temp->usn);
        free(temp);
        head = NULL;
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    printf("\nDeleted student: %s (%s)\n", temp->name, temp->usn);
    temp->prev->next = NULL;
    free(temp);
}

// Display all students
void display() {
    if (head == NULL) {
        printf("\nList is empty.\n");
        return;
    }
    struct Student *temp = head;
    printf("\n--- Student Details ---\n");
    while (temp != NULL) {
        printf("Name: %s | USN: %s | Sem: %d | CGPA: %.2f\n",
               temp->name, temp->usn, temp->sem, temp->cgpa);
        temp = temp->next;
    }
    printf("------------------------\n");
}

// Main menu
int main() {
    int choice;
    while (1) {
        printf("\n===== DOUBLY LINKED LIST MENU =====\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from End\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertFront(); display(); break;
            case 2: insertEnd(); display(); break;
            case 3: deleteFront(); display(); break;
            case 4: deleteEnd(); display(); break;
            case 5: display(); break;
            case 6: printf("Exiting...\n"); exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
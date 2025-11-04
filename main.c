#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertAtBeginning(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}


void displayList(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    printf("Linked list: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void deleteNode(Node** head, int value) {
    Node* temp = *head;
    Node* prev = NULL;

    if (temp != NULL && temp->data == value) {
        *head = temp->next;
        free(temp);
        printf("Deleted %d from the list.\n", value);
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }


    if (temp == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Deleted %d from the list.\n", value);
}
int main() {
    Node* head = NULL;
    insertAtEnd(&head, 10);
    insertAtBeginning(&head, 5);
    insertAtEnd(&head, 15);
    insertAtEnd(&head, 20);
    displayList(head);
    deleteNode(&head, 15);
    displayList(head);
    deleteNode(&head, 100);
    return 0;
}

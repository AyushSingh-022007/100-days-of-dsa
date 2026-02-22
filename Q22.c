//Problem: Count Nodes in Linked List
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

/* Create new node */
struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

/* Insert at end */
struct node* insertEnd(struct node* head, int value) {
    struct node* newNode = createNode(value);

    if (head == NULL)
        return newNode;

    struct node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

/* Traverse and print list */
void display(struct node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

/* Count nodes */
int countNodes(struct node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

int main() {
    int n, value;
    struct node* head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    // Print list
    display(head);

    // Print count
    printf("%d\n", countNodes(head));

    return 0;
}
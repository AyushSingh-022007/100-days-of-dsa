#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Rotate function
struct Node* rotateRight(struct Node* head, int k) {
    
    if (head == NULL || k == 0)
        return head;

    struct Node* temp = head;
    int length = 1;

    // Count length
    while (temp->next != NULL) {
        temp = temp->next;
        length++;
    }

    k = k % length;
    if (k == 0)
        return head;

    // Make circular
    temp->next = head;

    // Move to (length - k - 1) node
    int steps = length - k;
    struct Node* newTail = head;

    for (int i = 1; i < steps; i++)
        newTail = newTail->next;

    struct Node* newHead = newTail->next;

    // Break circle
    newTail->next = NULL;

    return newHead;
}

int main() {
    int n, value, k;
    struct Node *head = NULL, *temp = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        struct Node* newNode = createNode(value);

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    scanf("%d", &k);

    head = rotateRight(head, k);

    // Print rotated list
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
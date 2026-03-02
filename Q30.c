#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Function to create new node
struct Node* createNode(int c, int e) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, c, e;
    scanf("%d", &n);

    struct Node *head = NULL, *tail = NULL;

    for(int i = 0; i < n; i++) {
        scanf("%d %d", &c, &e);
        struct Node* newNode = createNode(c, e);

        if(head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    struct Node* temp = head;

    while(temp != NULL) {
        if(temp->exp > 1)
            printf("%dx^%d", temp->coeff, temp->exp);
        else if(temp->exp == 1)
            printf("%dx", temp->coeff);
        else
            printf("%d", temp->coeff);

        if(temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }

    return 0;
}
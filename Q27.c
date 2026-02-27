#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to get length
int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Function to find intersection
int findIntersection(struct Node* head1, struct Node* head2) {
    
    int len1 = getLength(head1);
    int len2 = getLength(head2);
    
    int diff = abs(len1 - len2);
    
    struct Node *ptr1 = head1;
    struct Node *ptr2 = head2;
    
    // Move pointer of longer list
    if (len1 > len2) {
        for (int i = 0; i < diff; i++)
            ptr1 = ptr1->next;
    } else {
        for (int i = 0; i < diff; i++)
            ptr2 = ptr2->next;
    }
    
    // Traverse together
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1 == ptr2)
            return ptr1->data;
        
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    
    return -1;  // No intersection
}

int main() {
    int n, m, i, value;
    
    struct Node *head1 = NULL, *head2 = NULL;
    struct Node *temp = NULL, *tail1 = NULL, *tail2 = NULL;
    
    // Input first list
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        temp = createNode(value);
        if (head1 == NULL)
            head1 = tail1 = temp;
        else {
            tail1->next = temp;
            tail1 = temp;
        }
    }
    
    // Input second list
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        scanf("%d", &value);
        temp = createNode(value);
        if (head2 == NULL)
            head2 = tail2 = temp;
        else {
            tail2->next = temp;
            tail2 = temp;
        }
    }
    
    int result = findIntersection(head1, head2);
    
    if (result == -1)
        printf("No Intersection");
    else
        printf("%d", result);
    
    return 0;
}
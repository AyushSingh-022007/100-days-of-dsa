//Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h> Q
struct node {
    int data;
    struct node *next;
};
struct node* createNode(int x) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}
struct node* insertEnd(struct node* head, int x) {
    struct node* newNode = createNode(x);
    if (head == NULL)
        return newNode;
    struct node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    return head;
}
struct node* mergeLists(struct node* l1, struct node* l2) {
    struct node* result = NULL;
    struct node* temp = NULL;
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    if (l1->data <= l2->data) {
        result = l1;
        l1 = l1->next;
    } else {
        result = l2;
        l2 = l2->next;
    }
    temp = result;
    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            temp->next = l1;
            l1 = l1->next;
        } else {
            temp->next = l2;
            l2 = l2->next;
        }
        temp = temp->next;
    }
    if (l1 != NULL)
        temp->next = l1;
    else
        temp->next = l2;

    return result;
}
void display(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
int main() {
    struct node *list1 = NULL, *list2 = NULL, *merged = NULL;
    int n1, n2, val;
    printf("Enter number of elements in List 1: ");
    scanf("%d", &n1);
    printf("Enter sorted elements:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &val);
        list1 = insertEnd(list1, val);
    }
    printf("Enter number of elements in List 2: ");
    scanf("%d", &n2);
    printf("Enter sorted elements:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &val);
        list2 = insertEnd(list2, val);
    }
    merged = mergeLists(list1, list2);
    printf("Merged Sorted List:\n");
    display(merged);
    return 0;
}
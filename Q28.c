#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
int main() {
    int n, i;
    struct node *head = NULL, *temp = NULL, *newnode = NULL;
    scanf("%d", &n);
    if (n <= 0)
        return 0;
    head = (struct node*)malloc(sizeof(struct node));
    scanf("%d", &head->data);
    head->next = head;  
    temp = head;
    for (i = 2; i <= n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = head;
        temp->next = newnode;
        temp = newnode;
    }
    temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    return 0;
}
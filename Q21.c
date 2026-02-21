// Problem: Create and Traverse Singly Linked List
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int main()
{
    int n, value;
    struct node *head = NULL, *temp = NULL, *newnode = NULL;
    scanf("%d", &n);
    if (n <= 0)
        return 0;
    scanf("%d", &value);
    head = (struct node *)malloc(sizeof(struct node));
    head->data = value;
    head->next = NULL;
    temp = head;
    for (int i = 1; i < n; i++)
    {
        scanf("%d", &value);
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = value;
        newnode->next = NULL;
        temp->next = newnode;
        temp = newnode;
    }
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return 0;
}
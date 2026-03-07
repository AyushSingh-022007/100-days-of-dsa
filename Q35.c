#include <stdio.h>
#define MAX 100
int queue[MAX];
int front = 0;
int rear = -1;
void enqueue(int x)
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }
    rear++;
    queue[rear] = x;
}
void display()
{
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
}
int main()
{
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        enqueue(x);
    }
    display();
    return 0;
}
#include <stdio.h>

int main()
{
    int n, m;
    
    scanf("%d", &n);
    
    int q[n];
    
    for(int i = 0; i < n; i++)
        scanf("%d", &q[i]);
    
    int front = 0;
    int rear = n - 1;
    
    scanf("%d", &m);
    
    for(int i = 0; i < m; i++)
        front = (front + 1) % n;
    
    int i = front;
    
    while(1)
    {
        printf("%d ", q[i]);
        
        if(i == rear)
            break;
        
        i = (i + 1) % n;
    }

    return 0;
}
#include <stdio.h>
#define MAX 100

int dq[MAX];
int front = -1, rear = -1;

int empty() {
    return front == -1;
}

int size() {
    if (empty()) return 0;
    return rear - front + 1;
}

void push_front(int x) {
    if (front == -1) {
        front = rear = 0;
    } else if (front == 0) {
        printf("Overflow\n");
        return;
    } else {
        front--;
    }
    dq[front] = x;
}

void push_back(int x) {
    if (rear == MAX - 1) {
        printf("Overflow\n");
        return;
    }
    if (front == -1)
        front = rear = 0;
    else
        rear++;

    dq[rear] = x;
}

void pop_front() {
    if (empty()) {
        printf("-1\n");
        return;
    }

    printf("%d\n", dq[front]);

    if (front == rear)
        front = rear = -1;
    else
        front++;
}

void pop_back() {
    if (empty()) {
        printf("-1\n");
        return;
    }

    printf("%d\n", dq[rear]);

    if (front == rear)
        front = rear = -1;
    else
        rear--;
}

int get_front() {
    if (empty()) return -1;
    return dq[front];
}

int get_back() {
    if (empty()) return -1;
    return dq[rear];
}

void clear() {
    front = rear = -1;
}

void reverse() {
    if (empty()) return;

    int i = front, j = rear;
    while (i < j) {
        int t = dq[i];
        dq[i] = dq[j];
        dq[j] = t;
        i++;
        j--;
    }
}

void sort() {
    for (int i = front; i <= rear; i++) {
        for (int j = i + 1; j <= rear; j++) {
            if (dq[i] > dq[j]) {
                int t = dq[i];
                dq[i] = dq[j];
                dq[j] = t;
            }
        }
    }
}

void display() {
    if (empty()) {
        printf("Empty\n");
        return;
    }

    for (int i = front; i <= rear; i++)
        printf("%d ", dq[i]);

    printf("\n");
}

int main() {
    int choice, x;

    while (1) {
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            scanf("%d", &x);
            push_front(x);
            break;

        case 2:
            scanf("%d", &x);
            push_back(x);
            break;

        case 3:
            pop_front();
            break;

        case 4:
            pop_back();
            break;

        case 5:
            printf("%d\n", get_front());
            break;

        case 6:
            printf("%d\n", get_back());
            break;

        case 7:
            printf("%d\n", empty());
            break;

        case 8:
            printf("%d\n", size());
            break;

        case 9:
            clear();
            break;

        case 10:
            reverse();
            break;

        case 11:
            sort();
            break;

        case 12:
            display();
            break;

        case 0:
            return 0;
        }
    }
}
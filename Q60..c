#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Build tree from level order array
struct Node* buildTree(int arr[], int n, int i) {
    if (i >= n) return NULL;

    struct Node* root = newNode(arr[i]);
    root->left = buildTree(arr, n, 2*i + 1);
    root->right = buildTree(arr, n, 2*i + 2);

    return root;
}

// Check complete binary tree
int isComplete(struct Node* root) {
    if (!root) return 1;

    struct Node* queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int flag = 0;

    while (front < rear) {
        struct Node* curr = queue[front++];

        if (curr == NULL) {
            flag = 1;
        } else {
            if (flag) return 0;
            queue[rear++] = curr->left;
            queue[rear++] = curr->right;
        }
    }
    return 1;
}

// Check heap property
int isMinHeap(struct Node* root) {
    if (!root) return 1;

    if (root->left && root->data > root->left->data)
        return 0;

    if (root->right && root->data > root->right->data)
        return 0;

    return isMinHeap(root->left) && isMinHeap(root->right);
}

// Main check
int checkMinHeap(struct Node* root) {
    return isComplete(root) && isMinHeap(root);
}

// MAIN FUNCTION (IMPORTANT)
int main() {
    int n;
    scanf("%d", &n);

    int arr[1000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n, 0);

    if (checkMinHeap(root))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// create new node
Node* newNode(int val) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

// build tree from level order array
Node* buildTree(int arr[], int n, int i) {
    if(i >= n || arr[i] == -1)
        return NULL;

    Node* root = newNode(arr[i]);

    root->left = buildTree(arr, n, 2*i + 1);
    root->right = buildTree(arr, n, 2*i + 2);

    return root;
}

// inorder traversal
void inorder(Node* root) {
    if(root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    Node* root = buildTree(arr, n, 0);

    inorder(root);

    return 0;
}
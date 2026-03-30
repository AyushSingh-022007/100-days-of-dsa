#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

int preIndex = 0;

// Create new node
struct Node* createNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Find index in inorder
int findIndex(int inorder[], int start, int end, int value) {
    for(int i = start; i <= end; i++) {
        if(inorder[i] == value)
            return i;
    }
    return -1;
}

// Build tree
struct Node* buildTree(int preorder[], int inorder[], int start, int end) {
    if(start > end)
        return NULL;

    int rootVal = preorder[preIndex++];
    struct Node* root = createNode(rootVal);

    if(start == end)
        return root;

    int index = findIndex(inorder, start, end, rootVal);

    root->left = buildTree(preorder, inorder, start, index - 1);
    root->right = buildTree(preorder, inorder, index + 1, end);

    return root;
}

// Postorder traversal
void postorder(struct Node* root) {
    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->val);
}

int main() {
    int n;
    scanf("%d", &n);

    int preorder[n], inorder[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    for(int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    preIndex = 0;
    struct Node* root = buildTree(preorder, inorder, 0, n - 1);

    postorder(root);

    return 0;
}
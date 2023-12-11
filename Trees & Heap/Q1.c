/*
WAP to implement BST given a binary tree and preserving the
structure of the given binary tree.
*/
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int key;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node with the given key
struct TreeNode* createNode(int key) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

// Inorder traversal of the binary tree, storing nodes in an array if provided
void inorderTraversal(struct TreeNode* node, struct TreeNode** nodes, int* index) {
    if (node) {
        // Traverse left subtree
        inorderTraversal(node->left, nodes, index);
        
        // Store the node in the array if nodes array is provided
        if (nodes) {
            nodes[*index] = node;
        }
        (*index)++;
        
        // Traverse right subtree
        inorderTraversal(node->right, nodes, index);
    }
}

// Comparison function for qsort to compare two TreeNode pointers based on keys
int compareNodes(const void* a, const void* b) {
    struct TreeNode* node1 = *(struct TreeNode**)a;
    struct TreeNode* node2 = *(struct TreeNode**)b;

    return node1->key - node2->key;
}

// Construct a balanced BST from an array of nodes using binary search
struct TreeNode* constructBST(struct TreeNode** nodes, int start, int end) {
    if (start > end) {
        return NULL;
    }

    int mid = (start + end) / 2;
    struct TreeNode* node = nodes[mid];
    
    // Recursively construct left and right subtrees
    node->left = constructBST(nodes, start, mid - 1);
    node->right = constructBST(nodes, mid + 1, end);

    return node;
}

// Inorder traversal of a binary tree
void inorder(struct TreeNode* node) {
    if (node) {
        inorder(node->left);
        printf("%d ", node->key);
        inorder(node->right);
    }
}



int main() {
    // Sample binary tree
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->key = 10;
    root->left = createNode(30);
    root->right = createNode(15);
    root->left->left = createNode(20);
    root->right->right = createNode(5);

    printf("Original binary tree:\n");
    inorder(root);
    printf("\n");

    // Convert the original binary tree to a BST
    int index = 0;
    inorderTraversal(root, NULL, &index);
    struct TreeNode** nodes = (struct TreeNode**)malloc(index * sizeof(struct TreeNode*));
    index = 0;
    inorderTraversal(root, nodes, &index);
    qsort(nodes, index, sizeof(struct TreeNode*), compareNodes);
    struct TreeNode* bst_root = constructBST(nodes, 0, index - 1);

    printf("Converted BST:\n");
    inorder(bst_root);
    printf("\n");


    return 0;
}

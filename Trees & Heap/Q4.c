/**
WAP to verify whether a given binary search tree is also an AVL tree.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition of a Binary Search Tree (BST) node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new BST node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node in the BST
struct TreeNode* insertNode(struct TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// Function to calculate the height of a tree
int height(struct TreeNode* node) {
    if (node == NULL) {
        return -1;
    }
    int left_height = height(node->left);
    int right_height = height(node->right);
    return (left_height > right_height) ? left_height + 1 : right_height + 1;
}

// Function to check if a given tree is an AVL tree
bool isAVLTree(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    }

    int left_height = height(root->left);
    int right_height = height(root->right);

    // Check if the balance factor of the current node is within [-1, 1]
    if (abs(left_height - right_height) > 1) {
        return false;
    }

    // Recursively check left and right subtrees
    return isAVLTree(root->left) && isAVLTree(root->right);
}

int main() {
    struct TreeNode* root = NULL;
    int numNodes, data;
    
    printf("Enter the number of nodes in the BST: ");
    scanf("%d", &numNodes);

    printf("Enter the values of the nodes:\n");
    for (int i = 0; i < numNodes; ++i) {
        scanf("%d", &data);
        root = insertNode(root, data);
    }

    if (isAVLTree(root)) {
        printf("The given BST is also an AVL tree.\n");
    } else {
        printf("The given BST is not an AVL tree.\n");
    }

    return 0;
}

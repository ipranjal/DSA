/**
WAP to find the third largest element in the BST. (BST must be a user
input in inorder traversal).
*/

#include <stdio.h>
#include <stdlib.h>

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

// Function to find the third largest element in the BST
int findThirdLargest(struct TreeNode* root) {
    int count = 0;
    struct TreeNode* current = root;
    struct TreeNode* thirdLargest = NULL;

    while (current != NULL) {
        if (current->right == NULL) {
            // Increment the count when moving to the left
            if (++count == 3) {
                thirdLargest = current;
            }
            current = current->left;
        } else {
            struct TreeNode* successor = current->right;
            // Find the leftmost node in the right subtree
            while (successor->left != NULL && successor->left != current) {
                successor = successor->left;
            }

            if (successor->left == NULL) {
                // Make the current node as the predecessor of its right subtree
                successor->left = current;
                current = current->right;
            } else {
                // Restore the tree structure and count the nodes
                successor->left = NULL;
                if (++count == 3) {
                    thirdLargest = current;
                }
                current = current->left;
            }
        }
    }

    return (thirdLargest != NULL) ? thirdLargest->data : -1;
}

int main() {
    struct TreeNode* root = NULL;
    int numNodes, data;
    
    printf("Enter the number of nodes in the BST: ");
    scanf("%d", &numNodes);

    printf("Enter the inorder traversal of the BST:\n");
    for (int i = 0; i < numNodes; ++i) {
        scanf("%d", &data);
        root = insertNode(root, data);
    }

    int result = findThirdLargest(root);

    if (result != -1) {
        printf("The third largest element in the BST is: %d\n", result);
    } else {
        printf("The BST does not have a third largest element.\n");
    }



    return 0;
}

// Author - Pranjal Pandey

/* 
   This program demonstrates the implementation of an AVL tree with insert, delete, and traversal operations.
   AVL trees are self-balancing binary search trees that ensure the height difference between left and right subtrees is at most one.
*/
#include <stdio.h>
#include <stdlib.h>

// Define the AVL Node structure.
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    int height;
};

// Function to calculate the height of a node.
int height(struct Node *node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Function to find the maximum of two integers.
int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

// Function to create a new AVL node.
struct Node *newNode(int data) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // New node is initially added at leaf.
    return node;
}

// Function to perform a right rotation.
struct Node *rightRotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *subtreeRoot = x->right; // Subtree root (T2)

    // Perform rotation.
    x->right = y;
    y->left = subtreeRoot;

    // Update heights.
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Function to perform a left rotation.
struct Node *leftRotate(struct Node *x) {
    struct Node *y = x->right;
    struct Node *subtreeRoot = y->left; // Subtree root (T2)

    // Perform rotation.
    y->left = x;
    x->right = subtreeRoot;

    // Update heights.
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Function to get the balance factor of a node.
int getBalance(struct Node *node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// Function to insert a node into an AVL tree.
struct Node *insert(struct Node *root, int data) {
    // Perform the normal BST insertion.
    if (root == NULL)
        return newNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    else // Equal keys are not allowed in BST.
        return root;

    // Update the height of the current node.
    root->height = 1 + max(height(root->left), height(root->right));

    // Get the balance factor and perform rotations if needed.
    int balance = getBalance(root);

    // Left Heavy
    if (balance > 1) {
        if (data < root->left->data) // Left-Left Case
            return rightRotate(root);
        else { // Left-Right Case
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }

    // Right Heavy
    if (balance < -1) {
        if (data > root->right->data) // Right-Right Case
            return leftRotate(root);
        else { // Right-Left Case
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }

    return root;
}

// Function to find the node with the minimum value in a tree.
struct Node *minValueNode(struct Node *node) {
    struct Node *current = node;

    // Loop down to find the leftmost leaf.
    while (current->left != NULL)
        current = current->left;

    return current;
}

// Function to delete a node from an AVL tree.
struct Node *deleteNode(struct Node *root, int data) {
    // Perform the normal BST deletion.
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        // Node with only one child or no child.
        if ((root->left == NULL) || (root->right == NULL)) {
            struct Node *temp = root->left ? root->left : root->right;

            // No child case.
            if (temp == NULL) {
                temp = root;
                root = NULL;
            }
            else // One child case.
                *root = *temp;

            free(temp);
        }
        else {
            // Node with two children. Get the inorder successor.
            struct Node *temp = minValueNode(root->right);

            // Copy the inorder successor's data to this node.
            root->data = temp->data;

            // Delete the inorder successor.
            root->right = deleteNode(root->right, temp->data);
        }
    }

    // If the tree had only one node, then return.
    if (root == NULL)
        return root;

    // Update the height of the current node.
    root->height = 1 + max(height(root->left), height(root->right));

    // Get the balance factor and perform rotations if needed.
    int balance = getBalance(root);

    // Left Heavy
    if (balance > 1) {
        if (getBalance(root->left) >= 0) // Left-Left Case
            return rightRotate(root);
        else { // Left-Right Case
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }

    // Right Heavy
    if (balance < -1) {
        if (getBalance(root->right) <= 0) // Right-Right Case
            return leftRotate(root);
        else { // Right-Left Case
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }

    return root;
}

// Function to perform an in-order traversal of the AVL tree.
void inorder(struct Node *root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Function to perform a pre-order traversal of the AVL tree.
void preorder(struct Node *root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Function to perform a post-order traversal of the AVL tree.
void postorder(struct Node *root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    struct Node *root = NULL;
    int choice, data;

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Inorder Traversal\n4. Preorder Traversal\n5. Postorder Traversal\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Enter the value to be deleted: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 5:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}

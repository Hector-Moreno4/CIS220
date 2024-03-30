#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define COUNT 10

//Hector Moreno
//Chapter 7 PA

struct Node {
	int key;
    struct Node* left;
    struct Node* right;
};

struct BinarySearchTree {
	struct Node* root;
};

void initBST(struct BinarySearchTree* bst) {
    bst->root = NULL;
}

struct Node* getRoot(struct BinarySearchTree* bst) {
    return bst->root;
}

struct Node* search(struct BinarySearchTree* bst, int desiredKey) {
	printf("\nSearching for node %d", desiredKey);
    struct Node* currentNode = bst->root;
	printf("\nStarting at root node %d", currentNode->key);
    while (currentNode != NULL) {
        if (currentNode->key == desiredKey) {
            return currentNode;
        } else if (desiredKey < currentNode->key) {
			printf("\nDid not find node, navigating to node %d's left child", currentNode->key); 
            currentNode = currentNode->left;
        } else {
			printf("\nDid not find node, navigating to node %d's right child", currentNode->key); 
            currentNode = currentNode->right;
        }
    }
    return NULL;
}

void insert(struct BinarySearchTree* bst, struct Node* node) {
	printf("\nInserting node %d", node->key);
    if (bst->root == NULL) {
        bst->root = node;
		printf("\nInserted node %d as the root node.\n", node->key);
    } else {
        struct Node* currentNode = bst->root;
        while (currentNode != NULL) {
            if (node->key < currentNode->key) {
				printf("\nChecking node %d for left child." , currentNode->key);
                if (currentNode->left == NULL) {
					printf("\nInserting node %d as left child of node %d.\n", node->key, currentNode->key);
                    currentNode->left = node;
                    currentNode = NULL;
                } else {
                    currentNode = currentNode->left;
					printf("\nTraversed to left child node %d.", currentNode->key);
                }
            } else {
				printf("\nChecking node %d for right child." , currentNode->key);
                if (currentNode->right == NULL) {
					printf("\nInserting node %d as right child of node %d.\n", node->key, currentNode->key);
                    currentNode->right = node;
                    currentNode = NULL;
                } else {
                    currentNode = currentNode->right;
					printf("\nTraversed to right child node %d.", currentNode->key);
                }
            }
        }
    }
}

bool removeNode(struct BinarySearchTree* bst, int key) {
    // Implement function based on remove algorithm found in Figure 7.6.1
    struct Node* parent = NULL;
    struct Node* currentNode = bst->root;

    while (currentNode != NULL) {
        if (currentNode->key == key) {
            // Case 1: Node has no children
            if (currentNode->left == NULL && currentNode->right == NULL) {
                if (parent == NULL) {
                    bst->root = NULL;
                } else if (parent->left == currentNode) {
                    parent->left = NULL;
                } else {
                    parent->right = NULL;
                }
                free(currentNode);
                return true; // Node found and removed
            }
            // Case 2: Node has only left child
            else if (currentNode->left != NULL && currentNode->right == NULL) {
                if (parent == NULL) {
                    bst->root = currentNode->left;
                } else if (parent->left == currentNode) {
                    parent->left = currentNode->left;
                } else {
                    parent->right = currentNode->left;
                }
                free(currentNode);
                return true; // Node found and removed
            }
            // Case 3: Node has only right child
            else if (currentNode->left == NULL && currentNode->right != NULL) {
                if (parent == NULL) {
                    bst->root = currentNode->right;
                } else if (parent->left == currentNode) {
                    parent->left = currentNode->right;
                } else {
                    parent->right = currentNode->right;
                }
                free(currentNode);
                return true; // Node found and removed
            }
            // Case 4: Node has both left and right children
            else {
                struct Node* successor = currentNode->right;
                while (successor->left != NULL) {
                    successor = successor->left;
                }
                currentNode->key = successor->key;
                key = successor->key;
                parent = currentNode;
                currentNode = currentNode->right;
            }
        } else if (currentNode->key < key) {
            parent = currentNode;
            currentNode = currentNode->right;
        } else {
            parent = currentNode;
            currentNode = currentNode->left;
        }
    }
    return false; // Node not found
}
	


// Function to print binary tree in 2D
// It does reverse inorder traversal
void print2DUtil(struct Node* root, int space)
{
    // Base case
    if (root == NULL) {
        return;
	}
	
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++) {
		printf(" ");
	}
    printf("%d\n", root->key);
 
    // Process left child
    print2DUtil(root->left, space);
}
 
// Wrapper over print2DUtil()
void print2D(struct Node* root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}

int main() {
    // Implement function based on program instructions
	struct BinarySearchTree bst; //create binary search tree
	initBST(&bst);
	
	int numbers[] = {20,35,13,6,24,18,48,1,27}; //Step 1. insert nodes

	for (int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->key = numbers[i];
        newNode->left = NULL;
        newNode->right = NULL;
        insert(&bst, newNode);
        }
        
	printf("\nInitial Binary Search Tree: \n");
	print2D(getRoot(&bst)); //Step 2. call print 2d
	
	int key = 18;// Step 3. Remove 18 and 48
	int found = removeNode(&bst, key);
	if (found) {
	printf("\nLeaf node 18 was removed.\n");
	}
	
	key = 48;
	found = removeNode(&bst, key);
	if (found) {
	printf("Leaf node 48 was removed.\n");
	}
	
	printf("\nBinary Search Tree after removing nodes 18 and 48: \n");
	print2D(getRoot(&bst)); //Step 4. call print 2d
	
	int NewNumbers[] = {16, 45}; //Step 5. insert nodes 16 and 45

	for (int i = 0; i < sizeof(NewNumbers) / sizeof(NewNumbers[0]); i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->key = NewNumbers[i];
        newNode->left = NULL;
        newNode->right = NULL;
        insert(&bst, newNode);
        }
	
	printf("\nBinary Search Tree after inserting nodes 16 and 45: \n");
	print2DUtil(getRoot(&bst), 0);// Step 6. Call print2dutil function
	
	key = 6;// Step 7. Remove 6 and 24
	found = removeNode(&bst, key);
	if (found) {
	printf("\nNode 6 with only left child was removed.\n");
	}
	
	key = 24;
	found = removeNode(&bst, key);
	if (found) {
	printf("Node 24 with only right child was removed.\n");
	}
	
	printf("\nBinary Search Tree after removing nodes 6 and 24: \n");
	print2D(getRoot(&bst)); //Step 8. call print 2d
	
	key = 20;// Step 9. Remove 20 and 38
	found = removeNode(&bst, key);
	if (found) {
	printf("\nNode 20 with a right and left child was removed.\n");
	}
	
	key = 38;
	found = removeNode(&bst, key);
	if (found) {
	printf("Node 38 was removed.\n");
	}
	else {
	printf("Node 38 was not removed.\n");
	}
	
	printf("\nBinary Search Tree after removing nodes 20 and 38: \n");
	print2D(getRoot(&bst)); //Step 10. call print 2d
	

    return 0;
}

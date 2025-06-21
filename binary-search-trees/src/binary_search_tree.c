#include "binary_search_tree.h"

#include <stdlib.h>

BST* initBST() {
  BST *tree = malloc(sizeof(BST));
  if (!tree) return NULL;

  tree->root = NULL;
  
  return tree;
}

void freeBST(BST *tree) {
  if (!tree) return;
  
  freeBSTNode(tree->root);
  
  free(tree);
}

void insertBSTNode(BST *tree, int value) {
  if (!tree) return;

  BSTNode *newNode = initBSTNode(value);

  if (!tree->root) {
    tree->root = newNode;
    return;
  }

  BSTNode *currentNode = tree->root;
  BSTNode *targetNode;

  while (currentNode) {
    targetNode = currentNode;

    if (value < currentNode->value) {
      currentNode = currentNode->left;
    } else {
      currentNode = currentNode->right;
    }
  }

  if (value < targetNode->value) {
    targetNode->left = newNode;
  } else {
    targetNode->right = newNode;
  }
}

void printPreorderRoute(BSTNode *root) {
  if (!root) return;

  printf("%d ", root->value);
  printPreorderRoute(root->left);
  printPreorderRoute(root->right);
}

void printInorderRoute(BSTNode *root) {
  if (!root) return;

  printInorderRoute(root->left);
  printf("%d ", root->value);
  printInorderRoute(root->right);
}

void printPostorderRoute(BSTNode *root) {
  if (!root) return;

  printPostorderRoute(root->left);
  printPostorderRoute(root->right);
  printf("%d ", root->value);
}

int getBSTBranchNumberOfLeafNodes(BSTNode *node) {
  if (!node) return 0;

  if (!node->left && !node->right) {
    return 1;
  }

  return getBSTBranchNumberOfLeafNodes(node->left) + getBSTBranchNumberOfLeafNodes(node->right);
}

int getBSTNumberOfLeafNodes(BST *tree) {
  return getBSTBranchNumberOfLeafNodes(tree->root);
}

int getBSTBranchHeight(BSTNode *node, int currentHeight) {
  if (!node) return currentHeight;

  int leftHeight = getBSTBranchHeight(node->left, currentHeight + 1);
  int rightHeight = getBSTBranchHeight(node->right, currentHeight + 1);

  return (leftHeight > rightHeight) ? leftHeight : rightHeight;
}

int getBSTHeight(BST *tree) {
  return getBSTBranchHeight(tree->root, 0);
}

BSTNode* initBSTNode(int value) {
  BSTNode *node = malloc(sizeof(BSTNode));
  if (!node) return NULL;

  node->value = value;
  node->left = NULL;
  node->right = NULL;

  return node;
}

void freeBSTNode(BSTNode *node) {
  if (!node) return;

  freeBSTNode(node->left);
  freeBSTNode(node->right);

  free(node);
}

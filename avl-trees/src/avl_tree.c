#include "avl_tree.h"

#include <stdio.h>
#include <stdlib.h>

#include "common/util.h"

AVLTree* initAVLTree() {
  AVLTree *tree = malloc(sizeof(AVLTree));
  if (!tree) return NULL;

  tree->root = NULL;

  return tree;
}

void freeAVLTree(AVLTree *tree) {
  if (!tree) return;

  freeAVLTreeNode(tree->root);
  free(tree);
}

AVLTreeNode* initAVLTreeNode(int value) {
  AVLTreeNode *node = malloc(sizeof(AVLTreeNode));
  if (!node) return NULL;

  node->value = value;
  node->height = 1; // Leaf node has height 1
  node->left = NULL;
  node->right = NULL;

  return node;
}

void freeAVLTreeNode(AVLTreeNode *node) {
  if (!node) return;

  freeAVLTreeNode(node->left);
  freeAVLTreeNode(node->right);
  free(node);
}

AVLTreeNode *insertAVLTreeNode(AVLTreeNode *root, int value) {
  if (!root) {
    return initAVLTreeNode(value);
  }

  if (value < root->value) {
    root->left = insertAVLTreeNode(root->left, value);
  } else if (value > root->value) {
    root->right = insertAVLTreeNode(root->right, value);
  } else {
    return root;
  }

  updateAVLTreeNodeHeight(root);

  int balanceFactor = getAVLTreeNodeBalanceFactor(root);

  if (balanceFactor > 1) {
    if (value > root->left->value) {
      printf("Rebalanceamento LR");
      root->left = rotateLeft(root->left); // Case LR
    } else {
      printf("Rebalanceamento LL");
    }

    return rotateRight(root); // Case LL and LR
  }

  if (balanceFactor < -1) {
    if (value < root->right->value) {
      root->right = rotateRight(root->right); // Case RL
      printf("Rebalanceamento RL");
    } else {
      printf("Rebalanceamento RR");
    }

    return rotateLeft(root); // Case RR and RL
  }

  return root;
}

AVLTreeNode *removeAVLTreeNode(AVLTreeNode *root, int value) {
  if (!root) return root;

  if (value < root->value) {
    root->left = removeAVLTreeNode(root->left, value);
  } else if (value > root->value) {
    root->right = removeAVLTreeNode(root->right, value);
  } else {
    if (!root->left || !root->right) {
      AVLTreeNode *temp = root->left ? root->left : root->right;

      if (!temp) {
        temp = root;
        root = NULL;
      } else {
        *root = *temp;
      }

      free(temp);
    } else {
      AVLTreeNode *temp = minAVLTreeNodeValue(root->right);
      root->value = temp->value;
      root->right = removeAVLTreeNode(root->right, temp->value);
    }
  }

  if (!root) return root;

  updateAVLTreeNodeHeight(root);

  int balanceFactor = getAVLTreeNodeBalanceFactor(root);

  if (balanceFactor > 1) {
    if (getAVLTreeNodeBalanceFactor(root->left) < 0) {
      root->left = rotateLeft(root->left); // Case LR
      printf("Rebalanceamento LR");
    } else {
      printf("Rebalanceamento LL");
    }

    return rotateRight(root); // Case LL and LR
  }

  if (balanceFactor < -1) {
    if (getAVLTreeNodeBalanceFactor(root->right) > 0) {
      root->right = rotateRight(root->right); // Case RL
      printf("Rebalanceamento RL");
    } else {
      printf("Rebalanceamento RR");
    }

    return rotateLeft(root); // Case RR and RL
  }

  return root;
}

void printInorderRoute(AVLTreeNode *root) {
  if (!root) return;

  printInorderRoute(root->left);
  printf("%d ", root->value);
  printInorderRoute(root->right);
}

void printInorderRouteWithBalanceFactor(AVLTreeNode *root) {
  if (!root) return;

  printInorderRouteWithBalanceFactor(root->left);
  printf("[%d (%d)] ", root->value, getAVLTreeNodeBalanceFactor(root));
  printInorderRouteWithBalanceFactor(root->right);
}

int getAVLTreeNodeHeight(AVLTreeNode *node) {
  return !node ? 0 : node->height;
}

void updateAVLTreeNodeHeight(AVLTreeNode *node) {
  node->height = 1 + max(getAVLTreeNodeHeight(node->left), getAVLTreeNodeHeight(node->right));
}

int getAVLTreeNodeBalanceFactor(AVLTreeNode *node) {
  return !node ? 0 : getAVLTreeNodeHeight(node->left) - getAVLTreeNodeHeight(node->right);
}

AVLTreeNode *minAVLTreeNodeValue(AVLTreeNode *node) {
  AVLTreeNode *currentNode = node;

  while (currentNode->left) {
    currentNode = currentNode->left;
  }

  return currentNode;
}

AVLTreeNode *rotateRight(AVLTreeNode *node) {
  AVLTreeNode *newRoot = node->left;
  AVLTreeNode *temp = newRoot->right;

  newRoot->right = node;
  node->left = temp;

  updateAVLTreeNodeHeight(node);
  updateAVLTreeNodeHeight(newRoot);

  return newRoot;
}

AVLTreeNode *rotateLeft(AVLTreeNode *node) {
  AVLTreeNode *newRoot = node->right;
  AVLTreeNode *temp = newRoot->left;

  newRoot->left = node;
  node->right = temp;

  updateAVLTreeNodeHeight(node);
  updateAVLTreeNodeHeight(newRoot);

  return newRoot;
}

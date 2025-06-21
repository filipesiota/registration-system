#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

typedef struct BSTNode BSTNode;

struct BSTNode {
  int value;
  BSTNode *left;
  BSTNode *right;
};

typedef struct {
  BSTNode *root;
} BST;

BST* initBST();
void freeBST(BST *tree);
void insertBSTNode(BST *tree, int value);
void printPreorderRoute(BSTNode *root);
void printInorderRoute(BSTNode *root);
void printPostorderRoute(BSTNode *root);
int getBSTNumberOfLeafNodes(BST *tree);
int getBSTHeight(BST *tree);

BSTNode* initBSTNode(int value);
void freeBSTNode(BSTNode *node);

#endif

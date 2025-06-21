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

BSTNode* initBSTNode(int value);
void freeBSTNode(BSTNode *node);

void insertBSTNode(BST *tree, int value);
void printPreorderRoute(BSTNode *root);
void printInorderRoute(BSTNode *root);
void printPostorderRoute(BSTNode *root);

int getBSTBranchNumberOfLeafNodes(BSTNode *node);
int getBSTNumberOfLeafNodes(BST *tree);
int getBSTBranchHeight(BSTNode *node, int currentHeight);
int getBSTHeight(BST *tree);

#endif

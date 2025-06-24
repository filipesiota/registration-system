#ifndef AVL_TREE_H
#define BINARY_SEARCH_TREE_H

typedef struct AVLTreeNode AVLTreeNode;

struct AVLTreeNode {
  int value;
  int height;
  AVLTreeNode *left;
  AVLTreeNode *right;
};

typedef struct {
  AVLTreeNode *root;
} AVLTree;

AVLTree* initAVLTree();
void freeAVLTree(AVLTree *tree);

AVLTreeNode* initAVLTreeNode(int value);
void freeAVLTreeNode(AVLTreeNode *node);

AVLTreeNode *insertAVLTreeNode(AVLTreeNode *root, int value);
AVLTreeNode *removeAVLTreeNode(AVLTreeNode *root, int value);
void printInorderRoute(AVLTreeNode *root);
void printInorderRouteWithBalanceFactor(AVLTreeNode *root);

int getAVLTreeNodeHeight(AVLTreeNode *node);
void updateAVLTreeNodeHeight(AVLTreeNode *node);
int getAVLTreeNodeBalanceFactor(AVLTreeNode *node);
AVLTreeNode *minAVLTreeNodeValue(AVLTreeNode *node);

AVLTreeNode *rotateRight(AVLTreeNode *node);
AVLTreeNode *rotateLeft(AVLTreeNode *node);

#endif

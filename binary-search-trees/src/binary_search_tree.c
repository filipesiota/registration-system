#include "binary_search_tree.h"

#include <stdio.h>
#include <stdlib.h>

// Inicializa a estrutura da árvore binária de busca (BST)
BST* initBST() {
  BST *tree = malloc(sizeof(BST));
  if (!tree) return NULL;

  tree->root = NULL;
  return tree;
}

// Libera toda a memória da árvore BST
void freeBST(BST *tree) {
  if (!tree) return;

  freeBSTNode(tree->root); // Libera nós recursivamente
  free(tree); // Libera estrutura principal
}

// Inicializa um nó da árvore com um valor específico
BSTNode* initBSTNode(int value) {
  BSTNode *node = malloc(sizeof(BSTNode));
  if (!node) return NULL;

  node->value = value;
  node->left = NULL;
  node->right = NULL;

  return node;
}

// Libera recursivamente os nós da árvore
void freeBSTNode(BSTNode *node) {
  if (!node) return;

  freeBSTNode(node->left);
  freeBSTNode(node->right);
  free(node);
}

// Insere um novo valor na árvore mantendo a propriedade de BST
void insertBSTNode(BST *tree, int value) {
  if (!tree) return;

  BSTNode *newNode = initBSTNode(value);

  if (!tree->root) {
    tree->root = newNode; // Se a árvore estiver vazia, define a raiz
    return;
  }

  BSTNode *currentNode = tree->root;
  BSTNode *targetNode;

  // Encontra a posição correta para inserção
  while (currentNode) {
    targetNode = currentNode;

    if (value < currentNode->value) {
      currentNode = currentNode->left;
    } else {
      currentNode = currentNode->right;
    }
  }

  // Insere o novo nó como filho esquerdo ou direito
  if (value < targetNode->value) {
    targetNode->left = newNode;
  } else {
    targetNode->right = newNode;
  }
}

// Percorre e imprime a árvore em pré-ordem (raiz, esquerda, direita)
void printPreorderRoute(BSTNode *root) {
  if (!root) return;

  printf("%d ", root->value);
  printPreorderRoute(root->left);
  printPreorderRoute(root->right);
}

// Percorre e imprime a árvore em ordem (esquerda, raiz, direita)
void printInorderRoute(BSTNode *root) {
  if (!root) return;

  printInorderRoute(root->left);
  printf("%d ", root->value);
  printInorderRoute(root->right);
}

// Percorre e imprime a árvore em pós-ordem (esquerda, direita, raiz)
void printPostorderRoute(BSTNode *root) {
  if (!root) return;

  printPostorderRoute(root->left);
  printPostorderRoute(root->right);
  printf("%d ", root->value);
}

// Retorna o número de nós folha a partir de um nó (folha = sem filhos)
int getBSTBranchNumberOfLeafNodes(BSTNode *node) {
  if (!node) return 0;

  if (!node->left && !node->right) {
    return 1; // É folha
  }

  // Soma folhas da subárvore esquerda e direita
  return getBSTBranchNumberOfLeafNodes(node->left) + getBSTBranchNumberOfLeafNodes(node->right);
}

// Retorna o número total de folhas da árvore
int getBSTNumberOfLeafNodes(BST *tree) {
  return getBSTBranchNumberOfLeafNodes(tree->root);
}

// Calcula a altura de um ramo da árvore
int getBSTBranchHeight(BSTNode *node, int currentHeight) {
  if (!node) return currentHeight;

  int leftHeight = getBSTBranchHeight(node->left, currentHeight + 1);
  int rightHeight = getBSTBranchHeight(node->right, currentHeight + 1);

  return (leftHeight > rightHeight) ? leftHeight : rightHeight;
}

// Retorna a altura total da árvore (nível máximo até uma folha)
int getBSTHeight(BST *tree) {
  return getBSTBranchHeight(tree->root, 0);
}

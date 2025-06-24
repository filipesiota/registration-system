#include "avl_tree.h"

#include <stdio.h>
#include <stdlib.h>

#include "common/util.h"

// Inicializa uma nova arvore AVL
AVLTree* initAVLTree() {
  AVLTree *tree = malloc(sizeof(AVLTree));
  if (!tree) return NULL;

  tree->root = NULL;
  return tree;
}

// Libera a memoria da arvore AVL
void freeAVLTree(AVLTree *tree) {
  if (!tree) return;

  freeAVLTreeNode(tree->root);
  free(tree);
}

// Cria e inicializa um novo no AVL
AVLTreeNode* initAVLTreeNode(int value) {
  AVLTreeNode *node = malloc(sizeof(AVLTreeNode));
  if (!node) return NULL;

  node->value = value;
  node->height = 1; // Folha comeca com altura 1
  node->left = NULL;
  node->right = NULL;

  return node;
}

// Libera recursivamente os nos da arvore
void freeAVLTreeNode(AVLTreeNode *node) {
  if (!node) return;

  freeAVLTreeNode(node->left);
  freeAVLTreeNode(node->right);
  free(node);
}

// Insere um valor na arvore AVL e reequilibra se necessario
AVLTreeNode *insertAVLTreeNode(AVLTreeNode *root, int value) {
  if (!root) {
    return initAVLTreeNode(value); // Insere novo no
  }

  // Insere recursivamente na subarvore correta
  if (value < root->value) {
    root->left = insertAVLTreeNode(root->left, value);
  } else if (value > root->value) {
    root->right = insertAVLTreeNode(root->right, value);
  } else {
    return root; // Valor duplicado, nao faz nada
  }

  // Atualiza a altura do no
  updateAVLTreeNodeHeight(root);

  // Calcula fator de balanceamento
  int balanceFactor = getAVLTreeNodeBalanceFactor(root);

  // Reequilibra se necessario
  if (balanceFactor > 1) {
    if (value > root->left->value) {
      root->left = rotateLeft(root->left); // Caso LR
      printf("Rebalanceamento LR");
    } else {
      printf("Rebalanceamento LL");
    }
    return rotateRight(root); // LL ou LR
  }

  if (balanceFactor < -1) {
    if (value < root->right->value) {
      root->right = rotateRight(root->right); // Caso RL
      printf("Rebalanceamento RL");
    } else {
      printf("Rebalanceamento RR");
    }
    return rotateLeft(root); // RR ou RL
  }

  return root;
}

// Remove um valor da arvore AVL e reequilibra
AVLTreeNode *removeAVLTreeNode(AVLTreeNode *root, int value) {
  if (!root) return root;

  // Busca recursiva pelo valor
  if (value < root->value) {
    root->left = removeAVLTreeNode(root->left, value);
  } else if (value > root->value) {
    root->right = removeAVLTreeNode(root->right, value);
  } else {
    // No com no maximo um filho
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
      // No com dois filhos
      AVLTreeNode *temp = minAVLTreeNodeValue(root->right);
      root->value = temp->value;
      root->right = removeAVLTreeNode(root->right, temp->value);
    }
  }

  if (!root) return root;

  // Atualiza altura e balanceia
  updateAVLTreeNodeHeight(root);

  int balanceFactor = getAVLTreeNodeBalanceFactor(root);

  if (balanceFactor > 1) {
    if (getAVLTreeNodeBalanceFactor(root->left) < 0) {
      root->left = rotateLeft(root->left); // Caso LR
      printf("Rebalanceamento LR");
    } else {
      printf("Rebalanceamento LL");
    }
    return rotateRight(root);
  }

  if (balanceFactor < -1) {
    if (getAVLTreeNodeBalanceFactor(root->right) > 0) {
      root->right = rotateRight(root->right); // Caso RL
      printf("Rebalanceamento RL");
    } else {
      printf("Rebalanceamento RR");
    }
    return rotateLeft(root);
  }

  return root;
}

// Impressao em ordem (esquerda, raiz, direita)
void printInorderRoute(AVLTreeNode *root) {
  if (!root) return;

  printInorderRoute(root->left);
  printf("%d ", root->value);
  printInorderRoute(root->right);
}

// Impressao com fator de balanceamento de cada no
void printInorderRouteWithBalanceFactor(AVLTreeNode *root) {
  if (!root) return;

  printInorderRouteWithBalanceFactor(root->left);
  printf("[%d (%d)] ", root->value, getAVLTreeNodeBalanceFactor(root));
  printInorderRouteWithBalanceFactor(root->right);
}

// Retorna altura de um no
int getAVLTreeNodeHeight(AVLTreeNode *node) {
  return !node ? 0 : node->height;
}

// Atualiza altura de um no baseado nos filhos
void updateAVLTreeNodeHeight(AVLTreeNode *node) {
  node->height = 1 + max(getAVLTreeNodeHeight(node->left), getAVLTreeNodeHeight(node->right));
}

// Retorna o fator de balanceamento de um no
int getAVLTreeNodeBalanceFactor(AVLTreeNode *node) {
  return !node ? 0 : getAVLTreeNodeHeight(node->left) - getAVLTreeNodeHeight(node->right);
}

// Encontra o menor valor de uma subarvore
AVLTreeNode *minAVLTreeNodeValue(AVLTreeNode *node) {
  AVLTreeNode *currentNode = node;

  while (currentNode->left) {
    currentNode = currentNode->left;
  }

  return currentNode;
}

// Rotacao simples a direita (para corrigir desbalanceamento para esquerda)
AVLTreeNode *rotateRight(AVLTreeNode *node) {
  AVLTreeNode *newRoot = node->left;
  AVLTreeNode *temp = newRoot->right;

  newRoot->right = node;
  node->left = temp;

  updateAVLTreeNodeHeight(node);
  updateAVLTreeNodeHeight(newRoot);

  return newRoot;
}

// Rotacao simples a esquerda (para corrigir desbalanceamento para direita)
AVLTreeNode *rotateLeft(AVLTreeNode *node) {
  AVLTreeNode *newRoot = node->right;
  AVLTreeNode *temp = newRoot->left;

  newRoot->left = node;
  node->right = temp;

  updateAVLTreeNodeHeight(node);
  updateAVLTreeNodeHeight(newRoot);

  return newRoot;
}

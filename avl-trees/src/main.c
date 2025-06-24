#include <stdio.h>
#include <stdlib.h>

#include "common/util.h"
#include "avl_tree.h"

int main() {
    AVLTree *tree = initAVLTree();

    sysCommand("clear_terminal");

    int numbers[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45};
    int numbersLength = sizeof(numbers) / sizeof(numbers[0]);
    int i;

    printf("Adicionando valores...\n");

    for (i = 0; i < numbersLength; i++) {
        tree->root = insertAVLTreeNode(tree->root, numbers[i]);
    }

    printf("\nIn-ordem: ");
    printInorderRoute(tree->root);

    int removeNumbers[] = {20, 30, 50};
    int removeNumbersLength = sizeof(removeNumbers) / sizeof(removeNumbers[0]);

    for (i = 0; i < removeNumbersLength; i++) {
        printf("\n\nRemovendo item %d: ", removeNumbers[i]);
        tree->root = removeAVLTreeNode(tree->root, removeNumbers[i]);

        printf("\nIn-ordem: ");
        printInorderRoute(tree->root);
    }

    printf("\n\nFator de balanceamento de cada no: ");
    printInorderRouteWithBalanceFactor(tree->root);

    freeAVLTree(tree);

    printf("\n\nPrograma finalizado!\n");
    sysCommand("pause_terminal");

    return 0;
}

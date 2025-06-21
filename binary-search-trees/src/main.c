#include <stdio.h>
#include <stdlib.h>

#include "common/util.h"
#include "binary_search_tree.h"

int main() {
    BST *tree = initBST();

    int numbers[] = {8, 4, 10, 2, 6, 9, 12};
    int numbersLength = sizeof(numbers) / sizeof(numbers[0]);
    int i;

    for (i = 0; i < numbersLength; i++) {
        insertBSTNode(tree, numbers[i]);
    }

    sysCommand("clear_terminal");
    
    printf("Pre-ordem: ");
    printPreorderRoute(tree->root);

    printf("\nIn-ordem: ");
    printInorderRoute(tree->root);

    printf("\nPos-ordem: ");
    printPostorderRoute(tree->root);

    printf("\n\nNúmero de folhas da BST: %d", getBSTNumberOfLeafNodes(tree));
    printf("\nAltura da BST: %d\n", getBSTHeight(tree));

    freeBST(tree);

    printf("\nPrograma finalizado!\n");
    sysCommand("pause_terminal");

    return 0;
}

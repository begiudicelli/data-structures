#include <stdio.h>
#include <stdlib.h>
#include "linked_list/linked_list.h"
#include "binary_tree/binary_tree.h"

int main() {

	TreeNode* tree = NULL;
	TreeNode* parent = NULL;

	tree = insertTreeNode(tree, 18);
	tree = insertTreeNode(tree, 15);
	tree = insertTreeNode(tree, 30);
	tree = insertTreeNode(tree, 40);
	tree = insertTreeNode(tree, 50);
	tree = insertTreeNode(tree, 100);


	int searchValue = 15;
	TreeNode* foundNode = searchTreeNodeAndParent(tree, searchValue, &parent);

    if (foundNode != NULL) {
        printf("Nó encontrado: %d\n", foundNode->cod);
        if (parent != NULL) {
            printf("Pai do nó encontrado: %d\n", parent->cod);
        } else {
            printf("O nó encontrado é a raiz da árvore.\n");
        }
    } else {
        printf("Nó com valor %d não encontrado na árvore.\n", searchValue);
    }

    return 0;
}

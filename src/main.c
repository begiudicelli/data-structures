#include <stdio.h>
#include <stdlib.h>
#include "linked_list/linked_list.h"
#include "binary_tree/binary_tree.h"

int main() {
	setbuf(stdout, NULL);

	TreeNode* tree = NULL;
	TreeNode* parent = NULL;

	tree = insertTreeNode(tree, 80);
	tree = insertTreeNode(tree, 22);
	tree = insertTreeNode(tree, 67);
	tree = insertTreeNode(tree, 72);
	tree = insertTreeNode(tree, 100);
	tree = insertTreeNode(tree, 103);
	tree = insertTreeNode(tree, 75);
	tree = insertTreeNode(tree, 50);
	tree = insertTreeNode(tree, 18);
	tree = insertTreeNode(tree, 2);

	int searchValue = 2;
	TreeNode* foundNode = searchTreeNodeAndParent(tree, searchValue, &parent);

    if (foundNode != NULL) {
        printf("Nó encontrado: %d\n", foundNode->cod);
        parent != NULL ? printf("Pai do nó encontrado: %d\n", parent->cod) : printf("O nó é a raiz da árvore.\n");
    } else printf("Nó com valor %d não encontrado na árvore.\n", searchValue);

    deleteTreeNode(tree, searchValue);
    printTree(tree);

    return 0;
}

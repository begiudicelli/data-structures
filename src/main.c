#include <stdio.h>
#include <stdlib.h>
#include "linked_list/linked_list.h"
#include "binary_tree/binary_tree.h"

int main() {

	TreeNode* tree = NULL;
	tree = insertTreeNode(tree, 5);
	tree = insertTreeNode(tree, 10);
	tree = insertTreeNode(tree, 15);
	tree = insertTreeNode(tree, 3);
	printTree(tree);

    return 0;
}

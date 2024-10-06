#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

TreeNode* createTreeNode(int cod){
	TreeNode* new = (TreeNode*) malloc(sizeof(TreeNode));
	new->cod = cod;
	new->right = NULL;
	new->left = NULL;
	return new;
}

TreeNode* insertTreeNode(TreeNode* root, int cod){
	if(root == NULL){
		root = createTreeNode(cod);
	}else if(cod < root->cod){
		root->left = insertTreeNode(root->left, cod);
	}else{
		root->right = insertTreeNode(root->right, cod);
	}
	return root;
}


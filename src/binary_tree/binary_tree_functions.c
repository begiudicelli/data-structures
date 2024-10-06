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
	}else if(cod > root->cod){
		root->right = insertTreeNode(root->right, cod);
	}else{
		root->left = insertTreeNode(root->left, cod);
	}
	return root;
}

TreeNode* searchTreeNode(TreeNode* root, int cod){
	if(root != NULL){
		if(cod == root->cod){
			printf("Encontrado!");
		}else if(cod > root->cod){
			root->right = searchTreeNode(root->right, cod);
		}else{
			root->left = searchTreeNode(root->left, cod);
		}
	}
	return root;
}

void printTree(TreeNode* root){
	if(root != NULL){
		printf("\nAtual %p - Código %d - Esquerda %p - Direita - %p",
						root, root->cod, root->left, root->right);
		printTree(root->left);
		printTree(root->right);
	}
}


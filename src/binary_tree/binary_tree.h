#ifndef BINARY_TREE_BINARY_TREE_H_
#define BINARY_TREE_BINARY_TREE_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct TreeNode {
    int cod;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createTreeNode(int cod);
TreeNode* searchTreeNode(TreeNode* root, int cod);
TreeNode* searchTreeNodeAndParent(TreeNode* root, int cod, TreeNode** parent);
TreeNode* insertTreeNode(TreeNode* root, int cod);
TreeNode* deleteTreeNode(TreeNode* root, int cod);
void printTreeNode(TreeNode* root);
void printTree(TreeNode* root);
void displayTreeMenu();

#endif

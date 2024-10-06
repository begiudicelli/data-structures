#ifndef BINARY_TREE_BINARY_TREE_H_
#define BINARY_TREE_BINARY_TREE_H_

#define COUNT 10

typedef struct TreeNode {
    int cod;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createTreeNode(int cod);
TreeNode* searchTreeNode(TreeNode* root, int cod);
TreeNode* insertTreeNode(TreeNode* root, int cod);
void printTree(TreeNode* root);

#endif

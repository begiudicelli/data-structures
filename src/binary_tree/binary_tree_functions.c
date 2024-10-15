#include "binary_tree.h"

TreeNode* createTreeNode(int cod){
	TreeNode* new = (TreeNode*) malloc(sizeof(TreeNode));
	new->cod = cod;
	new->right = NULL;
	new->left = NULL;
	return new;
}

TreeNode* insertTreeNode(TreeNode* root, int cod){
	if(root == NULL) root = createTreeNode(cod);
	else if(cod > root->cod) root->right = insertTreeNode(root->right, cod);
	else root->left = insertTreeNode(root->left, cod);
	return root;
}

void massInsertion(TreeNode** root, int amount){
	for(int i = 0; i < amount; i++){
		int value = rand() % 100;
		*root = insertTreeNode(*root, value);
	}
	printf("%d valores inseridos com sucesso.\n", amount);
}
TreeNode* searchTreeNode(TreeNode* root, int cod){
    if(root == NULL || root->cod == cod) return root;
    if(cod > root->cod) return searchTreeNode(root->right, cod);
    return searchTreeNode(root->left, cod);
}

TreeNode* searchTreeNodeAndParent(TreeNode* root, int cod, TreeNode** parent){
    if(root == NULL || root->cod == cod) return root;
    *parent = root;
    if(cod > root->cod) return searchTreeNodeAndParent(root->right, cod, parent);
    return searchTreeNodeAndParent(root->left, cod, parent);
}

TreeNode* deleteTreeNode(TreeNode* root, int cod){
	TreeNode* parent = NULL;
	TreeNode* delete = searchTreeNodeAndParent(root, cod, &parent);

	TreeNode* tmp = NULL;
	TreeNode* tmpParent = NULL;

	if(delete != NULL){
		if(delete->right == NULL){
			tmp = delete->left;
		}else if(delete->left == NULL){
			tmp = delete->right;
		}

		if(parent != NULL){
			if(delete-> cod > parent->cod){
				parent->right = tmp;
			}else{
				parent->left = tmp;
			}
		}else{
			root = tmp;
		}
		free(delete);
	}
	return root;
}

void printTreeNode(TreeNode* root){
	root != NULL ? printf("Valor encontrado: %d", root->cod) : printf("Valor não encontrado.\n");
}

void printTree(TreeNode* root){
	if(root != NULL){
		printf("\nAtual %p - Código %d - Esquerda %p - Direita - %p",
						root, root->cod, root->left, root->right);
		printTree(root->left);
		printTree(root->right);
	}
}

void displayTreeMenu(){
    setvbuf(stdout, NULL, _IONBF, 0);

    TreeNode* tree = NULL;
    TreeNode* searchNode = NULL;
    char opt;
    int value, amount;
    do {
        printf("\nMenu Principal: \n");
        printf("A - Inserir elemento\n");
        printf("B - Pesquisar elemento\n");
        printf("C - Imprimir\n");
        printf("D - Inserir em massa\n");
        printf("E - Finalizar\n");
        printf("Escolha uma opcao: ");
        scanf(" %c", &opt);

        switch (opt) {
        case 'A':
        	printf("Digite o valor do elemento a ser inserido: ");
        	scanf("%d", &value);
        	tree = insertTreeNode(tree, value);
            break;
        case 'B':
        	printf("Digite o valor do elemento a ser pesquisado: ");
        	scanf("%d", &value);
        	searchNode = searchTreeNode(tree, value);
        	printTreeNode(searchNode);
            break;
        case 'C':
        	printTree(tree);
            break;
        case 'D':
        	printf("Digite o numero de valores a serem inseridos: ");
        	scanf("%d", &amount);
        	massInsertion(&tree, amount);
            break;
        default:
            printf("Opcao invalida.\n");
            break;
        }
    } while (opt != 'E');
}


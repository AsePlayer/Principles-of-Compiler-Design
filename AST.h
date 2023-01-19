//Abstract Syntax Tree Implementation
#include <string.h>

struct AST{
	char nodeType[50];
	char LHS[50];
	char RHS[50];
	
	struct AST * left;
	struct AST * right;
	// review pointers to structs in C 
	// complete the tree struct with pointers
};

struct AST * AST_Type(char nodeType[50], char LHS[50], char RHS[50]){

	struct AST* ASTtype = malloc(sizeof(struct AST));
	strcpy(ASTtype->nodeType, nodeType);
	strcpy(ASTtype->LHS, LHS);
	strcpy(ASTtype->RHS, RHS);
		
	return ASTtype;
	
}
void printDots(int num)
{
	for (int i = 0; i < num; i++)
		printf("      ");
}
void printAST(struct AST* tree, int level){
	if (tree == NULL) return;
	printDots(level);
	printf("%s\n", tree->nodeType);
	printDots(level);
	printf("%s %s\n", tree->LHS, tree->RHS);
	if(tree->left != NULL) printAST(tree->left, level+1); else return;
	if(tree->right != NULL) printAST(tree->right, level+1); else return;
	
}
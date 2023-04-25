
//Abstract Syntax Tree Implementation
#include <string.h>

struct AST{
	char nodeType[50];
	char LHS[50];
	char RHS[50];
	char value[50];
	char defaultVal[50];

	char condition[50]; // for if statements
	
	struct AST * left;
	struct AST * right;
	// review pointers to structs in C 
	// complete the tree struct with pointers
};

struct AST * AST_assignment(char nodeType[50], char value[50], char LHS[50], char RHS[50]){
	

	struct AST* ASTassign = malloc(sizeof(struct AST));
	strcpy(ASTassign->nodeType, nodeType);
	strcpy(ASTassign->value, value);
	strcpy(ASTassign->LHS, LHS);
	strcpy(ASTassign->RHS, RHS);
	// print value of the node
	printf("Node type: %s, value: %s, LHS: %s, RHS: %s\n", ASTassign->nodeType, ASTassign->value, ASTassign->LHS, ASTassign->RHS);
	


/*
       =
	 /   \
	x     y

*/	
	return ASTassign;
	
}
struct AST * AST_BinaryExpression(char nodeType[50], char LHS[50], char RHS[50]){

	struct AST* ASTBinExp = malloc(sizeof(struct AST));
	strcpy(ASTBinExp->nodeType, nodeType);
	strcpy(ASTBinExp->LHS, LHS);
	strcpy(ASTBinExp->RHS, RHS);
	printf("Node type: %s, value: %s, LHS: %s, RHS: %s\n", ASTBinExp->nodeType, ASTBinExp->value, ASTBinExp->LHS, ASTBinExp->RHS);

	return ASTBinExp;
}

struct AST * AST_Number(char nodeType[50], char value[50]){

	struct AST* ASTnum = malloc(sizeof(struct AST));
	strcpy(ASTnum->nodeType, nodeType);
	strcpy(ASTnum->value, value);
	printf("Node type: %s, value: %s, LHS: %s, RHS: %s\n", ASTnum->nodeType, ASTnum->value, ASTnum->LHS, ASTnum->RHS);
	
	return ASTnum;
	
}

struct AST * AST_Array(char nodeType[50], char value[50], char LHS[50], char RHS[50]){

	struct AST* ASTarray = malloc(sizeof(struct AST));
	strcpy(ASTarray->nodeType, nodeType);
	strcpy(ASTarray->value, value);
	strcpy(ASTarray->LHS, LHS);
	strcpy(ASTarray->RHS, RHS);
	printf("Node type: %s, value: %s, LHS: %s, RHS: %s\n", ASTarray->nodeType, ASTarray->value, ASTarray->LHS, ASTarray->RHS);
	
	return ASTarray;
	
}


struct AST * AST_Type(char nodeType[50], char LHS[50], char RHS[50]){

	struct AST* ASTtype = malloc(sizeof(struct AST));
	strcpy(ASTtype->nodeType, nodeType);
	strcpy(ASTtype->LHS, LHS);
	strcpy(ASTtype->RHS, RHS);
		
	return ASTtype;
	
}

struct AST * AST_Fun(char nodeType[50], char LHS[50], char RHS[50]){
	
	struct AST* ASTtype = malloc(sizeof(struct AST));
	strcpy(ASTtype->nodeType, nodeType);
	strcpy(ASTtype->LHS, LHS);
	strcpy(ASTtype->RHS, RHS);
		
	return ASTtype;
	
}

struct AST * AST_Block(char nodeType[50], struct AST * declList, struct AST * stmtList){

	struct AST* ASTblock = malloc(sizeof(struct AST));
	strcpy(ASTblock->nodeType, nodeType);
	ASTblock->left = stmtList; // append the statement list to the left pointer of the block node
	ASTblock->right = declList; // append the declaration list to the right pointer of the block node
	// Traverse the statement list and append each statement to the left of the block node
	if(stmtList != NULL) {
		struct AST * current = stmtList;
		while(current->left != NULL) {
			printf("Node type: %s, value: %s, LHS: %s, RHS: %s\n", current->nodeType, current->value, current->LHS, current->RHS);
			ASTblock->right = AST_BinaryExpression(current->nodeType, current->LHS, current->RHS);
			current = current->left;
			// create a AST_BinaryExpression node using the current node's LHS and RHS
			// append the new node to the left of the current node
			// set the current node's LHS and RHS to NULL


			// print value of the node
		}
		// current->left = declList;
	}

	if(declList != NULL) {
		struct AST * current = declList;
		while(current->left != NULL) {
			printf("Node type: %s, value: %s, LHS: %s, RHS: %s\n", current->nodeType, current->value, current->LHS, current->RHS);
			ASTblock->right = AST_BinaryExpression(current->nodeType, current->LHS, current->RHS);
			current = current->left;
			// create a AST_BinaryExpression node using the current node's LHS and RHS
			// append the new node to the left of the current node
			// set the current node's LHS and RHS to NULL
		}
	}

	return ASTblock;
}

struct AST * AST_StmtList(char nodeType[50], char LHS[50], char RHS[50]){
	
	struct AST* ASTtype = malloc(sizeof(struct AST));
	strcpy(ASTtype->nodeType, nodeType);
	strcpy(ASTtype->LHS, LHS);
	strcpy(ASTtype->RHS, RHS);
		
	return ASTtype;
	
}

struct AST * AST_Write(char nodeType[50], char LHS[50], char RHS[50]){
	
	struct AST* ASTtype = malloc(sizeof(struct AST));
	strcpy(ASTtype->nodeType, nodeType);
	strcpy(ASTtype->LHS, LHS);
	strcpy(ASTtype->LHS, RHS);
		
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


























    
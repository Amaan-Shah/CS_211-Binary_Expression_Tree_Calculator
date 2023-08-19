// Amaan Shah, UIC, Spring 2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct TreeNode {
	char* val; 
	struct TreeNode *left; 
	struct TreeNode *right; 
} TreeNode; 

struct StackNode
{
	TreeNode* node;
	struct StackNode* next;
};
typedef struct StackNode stack;
//typedef stack* stackPtr; 


// Prototypes:
void printCommands();
TreeNode* parseExpression(char* input, stack** head);
void push (stack** head, TreeNode** Tnode);
TreeNode* pop(stack** head);
void infix(TreeNode* root);
void prefix(TreeNode* root);
void postfix(TreeNode* root);
int eval(TreeNode* root);
void clearTree(TreeNode* root);
void clearStack(stack** head);
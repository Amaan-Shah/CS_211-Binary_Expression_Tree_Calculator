// Amaan Shah, UIC, Spring 2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void infix(TreeNode* root) {
	if (root == NULL) {
		return;
	}

	if (strcmp(root->val, "+") == 0 || strcmp(root->val, "-") == 0 || strcmp(root->val, "*") == 0 || strcmp(root->val, "/") == 0) {
		printf("(");
	}
	infix(root->left);
	printf(" %s ", root->val);
	infix(root->right);
	if (strcmp(root->val, "+") == 0 || strcmp(root->val, "-") == 0 || strcmp(root->val, "*") == 0 || strcmp(root->val, "/") == 0) {
		printf(")");
	}
	
}

void prefix(TreeNode* root) {
	if (root == NULL) {
		return;
	}
	printf(" %s ", root->val);
	prefix(root->left);
	prefix(root->right);
}

void postfix(TreeNode* root) {
	if (root == NULL) {
		return;
	}
	postfix(root->left);
	postfix(root->right);
	printf(" %s ", root->val);
}

int eval(TreeNode* root) {
	if ( (strcmp(root->val, "+") != 0) && (strcmp(root->val, "-") != 0) && (strcmp(root->val, "*") != 0) && (strcmp(root->val, "/") != 0) ) {
		return atoi(root->val);
	}
	int leftval = eval(root->left);
	int rightval = eval(root->right);
	if (strcmp(root->val, "+") == 0) {
		return leftval + rightval;
	} else if ( strcmp(root->val, "-") == 0) {
		return leftval - rightval;
	} else if (strcmp(root->val, "*") == 0) {
		return leftval * rightval;
	} else if (strcmp(root->val, "/") == 0) {
		return leftval / rightval;
	}
}

TreeNode* parseExpression(char input[], stack** head) {
	char *temp = strtok(input, " \r\t\n");
	while (temp != NULL) {
		if (strcmp(temp, "*") == 0 || strcmp(temp, "+") == 0 || strcmp(temp, "-") == 0 || strcmp(temp, "/") == 0)
    	{
    		TreeNode* Tnode = (TreeNode*) malloc(sizeof(TreeNode));
	      	Tnode->val = temp;
	      	Tnode->right = pop(head);
	      	Tnode->left = pop(head);
	      	if (Tnode->left == NULL || Tnode->right == NULL) {
	      		clearStack(head);
	      	}
	      	push(head, &Tnode);

	    }
    	else
    	{
    		TreeNode* Tnode = (TreeNode*) malloc(sizeof(TreeNode));
      		Tnode->val = temp;
      		Tnode->left = NULL;
      		Tnode->right = NULL;
      		push(head, &Tnode);
    	}
    	//printf("%s ", temp);

		temp = strtok (NULL, " \r\t\n");
	}
  	stack* t = *head;
  	return t->node;
}

void clearTree(TreeNode* root) {
    if(root == NULL) {
    	return;
    }
    clearTree(root->left);
    clearTree(root->right);
    free(root);
   //root = NULL;
}
// Amaan Shah, UIC, Spring 2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main(int argc, char const *argv[])
{
  	char input[300];

  	/* set up an infinite loop */
  	while (1)
  	{
    	fgets(input,300,stdin);
    	/* remove the newline character from the input */
    	int i = 0;

     	while (input[i] != '\n' && input[i] != '\0')
     	{
        	i++;
     	}
     	input[i] = '\0';

    	/* check if user enter q or Q to quit program */
    	if ( (strcmp (input, "q") == 0) || (strcmp (input, "Q") == 0) ) {
    		break;
    	}
    	/* check if user enter ? to see command list */
    	else if ( strcmp (input, "?") == 0) {
    		printCommands();
    	}
    	/* user enters an expression */
    	else {
    		printf("\n%s\n", input);
    		/* 1- Store the expression in a tree
	           2- Display infix notation
	           3- Display prefix notation
	           4- Display postfix notation
	           5- Display the result 
	        */

	        // 1: Create Expression Tree
    		stack* head = NULL;
    		TreeNode* root = parseExpression(input, &head);
    		if (root == NULL || root->left == NULL || root->right == NULL) {
    			printf("Invalid expression. Enter a valid postfix expression \n");
                clearStack(&head);
    		} else {
    			//printf("Root:%s L:%s  R:%s\n", root->val, root->left->val, root->right->val);
    			// 2: Infix Notation
    			printf("Infix notation: ");
    			TreeNode* temp = root;
    			infix(root);
    			// 3: Prefix Notation
    			temp = root;
    			printf("\nPrefix notation: ");
    			prefix(temp);
    			// 4: Postfix Notation
    			temp = root;
    			printf("\nPostfix notation: ");
    			postfix(temp);
    			// 5: Evaluate Expression & Display Result
    			temp = root;
    			printf("\nExpression result: ");
    			int result = eval(temp);
    			printf("%d", result);

                clearStack(&head);
    		}
	        printf("\n");
    	}
   }

  printf ("\nGoodbye\n");
	
	return 0;
}

void printCommands()
{
	printf ("The commands for this program are:\n\n");
 	printf ("q - to quit the program\n");
 	printf ("? - to list the accepted commands\n");
 	printf ("or any postfix mathematical expression using operators of *, /, +, -\n");
}


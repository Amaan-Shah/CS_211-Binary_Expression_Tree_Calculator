// Amaan Shah, UIC, Spring 2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void push (stack** head, TreeNode** Tnode) {
	stack* cur = (stack*) malloc(sizeof(stack));
  	cur->node = *Tnode;
  	cur->next = *head;
  	*head = cur;
}

TreeNode* pop(stack** head) {
  stack* temp = *head;
  TreeNode* x = NULL;

  if (temp != NULL) {
    *head = temp->next;
    x = temp->node;
    free(temp);
  }
  return x;
}

void clearStack(stack** head) {
	stack* cur = *head;
	stack* next = NULL;

	while (cur != NULL) {
		next = cur->next;
    clearTree(cur->node);
		free(cur);
		cur = next;
	}
	*head = NULL;
}

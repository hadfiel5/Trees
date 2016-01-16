#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"tree.h"

typedef struct treeNode node;

static node* NewTreeNode(int data){

	node* temp = malloc(sizeof(node));

	temp->data = data;

	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

void Insert(node **top, int data){

	if(*top == NULL){

		*top = NewTreeNode(data);

	}else if((*top)->data > data){

		Insert(&((*top)->left), data);

	}else if((*top)->data < data){

		Insert(&((*top)->right), data);

	}else{

		return;
	}
}

int DeleteNode(node **top, int data){

	if((*top) == NULL){

		return -1;

	}else if((*top)->data == data){

		if((*top)->right == NULL && (*top)->left == NULL){

			free(*top);
			*top = NULL;
			return 0;

		}else if((*top)->right == NULL){

			node *temp = *top;

			*top = (*top)->left;
			
			temp->left = NULL;
			free(temp);
			temp = NULL;
			return 0;

		}else if((*top)->left == NULL){

			node *temp = *top;

			*top = (*top)->right;

			temp->right = NULL;
			free(temp);
			temp = NULL;
			return 0;
	
		}else{

			node *temp = (*top)->right;

			while(temp->left != NULL){
				temp = temp->left;
			}

			temp->left = (*top)->left;

			temp = *top;
			*top = (*top)->right;

			temp->left = NULL;
			temp->right = NULL;
			free(temp);
			temp = NULL;
			return 0;

		}	

	}else if((*top)->data > data){

		return DeleteNode(&((*top)->left), data);
	
	}else{

		return DeleteNode(&((*top)->right), data);
	}
}

node *FindItem(node *top, int data){

	if(top == NULL){

		return NULL;

	}else if(top->data == data){

		node* temp = top;

		return temp;

	}else if(top->data < data){

		return FindItem(top->right, data);

	}else{
		
		return FindItem(top->left, data);
	}
}

int PrintPreOrder(node *top){

	if(top == NULL){

		return -1;
	}

	printf("%d\n", top->data);

	PrintPreOrder(top->left);
	PrintPreOrder(top->right);

	return 0;
}

int PrintInOrder(node *top){

	if(top == NULL){
	
		return -1;
	}

	PrintInOrder(top->left);
	printf("%d\n", top->data);
	PrintInOrder(top->right);

	return 0;
}

int PrintPostOrder(node *top){

	if(top == NULL){

		return -1;
	}

	PrintPostOrder(top->left);
	PrintPostOrder(top->right);
	printf("%d\n", top->data);
	return 0;
}

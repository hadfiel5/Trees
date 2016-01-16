#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"tree.h"

int main(){

	char *command = malloc(8 * sizeof(char));
	int item;
	int printcase;
	struct treeNode **top = malloc(sizeof(struct treeNode));
	*top = NULL;

	do{

		printf("Command: ");
		scanf("%s", command);

		if(!strcmp(command, "insert")){

			printf("Item: ");
			scanf("%d", &item);

			Insert(top, item);

		}else if(!strcmp(command, "delete")){

			printf("Item: ");
			scanf("%d", &item);

			if(DeleteNode(top, item)){

				printf("Item not found - not in tree\n");
			}else{

				printf("Node deleted\n");
			}			

		}else if(!strcmp(command, "find")){

			printf("Item: ");
			scanf("%d", &item);

			struct treeNode *temp = FindItem(*top, item);

			if(temp == NULL){

				printf("Item not found - not in tree\n");

			}else{

				printf("Item found - address of item is: [%p]\n", (void*)temp);
			
			}
			temp = NULL;

		}else if(!strcmp(command, "print")){

			if(*top == NULL){printf("Cannot print an empty tree!\n");}

			printf("Order (1-PreOrder; 2-InOrder; 3-PostOrder): ");
			scanf("%d", &printcase);

			switch((char)printcase){

				case 1:
	
					PrintPreOrder(*top);
					break;

				case 2:

					PrintInOrder(*top);
					break;

				case 3:

					PrintPostOrder(*top);
					break;

			}	

		}else if(!strcmp(command, "quit")){}
		else{printf("Invalid Command\n");}

	}while(strcmp(command, "quit"));

	free(command);

	while(*top != NULL){

		DeleteNode(top, (*top)->data);

	}

	free(top);
}

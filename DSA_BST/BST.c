#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "BST.h"
#include<stdbool.h>

/*

typedef struct{
	int prodID;
	char prodName[20];
	int prodQty;
	float prodPrice;
} Product;

typedef struct node{
	Product data;
	struct node *left;
	struct node *right;
} NodeType, *NodePtr, BST, *BSTPtr;

*/

//Add element to the BST base on the productID
BST *addElement(BST *list, Product item) //using recursive method
{
	if(list == NULL)
		{
			BST *listTemp = malloc(sizeof(struct node));
				if(listTemp == NULL)
					{
						return NULL;
					}
			listTemp->data = item;
			listTemp->left = NULL;
			listTemp->right = NULL;
			list = listTemp;
			printf("\nSUCCESSFULLY ADDED\n");
			return list;
		}
	
	if(list->data.prodID > item.prodID)
		{
			list->left = addElement(list->left, item);
			return list;
		}
	else
		{
			list->right = addElement(list->right, item);
			return list;
		}
}
void insertBST(BSTPtr *list, Product item) //using iterative method
{
	bool inserted = false;
	BSTPtr temp = malloc(sizeof(struct node));
	if(temp == NULL)
		return;
	
	(*temp).data = item;
	(*temp).left = NULL;
	(*temp).right = NULL;
			
	if(*list == NULL)
	{
		*list = temp;
	}
	
	else
		{
			BSTPtr current = *list;
			while(true)
				{
					if(current->data.prodID > item.prodID)
						{
							if(current->left == NULL)
								{
									current->left = temp;
								}
							current = current->left;
						}
						
					else if(current->data.prodID < item.prodID)
						{
							if(current->right == NULL)
								{
									current->right = temp;
								}
							current = current->right;
						}
						
					else
						{
							break;
						}
				}
		}
}
//Delete element in the BST base on the productID
//study this function
void removeElement(BST **list, int prodID)//using iterative method
{
	BST *current = *list;
	BST *parent = NULL;
	
	
	//the pointer current ang nag hold sa node na idelete!
	while (current != NULL && current->data.prodID != prodID)
		{
			parent = current;
			if(prodID < current->data.prodID)
				current = current->left;
			else
				current = current->right;	
		}	
	
	if(current == NULL) //if there is no matching
		return;
	
	if(current->left == NULL && current->right == NULL)
		{
			if(parent == NULL)
				*list = NULL;
			
			else if(parent->left == current)
				parent->left = NULL;
			else parent->right = NULL;
			
			free(current);
		}
		
 else if (current->left == NULL) {
        if (parent == NULL)
            *list = current->right;
        else if (parent->left == current)
            parent->left = current->right;
        else
            parent->right = current->right;

        free(current);
    } else if (current->right == NULL) {
        if (parent == NULL)
            *list = current->left;
        else if (parent->left == current)
            parent->left = current->left;
        else
            parent->right = current->left;

        free(current);
    }
    // Case 3: Node to be removed has two children
    else {
        BST *successor = current->right;
        BST *successorParent = current;

        while (successor->left != NULL) {
            successorParent = successor;
            successor = successor->left;
        }

        current->data = successor->data;

        if (successorParent->left == successor)
            successorParent->left = successor->right;
        else
            successorParent->right = successor->right;

        free(successor);
    }
}
BST *deleteElement(BST *list, int prodID)//using recursive method
{	
	if (list == NULL)
		return NULL;
		
	if(prodID < list->data.prodID)
		{
			list->left = deleteElement(list->left, prodID);
		}
	else if (prodID > list->data.prodID)
		{
			list->right = deleteElement(list->right, prodID);
		}
		
		//no children and idelete na node
	else
		{
			if (list->left == NULL && list->right == NULL) {
				BST *temp = list->right;
            	free(list);
            	return temp;
        	}
        	
        //naay usa ka child
			else if(list->right == NULL)
				{
					BST *temp = list->left;
					free(list);
					return temp;
				}
			
		//two children
			else 
				{
					BST *temp = min(list->right);
					list->data = temp->data;
					list->right = deleteElement(list->right, temp->data.prodID);
				}
		}	
		return list;
}


//Display BST all in recursive method
void inorderBST(BST *list)
{
	if(list == NULL){
		return;
	}

		inorderBST(list->left);
		displayProduct(list->data);
		inorderBST(list->right);

}
void preorderBST(BST *list)
{
	if(list == NULL){
		return;
	}
		displayProduct(list->data);
		inorderBST(list->left);
		inorderBST(list->right);
}

void postorderBST(BST *list)
{
	if(list == NULL){
		return;
	}
	printf("{<%5s> | %20s<%s>}\n", "PRODUCT ID", " ", "PRODUCT NAME");
	printf("------------------------------------\n");
	
		inorderBST(list->left);
		inorderBST(list->right);
		displayProduct(list->data);
}

//other functions
BST *newBST()
{
	BST *list = NULL;
	printf("SUCCESSFULLy INITIALIZED");
	return list;
}

void initBST(BST **list)
{
	*list = NULL;
	printf("SUCCESSFULLY INITIALIZED");
}

bool isEmpty(BST *list)
{
	return list == NULL;
}

Product createProduct(int id, char *name, int qty, float price)
{
	Product newProd;
	newProd.prodID = id;
	strcpy(newProd.prodName, name);
	newProd.prodQty = qty;
	newProd.prodPrice = price;
	
	printf("\nSUCCESSFULLY CREATED A NEW PRODUCT");
	return newProd;
}

//use the following format {<id> | <prodName>} replacing the angular brackets with data
void displayProduct(Product prod)
{

	printf("{<%5d> | %20s<%s>}\n", prod.prodID, "", prod.prodName);	
}

BST *max(BST *list)
{
	if(list == NULL)
		return NULL;
		
	while(list->right != NULL)
		{
			list = list->right;
		}
	return list;
}

BST *min(BST *list)
{
	if(list == NULL)
		return NULL;
		
	while(list->left != NULL)
		{
			list = list->left;
		}
	return list;
}

bool isMember(BST *list, int prodID)
{
    if (list == NULL)
        return false;

    while (list != NULL)
    {
        if (prodID == list->data.prodID)
            return true;
        else if (prodID < list->data.prodID)
            list = list->left;
        else
            list = list->right;
    }

    return false; // Product ID not found
}


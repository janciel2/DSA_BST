#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int choice = 1;
	
	BSTPtr newBSTemp = newBST();


	Product newProd = createProduct(1,"Aqua Flask", 100, 500.50);
	Product newProd2 = createProduct(10,"Hydro Flask", 300, 700.50);
	Product newProd3 = createProduct(5,"Tsinelas", 300, 700.50);
	
	newBSTemp = addElement(newBSTemp, newProd);
	newBSTemp = addElement(newBSTemp, newProd2);
	newBSTemp = addElement(newBSTemp, newProd3);
	
	printf("{<%5s> | %20<%s>}\n", "PRODUCT ID", "PRODUCT NAME");
	printf("------------------------------------\n");
//	inorderBST(newBSTemp);
//	preorderBST(newBSTemp);
	postorderBST(newBSTemp);
	
	
	
	Product newProd4 = createProduct(3,"Apple Cider", 10, 400.50);
	Product newProd5 = createProduct(7,"Mango Float", 250, 150.50);
	Product newProd6 = createProduct(21,"Grahams", 70, 70.50);
	
	insertBST(&newBSTemp, newProd4);
	insertBST(&newBSTemp, newProd5);
	insertBST(&newBSTemp, newProd6);

	postorderBST(newBSTemp);
	deleteElement(newBSTemp, 7);
	postorderBST(newBSTemp);


	
	return 0;
}

/*
 * bst_min_max_element.c
 *
 *  Created on: Jul 21, 2017
 *      Author: khushbu
 */


#include<stdio.h>
#include<stdlib.h>

struct bnode
{
	struct bnode *left;
	int data;
	struct bnode *right;

};

void insert(struct bnode **root, int num)
{
	if((*root) == NULL)
	{
		(*root) = (struct bnode*)malloc(sizeof(struct bnode));
		(*root)->data = num;
		(*root)->left = NULL;
		(*root)->right = NULL;
	}

	else if(num <= (*root)->data)
	{
		insert((&(*root)->left), num);
	}
	else
	{
		insert(&((*root)->right), num);;
	}
}

void in_order(struct bnode *root)
{
	if(root != NULL)
	{
		in_order(root->left);
		printf("%d\t", root->data);
		in_order(root->right);
	}
}

void pre_order(struct bnode *root)
{
	if(root != NULL)
	{
		printf("%d\t", root->data);
		in_order(root->left);
		in_order(root->right);
	}
}

void post_order(struct bnode *root)
{
	if(root != NULL)
	{
		in_order(root->left);
		in_order(root->right);
		printf("%d\t", root->data);
	}
}

void minimum(struct bnode *root)
{

	while(root->left != NULL)
	{
		root = root->left;
	}
	printf("\nMinimum element of the tree is %d\n", root->data);
}

void maximum(struct bnode *root)
{

	while(root->right != NULL)
	{
		root = root->right;
	}
	printf("\nMaximum element of the tree is %d\n", root->data);
}

int height(struct bnode *root)
{

	if(root == NULL)
	{
		return 0;
	}
	int lheight = height(root->left);
	int rheight = height(root->right);
 	if(lheight > rheight)
	{
		return(lheight + 1);
	}
	else if(rheight > lheight)
	{
		return(rheight + 1);
	}
	else if(lheight == rheight)
	{
		return(rheight + 1);
	}
 	return 0;
}

void secondLargestUtil(struct bnode *root, int *c)
{
    // Base cases, the second condition is important to
    // avoid unnecessary recursive calls
    if (root == NULL || *c >= 2)
        return;

    // Follow reverse inorder traversal so that the
    // largest element is visited first
    secondLargestUtil(root->right, c);

    // Increment count of visited nodes
    (*c)++;

    // If c becomes k now, then this is the 2nd largest
    if (*c == 2)
    {
         printf("2nd largest element is %d\n", root->data);
         return;
    }

    // Recur for left subtree
    secondLargestUtil(root->left, c);
}

void secondSmallestUtil(struct bnode *root, int *c)
{
    // Base cases, the second condition is important to
    // avoid unnecessary recursive calls
    if (root == NULL || *c >= 2)
        return;

    // Follow reverse inorder traversal so that the
    // largest element is visited first
    secondSmallestUtil(root->left, c);

    // Increment count of visited nodes
    (*c)++;

    // If c becomes k now, then this is the 2nd largest
    if ((*c) == 2)
    {
         printf("2nd smallest element is %d\n", root->data);
         return;
    }

    // Recur for left subtree
    secondSmallestUtil(root->right, c);
}

int main()
{
	int c = 0;
	int k = 0;
	struct bnode *root = NULL;
	insert(&root, 50);
	insert(&root, 40);
	insert(&root, 43);
	insert(&root, 42);
	insert(&root, 35);
	insert(&root, 1);
	insert(&root, 10);
	insert(&root, 60);
	insert(&root, 70);
	insert(&root, 100);
	insert(&root, 98);
	insert(&root, 104);
	printf("In_order BST before deletion\n");
	in_order(root);
	printf("\n\nPre_order BST before deletion\n");
	pre_order(root);
	printf("\n\nPost_order BST before deletion\n");
	post_order(root);
	printf("\n");
	minimum(root);
	maximum(root);
	int theight = height(root);
	printf("\nHeight of the binary tree is %d\n", theight);
	secondLargestUtil(root, &c);
	secondSmallestUtil(root, &k);
}

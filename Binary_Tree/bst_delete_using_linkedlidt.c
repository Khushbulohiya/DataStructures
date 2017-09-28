/*
 * bst_linkedlist.c
 *
 *  Created on: Jul 20, 2017
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
	if(*root == NULL)
	{
		(*root) = (struct bnode*)malloc(sizeof(struct bnode));
		(*root)->data = num;
		(*root)->left = NULL;
		(*root)->right = NULL;
	}
	else if(num <= (*root)->data)
	{
		insert(&((*root)->left), num);
	}
	else
	{
		insert(&((*root)->right), num);
	}
}

void level_bst(struct bnode *root, int level, int initial_level) // the initial level is going to be zero initially
{
	struct bnode *current = root;
    if (current == NULL)
    {
        return;
    }
    if (level == initial_level)
	{
        printf("%d\t", current->data);
        return;
	}
    level_bst(current->left, level, initial_level + 1);
    level_bst(current->right,level, initial_level + 1);
}

//returns the address of the node to be deleted, address of its parent and whether the node is found or not
void serach(struct bnode **root, int num, struct bnode **parent, struct bnode **x, int *found)
{
	struct bnode *q;
	q = *root;
	*parent = NULL;
	*found = 0;
	while(q != NULL)
	{
		if(q->data == num)
		{
			*found = 1;
			*x = q;
			return;
		}
		*parent = q;
		if(q->data > num)
		{
			q = q->left;
		}
		else
		{
			q = q->right;
		}
	}
}

void delete(struct bnode **root, int num)
{
	int found;
	struct bnode *parent, *xsucc, *x;
	x = *root;
	serach(root, num, &parent, &x, &found);
	if(found == 0)
	{
		printf("\nNumber %d is not present in the tree and so no deletion of the element is possible.\n\n",num);
		return;
	}
	else
	{
		printf("\nNumber %d is present in the tree.\n\n",num);
	}

	// If the node to be deleted has both children
	if(x->left != NULL && x->right != NULL)
	{
		parent = x;
		// successor of the node to be deleted is leftmost of right child
		xsucc = x->right;

		// the successor will be leftmost of right child of the node to be deleted
		while(xsucc -> left != NULL)
		{
			parent = xsucc;
			xsucc = xsucc->left;
		}
		x->data = xsucc->data;
		free(xsucc);
	}
	// if left of node to be deleted is not null but right child is null
	else if(x->left != NULL && x->right == NULL)
	{

		if(parent->left == x)
		{
			parent->left = x->left;
		}
		else
		{
			parent->right = x->left;
		}
		free(x);
		return;
	}

	else if(x->left == NULL && x->right != NULL)
	{
		if(parent->left == x)
		{
			parent->left = x->right;
		}
		else
		{
			parent->right = x->right;
		}
		free(x);
		return;
	}
	else if(x->left == NULL && x->right == NULL)
	{
		if(parent->left == x)
		{
			parent->left = NULL;
		}
		else
		{
			parent->right = NULL;
		}
		free(x);
		return;
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

int main()
{
	struct bnode *root = NULL;

	insert(&root, 15);
	insert(&root, 10);
	insert(&root, 20);
	insert(&root, 25);
	insert(&root, 8);
	insert(&root, 12);

	printf("In_order BST before deletion\n");
	in_order(root);
	printf("\n\nPre_order BST before deletion\n");
	pre_order(root);
	printf("\n\nPost_order BST before deletion\n");
	post_order(root);
	printf("\n");
	level_bst(root, 1, 0);
	delete(&root, 10);
	printf("In_order BST after deletion\n");
	in_order(root);
	printf("\n\nPre_order BST after deletion\n");
	pre_order(root);
	printf("\n\nPost_order BST after deletion\n");
	post_order(root);
	printf("\n");
}



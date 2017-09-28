#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define boolean int 
#define false 0
#define true 1

struct node{
	int data;
	struct node *right;
	struct node *left;
};

boolean ismirror(struct node *aroot, struct node *broot)
{
	if(aroot == NULL && broot == NULL)
	{
		return true;
	}

	else if(aroot != NULL && broot != NULL)
	{
		return(aroot->data == broot->data && ismirror(aroot->left, broot->right) && ismirror(aroot->right, broot->left));
	}

	else
	{
		return false;
	}

}

//Means two trees are structually same
boolean issame(struct node *aroot, struct node *broot)
{

	if(aroot == NULL && broot == NULL)
	{
		return true;
	}

	else if(aroot != NULL && broot != NULL)
	{
		return(aroot->data == broot->data && issame(aroot->left, broot->left) && issame(aroot->right, broot->right));
	}

	else
	{
		return false;
	}
}

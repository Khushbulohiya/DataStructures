
#include<stdio.h>
#include<stdlib.h>

struct bnode
{
	struct bnode *left;
	int data;
	struct bnode *right;
};

void level_bst(struct node *root, int level, int initial_level) // this level is goinng to be zero initially
{
    if (root == NULL)
    {
        return;
    }
    if (level == initial_level)
	{
        printf("%d\t", root->data);
        return;
	}
    level_bst(root->left, level, (initial_level + 1));
    level_bst(root->right,level, (initial_level + 1));
}



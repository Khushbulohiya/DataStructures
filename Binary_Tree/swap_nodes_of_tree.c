/*
 * swap_nodes_of_tree.c
 *
 *  Created on: Sep 3, 2017
 *      Author: khushbu
 */


//make mirror tree using the given tree
void mirror(struct node* node) {
  if (node == NULL) {
    return;
} else {
    struct node* temp;
    // do the subtrees
    mirror(node->left);
    mirror(node->right);
    // swap the pointers in this node
    temp = node->left;
    node->left = node->right;
    node->right = temp;
} }

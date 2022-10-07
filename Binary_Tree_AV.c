// Tree traversal in C
#include <stdio.h>
#include <stdlib.h>

/*

Abhi Vachani
Binary Tree
Computer Systems Organization
Prof. Kayar

*/


// node definition
struct node {

  int data;
  struct node* left;
  struct node* right;

};


// Inorder traversal
void printInorderTraversal(struct node* root) {

  if (root != NULL) {
    printInorderTraversal(root->left);
    printf("%3d", root->data);
    printInorderTraversal(root->right);

  }

}

// Preorder traversal
void printPreorderTraversal(struct node* root) {

  if (root != NULL) {
    printf("%3d", root->data);
    printPreorderTraversal(root->left);
    printPreorderTraversal(root->right);

  }

}

// Postorder traversal
void printPostorderTraversal(struct node* root) {

  if (root != NULL) {
    printPostorderTraversal(root->left);
    printPostorderTraversal(root->right);
    printf("%3d", root->data);
    
  }

}

// Create a new Node
struct node* createNode(value) {

  // create new node (root to begin with) dynamically allocating memory
  struct node* root = malloc(sizeof(struct node));

  // assign value to root
  root->data = value;

  // point left and right of root to NULL
  root->left = NULL;
  root->right = NULL;

  // return root
  return root;

}

// Insert on the left of the node
struct node* insertLeft(struct node* root, int value) {

  // create new node with value given
  root->left = createNode(value);

  // assign new nodes data to value
  (root->left)->data = value;

  // return
  return root->left;


}

// Insert on the right of the node
struct node* insertRight(struct node* root, int value) {

  // create new node with value given
  root->right = createNode(value);

  // assign new nodes data to value
  (root->right)->data = value;

  // return 
  return root->right;
}

int main() {
  // Will manually build the tree as given below using functions above
  //         1
  //       /   \
  //      2     3
  //     / \   / \
  //    4   5 6   7



  // create root 
  struct node *root = createNode(1);

  // create values at depth 1
  struct node *left_1 = insertLeft(root, 2);
  struct node *right_1 = insertRight(root, 3);



  // create values at depth 2
  struct node *left_most = insertLeft(left_1, 4);
  struct node *right_middle = insertRight(left_1, 5);
  struct node *left_middle = insertLeft(right_1, 6);
  struct node *right_most = insertRight(right_1, 7);




  printf("Inorder traversal   -> ");
  printInorderTraversal(root);

  printf("\nPreorder traversal  -> ");
  printPreorderTraversal(root);

  printf("\nPostorder traversal -> ");
  printPostorderTraversal(root);

  printf("\n");


}

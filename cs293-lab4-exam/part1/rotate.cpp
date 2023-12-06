// Problem 2

// Do not include any other file
#include "bst.h"

//post-order traverse
void getHeight(TreeNode* root){
  if(root == NULL)
    return;
  if(root->right == NULL && root->left == NULL){ //leaf
    root->field1 = 0;
    return;
  }
  else if(root->right == NULL){ //single child left present
    getHeight(root->left);
    root->field1 = root->left->field1+1;
    return;
  }
  else if(root->left == NULL){ //single child right present
    getHeight(root->right);
    root->field1 = root->right->field1+1;
    return;
  }
  else{
    getHeight(root->left);
    getHeight(root->right);
    if(root->left->field1 >= root->right->field1)
      root->field1 = root->left->field1 + 1;
    else  
      root->field1 = root->right->field1 + 1;
    return;
  }
}

bool BST::rotate(int y_key) {
  //we find the key
  TreeNode* curr = root;
  while(curr->key!=y_key){
    if(curr->key < y_key){
      if(curr->right==NULL)
        return false; //this means y_key not present so the question is meaningless
      else
        curr = curr->right;
    }
    if(curr->key > y_key){
      if(curr->left==NULL)
        return false; //this means y_key not present so the question is meaningless
      else
        curr = curr->left;
    }
  }
  //now at this point curr points to y
  //now we first check if the tree is rotatable. ie height of curr->parent < transformed height of curr
  getHeight(root); //gets the height map
  int height_x,height_a,height_b,height_c;
  if(curr->parent != NULL)
    height_x = curr->parent->field1;
  else
    return false; //no parent 

  if(curr->left != NULL)
    height_b = curr->left->field1;
  else
    height_b = -1;

  if(curr->right != NULL)
    height_c = curr->right->field1;
  else
    height_c = -1;

  //make cases based on whether y is left or right child
  if(curr == curr->parent->right){
    if(curr->parent->left != NULL)
      height_a = curr->parent->left->field1;
    else  
      height_a = -1;
  }
  else{
    if(curr->parent->right != NULL)
      height_a = curr->parent->right->field1;
    else  
      height_a = -1;
  }
  int height_y_new = max(max(height_a+1,height_b+1),height_c) + 1;
  

  if(height_x < height_y_new){
    //now we implement tree rotate. Clearly since we have reached here curr has a parent so we needn't bother
    if(curr == curr->parent->right){
      TreeNode* x = curr->parent;

      x->right = curr->left;
      if(curr->left != NULL)
        curr->left->parent = x;

      if(x == root){
        curr->left = x;
        x->parent = curr;
        root = curr;
      }
      else if(x == x->parent->right){
        x->parent->right = curr;
        curr->left = x;
        x->parent = curr;
      }
      else{ //x = x->parent->left
        x->parent->left = curr;
        curr->left = x;
        x->parent = curr;
      }
    }
    else{
      TreeNode* x = curr->parent;

      x->left = curr->right;
      if(curr->right!= NULL)
        curr->right->parent = x;

      if(x == root){
        curr->left = x;
        x->parent = curr;
        root = curr;
      }
      else if(x == x->parent->right){
        x->parent->right = curr;
        curr->right = x;
        x->parent = curr;
      }
      else{ //x = x->parent->left
        x->parent->left = curr;
        curr->right = x;
        x->parent = curr;
      }

    }
    return true;
  }
  else
    return false;

  

}

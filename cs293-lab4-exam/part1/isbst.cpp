// Problem 1

#include "bst.h"


void inorder(TreeNode* root, vector<double>&inorderValues){
  if(root == NULL)
    return;
  inorder(root->left,inorderValues);
  inorderValues.push_back(root->key);
  inorder(root->right,inorderValues);
}

bool BST::isBST() {
  int i = 1;
  vector<double> inorderValues; 
  inorderValues.clear();
  inorder(root,inorderValues);
  while(i<(int)inorderValues.size()){
    if(inorderValues[i]<inorderValues[i-1])
      return false;
    i++;
  }
  return true;
}

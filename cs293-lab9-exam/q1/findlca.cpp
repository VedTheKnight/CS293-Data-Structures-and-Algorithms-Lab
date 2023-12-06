#include "tree.h"

//create a level map
int getLevel(TreeNode* a){
  int level = 0;
  while(a->parent!=nullptr){
    a = a->parent;
    level++;
  }
  return level;
}

// Function which returns lca node of given nodes 'a' and 'b'
TreeNode* TREE::findlca(TreeNode* a, TreeNode* b) {
  TreeNode* lca = nullptr;

  if(a==nullptr || b==nullptr){
    return nullptr;
  }
  
  int level_a = getLevel(a);
  int level_b = getLevel(b);

  //find the lower level and bring both to the same level
  if(level_a>level_b){
    while(level_a>level_b){
      a = a->parent;
      level_a--;
    }
  }
  else if(level_b>level_a){
    while(level_b>level_a){
      b = b->parent;
      level_b--;
    }
  }

  //now that they are at the same level, we keep going up until we hit the lca
  if(a==b)
    return a;

  while(a!=root && b!=root){
    a = a->parent;
    level_a--;
    b = b->parent;
    level_b--;
    if(a==b){
      lca = a;
      break;
    }
  }
  if(a==root){
    return nullptr;
  }
  return lca;
}
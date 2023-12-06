#include <iostream>
#include "TreeTraversal.h"
#include <string>
#include <cstring>
using namespace std;

Tree::Tree () {
  root = new struct Node;
  root -> c = ' ';
  root -> left = NULL;
  root -> right = NULL;
}

struct Node* Tree::deduce_tree (char* pre_order, char* in_order, int N) {
  Node* localRoot = new struct Node;
  char tempRoot = pre_order[0];
  localRoot -> c = tempRoot;
  if (N == 0) {
    return localRoot;
  }
  int i;
  for (i = 0; i < N; i++) {
    if (tempRoot == in_order[i]) {
      break;
    }
  }
  if (i == N) {
    return NULL;
  }
  char rightInOrder[N - i];
  for (int j = i + 1; j < N; j++) {
    rightInOrder[j - i - 1] = in_order[j];
  }
  rightInOrder[N - i - 1] = '\0';
  char rightPreOrder[N - i];
  for (int j = N - 1; j > i; j--) {
    rightPreOrder[j - i - 1] = pre_order[j];
  }
  rightPreOrder[N - i - 1] = '\0';
  localRoot -> right = deduce_tree(rightPreOrder,rightInOrder,N - i - 1);
  char leftInOrder[i + 1];
  for (int j = 0; j < i; j++) {
    leftInOrder[j] = in_order[j];
  }
  leftInOrder[i] = '\0';
  char leftPreOrder[i + 1];
  for (int j = i; j > 0; j--) {
    leftPreOrder[j - 1] = pre_order[j];
  }
  leftInOrder[i] = '\0';
  localRoot -> left = deduce_tree(leftPreOrder,leftInOrder,i);
  return localRoot;
}

void Tree::external (TraversalType_e tt, struct Node* myroot) {
  if (myroot == NULL) {
    return;
  }
  cout << myroot -> c;
}

void Tree::left (TraversalType_e tt, struct Node* myroot) {
  if (tt == PRE_ORDER) {
    external(tt,myroot);
  }
}

void Tree::right (TraversalType_e tt, struct Node* myroot) {
  if (tt == POST_ORDER) {
    external(tt,myroot);
  }
}

void Tree::below (TraversalType_e tt,struct Node* myroot) {
  if (tt == IN_ORDER) {
    external(tt,myroot);
  }
}

void Tree::traverse (TraversalType_e tt, struct Node* myroot) {
  if (myroot == NULL) {
    return;
  }
  if (tt == PRE_ORDER) {
    left(tt,myroot);
    traverse(tt,myroot -> left);
    traverse(tt,myroot -> right);
  }
  else if (tt == IN_ORDER) {
    traverse(tt,myroot -> left);
    below(tt,myroot);
    traverse(tt,myroot -> right);
  }
  else if (tt == POST_ORDER) {
    traverse(tt,myroot -> left);
    traverse(tt,myroot -> right);
    right(tt,myroot);
  }
}

int main () {
  string pre, in;
  cin >> pre >> in;
  if (pre.length() != in.length()) {
    cout << "Invalid pair of traversals." << endl;
  }
  int N = pre.length();
  char preOrder[N], inOrder[N];
  strcpy(preOrder,pre.c_str());
  strcpy(inOrder,in.c_str());
  Tree T(preOrder,inOrder,N);
  struct Node* root = T.giveRoot();
  T.traverse(PRE_ORDER,root);
  cout << endl;
  T.traverse(IN_ORDER,root);
  cout << endl;
  T.traverse(POST_ORDER,root);
  cout << endl;
}
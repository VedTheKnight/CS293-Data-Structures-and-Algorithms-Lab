#include "rb.h"
using ptr = RedBlackTree::ptr;

RedBlackTree::RedBlackTree(){}

const ptr RedBlackTree::getRoot() const
{
	return root; 
}

//this is a normal BST insertion and calls the fixup function at the end of the insertion if there is a red-red violation
ptr RedBlackTree::insert(int data)
{
	ptr newnodePtr = new node(data);
	if (!root) { //if root is null this executes
		root = newnodePtr;
		root->color = 0; // set root color as black
		return newnodePtr;
	}
	insert(root, newnodePtr);
	return newnodePtr;
}

// auxiliary function to perform RBT insertion of a node
// you may assume start is not nullptr
void RedBlackTree::insert(ptr start, ptr newnodePtr)
{
	// choose direction
	// recurse down the tree
	if(newnodePtr->data>=start->data){
		if(start->right!=nullptr)
			insert(start->right,newnodePtr);
		else{
			start->right = newnodePtr;
			newnodePtr->parent = start;
			return;
		}

	}
	else if(newnodePtr->data<start->data){
		if(start->left!=nullptr)
			insert(start->left,newnodePtr);
		else{
			start->left = newnodePtr;
			newnodePtr->parent = start;
			return;
		}
	}
}

// Credits to Adrian Schneider
void RedBlackTree::printRBT(ptr start, const std::string& prefix, bool isLeftChild) const
{
	if (!start) return;

	std::cout << prefix;
	std::cout << (isLeftChild ? "|--" : "|__" );
	// print the value of the node
	std::cout << start->data << "(" << start->color << ")" << std::endl;
	// enter the next tree level - left and right branch
	printRBT(start->left, prefix + (isLeftChild ? "│   " : "    "), true);
	printRBT(start->right, prefix + (isLeftChild ? "│   " : "    "), false);
}

// Function performing right rotation
// of the passed node
void RedBlackTree::rightrotate(ptr loc)
{
	ptr p = loc->parent;
	ptr gp = p->parent;
	if(gp!=nullptr){
		if(gp->right==p){
			//detach left child of loc
			ptr lc = loc->left;

			//make p the left child of loc
			loc->left = p;
			p->parent = loc;

			//make lc the right child of p
			p->right = lc;
			if(lc!=nullptr)
				lc->parent = p;

			//make loc the appropriate child of gp
			gp->right = loc;
			loc->parent = gp;
		}
		else if(gp->left==p){
			//detach left child of loc
			ptr lc = loc->left;

			//make p the left child of loc
			loc->left = p;
			p->parent = loc;

			//make lc the right child of p
			p->right = lc;
			if(lc!=nullptr)
				lc->parent = p;

			//make loc the appropriate child of gp
			gp->left = loc;
			loc->parent = gp;
		}
	}
	else{
		//detach left child of loc
		ptr lc = loc->left;

		//make p the left child of loc
		loc->left = p;
		p->parent = loc;

		//make lc the right child of p
		p->right = lc;
		if(lc!=nullptr)
			lc->parent = p;

		//make loc's parent null since that becomes the new root
		loc->parent = nullptr;
		root = loc; //since loc now becomes the new root
	}
}

// Function performing left rotation
// of the passed node
void RedBlackTree::leftrotate(ptr loc)
{
	ptr p = loc->parent;
	ptr gp = p->parent;
	if(gp!=nullptr){
		if(gp->right==p){
			//detach right child of loc
			ptr rc = loc->right;

			//make p the right child of loc
			loc->right = p;
			p->parent = loc;

			//make rc the left child of p
			p->left = rc;
			if(rc!=nullptr)
				rc->parent = p;

			//make loc the appropriate child of gp
			gp->right = loc;
			loc->parent = gp;
		}
		else if(gp->left==p){
			//detach right child of loc
			ptr rc = loc->right;

			//make p the right child of loc
			loc->right = p;
			p->parent = loc;

			//make rc the left child of p
			p->left = rc;
			if(rc!=nullptr)
				rc->parent = p;

			//make loc the appropriate child of gp
			gp->left = loc;
			loc->parent = gp;
		}
	}
	else{
		//detach right child of loc
		ptr rc = loc->right;

		//make p the right child of loc
		loc->right = p;
		p->parent = loc;

		//make rc the left child of p
		p->left = rc;
		if(rc!=nullptr)
			rc->parent = p;

		//make loc's parent null since that becomes the new root
		loc->parent = nullptr;
		root = loc; //since loc now becomes the new root
	}
}

// This function fixes violations
// caused by RBT insertion
void RedBlackTree::fixup(ptr loc)
{	

	//define some useful pointers
	if(loc==root){
		return;
	}
	if(loc->parent==root){
		return;
	}

	ptr parent = loc->parent; 
	ptr grand_parent = loc->parent->parent; 

	//we have to work only if parent is red
	if(parent->color == 1){
		if(parent == grand_parent->right){
			//CASE 1:
			//if the parent's sibling exists and is red
			if(grand_parent->left != nullptr && grand_parent->left->color == 1){ //if the grandparent's left child exists
				grand_parent->left->color = 0;
				parent->color = 0;
				grand_parent->color = 1; //all colors are determined by the constraints of the problem itself

				//now depending on the grandparent's parents we have three cases
				//case 1: if grandparent was the root itself, we just change it's color to black
				if(grand_parent->parent == nullptr){
					grand_parent->color = 0;
					return;
				}
				//case 2: if parent of grandparent is black we are done and we do nothing
				if(grand_parent->parent->color == 0)
					return;
				//case 3: if parent of the grandparent is red we again have a red-red violation at loc = grand_parent
				if(grand_parent->parent->color == 1)
					fixup(grand_parent);
					return;
			}

			//CASE 2-3:
			//if the parent's sibling is not red i.e. it either doesn't exist or is black 
			else if(grand_parent->left == nullptr || (grand_parent->left!=nullptr && grand_parent->left->color == 0)){
				//non straight path : CASE 2
				if(loc==grand_parent->right->left){
					leftrotate(loc);
					//we have successfully converted the violation to CASE 3
					loc->parent->color = 1;
					loc->color = 0;
					rightrotate(loc);
				}
				//straight path : CASE 3 
				//note that we want a fall through from case 2 since we convert case 2 into case 3!
				else if(loc==grand_parent->right->right){
					grand_parent->color = 1;
					parent->color = 0;
					rightrotate(parent);
				}
			}

		}
		else if(parent == grand_parent->left){

			//CASE 1:
			//if the parent's sibling exists and is red
			if(grand_parent->right != nullptr && grand_parent->right->color == 1){ //if the grandparent's left child exists
				grand_parent->right->color = 0;
				parent->color = 0;
				grand_parent->color = 1; //all colors are determined by the constraints of the problem itself

				//now depending on the grandparent's parents we have three cases
				//case 1: if grandparent was the root itself, we just change it's color to black
				if(grand_parent->parent == nullptr){
					grand_parent->color = 0;
					return;
				}
				//case 2: if parent of grandparent is black we are done and we do nothing
				if(grand_parent->parent->color == 0)
					return;
				//case 3: if parent of the grandparent is red we again have a red-red violation at loc = grand_parent
				if(grand_parent->parent->color == 1)
					fixup(grand_parent);
					return;
			}

			//CASE 2-3:
			//if the parent's sibling is not red i.e. it either doesn't exist or is black 
			else if(grand_parent->right == nullptr || (grand_parent->right!=nullptr && grand_parent->right->color == 0)){
				//non straight path : CASE 2
				if(loc==grand_parent->left->right){
					rightrotate(loc);
					//we have successfully converted the violation to CASE 3
					loc->parent->color = 1;
					loc->color = 0;
					leftrotate(loc);
				}
				//straight path : CASE 3 
				//note that we want a fall through from case 2 since we convert case 2 into case 3!
				else if(loc==grand_parent->left->left){
					grand_parent->color = 1;
					parent->color = 0;
					leftrotate(parent);
				}

			}
		}
	}
	else
		return;
}

// Function to print inorder traversal
// of the fixated tree
void RedBlackTree::inorder(ptr start) const
{
	if (!start)
		return;
	
	inorder(start->left);
	std::cout << start->data << " ";
	inorder(start->right);
}

// driver code
int main()
{
	int n; std :: cin >> n;
	assert (n < 10000 && n >= 0);
	int a[10000];
	RedBlackTree tree;
	
	for (int i = 0; i < n; i++) {
		//std::cin >> a[i];
		a[i] = rand();

		// allocating memory to the node and initializing:
		// 1. color as red
		// 2. parent, left and right pointers as NULL
		// 3. data as i-th value in the array

		// calling function that performs rbt insertion of
		// this newly created node
		auto newnodePtr = tree.insert(a[i]);

		// calling function to preserve properties of rb
		// tree
		tree.fixup(newnodePtr); 
	}
	tree.printRBT(tree.getRoot());

	return 0;
}

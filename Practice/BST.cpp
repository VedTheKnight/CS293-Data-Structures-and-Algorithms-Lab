#include <iostream>
#include <queue>
#include <stack>
using namespace std;

/*1. insert(int JourneyCode, int price) : Insert a new node in your Binary Search Tree, representing this Journey with appropriate Journey Code and Cost, as mentioned.
2. find(int JourneyCode, int price) : Check if this (JourneyCode,Price) is present in your BST, and return True/False accordingly.
3. remove(int JourneyCode, int price) : Check if this Node is to be found in the BST, Delete it, if you can.
4. traverse(int type) : Traverse the BST in different ways depending on what type is.
5. getMinimum() : Return the price of cheapest journey.*/

struct Node{
    int JourneyCode=0;
    int price=0;
    struct Node* right = nullptr; //can drop struct since namespace std is called.
    struct Node* left = nullptr;
    struct Node* parent = nullptr; //needed for successor and predecessor
};

class BST{
    private:
        struct Node* root;

    public:
        BST(int JourneyCode, int price){
            root = new struct Node;
            root->JourneyCode = JourneyCode;
            root->price = price;
            root->left = nullptr;
            root->right = nullptr;
            root->parent = nullptr;
        }

        ~BST(){
            
        }

        struct Node* getRoot(){
            return root;
        }
        void insert(int JourneyCode, int price){
            struct Node* newNode = new struct Node;
            newNode->JourneyCode = JourneyCode;
            newNode->price = price;
            newNode -> left = nullptr;
            newNode -> right = nullptr;
            newNode->parent = nullptr;

            struct Node* curr = root;
            struct Node* parent = nullptr; //need this so we can explicitly link the parent with the child
            while(true){
                if(curr == nullptr){ //empty spot and can insert and stop
                    if(newNode->price > parent->price){
                        parent->right = newNode;
                        newNode->parent = parent;
                    }
                    else{
                        parent->left = newNode;
                        newNode->parent = parent;
                    }
                    break;
                }
                if(newNode->price > curr->price){
                    parent = curr;
                    curr = curr->right;
                }
                else{
                    parent = curr;
                    curr = curr->left;
                }
            }
        }

        bool find(int JourneyCode, int price){
            struct Node* curr = root;
            
            while(curr!=NULL){
                if(price == curr->price ){
                    if(JourneyCode == curr->JourneyCode)
                        return true;
                    else
                        return false; //this means the exact JourneyCode and price combo is not present in the BST.
                }
                if(price > curr->price){
                    curr = curr->right;
                }
                else{
                    curr = curr->left;
                }
            }
            return false;
        }

        void remove(int JourneyCode, int price){
            struct Node* curr = root;
            struct Node* parent = nullptr; //need this so we can explicitly link the parent with the child
            int flag = -1;
            while(curr!=NULL){
                if(price == curr->price ){
                    if(JourneyCode == curr->JourneyCode){
                        delete curr;
                        if(flag == 1)
                            parent->right = nullptr;
                        else    
                            parent->left = nullptr;
                    }
                    else{
                        cout << "Element not present in the BST!"<<"\n";
                        //this means the exact JourneyCode and price combo is not present in the BST.
                    }
                }
                if(price > curr->price){
                    parent = curr;
                    curr = curr->right;
                    flag = 1;
                }
                else{
                    parent = curr;
                    curr = curr->left;
                    flag = 0;
                }
            }
        }

        void traverse(int type,struct Node* node){
            if(node==nullptr)
                return;
            switch(type){
                case 1: //pre-order walk
                    cout<<node->JourneyCode<<" "<<node->price<<"\n";
                    traverse(1,node->left);
                    traverse(1,node->right);
                    break;
                case 2: //post-order walk
                    traverse(2,node->left);
                    traverse(2,node->right);
                    cout<<node->JourneyCode<<" "<<node->price<<"\n";
                    break;
                case 3: //in-order walk
                    traverse(3,node->left);
                    cout<<node->JourneyCode<<" "<<node->price<<"\n";
                    traverse(3,node->right);
            }
        }

        void getMinimum(struct Node* node){
            struct Node* curr = node;
            while(curr->left != nullptr){
                curr = curr->left;
            }
            cout<<curr->JourneyCode<<" "<<curr->price<<"\n";

        }

        void getMaximum(struct Node* node){
            struct Node* curr = node;
            while(curr->right != nullptr){
                curr = curr->right;
            }
            cout<<curr->JourneyCode<<" "<<curr->price<<"\n";

        }


        void getSuccessor(struct Node* node){
            struct Node* parent = node->parent;
            if(node->right!=nullptr){
                getMinimum(node->right);
            }
            while(parent!=NULL and parent->right == node){
                node = parent;
                parent = node->parent;
                if(parent == root)
                    cout<<"There is no successor";
            }
            cout<<parent->JourneyCode<<" "<<parent->price<<"\n";
        }

        void getPredecessor(struct Node* node){
            struct Node* parent = node->parent;
            if(node->left!=nullptr){
                getMaximum(node->left);
            }
            while(parent!=NULL and parent->left == node){
                node = parent;
                parent = node->parent;
                if(parent == root)
                    cout<<"There is no predecessor";
            }
            cout<<parent->JourneyCode<<" "<<parent->price<<"\n";
        }

        void LevelOrderTraversal(){
            queue<struct Node*> q;
            struct Node* curr = root;
            q.push(curr);
            if(root == nullptr)
                return;
            
            while(q.size()>0){
                curr = q.front();
                q.pop();
                cout<<curr->JourneyCode<<" "<<curr->price<<"\n";
                if(curr->left!=nullptr)
                    q.push(curr->left);
                if(curr->right!=nullptr)
                    q.push(curr->right);
            }
        }

        void DepthFirstTraversal(){
            stack<struct Node*> s;
            //similar to level order traversal.
        }
};

int main(){
    BST b(1,300);
    b.insert(2,600);
    b.insert(3,450);
    b.insert(4,150);
    b.insert(5,700);
    b.insert(6,75);

    //b.traverse(3,b.getRoot());
    b.LevelOrderTraversal();
    /*cout<<b.find(3,450)<<"\n";
    b.remove(4,450);
    b.remove(3,450);
    cout<<b.find(3,450)<<"\n";*/
    
    return 0;
}
#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

node* newLinkedList(){
    node* header = new node; // creates a pointer to a structure
    header->data = 0;
    header->next = NULL;
    return header; 
}// the first node is a dummy node

void appendNode(node* header, int value){
    node* q = header;

    node *p = new node; // creates a new node to put at the end of the linked list
    p->data = value;
    p->next = NULL;

    while(q->next!=NULL){
        q = q->next;
    }

    q->next = p;
}

void displayList(node* header){
    node *q = header;
    if(header == NULL){ 
        cout<<"This list doesn't exist";
        return;
    }
    if(header->next == NULL){
        cout<<endl<<"The list is empty";
        return;
    }
    cout<<endl;
    while(q!=NULL){
        if(q!=header)
            cout<<q->data<<" ";
            q = q->next;
    }

}

bool deleteLastNode(node* header){
    
    node *curr = header;
    node *prev;
    if(header->next == NULL) // no elements in the linked list
        return false;

    while(curr->next != NULL){
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    delete curr; //frees the memory

    return true;
}

void deleteLinkedList(node* header){

    do{
        bool flag = deleteLastNode(header);
        if(flag == false){
            break;
        }
        displayList(header);
    }while(true);

    delete header;
}

node* reverseLinkedList(node *header){
    if(header == NULL){ 
        cout<<"No elements in the linked list";
        return header;
    }
    node* curr = header;
    node* prev = NULL;
    node* next = NULL;

    while(curr!=NULL){
        next = curr->next;

        if(prev == header) curr->next = NULL;
        else curr->next = prev; // this is to ensure that the old header is not a part of the reversed linked list

        prev = curr;
        curr = next;
    }

    node* rev_header = new node;
    rev_header->data = 0;
    rev_header->next = prev;
    return rev_header;

}

int findMiddleElement(node *header){ //only works if the middle element of the linked list uniquely exists
    node *one_jump = header;
    node *two_jump = header;

    while(two_jump!=NULL){
        one_jump = one_jump->next;
        two_jump = two_jump->next->next;
    }

    return one_jump->data;
}

int main(){

    node *header = newLinkedList();
    appendNode(header,5);
    appendNode(header,4);
    appendNode(header,7);
    appendNode(header,9);
    appendNode(header,11);
    displayList(header);
    
    cout<<endl<<"Middle Element : "<<findMiddleElement(header);

    return 0;
}
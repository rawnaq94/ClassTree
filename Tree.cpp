#include <iostream>
#include "Tree.hpp"
#include "Node.hpp"
#include <stddef.h>   // For NULL

using namespace std;

namespace ariel {

   Tree::Tree() {

      Troot = NULL;
      len = 0;
   }
   
   Tree::~Tree() {

      if (Troot == NULL) { // if we remove manually so the Troot point to Null - we have to delete him 

         // cout <<"deleted Tree" << endl;
         delete Troot;
      } else {

         destroy(Troot);
      }
   }
   
   void Tree::destroy(Node *t) {

      if (t != NULL) {

         destroy(t->left);
         destroy(t->right);
         //cout <<"delete" << t->data << endl;
         delete(t);
      }
   }

   Tree& Tree::insert(int i) {

      // if the tree contains i => exception
      if (contains(i)) {

         throw("The number is already exists");
      }

      Node *newNode = new Node(i);
      bool inserted = false;
      if (Troot == NULL) {

         Troot = newNode;
         newNode->left = NULL;
         newNode->right = NULL;
      } else {

         Node *current = Troot;

         while (current != NULL && !inserted) {

            if (i < current->data) {
               if (current->left == NULL) {

                  current->left = newNode;
                  inserted = true;
               }
               current = current->left;

            } else {

               if (i > current->data) {
                  if (current->right == NULL) {

                     current->right = newNode;
                     inserted = true;
                  }
                  current = current->right;
               }
            }
         }
      }

      len++;
      return *this;
   }


   Tree & Tree::remove(int i) {

               // if the tree not conatins i => exception

      if (!contains(i)) {

         throw("The number is not exists");
      }
      // if Troot is the last element so it will point to Null for keep option for add elements instead of delete
      Delete(Troot, i);
      len--;
      return *this;
   }
   
   // Function to search a delete a value from tree.
Node* Tree::Delete(Node *root, int data) {
	if(root == NULL) return root; 
	else if(data < root->data) root->left = Delete(root->left,data);
	else if (data > root->data) root->right = Delete(root->right,data);
	// Wohoo... I found you, Get ready to be deleted	
	else {
		// Case 1:  No child
		if(root->left == NULL && root->right == NULL) { 
			root = NULL;
		}
		//Case 2: One child 
		else if(root->left == NULL) {
			Node *temp = root;
			root = root->right;
		}
		else if(root->right == NULL) {
			Node *temp = root;
			root = root->left;
		}
		// case 3: 2 children
		else { 
			Node *temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}
	}
	return root;
}
   
      Node *Tree::FindMin(Node * current) {
      while (current->left != NULL)
         current = current->left;
      return current;
   }

   int Tree::size() {

      return len;
   }
   
   bool Tree::contains(int i) {

      Node *current = Troot;

      while (current != NULL) {

         if (current->data == i) {

            return true;
         }
         
         if (i < current->data) {

            current = current->left;
         } else {

            if (i > current->data) {

               current = current->right;
            }
         }
      }
      return false;
   }
   
   int Tree::root() {

      if(Troot==NULL){
         
         throw("the root is null");
      }
         
      return Troot->data;
   }
   
   int Tree::parent(int i) {

      if (Troot == NULL) {

         throw("the tree is empty");

      }
      
      if (Troot->data == i) {

         throw("the root doesn't have parent");

      }

      if (!contains(i)) {

         throw("the number is not exist");

      }

      Node *current = Troot;

      while (current != NULL) {

         if (left(current->data) == i || right(current->data) == i) {

            return current->data;
         }

         if (i < left(current->data)) {
            current = current->left;
         } else {
            current = current->right;
         }
      }
      return 0;
   }
   
   int Tree::left(int i) {

      Node *current =getNode(i);
      if(current->left==NULL){
         
         throw("there is no left child to ");
      }else{
         return (current->left)->data;   
      }
   }
   
   int Tree::right(int i) {

      Node *current =getNode(i);
      if(current->right==NULL){
         
         throw("there is no right child to ");
      }
      else{
         return (current->right)->data;   
      }
   }
   
   void Tree::print() {
      cout << "inOrder : ";
	   inOrder(Troot);
   }
	
	void Tree::inOrder(Node * t) {

      if (t != NULL) {

         inOrder(t->left);
         cout << "--" << t->data;
         inOrder(t->right);
      }
   }

     Node* Tree::getNode(int i) {

      if (Troot == NULL) {

         throw("the tree is empty");

      }

      if (!contains(i)) {

         throw("the number is not exist");

      }

      Node *current = Troot;

      while (current != NULL) {

         if (current->data == i) {
            return current;
         }

         if (i < current->data) {
            current = current->left;
         } else {
            current = current->right;
         }

      }
      return current;
  }
};

// int main(int x){

//     using namespace ariel;


//   Tree ourTree;
//   ourTree.insert(6);
//   ourTree.insert(2);
//   cout << ourTree.root()<< endl;
//   ourTree.remove(6);

//     return 0;

// }

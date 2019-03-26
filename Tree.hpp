#include <stddef.h> // for NULL

class Node
{
public:
    int data;
    Node* right;
    Node* left;
    
    Node(int i){
        
        data=i;
        right=NULL;
        left=NULL;
    }
};


namespace ariel{
#include "Node.hpp"

    class Tree{
        
        private:
        
        int len;
        Node* Troot;
        Node* Delete(Node *root, int data);
        Node* FindMin(Node* root);
        void inOrder(Node* t);
        Node* getNode(int i);
        
        public:
        Tree();
        ~Tree();
        void destroy(Node* t);
        Tree& insert(int i);
        Tree& remove(int i);
        int size();
        bool contains(int i);
        int root();
        int parent(int i);
        int left(int i);
        int right(int i);
        void print();
    };
}

/**
 * A collection of signatures without realizations.
 * By rawnaq 
 */


#include <iostream>
using namespace std;


class NodeT
{
   private:
      	int num;
	      NodeT* leftChild;
	      NodeT* rightChild;
	     

   public:
	NodeT(int n)
	{ 
		num=n; 
		leftChild=Null;
		rightChild=Null;
	} 
	
        NodeT();
	~NodeT();
	
	NodeT* getLeftChild() { return leftChild; }
	void setLeftChild(NodeT* i);
	{
		leftChild=i; 
	}
	
	NodeT* getRightChild() { return rightChild; }
	void setRightChild(NodeT* j)
	{
		rightChild=j;
	}
	
        int getNum() { return num; }
	void setNum(int k) 
	{
		num=k;
	}
};

namespace ariel {


class Tree
{
        
 public:
        Tree()
        {
	     root=Null;
	     cap=0;
	}
	
        ~Tree() 
	{
		  destructor(root);
	}
	
    Tree& insert(int i);
    void remove(int i);
    int size();
    boolean contains(int i);
    int root();
    int parent(int i);
    int left();
    int right();
    void print(NodeT *root);
 
	
  private:
        NodeT *root;
	int cap;

};
}


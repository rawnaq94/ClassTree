#include <iostream>
#include <string>

using namespace std;


class node
{
   private:
      	int num;
	      node *leftChild;
	      node *rightChild;
	      node *parent;

   public:
	node(int i);
        node();
	~node();
	node *getLeftChild();
	void setLeftChild(node *i);
	node *getRightChild();
	void setRightChild(node *j);
	node *getParent();
	void setParent(node *k);
    int getNum();
};


class Tree
{
private:
        node *root;
        
 public:
    Tree();
    ~Tree();
    
    void insert(int i);
    void remove(int i);
    static int size();
    static boolean contains(int i);
    static int root();
    static int parent(int i);
    static int left();
    static int right();
    void print();
    
};



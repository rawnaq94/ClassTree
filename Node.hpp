
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

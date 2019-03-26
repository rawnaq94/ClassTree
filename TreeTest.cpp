/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using std::cout, std::endl;
using namespace std;
#include "badkan.hpp"
#include "Tree.hpp"

int main() {
  ariel::Tree emptytree;
  ariel::Tree threetree;  
  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3);
  
  // new tree //

  ariel::Tree myTree1;
  ariel::Tree myTree2;
  ariel::Tree myTree3;
  
  // Fill the first tree //

  myTree1.insert(12);
  myTree1.insert(6);
  myTree1.insert(2);
  
  
  // Fill the second tree //
  
  myTree2.insert(8)
  myTree2.insert(6);
  myTree2.insert(4);
  myTree2.insert(2);
  
  
  // Fill the Third tree //
  
  myTree3.insert(10);
  myTree3.insert(12);
  myTree3.insert(15);
  myTree3.insert(20);
  myTree3.insert(17);
  myTree3.insert(16);
  myTree3.insert(11);
  myTree3.insert(2);
  myTree3.insert(3);
  myTree3.insert(6);
  myTree3.insert(9);
  myTree3.insert(7);
  myTree3.insert(8);
  myTree.print();
  
  
  
  badkan::TestCase tc("Binary tree");
  tc
  .CHECK_EQUAL (emptytree.size(), 0)
  .CHECK_OK    (emptytree.insert(5))
  .CHECK_EQUAL (emptytree.size(), 1)
  .CHECK_EQUAL (emptytree.contains(5), true)
  .CHECK_OK    (emptytree.remove(5))
  .CHECK_THROWS(emptytree.remove(5))
  .CHECK_EQUAL (emptytree.size() ,0)
    
  .CHECK_EQUAL (threetree.size(), 3)
  .CHECK_EQUAL (threetree.root(), 5)
  .CHECK_EQUAL (threetree.parent(3), 5)
  .CHECK_EQUAL (threetree.parent(7), 5)
  .CHECK_EQUAL (threetree.left(5), 3)
  .CHECK_EQUAL (threetree.right(5), 7)
  .CHECK_THROWS(threetree.insert(3))
  .CHECK_OK    (threetree.print())
    
    
   // myTree1 test //
   
   
  .CHECK_EQUAL(myTree1.size(), 3)
  .CHECK_EQUAL(myTree1.root(),12)
  .CHECK_OK   (myTree1.remove(12))
  .CHECK_EQUAL(myTree1.root(),6)
  .CHECK_THROWS (myTree1.remove(12))
  .CHECK_OK   (myTree1.remove(6))
  .CHECK_EQUAL(myTree1.root(),2)
  .CHECK_THROWS (myTree1.remove(6))
  .CHECK_EQUAL(myTree1.size(), 1)
  .CHECK_OK    (myTree1.print())
    
    
  // myTree2 test //
    
  .CHECK_EQUAL (myTree2.size(), 4)
  .CHECK_EQUAL (myTree2.root(), 8)
  .CHECK_EQUAL (myTree2.parent(6), 8)
  .CHECK_EQUAL (myTree2.parent(4), 8)
  .CHECK_EQUAL (myTree2.left(8), 4)
  .CHECK_EQUAL (myTree2.right(8), 6)
  .CHECK_OK   (myTree2.remove(8))
  .CHECK_EQUAL (myTree2.root(), 6)
  .CHECK_EQUAL (myTree2.parent(4), 6)
  .CHECK_EQUAL (myTree2.parent(2), 6)
  .CHECK_EQUAL (myTree2.left(6), 2)
  .CHECK_EQUAL (myTree2.right(6), 4)
  .CHECK_OK    (myTree2.print())
    
    
   // myTree3 test //
    
    
  .CHECK_EQUAL(myTree3.size(), 13)
  .CHECK_EQUAL(myTree3.root(), 10)
  .CHECK_EQUAL(myTree3.right(12), 15)
  .CHECK_OK (myTree3.remove(12)) 
  .CHECK_EQUAL(myTree3.right(10), 15)
  .CHECK_EQUAL(myTree3.left(15), 11)
  .CHECK_EQUAL(myTree3.size(), 12)
  .CHECK_OK (myTree3.remove(9))
  .CHECK_EQUAL(myTree3.right(6), 7)  
  .CHECK_OK (myTree3.remove(16)) 
  .CHECK_EQUAL(myTree3.size(), 10)
  .CHECK_THROWS (myTree3.remove(22))
    
  .print();
  
  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}

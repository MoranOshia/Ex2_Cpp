/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using std::cout, std::endl;
#include "badkan.hpp"
#include "Tree.hpp"

int main() {
  ariel::Tree emptytree;
  ariel::Tree threetree;
  ariel::Tree myTestTree;  
  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3);
  
  myTestTree.insert(2);
  myTestTree.insert(1);
  myTestTree.insert(8);
  
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
  
  .CHECK_EQUAL (myTestTree.size(), 3)
  .CHECK_EQUAL (myTestTree.root(), 2)
  .CHECK_EQUAL (myTestTree.parent(1), 2)
  .CHECK_EQUAL (myTestTree.parent(7),2)
  .CHECK_EQUAL (myTestTree.left(2), 1)
  .CHECK_EQUAL (myTestTree.right(2), 8)
  .CHECK_THROWS(myTestTree.insert(3))
  .CHECK_THROWS(myTestTree.insert(20))
  .CHECK_EQUAL (myTestTree.size(), 5)
  .CHECK_EQUAL (myTestTree.left(8), 3)
  .CHECK_EQUAL (myTestTree.right(8), 20)
  .CHECK_EQUAL (myTestTree.contains(20), true)
  .CHECK_EQUAL (myTestTree.contains(39), true)
  .CHECK_OK    (myTestTree.remove(20))
  .CHECK_THROWS(myTestTree.remove(20))
  .CHECK_OK    (myTestTree.remove(3))
  .CHECK_THROWS(myTestTree.remove(3))
  .CHECK_EQUAL (myTestTree.size(), 3)
  .CHECK_OK    (myTestTree.remove(8))
  .CHECK_THROWS(myTestTree.remove(8))
  .CHECK_OK    (myTestTree.remove(1))
  .CHECK_THROWS(myTestTree.remove(1))
  .CHECK_OK    (myTestTree.remove(2))
  .CHECK_THROWS(myTestTree.remove(2))
  .CHECK_EQUAL (myTestTree.size(), 0)
  .CHECK_OK    (myTestTree.print())
  
  .print();
  
  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}

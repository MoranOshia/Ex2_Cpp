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
		ariel::Tree nullTree;
		for (int i = 14; i <= 20; i+=2)
		{
			myTestTree.insert(i);

		}
		for (int i = 6; i <= 12; i+=2)
		{
			myTestTree.insert(i);

		}
		for (int i = 4; i >= 2; i-=2)
		{

			myTestTree.insert(i);

		} 
		
		
	
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
		
		.CHECK_EQUAL (myTestTree.root(), 14)
		.CHECK_EQUAL (myTestTree.size(), 10)
		.CHECK_EQUAL (myTestTree.parent(16), 14)
		.CHECK_EQUAL (myTestTree.parent(6),14)
		.CHECK_THROWS(myTestTree.left(10))
		.CHECK_EQUAL (myTestTree.right(10), 12)
		.CHECK_THROWS (myTestTree.left(20))
		.CHECK_THROWS (myTestTree.right(20))
		.CHECK_EQUAL (myTestTree.contains(456), false)
		.CHECK_EQUAL (myTestTree.contains(4), true)
		.CHECK_OK    (myTestTree.remove(8))
		.CHECK_THROWS(myTestTree.remove(8))
		.CHECK_OK    (myTestTree.insert(15))
		.CHECK_OK    (myTestTree.insert(17))
		.CHECK_EQUAL (myTestTree.size(), 11)
		.CHECK_THROWS (myTestTree.right(8))
		.CHECK_THROWS(myTestTree.parent(3))
		.CHECK_THROWS(myTestTree.parent(14))
		
		
		.CHECK_OK    (myTestTree.remove(14))
		.CHECK_THROWS(myTestTree.remove(14))
		.CHECK_EQUAL (myTestTree.root(), 15)
		.CHECK_EQUAL (myTestTree.size(), 10)
		.CHECK_OK    (myTestTree.print())
		
		.CHECK_THROWS(nullTree.root())
		.CHECK_THROWS (nullTree.right(nullTree.root()))
		.CHECK_THROWS (nullTree.left(nullTree.root()))
		.print();

		cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
	}

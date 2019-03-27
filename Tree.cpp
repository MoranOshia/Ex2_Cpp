
	/**
	 * Examples of automatic tests for the exercise on binary trees.
	 *
	 * @author Erel Segal-Halevi
	 * @since 2019-02
	 */

	#include <iostream>
	#include <math.h>
	#include <algorithm>
	#include "Tree.hpp"



	using namespace std;
	using namespace ariel;



	Node::Node(){
		//default Constructor
		this->value=0;
	}
	Node::Node(int val) {
		// Constructor by value
		this->value = val;
		this->left = NULL;
		this->right = NULL;
	}

	Node::Node(int val, Node *left, Node *right) {
		//Copy Constructor
		this->value = val;
		this->left = left;
		this->right = right;
	}

	Tree::Tree(){
		//default Constructor
        roo = NULL;
    }
	Tree::~Tree()
	{//D constructor
		destroyTree(this->roo);
	}

	void Tree::destroyTree(Node* leaf)
	{//Deleting all the Tree for Memory leak
		if(leaf!=NULL)
		{
			destroyTree(leaf->left);
			destroyTree(leaf->right);
			delete leaf;
		}
	}
	void Tree::addHelper(Node *root, int val) {
		//Function that add new node by value we get 
		if (root->value > val) {
			if (!root->left) {
				root->left = new Node(val);
			} else {
				addHelper(root->left, val);
			}
		} else {
			if (!root->right) {
				root->right = new Node(val);
			} else {
				addHelper(root->right, val);
			}
		}
	}


	void Tree::printHelper(Node *root) {
		//postOrder printing Tree
		if (!root) return;
		printHelper(root->left);
		cout<<root->value<<' ';
		printHelper(root->right);
	}

	int Tree::nodesCountHelper(Node *root) {
		//Function counting size of the tree
		if (!root) return 0;
		else return 1 + nodesCountHelper(root->left) + nodesCountHelper(root->right);
	}

	int Tree::heightHelper(Node *root) {
		if (!root) return 0;
		else return 1 + std::max(heightHelper(root->left), heightHelper(root->right));
	}

	void Tree::printMaxPathHelper(Node *root) {
		//Function Counting maximum path of Tree
		if (!root) return;
		cout<<root->value<<' ';
		if (heightHelper(root->left) > heightHelper(root->right)) {
			printMaxPathHelper(root->left);
		} else {
			printMaxPathHelper(root->right);
		}
	}

	bool Tree::deleteValueHelper(Node *parent, Node *current, int value) {
		//Function deleting value we get from tree
		if (!current) return false; //check isn't NULL
		if (current->value == value) { //Check if we in the current value
			if (current->left == NULL || current->right == NULL) {
				Node *temp = current->left;
				if (current->right) temp = current->right;
				if (parent) {
					if (parent->left == current) {
						parent->left = temp;
					} else {
						parent->right = temp;
					}
				} else {
					this->roo = temp;
				}
			} else { 
				Node *validSubs = current->right;
				while (validSubs->left) {//goes to the most lef Node
					validSubs = validSubs->left;
				}
				int temp = current->value;
				current->value = validSubs->value;
				validSubs->value = temp;
				return deleteValueHelper(current, current->right, temp);//recorsive
			}
			delete current;
			return true;
		}
		return deleteValueHelper(current, current->left, value) || deleteValueHelper(current, current->right, value);//recorsive
	}

	bool Tree::containsNode(Node* top, int data) {
		//Boolean Function check if data is in the Tree
		if (top == NULL) return false;
		if (data == top->value) return true;
		if (data < top->value)  return containsNode(top->left, data);    
		return containsNode(top->right, data);
	}

	Node* Tree::getParent(Node *root, int key){
		//Function returning the parent of key we got
		if (root == NULL){//check if NULL
			return NULL;
		}
		else if ((root->left!=NULL && root->left->value == key)|| (root->right!=NULL && root->right->value == key))//checking root
		{
			return root;
		}
		else {
			Node* parentN= getParent(root->left, key);//recorsive left size 
			if (parentN!=NULL){
				return parentN;
			}
			else{
				return getParent(root->right, key);//recorsive right size 
			}
		}

	}

	Node* Tree::getNodeByIndex(Node* top, int data) {
		//Getting node by data we get
		if (top == NULL) return NULL;
		if (data == top->value) return top;
		if (data < top->value)  return getNodeByIndex(top->left, data);    
		return getNodeByIndex(top->right, data);
	}


	void Tree::insert(int i){
		//isnsert function bt index using addHelper
		if(contains(i) == true)//check if exsist
		{
			throw std::invalid_argument( "Value already exists" );
		}
		else{
			if (roo) {
				this->addHelper(roo, i);
			} else {//if null
				roo = new Node(i);
			}
		}
	}

	void Tree::remove(int i){
		//isnsert function bt index using deleteValueHelper
		if(contains(i) == false)//check if exsist
		{
			throw std::invalid_argument( "value not exist" );
		}
		else{
			bool flag= this->deleteValueHelper(NULL, this->roo, i);
		}
	}

	int Tree::size(){
		//returnig size of the tree use nodesCountHelper
		return nodesCountHelper(roo);
	}

	bool Tree::contains(int i){
		//Check if index exsist in tree use containsNode
		bool con = containsNode(roo, i);
		return con;


	}

	int Tree::root(){
		//returning index of root
		if(this->roo!=NULL){//if root not NULL
			return this->roo->value;
		}
		else
		{
			throw std::invalid_argument( "WORNG root is NULL" );
		}
	}

	int Tree::parent(int i){
		//returning index of root
		if(contains(i)==true){//if index exsist
			Node* parent=getParent(this->roo, i);

			if(parent!=NULL){//parent not NULL
				return parent->value;
			}
			else //parent NULL
			{
				throw std::invalid_argument( "WORNG dont have parents" );
			}
		}
		else //index not exsist
		{
			throw std::invalid_argument( "Not have key in the tree" );

		}
	}

	int Tree::left(int i){
		//returning index of the left Node of the Index we got
		if(contains(i)==true){//if index exsist

			Node* leftN=getNodeByIndex(this->roo, i);
			if(leftN!=NULL && leftN->left!=NULL){//left node we got not NULL
				return leftN->left->value;
			}
			else
			{//left NULL
				throw std::invalid_argument( "The right Node is NULL" );
			}
		}
		else
		{//index not exsist
			throw std::invalid_argument( "Not have key in the tree" );
		}
	}

	int Tree::right(int i){
		//returning index of the right Node of the Index we got
		if(contains(i)==true){

			Node* n=getNodeByIndex(this->roo, i);

			if(n!=NULL && n->right!=NULL ){//right node we got not NU:: 
				return n->right->value;
			}
			else
			{//right NULL
				throw std::invalid_argument( "The right Node is NULL" );
			}
		}
		else
		{//index not exsist
			throw std::invalid_argument( "Not have key in the tree" );
		}
	}

	void Tree::print(){
		//printing function use printHelper
		printHelper(this->roo);
	}


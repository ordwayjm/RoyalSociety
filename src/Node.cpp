#include "Node.h"

Node::Node(void)
{
	next_ = this;
	prev_ = next_;
}

Node::Node(Node* next, Node* prev, Window* window)
{
	next_ = next;
	prev_ = prev;
	window_ = window;
}

/*
	Creates a new node and inserts it after passed node in the list
*/

//Matt: I changed the name "nodeAt" to "currentNode".  This is a bit less
//confusing of an identifier.
void Node::insertAfter(Node* currentNode, Window* newWindow)
{
	Node* nextNode = currentNode->next_;
	Node* tmp = new Node(nextNode, currentNode, newWindow);
	currentNode->next_ = tmp;
	nextNode->prev_ = tmp;
}

/*
	Creates a new node and inserts it before passed node in the list
*/

//Matt: I changed the name "nodeAt" to "currentNode".  This is a bit less
//confusing of an identifier.
void Node::insertBefore(Node* currentNode, Window* newWindow)
{
	Node* prevNode = currentNode->prev_;
	Node* tmp = new Node(currentNode, prevNode, newWindow);
	currentNode->prev_ = tmp;
	prevNode->next_ = tmp;
}

/*
	Moves targeted node to the back of the list
*/

/*
	Matt:  I changed the name of this method to "moveToBack" because it is
	a better descriptor of what the method does with your nodes.  Also, I 
	changed the name "nodeAt" to "currentNode".  This is a bit less confusing
	of an identifier.
*/
void Node::moveToBack(Node* currentNode)
{
		Node* target = currentNode->next_;
		currentNode->next_ = target->next_;
		target->prev_ = currentNode->prev_;
		currentNode->prev_ = target;
		target->next_ = currentNode;
		currentNode->next_->prev_ = currentNode;
		target->prev_->next_ = target;
}

/*
	Moves targeted node to the front of the list
*/

/*
	Matt:  I changed the name of this method to "moveToFront" because it is
	a better descriptor of what the method does with your nodes. Also, I 
	changed the name "nodeAt" to "currentNode".  This is a bit less confusing
	of an identifier.
*/

void Node::moveToFront(Node* currentNode)
{
		Node* target = currentNode->prev_;
		currentNode->prev_ = target->prev_;
		target->next_ = currentNode->next_;
		currentNode->next_ = target;
		target->prev_ = currentNode;
		currentNode->prev_->next_ = currentNode;
		target->next_->prev_ = target;
}

/*
	Removes selected node from list
*/
void Node::remove(Node* remove_here) 
{
	remove_here->prev_->next_ = remove_here->next_;
	remove_here->next_->prev_ = remove_here->prev_;
	delete remove_here;
}

/*
	Reverses the order of the list
*/
void Node::reverse(Node* sentinel)
{
	Node* tmp;
	Node* cur = sentinel;
	do
	{
		tmp = cur->next_;
		cur->next_ = cur->prev_;
		cur->prev_ = tmp;
		cur = cur->prev_;
	} while(cur != sentinel);
}


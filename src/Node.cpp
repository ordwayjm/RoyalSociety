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
void Node::insertAfter(Node* nodeAt, Window* newWindow)
{
	Node* nextNode = nodeAt->next_;
	Node* tmp = new Node(nextNode, nodeAt, newWindow);
	nodeAt->next_ = tmp;
	nextNode->prev_ = tmp;
}

/*
	Creates a new node and inserts it before passed node in the list
*/
void Node::insertBefore(Node* nodeAt, Window* newWindow)
{
	Node* prevNode = nodeAt->prev_;
	Node* tmp = new Node(nodeAt, prevNode, newWindow);
	nodeAt->prev_ = tmp;
	prevNode->next_ = tmp;
}

/*
	Moves targeted node to the back of the list
*/
void Node::moveLeft(Node* nodeAt)
{
		Node* target = nodeAt->next_;
		nodeAt->next_ = target->next_;
		target->prev_ = nodeAt->prev_;
		nodeAt->prev_ = target;
		target->next_ = nodeAt;
		nodeAt->next_->prev_ = nodeAt;
		target->prev_->next_ = target;
}

/*
	Moves targeted node to the front of the list
*/
void Node::moveRight(Node* nodeAt)
{
		Node* target = nodeAt->prev_;
		nodeAt->prev_ = target->prev_;
		target->next_ = nodeAt->next_;
		nodeAt->next_ = target;
		target->prev_ = nodeAt;
		nodeAt->prev_->next_ = nodeAt;
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


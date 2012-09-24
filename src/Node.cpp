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

void Node::insertAfter(Node* nodeAt, Window* newWindow)
{
	Node* nextNode = nodeAt->next_;
	Node* tmp = new Node(nextNode, nodeAt, newWindow);
	nodeAt->next_ = tmp;
	nextNode->prev_ = tmp;
}

void Node::insertBefore(Node* nodeAt, Window* newWindow)
{
	Node* prevNode = nodeAt->prev_;
	Node* tmp = new Node(nodeAt, prevNode, newWindow);
	nodeAt->prev_ = tmp;
	prevNode->next_ = tmp;
}

void Node::remove(Node* remove_here) 
{
	remove_here->prev_->next_ = remove_here->next_;
	remove_here->next_->prev_ = remove_here->prev_;
	delete remove_here;
}

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


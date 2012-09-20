#include "Node.h"

Node::Node()
{
	next_ = this;
	prev_ = next_;
}

void Node::insertAfter(Node* node, Window* window)
{
	Node* newNode = new Node;
	newNode->window_ = window;
	newNode->next_ = node->next_;
	newNode->prev_ = node;
	node->next_ = newNode;
}


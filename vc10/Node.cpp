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

void remove(Node* remove_here) 
{
	delete remove_here;
}

// doubly linked circular
void reverse(Node* sentinel)
{
	Node* cur = sentinel;
	do
	{
		Node* tmp = cur->next_;
		cur->next_ = cur->prev_;
		cur->prev_ = tmp;
		
		cur = cur->prev_;
	} while(cur != sentinel);
}

/*

// singly linked circular - recursive
void reverse(Node* sentinel)
{
	if(sentinel != sentinel->next_)
	{
		Node* temp = sentinel->next_;
		remove_without_deleting(temp);
		reverse(sentinel);
		temp->next_->next_ = temp;
		temp->next_ = sentinel;
	}
}


*/


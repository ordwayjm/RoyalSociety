#include "Window.h"

class Node
{
	public:

		Node* next_;
		Node* prev_;

		Window* window_;

		Node::Node();
		void Node::insertAfter(Node* node, Window* newWindow);
};


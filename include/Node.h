#include "Window.h"


class Node
{
	public:

		Node* next_;
		Node* prev_;

		Window* window_;

		Node(void);
		Node(Node* next, Node* prev, Window* window);
		void insertAfter(Node* node, Window* newWindow);
		void insertBefore(Node* node, Window* newWindow);
		void remove(Node* remove_here);
		void reverse(Node* sentinel);
};


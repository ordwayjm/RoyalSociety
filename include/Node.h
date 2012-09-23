#include "Window.h"


class Node
{
	public:

		Node* next_;
		Node* prev_;

		Window* window_;

		Node(void);
		Node(Node* next, Node* prev, Window* window);
		
		void insertAfter(Node* nodeAt, Window* newWindow);
		void insertBefore(Node* nodeAt, Window* newWindow);
		
		void moveAfter(Node* nodeToMove, Node* nodeAt);
		void moveBefore(Node* nodeToMove, Node* nodeAt);
		
		void remove(Node* remove_here);

		void reverse(Node* sentinel);
};


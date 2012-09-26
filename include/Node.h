#include "Window.h"

// Matt: Be sure to put some documentation in your header files
// so people reviewing your code know what is going on in here

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
		void moveToBack(Node* nodeAt);
		void moveToFront(Node* nodeAt);
		void remove(Node* remove_here);
		void reverse(Node* sentinel);
};


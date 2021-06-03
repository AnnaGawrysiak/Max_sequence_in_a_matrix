#include "Node.h"

Node::Node(int value)
{
	data = value;
	child_low = nullptr;
	child_right = nullptr;
}

Node::Node()
{
	child_low = nullptr;
	child_right = nullptr;
}

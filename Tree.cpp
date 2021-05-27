#include "Tree.h"
#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <iomanip>
#include <string>

Tree::Tree()
{
	root = nullptr;
}

std::shared_ptr<Node> Tree::Create_New_Node(int val)
{
	std::shared_ptr<Node> node = std::make_shared<Node>();

	node->data = val;
	node->child_low = nullptr;
	node->child_right = nullptr;

	return node;
}

void Tree::insert_matrix(const std::vector<std::vector<int>>& matrix)
{
	root = Create_New_Node(matrix.at(0).at(0));
	std::shared_ptr<Node> curr = root;

	int rows = matrix.size();
	int cols = matrix.at(0).size();

	for (int i = 0; i < rows; i++)
	{
		std::shared_ptr<Node> temp = curr;

		std::cout << "curr: " << curr->data << std::endl;

		for (int j = 0; j < cols; j++)
		{
			if ((j + 1) < cols)
			{
				curr->child_right = Create_New_Node(matrix.at(i).at(j + 1));
				std::cout << "child right: " << curr->child_right->data << std::endl;
			}

			if ((i + 1) < rows)
			{
				curr->child_low = Create_New_Node(matrix.at(i + 1).at(j));
				std::cout << "child low: " << curr->child_low->data << std::endl;
			}

			curr = curr->child_right;
		}

		curr = temp->child_low;
	}

}
void Tree::BFS()
{
	std::shared_ptr<Node> source = root;
	std::queue<std::shared_ptr<Node> > myqueue;
	myqueue.push(source);
	// whenever an item touches a queue we mark it as seen
	std::map<std::shared_ptr<Node>, bool> discovered;
	discovered[source] = true;

	while (!myqueue.empty())
	{
		std::shared_ptr<Node> curr = myqueue.front();
		myqueue.pop();
		std::cout << curr->data << " ";

		// add undiscovered children of the curr
		if (curr->child_low != nullptr && discovered[curr->child_low] == false)
		{
			// mark it as discovered and enqueue it
			discovered[curr->child_low] = true;
			myqueue.push(curr->child_low);
		}

		if (curr->child_right != nullptr && discovered[curr->child_right] == false)
		{
			discovered[curr->child_right] = true;
			myqueue.push(curr->child_right);
		}
	}
}

// Iterative function to calculate the height of a given binary tree
// by doing level order traversal on the tree

int Tree::getDepth()
{
	if (root == nullptr) // kod bledu
		return -1;

	std::shared_ptr<Node> source = root;
	std::queue<std::shared_ptr<Node> > myqueue;
	myqueue.push(source);
	// whenever an item touches a queue we mark it as seen
	std::map<std::shared_ptr<Node>, bool> discovered;
	discovered[source] = true;
	int levels = 0;

	while (!myqueue.empty())
	{
		// calculate the total number of nodes at the current level
		int size = myqueue.size();

		while (size--)
		{
			std::shared_ptr<Node> curr = myqueue.front();
			myqueue.pop();

			if (curr->child_low != nullptr && discovered[curr->child_low] == false)
			{
				// mark it as discovered and enqueue it
				discovered[curr->child_low] = true;
				myqueue.push(curr->child_low);
			}

			if (curr->child_right != nullptr && discovered[curr->child_right] == false)
			{
				discovered[curr->child_right] = true;
				myqueue.push(curr->child_right);
			}
		}

		levels++;
	}


	return levels;
}

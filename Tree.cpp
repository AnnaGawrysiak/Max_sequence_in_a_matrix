#include "Tree.h"
#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <iomanip>
#include <string>
#include <limits>

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
	if (matrix.empty())
		return;

	root = Create_New_Node(matrix.at(0).at(0));
	std::shared_ptr<Node> curr = root;

	int rows = matrix.size();
	int cols = matrix.at(0).size();

	// Create first row

	for (int i = 1; i < cols ; i++)
	{
		curr->child_right = Create_New_Node(matrix.at(0).at(i));
		curr = curr->child_right;
	}

	std::shared_ptr<Node> parent = root;
	// insert subsequent rows

	for (int i = 1; i < rows; i++)
	{
		std::shared_ptr<Node> curr = Create_New_Node(matrix.at(i).at(0));
		std::shared_ptr<Node> temp = curr;

		for (int j = 0; j < cols; j++)
		{
			parent->child_low = curr;
			parent = parent->child_right;

			if (j < cols - 1)
			{
				curr->child_right = Create_New_Node(matrix.at(i).at(j+1));
				curr = curr->child_right;
			}
			
		}

		parent = temp;
	}

}
void Tree::BFS()
{

	if (root == nullptr)
		return;
	
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

int Tree::MaxSumFromRootToLeaf()
{
	std::shared_ptr<Node> node = root;
	Max_Sum_helper(node, 0);
	return max_sum;

}
void Tree::Max_Sum_helper(std::shared_ptr<Node> curr, int sum)
{
	if (curr == nullptr) 
		return;

	if (curr->child_low == nullptr && curr->child_right == nullptr && sum + curr->data > max_sum)
	{
		max_sum = sum + curr->data;
		return;
	}

	if (curr->child_low != nullptr)
		Max_Sum_helper(curr->child_low, sum += curr->data);

	if (curr->child_right != nullptr)
		Max_Sum_helper(curr->child_right, sum += curr->data);

	return;
}
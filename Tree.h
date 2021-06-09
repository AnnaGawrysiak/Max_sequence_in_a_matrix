#pragma once
#include "Node.h"
#include <string>
#include <vector>
#include <limits>

class Tree
{
private:
	int max_sum = INT_MIN;
	std::shared_ptr<Node> root;
public:
	Tree();
	std::shared_ptr<Node> Create_New_Node(int val);
	void insert_matrix(const std::vector<std::vector<int>>& matrix);
	void BFS();
	std::vector<int> MaxNumberFromRootToLeaf();
	int MaxSumFromRootToLeaf();
	void Max_Sum_helper(std::shared_ptr<Node> curr, int sum);
};


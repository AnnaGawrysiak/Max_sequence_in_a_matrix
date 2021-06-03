#pragma once
#include "Node.h"
#include <string>
#include <vector>
#include <limits>

class Tree
{
private:
	int max_sum = INT_MIN;
	std::vector<int> max_sum_path;
	std::shared_ptr<Node> root;
public:
	Tree();
	std::shared_ptr<Node> Create_New_Node(int val);
	void insert_matrix(const std::vector<std::vector<int>>& matrix);
	std::shared_ptr<Node> Max_Sum_Path();
	void BFS();
	int MaxSumFromRootToLeaf();
	void Max_Sum_helper(std::shared_ptr<Node> curr, int sum);
};


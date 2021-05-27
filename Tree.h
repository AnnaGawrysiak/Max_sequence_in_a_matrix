#pragma once
#include "Node.h"
#include <string>
#include <vector>

class Tree
{
public:
	std::shared_ptr<Node> root;
public:
	Tree();
	std::shared_ptr<Node> Create_New_Node(int val);
	void insert_matrix(const std::vector<std::vector<int>>& matrix);
	std::shared_ptr<Node> Max_Sum_Path();
	void BFS();
	int getDepth();
};


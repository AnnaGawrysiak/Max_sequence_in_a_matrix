#pragma once
#include <memory>

class Node
{
public:
    int data;
    std::shared_ptr<Node> child_low;
    std::shared_ptr<Node> child_right;
    Node(int value);
    Node();
};


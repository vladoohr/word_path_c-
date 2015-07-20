
#include "stdafx.h"
#include "node.h"
#include <string>

int Node::getCost() const{
	return cost;
}

Node::Node(std::string start_w, std::string end_w, Node *parNode, int path_cost)
{
	start_word = start_w;
	end_word = end_w;
	parent = parNode;
	cost = path_cost;
}
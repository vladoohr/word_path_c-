#ifndef Node_H
#define Node_H
#include <string>

class Node
{
public:
	std::string start_word;
	std::string end_word;
	Node  *parent;
	int cost;
	int getCost() const;

	Node(std::string start_w, std::string end_w, Node *parNode, int path_cost);
};

#endif

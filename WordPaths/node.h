#ifndef Node_H
#define Node_H
#include <string>
#include <vector>

class Node
{
public:
	//Getters
	std::string get_start_word();
	std::string get_end_word();
	Node *get_parent();
	int getCost();

	//Setters
	void set_start_word(std::string s_w);
	void set_end_word(std::string e_w);
	void set_parent(Node *p);
	void setCost( int c);

	Node(std::string start_w, std::string end_w, Node *parNode, int path_cost);
	std::vector<std::string> path();
	std::vector<std::string> generate_words(std::vector<std::string> dictionary);

private:
	std::string start_word;
	std::string end_word;
	Node  *parent;
	int cost;
};

#endif

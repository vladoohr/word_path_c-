
#include "stdafx.h"
#include "node.h"

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include <iterator>

Node::Node(std::string start_w, std::string end_w, Node *parNode, int path_cost)
{
	start_word = start_w;
	end_word = end_w;
	parent = parNode;
	cost = path_cost;
}

std::vector<std::string> Node::path(){
	std::vector<std::string> chain;

	chain.push_back(end_word);
	chain.push_back(start_word);

	Node *n = parent;

	while (n->get_parent() != nullptr){
		chain.push_back(n->get_start_word());
		n = n->get_parent();
	}

	chain.push_back(n->get_start_word());

	std::reverse(chain.begin(), chain.end());

	return chain;
}

std::vector<std::string> Node::generate_words( std::vector<std::string> dictionary){
	std::vector<std::string> words;

	std::string alphabet("abcdefghijklmnopqrstuvwxyz");
	std::string str_replaced;

	for (int i = 0; i < start_word.size(); i++){
		for (char & c : alphabet)
		{
			std::stringstream ss;
			std::string s;
			ss << c;
			ss >> s;
			str_replaced = start_word;
			str_replaced.replace(i, 1, s);
			if (find(dictionary.begin(), dictionary.end(), str_replaced) != dictionary.end())
				words.push_back(str_replaced);
		}
	}

	return words;
}

//Getters
std::string Node::get_start_word(){
	return start_word; 
}

std::string Node::get_end_word(){
	return end_word; 
}

int Node::getCost(){
	return cost; 
}

Node* Node::get_parent(){
	return parent;
}

//Setters
void Node::set_start_word(std::string s_w){
	start_word = s_w;
}

void Node::set_end_word(std::string e_w){
	end_word = e_w;
}

void Node::set_parent(Node *p){
	parent = p;
}

void Node::setCost(int c){
	cost = c;
}

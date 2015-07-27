// WordPaths.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "node.h"
#include "functions.h"

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include <iterator> 
#include <queue>

using namespace std;

struct CompareNode : public std::binary_function<Node*, Node*, bool>
{
	bool operator()(Node* lhs, Node* rhs) const
	{
		return lhs->getCost() > rhs->getCost();
	}
};

int main(int argc, char * argv[])
{	
	if (argc > 1){
		if (!string(argv[1]).compare("--help")){
			cout << help();
			return 0;
		}

		if (!string(argv[1]).compare("--version")){
			cout << version();
			return 0;
		}
	}
	
	// both start and end word must have the same number of char
	string start_word = "head";
	string end_word = "tail";
	
	bool found = false;
	vector<string> words;
	vector<string> generated_words;
	vector<Node*> created_words;
	vector<string> explored;
	vector<string> chain;

	// get all words from words.txt
	vector<string> dictionary = all_words();
	
	priority_queue<Node*, vector<Node*>, CompareNode > pq;

	Node *node = new Node(start_word, end_word, nullptr, diff_char(start_word, end_word));
	pq.push(node);
	created_words.push_back(node);

	while (!pq.empty())
	{
		// if path from start to end word is found
		if (found)
			break;

		// get node with lowest cost
		Node* n = pq.top();
		pq.pop();

		// generate all combinations with changing one letter each time.
		// generated word must be in words.txt file
		generated_words = n->generate_words(dictionary);
		explored.push_back(n->get_start_word());

		for (vector<int>::size_type i = 0; i != generated_words.size(); i++) {
			if (generated_words[i] == end_word){
				chain = n->path();

				for (vector<string>::iterator i = chain.begin(); i != chain.end(); ++i){
					cout << *i;

					if (i+1 != chain.end())
						cout << "->";
					else
						cout << endl;
				}

				found = true;
				break;
			}
			else {
				if (find(explored.begin(), explored.end(), generated_words[i]) == explored.end()){
					Node *nextNode = new Node(generated_words[i], n->get_end_word(), n, diff_char(generated_words[i], n->get_end_word()));
					pq.push(nextNode);
					created_words.push_back(nextNode);
				}
			}
		}
	}
	
	// Delete pointer that vector contains  
	for (vector<Node*>::iterator it = created_words.begin(); it != created_words.end(); ++it)
		delete *it;

	return 0;
}


#include "stdafx.h"
#include "node.h"

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include <iterator>

using namespace std;

vector<string> all_words(){
	vector<string> words;

	ifstream myfile("C:\\Users\\xxvs0026\\Documents\\Visual Studio 2013\\Projects\\WordPaths\\WordPaths\\words.txt");
	copy(istream_iterator<string>(myfile), istream_iterator<string>(), back_inserter(words));

	/*
	ifstream file("C:\\Users\\xxvs0026\\Documents\\Visual Studio 2013\\Projects\\WordPaths\\WordPaths\\words.txt");
	string str;
	while (getline(file, str)){
	words.push_back(str);
	}
	*/

	return words;
}

int diff_char(string start_word, string end_word){
	int diff = 0;

	for (int i = 0; i<start_word.length(); ++i)
	{
		if (start_word.at(i) != end_word.at(i)){
			diff++;
		}
	}

	return diff;
}

vector<string> generate_words(Node *node, vector<string> dictionary){
	vector<string> words;

	string alphabet("abcdefghijklmnopqrstuvwxyz");
	string str_replaced;

	for (int i = 0; i < node->start_word.size(); i++){
		for (char & c : alphabet)
		{
			stringstream ss;
			string s;
			ss << c;
			ss >> s;
			str_replaced = node->start_word;
			str_replaced.replace(i, 1, s);
			if (find(dictionary.begin(), dictionary.end(), str_replaced) != dictionary.end())
				words.push_back(str_replaced);
		}
	}

	return words;
}

vector<string> path(Node *node){
	vector<string> chain;
	chain.push_back(node->end_word);
	chain.push_back(node->start_word);

	Node *n = node->parent;

	while (n->parent != nullptr){
		chain.push_back(n->start_word);
		n = n->parent;
	}

	chain.push_back(n->start_word);

	reverse(chain.begin(), chain.end());

	return chain;
}

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
	string file_path = "C:\\Users\\xxvs0026\\Documents\\Visual Studio 2012\\Projects\\WordPaths\\WordPaths\\words.txt";
	
	//errno must be reset to 0
	errno= 0;
	try{
		ifstream myfile(file_path);
		myfile.exceptions (std::ios::badbit | std::ios::failbit);
		copy(istream_iterator<string>(myfile), istream_iterator<string>(), back_inserter(words));
	}catch(const ios_base::failure& e){
		if(errno){
			cerr << "*Error: " << e.code().message()
				 << " " << file_path << " - " << strerror(errno) << endl;
		}
	}

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

string version(){
	string version = "1.0";
	return "Version: " + version;
}

string help(){
	const string help =\
"-------------------------------------------- Help ---------------------------------------------\n\
--version      - Show the version of WordPaths \t\n\
--help         - Show help \t\n\
-----------------------------------------------------------------------------------------------\n";
	return help;
}
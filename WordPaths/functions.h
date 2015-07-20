#ifndef _FUNCTION_H
#define _FUNCTION_H

#include "node.h"
#include <string>
#include <vector>

std::vector<std::string> all_words();
int diff_char(std::string start_word, std::string end_word);
std::vector<std::string> generate_words(Node *node, std::vector<std::string> dictionary);
std::vector<std::string> path(Node *node);
<<<<<<< HEAD
std::string help();
std::string version();
=======
>>>>>>> 3708aa088d27140b571071f4c105d5ea2c3ad301

#endif
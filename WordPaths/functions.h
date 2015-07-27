#ifndef _FUNCTION_H
#define _FUNCTION_H

#include "node.h"
#include <string>
#include <vector>

std::vector<std::string> all_words();
int diff_char(std::string start_word, std::string end_word);
std::string help();
std::string version();

#endif
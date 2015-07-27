#include "stdafx.h"
#include "WordPathsTestCase.h"

CPPUNIT_TEST_SUITE_REGISTRATION(WordPathsTestCase);

void WordPathsTestCase::setUp()
{
	node1 = new Node("head", "tail", nullptr, 0);
}
 
void WordPathsTestCase::tearDown()
{
	delete node1;
	node1 = NULL;
}

void WordPathsTestCase::pathTest(){
	Node *node2 = new Node("tead", "tail", node1, 0);
	Node *node3 = new Node("teal", "tail", node2, 0);
	Node *node4 = new Node("teil", "tail", node3, 0);
	Node *node5 = new Node("tail", "tail", node4, 0);

	std::vector<std::string> chain = node4->path();
	int chain_size = chain.size();

	std::stringstream ss;
	
	for(int i = 0; i < chain.size(); i++)
	{
		if(i != 0)
		ss << ",";
		ss << chain[i];
	}

	std::string s = ss.str();
	std::string expected_string = "head,tead,teal,teil,tail";

	CPPUNIT_ASSERT(chain_size != 0);
	CPPUNIT_ASSERT_EQUAL(chain_size, 5);
	CPPUNIT_ASSERT_EQUAL(s, expected_string);
}

void WordPathsTestCase::generate_wordsTest(){
	std::vector<std::string> dictionary = all_words();
	std::vector<std::string> generated_words = node1->generate_words(dictionary);
	int generated_words_size = generated_words.size();

	std::stringstream ss;
	
	for(size_t i = 0; i < generated_words.size(); ++i)
	{
		if(i != 0)
		ss << ",";
		ss << generated_words[i];
	}

	std::string s = ss.str();

	std::string expected_words = "bead,dead,head,lead,mead,read,tead,head,head,heed,hend,herd,head,heaf,heal,heap,hear,heat";

	CPPUNIT_ASSERT(generated_words_size != 0);
	CPPUNIT_ASSERT_EQUAL(generated_words_size, 18);
	CPPUNIT_ASSERT_EQUAL(s, expected_words);
}

void WordPathsTestCase::diff_charTest(){
	std::string word1 = "head";
	std::string word2 = "tail";

	int diff = diff_char(word1, word2);
	CPPUNIT_ASSERT_EQUAL(diff, 4);
}
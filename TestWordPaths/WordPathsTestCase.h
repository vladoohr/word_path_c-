#ifndef WordPathsTestCase_H
#define WordPathsTestCase_H

#include "..\WordPaths\node.h"
#include "..\WordPaths\functions.h"

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

class WordPathsTestCase : public CPPUNIT_NS::TestFixture  
{
	CPPUNIT_TEST_SUITE(WordPathsTestCase);
		CPPUNIT_TEST(pathTest);
		CPPUNIT_TEST(generate_wordsTest);
		CPPUNIT_TEST(diff_charTest);
	CPPUNIT_TEST_SUITE_END();

public:
	void setUp();
	void tearDown();

protected:
	void pathTest();
	void generate_wordsTest();
	void diff_charTest();

private:
	Node *node1;

};

#endif // !defined(WordPathsTestCase_H)
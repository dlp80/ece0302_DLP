// Project 3 -- XML Parsing Project

/** XML parsing class implementation.
    @file XMLParser.cpp */

#include <string>
#include <assert.h>
#include "XMLParser.hpp"

// TODO: Implement the constructor here
XMLParser::XMLParser()
{
}  // end default constructor

// TODO: Implement the destructor here
XMLParser::~XMLParser()
{
}  // end destructor

// TODO: Implement the tokenizeInputString method
/*main idea: we want to first read through the entire string. every time we encounter < or > push it + the contents inside onto the stack
once there are no doubles, we will proceed to the next round of testing. for all contents between <>, check
for "tag type". must be successful start/end combo, empty tag, and ? declaration.

once we check that everything has proper enclosing in tags <>, we must then determine if each tag
falls under one of the 4 tag categories*/
bool XMLParser::tokenizeInputString(const std::string &inputString)
{
	return false;
}  // end

// TODO: Implement the parseTokenizedInput method here
bool XMLParser::parseTokenizedInput()
{
	return false;
}

// TODO: Implement the clear method here
void XMLParser::clear()
{
}

vector<TokenStruct> XMLParser::returnTokenizedInput() const
{
	return tokenizedInputVector;
}

// TODO: Implement the containsElementName method
bool XMLParser::containsElementName(const std::string &inputString) const
{
	return false;
}

// TODO: Implement the frequencyElementName method
int XMLParser::frequencyElementName(const std::string &inputString) const
{
	return -1;
}


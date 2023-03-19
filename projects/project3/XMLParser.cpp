// Project 3 -- XML Parsing Project

/** XML parsing class implementation.
    @file XMLParser.cpp */

#include <string>
#include <assert.h>
#include "XMLParser.hpp"
static std::string deleteAttributes(std::string input);
// Implement the constructor here
XMLParser::XMLParser() : size(0)
{
	elementNameBag = new Bag <std::string>;
	parseStack=new Stack <std::string>;
	tokenizedInputVector={};
}  // end default constructor

// Implement the destructor here
XMLParser::~XMLParser()
{
	delete elementNameBag;
	delete parseStack;
	tokenizedInputVector.clear();
	size = 0;
}  // end destructor

//  Implement the tokenizeInputString method
bool XMLParser::tokenizeInputString(const std::string &inputString)
{
	int i=0;
	string word;
	string inValid="!#$\"%&'()*+,/;<=>?@[]^`{|}~\\";
	string badStart=".-,0123456789";
	StringTokenType type;
	TokenStruct element ;
	while (i != inputString.length())
	{
		//check if first char is a starting tag
		if (inputString.at(0) != '<')
		{
			tokenizedInputVector.clear();
			return false;
		}
		word="";
		//check if the word is encapsulated
		if(inputString.at(i) == '<')
		{
			//setting the tags
			i++;
			
			if(inputString.at(i)=='/')
			{
				type=END_TAG;
				i++;

				//checking for bad starts 
				for (int k = 0; k<badStart.length(); k++)
				{
					if(inputString.at(i)==badStart.at(k))
					{
						tokenizedInputVector.clear();
						return false;
					}
				}
			}
			else if (inputString.at(i)=='?')
			{
				type = DECLARATION;
				i++;
				//checking for bad starts 
				for (int k = 0; k<badStart.length(); k++)
				{
					if(inputString.at(i)==badStart.at(k))
					{
						tokenizedInputVector.clear();
						return false;
					}
				}
			}
			else
			{
				type = START_TAG;
			}
			
			while(inputString.at(i) != '>')
			{
				//|| inputString.at(i)=='/'
				if(inputString.at(i)=='<' )
				{
					tokenizedInputVector.clear();
					return false;
				}
				word=word + inputString.substr(i,1);
				i++;
			}
			
			//make sure the declaration is with the ?s in the correct syntax
			if(type == DECLARATION)
			{
				if(inputString.at(i-1)=='?')
				{
					int len=word.length();
					word=word.substr(0,len-1);
				}
				else
				{
					tokenizedInputVector.clear();
					return false;
				}
			} 

			//checking if it is an empty tag
			if (type == START_TAG && inputString.at(i-1)=='/')
			{
				type=EMPTY_TAG;
				int len=word.length();
				word=word.substr(0,len-1);
			}

			//get rid of anything after the tag / ' '
			if (type == START_TAG || type == EMPTY_TAG)
			{
				word=deleteAttributes(word);
			}

			//checking for invalid characters
			for (int j = 0;j<word.length();j++)
			{
				for (int k=0;k<inValid.length();k++)
				{
					if(word.at(j)==inValid.at(k))
					{
						tokenizedInputVector.clear();
						return false;
					}
				}
			}

			if (type == START_TAG || type == EMPTY_TAG)
			{
				//adding tag to bag
				elementNameBag->add(word);
			}

			element = {type,word};
			tokenizedInputVector.push_back(element);
			size++;
		}
		
		//checking content
		else if (inputString.at(i)=='>')
		{
			i++; 
			
			//making sure it is actually content and not another tag
			if (inputString.at(i)=='<')
			{
				break;
			}
			type=CONTENT;
			while(inputString.at(i) != '<')
			{
				word=word + inputString.substr(i,1);
				i++;
			}

			//checking for invalid characters and nested endings >>
			for (int j = 0;j<word.length();j++)
			{
				for (int k=0;k<inValid.length();k++)
				{
					if(word.at(j)==inValid.at(k))
					{
						tokenizedInputVector.clear();
						return false;
					}
				}
			}

			element = {type,word};
			tokenizedInputVector.push_back(element);
			size++;
		}

	}
	return true;
}  // end

//  Implement a helper function to delete attributes from a START_TAG
// or EMPTY_TAG string (you can change this...)
static std::string deleteAttributes(std::string input)
{
	int loc=input.find(' ');
	int len=input.length();
	string word  = input.substr(0,loc);
	string word2 = input.substr(0,len);
	
	//if there is a space before the end of the tag only return the first part
	if(word.length() < word2.length())
	{
		return word;
	}
	else
	{
		return word2;
	}
}

// Implement the parseTokenizedInput method here
bool XMLParser::parseTokenizedInput()
{
	bool parsed = (tokenizedInputVector.size()==0);
	if (parsed)
	{
		return false;
	}

	int amt=tokenizedInputVector.size();
	StringTokenType startType = tokenizedInputVector[0].tokenType;
	StringTokenType endType   = tokenizedInputVector[amt-1].tokenType;

	if( (startType!=1 && startType!=5) || endType!=2)
	{
		return false;
	}
	else
	{
		int startTagAmt=0, endTagAmt=0;
		//going thru vector 
		for (int i = 0; i<amt;i++)
		{
			//if it is a start tag add to stack
			if (tokenizedInputVector[i].tokenType==1)
			{
				parseStack->push(tokenizedInputVector[i].tokenString);
				startTagAmt++;
			}
			//if end tag
			else if (tokenizedInputVector[i].tokenType==2)
			{
				//first end tag matches last start tag
				if (tokenizedInputVector[i].tokenString==parseStack->peek())
				{
					parseStack->pop();
				}
				else{
					parsed=false;
					return false;
				}
				endTagAmt++;
			}
		}
		
		if (startTagAmt!=endTagAmt)
		{
			return false;
		}
		if (parseStack->size()!=0)
		{
			return false;
		}
	}

	parsed =true;
	return parsed;

}

//  Implement the clear method here
void XMLParser::clear()
{
	elementNameBag->clear();
	parseStack->clear();
	tokenizedInputVector.clear();
	
	elementNameBag=nullptr;
	parseStack=nullptr;
	//tokenizedInputVector=nullptr;
}

vector<TokenStruct> XMLParser::returnTokenizedInput() const
{
	return tokenizedInputVector;
}

// Implement the containsElementName method
bool XMLParser::containsElementName(const std::string &inputString) const
{
	bool tokenized = (tokenizedInputVector.size()==0);
	if (tokenized==true || parsed==false)
	{
		throw std::logic_error("It was not tokenized and/or parsed.");
	}
	bool test = elementNameBag->contains(inputString);
	return test;
}

// Implement the frequencyElementName method
int XMLParser::frequencyElementName(const std::string &inputString) const
{	
	bool tokenized = (tokenizedInputVector.size()==0);
	if (tokenized==true || parsed==false)
	{
		throw std::logic_error("It was not tokenized and/or parsed.");
	}

	int freq = elementNameBag->getFrequencyOf(inputString);
	return freq;
}

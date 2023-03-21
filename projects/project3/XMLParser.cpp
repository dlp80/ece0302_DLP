// Project 3 -- XML Parsing Project

/** XML parsing class implementation.
    @file XMLParser.cpp */

#include <string>
#include <assert.h>
#include "XMLParser.hpp"

// TODO: Implement the constructor here
XMLParser::XMLParser()
{
	size = 0;
	elementNameBag = new Bag <std::string>;
	parseStack=new Stack <std::string>;
	tokenizedInputVector={};
}  // end default constructor

// TODO: Implement the destructor here
XMLParser::~XMLParser()
{
	delete elementNameBag;
	delete parseStack;
	tokenizedInputVector.clear();
	size = 0;
}  // end destructor


// TODO: Implement the tokenizeInputString method
/*main idea: we want to first read through the entire string. every time we encounter < or > push it + the contents inside onto the stack
once there are no doubles, we will proceed to the next round of testing. for all contents between <>, check
for "tag type". must be successful start/end combo, empty tag, and ? declaration.

once we check that everything has proper enclosing in tags <>, we must then determine if each tag
falls under one of the 4 tag categories*/
bool XMLParser::tokenizeInputString(const std::string &inputString)
{
//initialize
	//std::cout << inputString;
	
	string item;
	string name;
	string badTag="!#$\"%&'()*+,/;<=>?@[]^`{|}~\\";
	string badStart=".-,0123456789";
	StringTokenType type;
	TokenStruct element ;

	//checking start and end characters are indeed carrots
	int dim = inputString.length();


	// pushing < and > onto temp stack. checking for << or >> appearances
	for(int i=0; i < inputString.length(); i++){
		if(inputString[i] =='<' || inputString[i] == '>'){
			//push the carrots onto the stack
			item.push_back(inputString[i]);
		}
	}

	for(int j = 0; j < item.length(); j++){
			if(item[j] == item[j+1]){
				return false;
			}
	}


//we should now not anticipate any << or >> its chill

//PHASE 2

//now that we have checked that inputString is good, we track through it. 
//the stack will hold <tag> | "content" | <tag>
//we must error check each item

//std::string inputString = "<test>content</test>";
std::vector<std::string> output;
std::string tag, content;

for (size_t i = 0; i < inputString.size(); i++) {

    if (inputString[i] == '<') {
        // Push the previous content string to the output vector (if it's not empty)
        if (!content.empty()) {
            output.push_back(content);
            content.clear();
        }
        // Copy the tag character by character into a temporary string
        tag.clear();
		tag = '<';
        size_t j = i + 1;
        while (j < inputString.size() && inputString[j] != '>') {
            tag += inputString[j];
            j++;
        }
        // Push the completed tag to the output vector
        tag += '>';
        output.push_back(tag);
        // Jump to the end of the tag
        i = j;
    } else {
        // Copy non-tag characters into the content string
        content += inputString[i];
    }
}

// Push any remaining content to the output vector (if it's not empty)
if (!content.empty()) {
    output.push_back(content);
}

//test print
for (const auto& item : output) {
    std::cout << item << " ";
}
 //temp vec should hold all parts of the string. now we will sort and inpsect each individual element

	vector<string> tempVec = output;
	

	for(int p = 0; p < output.size(); p++){

		string v = output[p];
		
		//here, each v = string of variable length
		
		int endy = v.length();
		
		for(int i = 0; i < v.length(); i++){ //now lets check all the things in the string
			
			if(v[0] == '<'){ //if the string starts w '<' we treat it as a tag
			
				//here i = character in the string
				
				if(v[1] == '?'){
					
					type = DECLARATION;
					string temp;

					//established that type == declaration. now we must return valid tag name (excluding <?__?>
					
					for(int k = 0; k < endy; k++){

						if(v[k] == '<' || v[k] == '?' ||v[k] == '>' ){
							continue;
						}
						
							temp.push_back(v[k]);

						}
						
						//pushback successful declaration
						name = temp;
						element = {type,name};
						tokenizedInputVector.push_back(element);
						std::cout<< name << " ";
						size++;
					}
				
				else if(v[1] == '/'){
					
					//aside - error checking
					if(v[endy-1] == '/' || v[endy-1] == '?'){
						tokenizedInputVector.clear();
						return false;
					}
					
					type = END_TAG;
					string temp;
					
					//established endTag type. now we must determine valid tag name
					
					for(int k = 2; k < (endy-1); k++){
						for(int bStart = 0; bStart < badStart.length(); bStart++){
							
							if(v[2] == badStart[bStart]){ //if the starting char is bad return false
								tokenizedInputVector.clear();
								return false;
							}
						}
						for(int bad = 0; bad < badTag.length(); bad++){
							
							if(v[k] == badTag[bad] || v[k] == ' '){ //if any element in v, excluding </ == badTag or whitespace. return false
								tokenizedInputVector.clear();
								return false;
							}
							
						}
					}
					
					//ok now we have a valid end tag. bad chars been filtered out
					
					//now we must establish the tag name
				for (int k = 1; k < endy && v[k] != ' '; k++) {
					while (v[k] != '<' && v[k] != '/' && v[k] != '>' && v[k] != ' ') {
						
						temp.push_back(v[k]);
												
						k++; // increment k to move to the next character
					}
					
					if (v[k] == ' ' || v[k] == '\n' || v[k] == '\t') {
						break; // stop the loop if a space is encountered
					}
				}
					//pushback successful declaration
					name = temp;
					element = {type,name};
					tokenizedInputVector.push_back(element);
					std::cout<< name << " ";
					size++;
					
				}
				
				else if (v[endy-1] == '/'){
					
					//aside - error checking
					if(v[1] == '/' || v[1] == '?'){
						tokenizedInputVector.clear();
						return false;
					}
					
					type = EMPTY_TAG;
					string temp;

					//established that this is empty tag. now we must determine valid tag name
					
					for(int k = 1; k < (endy-2); k++){
						for(int bStart = 0; bStart < badStart.length(); bStart++){
							
							if(v[1] == badStart[bStart]){ //if the starting char is bad return false
								tokenizedInputVector.clear();
								return false;
							}
						}
						for(int bad = 0; bad < badTag.length(); bad++){
							
							if(v[k] == badTag[bad]){ //if any element in v, excluding /> == badTag or whitespace. return false
								tokenizedInputVector.clear();
								return false;
							}
							
						}
					}
					
					//ok now we have a valid empty tag. bad chars been filtered out
					
					//now we must establish the tag name
					
					for(int k = 1; k < (endy-2); k++){
						
						if(k == ' '){
							break;
						}
						
						while(v[k] != '<' && v[k] != '/' && v[k] != '>'){
							
							temp.push_back(v[k]);
							//k++;
							//pushback successful declaration

						}
					}
				name = temp;
				//element = {type,name};
				tokenizedInputVector.push_back({type,name});
				std::cout<< name << " ";
				size++;
				}
				
				else{
					
					type = START_TAG;
					string temp;
					
					// we have determined that this is a start tag. now we must validate tag name
					
					for(int k = 1; k < (endy-1); k++){
						if(k == ' ' || k == '\n' || k == '\t'){
							k = endy-2;
							break;
						}
						else{
						for(int bStart = 0; bStart < badStart.length(); bStart++){
							
							if(v[1] == badStart[bStart]){ //if the starting char is bad return false
								tokenizedInputVector.clear();
								return false;
							}
						}
						for(int bad = 0; bad < badTag.length(); bad++){
							
							if(v[k] == badTag[bad]){ //if any element in v, excluding /> == badTag or whitespace. return false
								tokenizedInputVector.clear();
								return false;
							}
							
						
						}
					}
					}

					//ok now we have a valid empty tag. bad chars been filtered out
					
					//now we must establish the tag name
					
				for (int k = 1; k < endy && v[k] != ' '; k++) {
					while (v[k] != '<' && v[k] != '/' && v[k] != '>' && v[k] != ' ') {
						
						temp.push_back(v[k]);
												
						k++; // increment k to move to the next character
					}
					
					if (v[k] == ' ' || v[k] == '\n' || v[k] == '\t') {
						break; // stop the loop if a space is encountered
					}
				}
				name = temp;
				// pushback successful declaration
				element = {type, name};
				tokenizedInputVector.push_back(element);
				std::cout<< name << " ";
				size++;
				}
			break;	
			}
			
			
			if(v[0] != '<'){ //if the string DOES NOT start w '<' we do must act as if it is a content
				
				type = CONTENT;
				
				string temp;
				
				for(int k = 0; k < endy; k++){
					
					if (v[k] == ' ' || v[k] == '\n' || v[k] == '\t') {
						break; // stop the loop if a space is encountered
					}
					else{
					temp.push_back(v[k]);}
				
					}
				
				
				//successfully put content in a string + excluded whitespace
				name = temp;

				if(!name.empty()){
				//pushback successful declaration
				element = {type,name};
				tokenizedInputVector.push_back(element);
				std::cout<< temp << " ";
				size++;
				}
			break;
			}
			
		}
	}
return true;
}

	


// TODO: Implement the parseTokenizedInput method here
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


// TODO: Implement the clear method here
void XMLParser::clear()
{
	elementNameBag->clear();
	parseStack->clear();
	tokenizedInputVector.clear();
	
	elementNameBag=nullptr;
	parseStack=nullptr;

	size = 0;
}

vector<TokenStruct> XMLParser::returnTokenizedInput() const
{
	return tokenizedInputVector;
}

// TODO: Implement the containsElementName method
bool XMLParser::containsElementName(const std::string &inputString) const
{
	return elementNameBag->contains(inputString);
}

// TODO: Implement the frequencyElementName method
int XMLParser::frequencyElementName(const std::string &inputString) const
{
	return (elementNameBag->getFrequencyOf(inputString));
}


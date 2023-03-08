#ifndef CLASS_listNode
#define CLASS_listNode
#include <iostream>
#include <vector>

class listNode
{
	public:
	std::string word;
	std::vector <std::string> pos;
    std::vector <std::string> synonym;
	listNode * next;
	listNode();
	listNode(std::string word,std::string pos,std::string synonym);

    void ammend(std::string word,std::string pos,std::string synonym);
};

#endif
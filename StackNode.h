#ifndef CLASS_StackNode
#define CLASS_StackNode
#include <iostream>

class StackNode
{
public:
    std::string word;
    std::string pos;
    std::string meaning;
    StackNode *next;
    StackNode();
    StackNode(std::string word,std::string pos,std::string meaning);
};

#endif
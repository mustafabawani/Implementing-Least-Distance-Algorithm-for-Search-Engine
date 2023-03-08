#ifndef CLASS_Stack
#define CLASS_Stack
#include "StackNode.h"
#include "listNode.h"
#include <fstream>
class Stack
{
public:
    StackNode *top;
    Stack();
    void StackReverse();
    void push(std::string word, std::string pos, std::string meaning);
    void displayStack();
    StackNode *pop();
    void readFromFile();
    StackNode * getNodeIndex(int index);
    void AddSearchHistory(std::string,std::string,std::string);
    void writeToFile(std::string word, std::string pos, std::string synonym);
};
#endif
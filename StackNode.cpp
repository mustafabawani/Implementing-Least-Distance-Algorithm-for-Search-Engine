#include "StackNode.h"
#include <iostream>
using namespace std;

StackNode::StackNode()
{
    next = NULL;
}
StackNode::StackNode(string word,string pos,string meaning)
{    
    this->word = word;
    this->pos = pos;
    this->meaning = meaning;
    next = NULL;
}
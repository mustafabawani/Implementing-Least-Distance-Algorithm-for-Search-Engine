#include "listNode.h"

using namespace std;

listNode::listNode()
{
    this->next=NULL;	
}	
listNode::listNode(string word,string pos,string synonym)
{
    this->word=word;
    this->pos.push_back(pos);
    this->synonym.push_back(synonym);
    this->next=NULL;
}
void listNode::ammend(string word,string pos,string synonym)
{
    this->word=word;
    this->pos.push_back(pos);
    this->synonym.push_back(synonym);
}


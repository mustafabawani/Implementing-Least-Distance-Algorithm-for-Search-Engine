#include "stack.h"
#include "listNode.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
Stack::Stack()
{
    top = NULL;
    readFromFile();
    //StackReverse();
}

void Stack::readFromFile(){
    string word, pos, synonym;
    ifstream is("searchHistory.txt");
    while (!is.eof())
    {
        getline(is, word, ',');
        getline(is, pos, ',');
        getline(is, synonym);
        push(word, pos, synonym);
    }
    is.close();
}


void Stack::StackReverse()
{
    if(top==NULL)
        return;
    Stack  temp;
    StackNode * t=new StackNode();
    while(top!=NULL)
    {
        t=pop();
        temp.push(t->word,t->pos,t->meaning);
    }
    top=temp.top;
}



void Stack::push(string word, string pos, string meaning)
{
    StackNode *new_node = new StackNode;
    new_node->word = word;
    new_node->pos = pos;
    new_node->meaning = meaning;
    if (top == NULL)
    {
        top = new_node;
        top->next = NULL;
    }
    else
    {
        new_node->next = top;
        top = new_node;
    }
}

void Stack::writeToFile(string word, string pos, string meaning)
{
    ofstream os("searchHistory.txt",ios::app);
    os << endl;
    os << word << ", " << pos << ", " << meaning;
    os.close();
}

void Stack::displayStack()
{
    StackNode *temp = top;
    while (temp != NULL)
    {
        cout << temp->word << endl;
        temp = temp->next;
    }
}
StackNode* Stack::pop(){
    if(top==NULL)
        return NULL;
    
    StackNode* temp=top;
    top=top->next;
    return temp;
}

StackNode * Stack::getNodeIndex(int index)
{
    StackNode * temp=top;
    for(int i=0;i<index;i++)
        temp=temp->next;
    return temp;
}

void Stack:: AddSearchHistory(string word,string pos,string meaning)
{
    push(word,pos,meaning);
    writeToFile(word,pos,meaning);
}
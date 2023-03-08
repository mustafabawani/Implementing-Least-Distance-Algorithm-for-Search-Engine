#include <iostream>
#include "SLL.h"
#include "globalfunctions.h"

using namespace std;


SLL::SLL()
{
    head=NULL;
    tail=NULL;
}

void SLL::insert(string word,string pos,string synonym)
{	
    listNode * temp=new listNode(word,pos,synonym);
    if(head==NULL && tail==NULL)
    {
        head=temp;
        tail=temp;
        return;
    }
    if(capitalToSmall(tail->word)==capitalToSmall(word))
    {          	
        tail->ammend(word,pos,synonym);
        return;
    }
    tail->next=temp;
    tail=tail->next;
}


listNode* SLL::search(string word)
{
    listNode * t=head;
    while(t!=NULL)
    {
        if(capitalToSmall(t->word)==capitalToSmall(word))
        {
            // cout << t->word << " " ;
            // for(int i=t->pos.size()-1; i >=0 ; i--)
            //     cout << t->pos.at(i) << ' ';
            // for(int i=t->synonym.size()-1; i >=0 ; i--)
            //     cout << t->synonym.at(i) << ' ';
            // cout << endl;
            return t;
        }
        t=t->next;
    }
    return NULL;
}

void SLL::deleteNode(std::string word)
{
    listNode * temp=head;
    if(word==temp->word)
    {
        head=head->next;
        return;
    }
    while(temp!=NULL)
    {
        if(word==temp->next->word)
            break;
        temp=temp->next;
    }
    if(temp->next->next==NULL)
    {
        temp->next=NULL;
    }
    
    temp->next=temp->next->next;
}
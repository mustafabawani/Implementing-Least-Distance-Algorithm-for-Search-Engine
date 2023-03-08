#ifndef CLASS_SLL
#define CLASS_SLL
#include <iostream>
#include "listNode.h"

class SLL
{
	public:
		listNode * head;
		listNode * tail;
		SLL();
		
		void insert(std::string word,std::string pos,std::string synonym);
		
		listNode* search(std::string word);

		void deleteNode(std::string word);
};

#endif
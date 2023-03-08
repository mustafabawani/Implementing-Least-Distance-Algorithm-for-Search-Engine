#include <iostream>
#include "SLL.h"
#include "listNode.h"
#include "treenode.h"
#include <vector>

std::string capitalToSmall(std::string str);
long long int hashingFunction(std::string word);
void readAndHashing(SLL* list);
listNode* searchHashing(std::string word, SLL* list);
std::vector <std::string> recommendations(std::string word, TreeNode* node,std::vector <std::string> v);
int minimumEditDistance(std::string word1, std::string word2);
int minThree(int a, int b, int c);
bool inArray(std::string* arr, std::string word);
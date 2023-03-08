#ifndef CLASS_TreeNode
#define CLASS_TreeNode
#include <iostream>

class TreeNode
{
public:
    std::string word;
    std::string pos;
    std::string meaning;
    TreeNode *left;
    TreeNode *right;
    std::string key;
    TreeNode();
    TreeNode(std::string word, std::string pos, std::string meaning);
};

#endif
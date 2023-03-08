#include "treenode.h"
#include <iostream>
using namespace std;

TreeNode::TreeNode()
{
    left = NULL;
    right = NULL;
}
TreeNode::TreeNode(string word, string pos, string meaning)
{
    this->word = word;
    this->pos = pos;
    this->meaning = meaning;
    left = NULL;
    right = NULL;
}
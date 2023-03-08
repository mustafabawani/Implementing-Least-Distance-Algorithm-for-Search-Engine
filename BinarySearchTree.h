#ifndef CLASS_BinarySearchTree
#define CLASS_BinarySearchTree
#include "treenode.h"
#include <iostream>
#include <fstream>
class BinarySearchTree
{
public:
    TreeNode *root;
    BinarySearchTree();
    void insert(std::string word, std::string pos, std::string meaning);
    void inorder(TreeNode *temp);

    TreeNode *minValueNode(TreeNode *temp);

    TreeNode *del(std::string val, TreeNode *temp);

    int maxHeight(TreeNode *t);

    void readFromFile();
    void WriteInFile();
    void WriteInFileUsingInorder(TreeNode *temp,std::ofstream& os);
};
#endif
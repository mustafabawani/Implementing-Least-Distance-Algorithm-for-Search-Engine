#include <iostream>
#include <fstream>
#include "BinarySearchTree.h"
using namespace std;
    BinarySearchTree::BinarySearchTree(){
        root=NULL;
        readFromFile();
    }
    void BinarySearchTree::insert(string word,string pos,string meaning){
        TreeNode* new_node=new TreeNode(word,pos,meaning);
        if(root==NULL){
            root=new_node;
            return;
        }

        TreeNode* temp=root;
        while(temp!=NULL){

            if(temp->word>=new_node->word){
                if(temp->left==NULL){
                    temp->left=new_node;
                    return;
                }
                else
                {
                    temp=temp->left;
                }
            }

            
            if(temp->word<new_node->word){
                if(temp->right==NULL){
                    temp->right=new_node;
                    return;
                }
                else
                {
                    temp=temp->right;
                }
            } 
        }

    }

void BinarySearchTree::inorder(TreeNode* temp){
    if(temp==NULL){
        return;
    }
    inorder(temp->left);
    cout<<temp->word<<" "<<endl;
    inorder(temp->right);
}

TreeNode* BinarySearchTree::minValueNode(TreeNode* temp){
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

TreeNode* BinarySearchTree::del(string val,TreeNode* temp){
    if(temp==NULL){
        return NULL;
    }

    if(temp->word > val){
        temp->left=del(val,temp->left);
    }
    else if(temp->word < val){
        temp->right=del(val,temp->right);
    }
    else{
        if(temp->left==NULL){
            delete temp->right;
        }
        else if(temp->right==NULL){
            delete temp->left;
        }
        else{
            TreeNode* t=minValueNode(temp->right);
            temp->word=t->word;
            // t->left=NULL;
            temp->right=del(temp->word,temp->right);
            }
    }
    return temp;
}


int BinarySearchTree::maxHeight(TreeNode* t){
    if(t==NULL){
        return 0;
    }

    int lheight=maxHeight(t->left);
    int rheight=maxHeight(t->right);

    if(lheight>rheight)
        return lheight+1;
    return rheight+1;
}

void BinarySearchTree::readFromFile(){
    ifstream is;
    string word,pos,meaning;
    is.open("dataset_mini.txt");
    while(!is.eof()){
        getline(is,word,',');
        getline(is,pos,',');
        getline(is,meaning);
        insert(word,pos,meaning);
    }
}

void BinarySearchTree::WriteInFileUsingInorder(TreeNode *temp,ofstream& os)
{
    if (temp == NULL)
    {
        return;
    }
    WriteInFileUsingInorder(temp->left,os);
    os << temp->word << "," << temp->pos << "," << temp->meaning << endl;
    WriteInFileUsingInorder(temp->right,os);
}

void BinarySearchTree::WriteInFile()
{
    ofstream os("dataset_mini.txt");
    WriteInFileUsingInorder(this->root, os);
}
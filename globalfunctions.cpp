#include <iostream>
#include "globalfunctions.h"
#include <fstream>
#include <string>
#include "SLL.h"
#include "treenode.h"
#include <vector>

using namespace std;

string capitalToSmall(string str)
{
	for(int i=0;i<str.length();i++)
	{
		if(str[i]>='A' && str[i]<='Z')
			str[i]=str[i]+32;
	}
	return str;
}

long long int hashingFunction(string word)
{
	int g=31;
	long int m=106824;
	long long int hash=0;
	int g_power=1;
	for (int i = 0; i < word.length(); i++) 
	{
		hash= (hash	+ (word[i] - 'a' + 1) * g_power)% m;       
        g_power = (g_power * g) % m;
    }
	if(hash<0)
		hash=abs(hash);
    return hash;
}

void readAndHashing(SLL* list){
	long long int index=0;
    ifstream is;
	string small_word;
    string word,pos,synonym;
    is.open("dataset_mini.txt");
	if(!is)
	{
		cout << "file not found" <<endl;
		return;
	}
    int i=0;
	int j=0;
    while(!is.eof())
	{
        getline(is,word,',');
        getline(is,pos,',');
        getline(is,synonym);
		small_word=capitalToSmall(word);
        index=hashingFunction(small_word);
        list[index].insert(word,pos,synonym);		
    }
}

listNode* searchHashing(string word, SLL* list)
{
	string small_word=capitalToSmall(word);
    long long int index=0;
    index=hashingFunction(small_word);
    return list[index].search(small_word);	
}

int minThree(int a, int b, int c)
{
    return min(min(a, b), c);
}

int minimumEditDistance(string word1, string word2)
{
    int table[word2.length() + 2][word1.length() + 2];
    int i, j;
    
    for (i = 0; i < word1.length() + 1; i++)
    {
        table[0][i] = i;
    }
    for (i = 0; i < word2.length() + 1; i++)
    {
        table[i][0] = i;
    }

    for(i = 1; i < word2.length() + 1; i++)
    {
        for (j = 1; j < (word1.length() + 1); j++)
        {
            
            if (word2[i-1] == word1[j-1])
                table[i][j] = table[i-1][j-1];
            else
                table[i][j] = 1 + minThree(table[i][j-1], table[i-1][j-1], table[i-1][j]);
            
        }
    }

    return table[i-1][j-1];
}

bool inArray(vector<string> arr, string word)
{
    int i;
    for (i = 0; i < arr.size(); i++)
    {
        if (word == arr.at(i))
            return true;
    }
    return false;
}

vector <string> recommendations(string word, TreeNode* node, vector<string> v )//, string* arr, int index)
{
    if (node == NULL)
        return v;
    if (node->word == "")
        return v;
    
    v=recommendations(word, node->left,v);//, arr, index);
    int distance = minimumEditDistance(word, node->word);
    if (distance < 2 && !inArray(v, node->word)){
        v.push_back(node->word);}
    return recommendations(word, node->right,v);//, arr, index);
    
}


#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include "SLL.h"
#include "globalfunctions.h"
#include "BinarySearchTree.h"
#include <string>
#include<vector>
#include "stack.h"
#include "StackNode.h"

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // used for goto
COORD CursorPosition; // used for goto

void gotoXY(int,int); 
void searchMenu();
void addWordMenu();
void searchHistoryMenu();
void deleteWordMenu();

SLL * list= new SLL[106824];
BinarySearchTree* bst = new BinarySearchTree();
Stack* stack = new Stack();

int main()
{
	int menu_item=0, run, x=7;
	bool running = true;
    readAndHashing(list);
	
	system("cls");
    gotoXY(20,5); cout << "English Dictionary";
	gotoXY(18,7); cout << "->";
    
	
    while(running)
	{
        
        gotoXY(20,7);  cout << "Search Dictionary";
		gotoXY(20,8);  cout << "Check Search History";
		gotoXY(20,9);  cout << "Add a word to Dictionary";
		gotoXY(20,10); cout << "Delete a word from the dictionary";
		gotoXY(20,11); cout << "Quit Program";

		system("pause>nul"); // the >nul bit causes it the print no message
		
		if(GetAsyncKeyState(VK_DOWN) && x != 11) //down button pressed
			{
				gotoXY(18,x); cout << "  ";
				x++;
				gotoXY(18,x); cout << "->";
				menu_item++;
				continue;
				
			}
			
		if(GetAsyncKeyState(VK_UP) && x != 7) //up button pressed
			{
				gotoXY(18,x); cout << "  ";
				x--;
				gotoXY(18,x); cout << "->";
				menu_item--;
				continue;
			}
			
		if(GetAsyncKeyState(VK_RETURN)){ // Enter key pressed
			
			switch(menu_item){
				
				case 0: {
					
                    searchMenu();
					break;
				}
					
					
				case 1: {
                    searchHistoryMenu();
					break;
				}
					
				case 2: {
					addWordMenu();
                    break;
				}
					
				case 3: {
					deleteWordMenu();
					break;
				}
					
				case 4: {
					gotoXY(20,16);
					cout << "The program has now terminated!!";
					running = false;
				}
				 
			}
				
		}		
		
	}
	
	gotoXY(20,21);
	return 0;
}

void gotoXY(int x, int y) 
{ 
	CursorPosition.X = x; 
	CursorPosition.Y = y; 
	SetConsoleCursorPosition(console,CursorPosition); 
}

void searchMenu()
{
    string word;
    int i = 0;
    system("cls");
    gotoXY(20, 5); cout << "Enter a word to search: ";
    cin >> word;
    listNode* node = searchHashing(word, list);
    if (node == NULL)
    {
        gotoXY(20, 7); cout << "No Results Found!";
        gotoXY(20, 8); cout << "Did you mean?";
        vector<string> arr;
        arr=recommendations(word, bst->root,arr);
        for (i = 0; i < arr.size(); i++)
        {
            gotoXY(20, i + 10); cout << arr.at(i);
        }
        i += 2;

    }
    else
    {
        string tword=node->word;
        string tpos=node->pos.front();
        string tsynonym=node->synonym.front();
        stack->AddSearchHistory(tword,tpos,tsynonym);
        for (i = 0; i < node->pos.size(); i++)
        {
            gotoXY(20, i+7); cout << node->word << " " << node->pos.at(i) << " " << node->synonym.at(i);
        }
    }

    int x = i + 9;
    int menu_item = 0;
    bool running = true;
    gotoXY(18, x); cout << "->";

    while(running)
    {
        gotoXY(20, i + 9); cout << "Search another word";
        gotoXY(20, i + 10); cout << "Back to Main Menu";

        system("pause>nul"); 
            
        if(GetAsyncKeyState(VK_DOWN) && x != i + 10) //down button pressed
            {
                gotoXY(18,x); cout << "  ";
                x++;
                gotoXY(18,x); cout << "->";
                menu_item++;
                continue;
                
            }
            
        if(GetAsyncKeyState(VK_UP) && x != i + 9) //up button pressed
            {
                gotoXY(18,x); cout << "  ";
                x--;
                gotoXY(18,x); cout << "->";
                menu_item--;
                continue;
            }
            
        if(GetAsyncKeyState(VK_RETURN)){ // Enter key pressed
            
            switch(menu_item){
                
                case 0: {
                    
                    return searchMenu();
                }
                    
                    
                case 1: {
                    system("cls");
                    gotoXY(20,5); cout << "English Dictionary";
                    gotoXY(18,7); cout << "->";
                    return;
                }
                    
                
            }
                
        }
    }
    

}

void addWordMenu()
{
    string word, pos, meaning, small_word;
    int index;
    system("cls");
    gotoXY(20, 7); cout << "Enter word: ";
    getline(cin, word);
    gotoXY(20, 8); cout << "Enter POS: ";
    getline(cin, pos);
    gotoXY(20, 9); cout << "Enter meaning: ";
    getline(cin, meaning);
    bst->insert(word, pos, meaning);
    small_word=capitalToSmall(word);
    index=hashingFunction(small_word);
    list[index].insert(word,pos,meaning);
    ofstream os("dataset_mini.txt", ios::app);
    os << word << "," << pos << "," << meaning << endl;
    os.close();

    gotoXY(20, 11); cout << "Word Added Successfully!";
    
    int menu_item = 0;
    bool running = true;
    gotoXY(18, 13); cout << "->";
    int x = 13;
    while(running)
    {
        gotoXY(20, 13); cout << "Add another word";
        gotoXY(20, 14); cout << "Back to Main Menu";

        system("pause>nul"); 
            
        if(GetAsyncKeyState(VK_DOWN) && x != 14) //down button pressed
            {
                gotoXY(18,x); cout << "  ";
                x++;
                gotoXY(18,x); cout << "->";
                menu_item++;
                continue;
                
            }
            
        if(GetAsyncKeyState(VK_UP) && x != 13) //up button pressed
            {
                gotoXY(18,x); cout << "  ";
                x--;
                gotoXY(18,x); cout << "->";
                menu_item--;
                continue;
            }
            
        if(GetAsyncKeyState(VK_RETURN)){ // Enter key pressed
            
            switch(menu_item){
                
                case 0: {
                    
                    return addWordMenu();
                }
                    
                    
                case 1: {
                    system("cls");
                    gotoXY(20,5); cout << "English Dictionary";
                    gotoXY(18,7); cout << "->";
                    return;
                }
                    
                
            }
                
        }
    }


}

void searchHistoryMenu()
{
    while(true)
    {
        system("cls");
        gotoXY(20, 7); cout << "Your recent search history is: ";
        StackNode* temp = stack->top;
        int x = 9;
        if (temp == NULL)
        {
            gotoXY(20, x++); cout << "No Search History Found!";
        }
        while(temp != NULL && x != 19)
        {
            gotoXY(20, x++); cout << temp->word;
            temp = temp->next;
        }

        bool running = true;
        int menu_item = 0;
        gotoXY(18, 9); cout << "->";
        x = 9;
        while(running)
        {
            gotoXY(20, 19); cout << "Back to Main Menu";

            system("pause>nul"); 
                
            if(GetAsyncKeyState(VK_DOWN) && x != 19) //down button pressed
                {
                    gotoXY(18,x); cout << "  ";
                    x++;
                    gotoXY(18,x); cout << "->";
                    menu_item++;
                    continue;
                    
                }
                
            if(GetAsyncKeyState(VK_UP) && x != 9) //up button pressed
                {
                    gotoXY(18,x); cout << "  ";
                    x--;
                    gotoXY(18,x); cout << "->";
                    menu_item--;
                    continue;
                }
                
            if(GetAsyncKeyState(VK_RETURN)){ // Enter key pressed
                
                if (menu_item == 10)
                {
                    system("cls");
                    gotoXY(20,5); cout << "English Dictionary";
                    gotoXY(18,7); cout << "->";
                    return;
                }

                else 
                {
                    listNode* node = searchHashing(stack->getNodeIndex(menu_item)->word, list);
                    system("cls");
                    if (node == NULL)
                    {
                        gotoXY(20, 7); cout << "Word not Found!";
                        gotoXY(18, 8); cout << "->Back";
                        getchar();
                        break;
                    }
                    int j;
                    for (j = 0; j < node->pos.size(); j++)
                    {
                        gotoXY(20, j + 7); cout << node->word << " " << node->pos.at(j) << " " << node->synonym.at(j);
                    }

                    gotoXY(20, ++j + 7); cout << "->Back";
                    getchar();
                    break;

                }
                    
            }
        }
    }

}

void deleteWordMenu(){
    string word,small_word;
    system("cls");
    gotoXY(20, 7); cout << "Enter word: ";
    
    getline(cin, word);
    small_word=capitalToSmall(word);

    bst->root=bst->del(small_word,bst->root);
    int index=hashingFunction(small_word);

    list[index].deleteNode(small_word);


    gotoXY(20, 11); cout << "Word Deleted Successfully!";
    
    int menu_item = 0;
    bool running = true;
    gotoXY(18, 13); cout << "->";
    int x = 13;
    while(running)
    {
        gotoXY(20, 13); cout << "Delete another word";
        gotoXY(20, 14); cout << "Back to Main Menu";

        system("pause>nul"); 
            
        if(GetAsyncKeyState(VK_DOWN) && x != 14) //down button pressed
            {
                gotoXY(18,x); cout << "  ";
                x++;
                gotoXY(18,x); cout << "->";
                menu_item++;
                continue;
                
            }
            
        if(GetAsyncKeyState(VK_UP) && x != 13) //up button pressed
            {
                gotoXY(18,x); cout << "  ";
                x--;
                gotoXY(18,x); cout << "->";
                menu_item--;
                continue;
            }
            
        if(GetAsyncKeyState(VK_RETURN)){ // Enter key pressed
            
            switch(menu_item){
                
                case 0: {
                    
                    return deleteWordMenu();
                }
                    
                    
                case 1: {
                    system("cls");
                    gotoXY(20,5); cout << "English Dictionary";
                    gotoXY(18,7); cout << "->";
                    return;
                }
                    
                
            }
                
        }
    }



}


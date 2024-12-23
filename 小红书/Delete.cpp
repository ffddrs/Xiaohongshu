#include<iostream>
#include<string>
#include<vector>
#include"GeneralFunctions.h"
#include"Choose_Module.h"
#include"GlobalVariable.h"
#include"Postoutfile.h"
#include"Postinfile.h"
#include"Browse.h"
#include"Home.h"

using namespace std;

void deletepost()
{
	postoutfile();
	int n=sortbyphonum(allcontent, currentphonum);
	nbrowse(n);
	display_selections(3, "Choose one,Home,Exit");
	if (final_selection == "Home")
		home();
	else if (final_selection == "Exit")
		exit(0);
	else if (final_selection == "Choose one")
	{
		int inp;
		cout << "Please enter a number of the post you want to browse" << endl;
		do
		{
			cin >> inp;
			if (cin.fail())
			{
				cin.clear(); 
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
				cout << "Invalid input, enter again" << endl;
				inp = 0;
			}
			else if (inp < 1 || inp > temp)
			{
				cout << "Invalid input, enter again" << endl;
			}
		} while (inp < 1 || inp > temp);
		cout << "Are you sure to delete this post" << endl;
		display_selections(2, "Yes,No");
		if (final_selection == "Yes")
		{
			allcontent.erase(allcontent.begin() + inp - 1);
			cout << "Delete successfully" << endl;
		}
		else if (final_selection == "No")
		{
			home();
		}
	}
	else if (true)
	{
		cout << "Invalid input, go to home page";
		home();
	}
	infile();
	home();
}
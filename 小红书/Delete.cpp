#include<iostream>
#include<string>
#include<vector>
#include"GeneralFunctions.h"
#include"Choose_Module.h"
#include"GlobalVariable.h"
#include"Postoutfile.h"
#include"Browse.h"
#include"Home.h"

using namespace std;

void deletepost()
{
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
		cin >> inp;
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
	home();
}
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include"GlobalVariable.h"
#include"Postoutfile.h"
#include"GeneralFunctions.h"
#include"Choose_Module.h"

using namespace std;

void browse()
{
	clearscreen();
	int i = 0;
	for (content post : allcontent)
	{
		cout << i+1 << "." << post.title << "  " << "Posted by " << post.nickname << "  " << convertstrtime(converttime(post.time)) << endl;
		i++;
	}
	display_selections(3, "Choose one,Home,Exit");
	choose_module();
}

void nbrowse(int n)
{
	clearscreen();
	int i = 0;
	for (int i=0;i<n;i++)
	{
		cout << i + 1 << "." << allcontent[i].title << "  " << "Posted by " << allcontent[i].nickname << "  " << convertstrtime(converttime(allcontent[i].time)) << endl;
		i++;
	}
}

void displaycomment(const content& c, int indent = 0)
{
	
	string indentStr(indent, ' ');
	cout << indentStr << "Text: " << c.text << endl << endl;
	cout << indentStr << "Posted by: " << c.nickname << endl;
	cout << indentStr << "Posted at: " << convertstrtime(converttime(c.time)) << endl;
	cout << indentStr << "-----------------------------" << endl;

	for (const auto& comment : c.comments)
	{
		displaycomment(comment, indent + 4);
	}
	
}


void displaypost(int n ,int indent=0)
{
	int m = n - 1;
	clearscreen();
	string indentStr(indent, ' ');
	cout << indentStr << "Title: " << allcontent[m].title << endl << endl << endl;
	cout << indentStr << "Text: " << allcontent[m].text << endl << endl;
	cout << indentStr << "Posted by: " << allcontent[m].nickname << endl;
	cout << indentStr << "Posted at: " << convertstrtime(converttime(allcontent[m].time)) << endl;
	cout << indentStr << "-----------------------------" << endl;

	for (const auto& comment : allcontent[m].comments)
	{
		displaycomment(comment, indent + 4);
	}
}

void chooseone()
{
	int n;
	cout << "Please enter a number of the post you want to browse" << endl;
	cin >> n;
	displaypost(n);
	cout << endl;
	display_selections(4, "Back to Browse,Comment,Home,Exit");
	choose_module();
}
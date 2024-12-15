#include<iostream>
#include"GlobalVariable.h"
#include"Content&Comments.h"
#include"Postinfile.h"
#include"GeneralFunctions.h"
#include"Home.h"

using namespace std;

void upload()
{
	string answer;
	content uploadcont;
	datetime ctime;
	clearscreen();
	cout << "Please type in your title below:" << endl;
	cin.ignore();
	getline(cin, uploadcont.title);
	cout << "Please type in your text below" << endl;
	getline(cin, uploadcont.text);
	cout << "Are you sure to upload now ?" << endl;
	display_selections(2, "Yes,No");
	if (final_selection == "No")
	{	
		cout << "Upload canceled";
		home();
	}
	else if (final_selection == "Yes")
	{
		uploadcont.nickname = currentnickname;
		uploadcont.phonum = currentphonum;
		ctime = gettime();
		uploadcont.time = ctime;
		postinfile(uploadcont);
		cout << "Successfully upload" << endl;
		home();
	}
}
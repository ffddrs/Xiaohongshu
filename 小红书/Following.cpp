#include<iostream>
#include<string>
#include<vector>
#include"GeneralFunctions.h"
#include"GlobalVariable.h"
#include"Browse.h"
#include"Choose_Module.h"
#include"Postoutfile.h"
#include"Login&Register.h"

using namespace std;

void following()
{
	int uploader_selection_num;
	clearscreen();
	postoutfile();
	accountsinfile();
	int i = 1;
	for (string phonum : acc[currentaccno].subscription)
	{
		if (findphonum(phonum) != "NULL")
			cout << i << '.' << findphonum(phonum) << endl;
		else
			cout << i << '.' << "ERROR:NOT FOUND" << endl;
		i++;
	}
	temp = i - 1;
	cout << endl << endl << endl << "Please enter the number of the uploader you want to browse" << endl;
	do
	{
		cin >> uploader_selection_num;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input, enter again" << endl;
			uploader_selection_num = 0; 
		}
		else if (uploader_selection_num < 1 || uploader_selection_num > temp)
		{
			cout << "Invalid input, enter again" << endl;
		}
	} while (uploader_selection_num < 1 || uploader_selection_num > temp);
	int n = sortbyphonum(allcontent, acc[currentaccno].subscription[uploader_selection_num - 1]);
	nbrowse(n);
	display_selections(3, "Choose one,Home,Exit");
	choose_module();
}
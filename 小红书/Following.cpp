#include<iostream>
#include<string>
#include<vector>
#include"GeneralFunctions.h"
#include"GlobalVariable.h"
#include"Browse.h"
#include"Choose_Module.h"
#include"Postoutfile.h"

using namespace std;

void following()
{
	int uploader_selection_num;
	clearscreen();
	postoutfile();
	int i = 1;
	for (string phonum : acc[currentaccno].subscription)
	{
		if (findphonum(phonum) != "NULL")
			cout << i << '.' << findphonum(phonum) << endl;
		else
			cout << i << '.' << "ERROR:NOT FOUND" << endl;
	}
	cout << "Please enter the number of the uploader you want to browse" << endl;
	cin >> uploader_selection_num;
	int n = sortbyphonum(allcontent, acc[currentaccno].subscription[uploader_selection_num - 1]);
	nbrowse(n);
	display_selections(3, "Choose one,Home,Exit");
	choose_module();
}
#include<iostream>
#include<vector>
#include<string>
#include"GeneralFunctions.h"
#include"GlobalVariable.h"
#include"Choose_Module.h"
#include"Postoutfile.h"
#include"Browse.h"

using namespace std;

int currentcomment;

void messages()
{
	clearscreen();
	postoutfile();
	int n = sortbyphonumandcomment(allcontent, currentphonum);
	nbrowse(n);
	display_selections(3, "Choose one to reply,Home,Exit");
	choose_module();
}

void reply()
{
	int n;
	cout << "Please enter the number of the comment you want to reply to" << endl;
	cin >> n;
	currentcomment = n;
	comment4reply();
}
#include<iostream>
#include"GeneralFunctions.h"
#include"Choose_Module.h"
#include"Postoutfile.h"

using namespace std;

bool loginstatus = 0;

int main()
{
	postoutfile();
	cout << "Welcome" << endl;
	display_selections(3, "Log in,Register,Exit");
	choose_module();

}
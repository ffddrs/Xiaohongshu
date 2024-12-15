#include<iostream>
#include"GeneralFunctions.h"
#include"Choose_Module.h"
#include"GlobalVariable.h"

using namespace std;

void home()
{
	if (loginstatus == 1) 
	{
		clearscreen();
		display_selections(6, "Browse,Upload,Comments,Delete,Following,Exit");
		choose_module();
	}
	else
	{
		clearscreen();
		display_selections(3, "Log in,Register,Exit");
		choose_module();
	}
}
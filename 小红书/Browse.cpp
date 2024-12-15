#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include"GlobalVariable.h"
#include"Content&Comments.h"
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
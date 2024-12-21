#pragma once
#include<string>
#include"GlobalVariable.h"

using namespace std;
void display_selections(int, string);
void clearscreen();
int stringtoint(string str);
int sortbyphonum(vector<content>& postlist,string targetphonum);
datetime gettime();
string converttime(datetime);
string convertstrtime(string);
string findphonum(string targetphonum);
bool contain_space(const string& input);
vector<content>& sortbytime(vector<content>& postlist);
vector<content>& nsortbytime(vector<content>& postlist, int n);

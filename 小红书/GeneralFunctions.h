#pragma once
#include<string>
#include"GlobalVariable.h"

using namespace std;
void display_selections(int, string);
void clearscreen();
int stringtoint(string str);
datetime gettime();
string converttime(datetime);
string convertstrtime(string);
bool contain_space(const string& input);
vector<content>& sortbytime(vector<content>& postlist);

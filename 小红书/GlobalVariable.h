// GlobalVariable.h
#ifndef GLOBALVARIABLE_H
#define GLOBALVARIABLE_H

#include<string>
#include<vector>

using namespace std;

struct content
{
    string nickname;
    string title;
    string time;
    string text;
    string phonum;
    bool ifcomment = false;
    int commentnum = 0;
    vector<content> comments;
};


extern string final_selection;
extern string currentnickname;
extern string currentphonum;
extern vector<content> allcontent;
extern bool loginstatus;

struct datetime 
{
    string year;
    string month;
    string day;
    string hour;
    string minute;
    string second;
};

#endif // GLOBALVARIABLE_H

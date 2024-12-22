// GlobalVariable.h
#ifndef GLOBALVARIABLE_H
#define GLOBALVARIABLE_H

#include<string>
#include<vector>

using namespace std;

struct datetime
{
    string year;
    string month;
    string day;
    string hour;
    string minute;
    string second;
};


struct content
{
    string nickname;
    string title;
    datetime time;
    string text;
    string phonum;
    bool ifcomment = false;
    int commentnum = 0;
    vector<content> comments;
    long long int timesort = 0;
};

struct accounts
{
    string accphonum;
    string accpassword;
    string nickname;
    int subscrinum = -1;
    vector<string> subscription;
};

extern int currentpostnum;
extern int currentcomment;
extern int temp;
extern string final_selection;
extern string currentnickname;
extern string currentphonum;
extern accounts acc[200];
extern int currentaccno;
extern vector<content> allcontent;
extern bool loginstatus;

#endif // GLOBALVARIABLE_H

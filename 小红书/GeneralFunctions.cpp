#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<string>
#include"GlobalVariable.h"

using namespace std;

string final_selection;

void clearscreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void display_selections(int selection_num,string selections)
{
    string assist;
    final_selection = assist;
    const string continu = "Press the keys below to continue";
    cout << endl << endl << endl;
    cout << continu<<endl;
    int p = 0;
    for (int i = 1; i <= selection_num; i++)
    {
        cout << i<<"£º";
        for (; p < selections.size(); p++)
        {
            if (selections[p] != ',')
                cout << selections[p];
            else
            {
                p++;
                break;
            }

        }
        cout << "   ";
    }
    cout << endl;
    int input;
    do 
    { 
        cin >> input; 
        if (input<1 || input>selection_num)
            cout << "Invalid input, enter again" << endl;
    } while (input<1 || input>selection_num);
    int scan_selection = 1;
    for (char i : selections)
    {
        if (i == ',')
            scan_selection++;
        if (input == scan_selection && i != ',')
            final_selection += i;
    }
}

datetime gettime()
{
    time_t curtime;
    ::time(&curtime); 

    tm nowtime;
    localtime_s(&nowtime, &curtime);

    char yearBuffer[5];  
    char monthBuffer[3];
    char dayBuffer[3];   
    char hourBuffer[3];  
    char minuteBuffer[3]; 
    char secondBuffer[3]; 

    strftime(yearBuffer, sizeof(yearBuffer), "%Y", &nowtime);
    strftime(monthBuffer, sizeof(monthBuffer), "%m", &nowtime);
    strftime(dayBuffer, sizeof(dayBuffer), "%d", &nowtime);
    strftime(hourBuffer, sizeof(hourBuffer), "%H", &nowtime);
    strftime(minuteBuffer, sizeof(minuteBuffer), "%M", &nowtime);
    strftime(secondBuffer, sizeof(secondBuffer), "%S", &nowtime);

    datetime dateTime;
    dateTime.year = yearBuffer;
    dateTime.month = monthBuffer;
    dateTime.day = dayBuffer;
    dateTime.hour = hourBuffer;
    dateTime.minute = minuteBuffer;
    dateTime.second = secondBuffer;

    return dateTime;
}

string converttime(datetime ctime)
{
    string time;
    time += ctime.year;
    time += '-';
    time += ctime.month;
    time += '-';
    time += ctime.day;
    time += '-';
    time += ctime.hour;
    time += '-';
    time += ctime.minute;
    time += '-';
    time += ctime.second;
    return time;
}

string convertstrtime(string time)
{
    string ctime;
    int blanktime = 0;
    for (char i : time)
    {
        if (i >= '0' && i <= '9')
            ctime += i;
        if (i == '-')
        {
            blanktime++;
            if (blanktime == 1 || blanktime == 2)
                ctime += '/';
            else if (blanktime == 3)
                ctime += ' ';
            else if (blanktime == 4 || blanktime == 5)
                ctime += ':';
        }
    }
    return ctime;
}

bool contain_space(const string& input) 
{
    return input.find(' ') != string::npos;
}

int stringtoint(string str)
{
    int sum = 0;
    int k = str.size();
    for (char ch : str)
    {
        sum += (ch - '0') * pow(10, k - 1);
        k--;
    }
    return sum;
}

vector<content>& sortbytime(vector<content>& postlist)
{
    for (content& post : postlist)
    {
        post.timesort = stringtoint(post.time.second) + stringtoint(post.time.minute) * 100 + stringtoint(post.time.hour) * 10000 + stringtoint(post.time.day) * 1000000 + stringtoint(post.time.month) * 100000000 + stringtoint(post.time.year) * 1000000000000;
    }
    for (int k = postlist.size(); k > 1; k--)
    {
        for (int i = 1; i < k; i++)
        {
            content temp;
            if (postlist[i].timesort > postlist[i - 1].timesort)
            {
                temp = postlist[i - 1];
                postlist[i - 1] = postlist[i];
                postlist[i] = temp;
            }
        }
    }
    return postlist;
}

vector<content>& nsortbytime(vector<content>& postlist,int n)
{
    for (content& post : postlist)
    {
        post.timesort = stringtoint(post.time.second) + stringtoint(post.time.minute) * 100 + stringtoint(post.time.hour) * 10000 + stringtoint(post.time.day) * 1000000 + stringtoint(post.time.month) * 100000000 + stringtoint(post.time.year) * 1000000000000;
    }
    for (int k = n; k > 1; k--)
    {
        for (int i = 1; i < k; i++)
        {
            content temp;
            if (postlist[i].timesort > postlist[i - 1].timesort)
            {
                temp = postlist[i - 1];
                postlist[i - 1] = postlist[i];
                postlist[i] = temp;
            }
        }
    }
    return postlist;
}


int sortbyphonum(vector<content>& postlist, string targetphonum)
{
    int sum = 0;
    for (int i=0;i<postlist.size();i++)
    {
        if (postlist[i].phonum == targetphonum)
        {
            sum++;
            content temp = postlist[i];
            for (int i1 = i; i1 > 0; i1--)
                postlist[i] = postlist[i - 1];
            postlist[0] = temp;
        }
    }
    return sum;
}
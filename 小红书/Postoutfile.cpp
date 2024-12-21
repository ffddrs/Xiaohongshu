#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include"GlobalVariable.h"

using namespace std;

vector<content> allcontent;

vector<content> commentoutfile(int commentnum, ifstream& in_file)
{
    vector<content> allcomment;
    vector<content> blank;
    allcomment = blank;
    for (int i = 0; i < commentnum; i++)
    {
        content comment;
        in_file.ignore();
        getline(in_file, comment.nickname);
        getline(in_file, comment.time.year);
        getline(in_file, comment.time.month);
        getline(in_file, comment.time.day);
        getline(in_file, comment.time.hour);
        getline(in_file, comment.time.minute);
        getline(in_file, comment.time.second);
        getline(in_file, comment.phonum);
        getline(in_file, comment.title);
        getline(in_file, comment.text);
        in_file >> comment.ifcomment;
        in_file >> comment.commentnum;
        if (comment.ifcomment == 1)
        {
            comment.comments = commentoutfile(comment.commentnum, in_file);
        }
        allcomment.push_back(comment);
    }
    return allcomment;
}

void postoutfile()
{
    allcontent.clear();
    content post;
    ifstream in_file("content", ios::in);
    if (!in_file)
    {
        cout << "An error occurred: failed to open file 'content'" << endl;
        exit(-1);
    }
    while (true)
    {
        in_file.ignore();
        if (!getline(in_file, post.nickname)) break;
        if (!getline(in_file, post.time.year)) break;
        if (!getline(in_file, post.time.month)) break;
        if (!getline(in_file, post.time.day)) break;
        if (!getline(in_file, post.time.hour)) break;
        if (!getline(in_file, post.time.minute)) break;
        if (!getline(in_file, post.time.second)) break;
        if (!getline(in_file, post.phonum)) break;
        if (!getline(in_file, post.title)) break;
        if (!getline(in_file, post.text)) break;
        if (!(in_file >> post.ifcomment)) break;
        if (!(in_file >> post.commentnum)) break;
        if (post.ifcomment == 1)
        {
            post.comments = commentoutfile(post.commentnum, in_file);
        }
        else if (post.ifcomment == 0)
            post.comments.clear();
        allcontent.push_back(post);
    }
}

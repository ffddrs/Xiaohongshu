#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include"GlobalVariable.h"
#include"Content&Comments.h"

using namespace std;

vector<content> allcontent;
vector<content> temp;


vector<content>* commentoutfile(int commentnum, ifstream& in_file)
{
    vector<content> allcomment;
    vector<content> blank;
    allcomment = blank;
    vector<content>* comaddress;
    comaddress = &allcomment;
    for (int i = 0; i < commentnum; i++)
    {
        content comment;
        in_file.ignore();
        getline(in_file, comment.nickname);
        getline(in_file, comment.time);
        getline(in_file, comment.phonum);
        getline(in_file, comment.title);
        getline(in_file, comment.text);
        in_file >> comment.ifcomment;
        in_file >> comment.commentnum;
        if (comment.ifcomment == 1)
        {
            comment.comments = *commentoutfile(comment.commentnum, in_file);
        }
        allcomment.push_back(comment);
        temp = allcomment;
    }
    return &temp;
}

void postoutfile()
{
    content post;
    ifstream in_file("content", ios::in);
    if (!in_file)
    {
        cout << "An error occurred: failed to open file 'content'" << endl;
        exit(-1);
    }
    getline(in_file, post.nickname);
    getline(in_file, post.time);
    getline(in_file, post.phonum);
    getline(in_file, post.title);
    getline(in_file, post.text);
    in_file >> post.ifcomment;
    in_file >> post.commentnum;
    if (post.ifcomment == 1)
    {
        post.comments = *commentoutfile(post.commentnum, in_file);
    }
    allcontent.push_back(post);
    int i = 1;
    while (!in_file.fail())
    {
        in_file.ignore();
        getline(in_file, post.nickname);
        getline(in_file, post.time);
        getline(in_file, post.phonum);
        getline(in_file, post.title);
        getline(in_file, post.text);
        in_file >> post.ifcomment;
        in_file >> post.commentnum;
        if (post.ifcomment == 1)
        {
            post.comments = *commentoutfile(post.commentnum, in_file);
        }
        allcontent.push_back(post);
        i++;
    }
}
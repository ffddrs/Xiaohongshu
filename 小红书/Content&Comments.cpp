#include<iostream>
#include<vector>
#include<string>
#include "GlobalVariable.h"
#include "Content&Comments.h"

using namespace std;

void displaycomments(vector<content> comments)
{
    for (content com : comments)
    {
        cout << "Comment by: " << com.nickname << endl;
        cout << "Title: " << com.title << endl;
        cout << "Time: " << com.time << endl;
        cout << "Text: " << com.text << endl;
        if (com.ifcomment == true)
        {
            displaycomments(com.comments);
        }
    }
}

void displayposts(content post)
{
    cout << "Post by: " << post.nickname << endl;
    cout << "Title: " << post.title << endl;
    cout << "Time: " << post.time << endl;
    cout << "Text: " << post.text << endl;
    if (post.ifcomment && !post.comments.empty()) {
        displaycomments(post.comments);
    }
}
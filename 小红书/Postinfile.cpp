#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include"GlobalVariable.h"
#include"Content&Comments.h"


void commentinfile(vector<content> comments)
{
	ofstream out_file("content", ios::app);
	if (!out_file)
	{
		cout << "An error occurred: failed to open file";
		exit(-1);
	}
	for (content com : comments)
	{
		out_file << com.nickname << endl;
		out_file << com.time << endl;
		out_file << com.phonum << endl;
		out_file << com.title << endl;
		out_file << com.text << endl;
		if (com.ifcomment == 0)
			out_file << "no" << endl;
		else
		{
			out_file << "yes" << endl;
			out_file << com.commentnum << endl;
			commentinfile(com.comments);
		}
	}
	out_file.close();
}

void postinfile(content post)
{
	ofstream out_file("content", ios::app);
	if (!out_file)
	{
		cout << "An error occurred: failed to open file" << endl;
		exit(-1);
	}
	out_file << post.nickname << endl;
	out_file << post.time << endl;
	out_file << post.phonum << endl;
	out_file << post.title << endl;
	out_file << post.text << endl;
	if (post.ifcomment == 0)
	{		
		out_file << "no" << endl;
		out_file << '0' << endl;
	}
	else
	{
		out_file << "yes" << endl;
		out_file << post.commentnum << endl;
	}
	out_file.close();
	if (post.ifcomment == 1)
		commentinfile(post.comments);
}
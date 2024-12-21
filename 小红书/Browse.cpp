#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include"GlobalVariable.h"
#include"Postoutfile.h"
#include"Choose_Module.h"
#include"Postinfile.h"
#include"GeneralFunctions.h"
#include"Home.h"

using namespace std;

int currentpostnum;

void browse()
{
	clearscreen();
	postoutfile();
	sortbytime(allcontent);
	int i = 0;
	for (content post : allcontent)
	{
		cout << i+1 << "." << post.title << "  " << "Posted by " << post.nickname << "  " << convertstrtime(converttime(post.time)) << endl;
		i++;
	}
	display_selections(3, "Choose one,Home,Exit");
	choose_module();
}

void nbrowse(int n)
{
	clearscreen();
	nsortbytime(allcontent,n);
	int i = 0;
	for (int i=0;i<n;i++)
		cout << i + 1 << "." << allcontent[i].title << "  " << "Posted by " << allcontent[i].nickname << "  " << convertstrtime(converttime(allcontent[i].time)) << endl;
}

void displaycomment(const content& c, int indent = 0)
{
	
	string indentStr(indent, ' ');
	cout << indentStr << "Text: " << c.text << endl << endl;
	cout << indentStr << "Posted by: " << c.nickname << endl;
	cout << indentStr << "Posted at: " << convertstrtime(converttime(c.time)) << endl;
	cout << indentStr << "-----------------------------" << endl;

	for (const auto& comment : c.comments)
	{
		displaycomment(comment, indent + 4);
	}
}


void displaypost(int n ,int indent=0)
{
	int m = n - 1;
	clearscreen();
	sortbytime(allcontent[m].comments);
	string indentStr(indent, ' ');
	cout << indentStr << "Title: " << allcontent[m].title << endl << endl << endl;
	cout << indentStr << "Text: " << allcontent[m].text << endl << endl;
	cout << indentStr << "Posted by: " << allcontent[m].nickname << endl;
	cout << indentStr << "Posted at: " << convertstrtime(converttime(allcontent[m].time)) << endl;
	cout << indentStr << "-----------------------------" << endl;

	for (const auto& comment : allcontent[m].comments)
	{
		displaycomment(comment, indent + 4);
	}
}

void displaypost4reply(int n, int indent = 0)
{
	int m = n - 1;
	clearscreen();
	sortbytime(allcontent[m].comments);
	string indentStr(indent, ' ');
	cout << indentStr << "Title: " << allcontent[m].title << endl << endl << endl;
	cout << indentStr << "Text: " << allcontent[m].text << endl << endl;
	cout << indentStr << "Posted by: " << allcontent[m].nickname << endl;
	cout << indentStr << "Posted at: " << convertstrtime(converttime(allcontent[m].time)) << endl;
	cout << indentStr << "-----------------------------" << endl;

	int i = 1;
	for (const auto& comment : allcontent[m].comments)
	{
		cout << i << '.' << endl;
		displaycomment(comment, indent + 4);
		i++;
	}

}

void chooseone()
{
	int n;
	cout << "Please enter a number of the post you want to browse" << endl;
	cin >> n;
	currentpostnum = n;
	displaypost(n);
	cout << endl;
	display_selections(4, "Back to Browse,Comment,Home,Exit");
	choose_module();
}

void chooseone2reply()
{
	int n;
	cout << "Please enter the number of the post you want to reply to" << endl;
	cin >> n;
	currentpostnum = n;
	displaypost4reply(n);
	cout << endl;
	display_selections(3, "Reply,Home,Exit");
	choose_module();
}

void subscribeaftcomm(string postphonum)
{
	if (acc[currentaccno].subscrinum != 0)
	{
		for (string subscriphonum : acc[currentaccno].subscription)
		{
			if (subscriphonum == postphonum)
				return;
		}
	}
	cout << "You haven't subscribed to this author, do you want to subscribe ?" << endl;
	display_selections(2, "Yes,No");
	if (final_selection == "No")
		browse();
	else if (final_selection == "Yes")
	{
		acc[currentaccno].subscrinum++;
		acc[currentaccno].subscription.push_back(postphonum);
		ofstream out_file("accounts", ios::out);
		if (!out_file)
		{
			cout << "An error occurred: failed to open file";
			exit(-1);
		}
		for (accounts account : acc)
		{
			out_file << account.accphonum << endl << account.accpassword << endl << account.nickname << endl << account.subscrinum << endl;
			for (string sub : account.subscription)
				out_file << sub << endl;
		}
		out_file.close();
		return;
	}
}

void comment()
{
	content newcomment;
	cout << "Please enter the text below" << endl;
	cin.ignore();
	getline(cin, newcomment.text);
	newcomment.commentnum = 0;
	newcomment.ifcomment = 0;
	newcomment.nickname = currentnickname;
	newcomment.phonum = currentphonum;
	newcomment.time = gettime();
	allcontent[currentpostnum - 1].ifcomment = 1;
	allcontent[currentpostnum - 1].commentnum++;
	allcontent[currentpostnum - 1].comments.push_back(newcomment);
	ofstream out_file("content", ios::out);
	if (!out_file)
	{
		cout << "An error occurred: failed to open file" << endl;
		exit(-1);
	}
	out_file << endl;
	out_file.close();
	for (content c : allcontent)
	{
		postinfile(c);
	}
	cout << "Commentted successfully" << endl;
	subscribeaftcomm(allcontent[currentpostnum - 1].phonum);
	display_selections(3, "Browse,Home,Exit");
	choose_module();
}

void reply()
{
	content newcomment;
	cout << "Please enter the number of the comment you want to reply to" << endl;
	cin >> currentcomment;
	cout << "Please enter the text below" << endl;
	cin.ignore();
	getline(cin, newcomment.text);
	cout << "Are you sure to upload now ?" << endl;
	display_selections(2, "Yes,No");
	if (final_selection == "No")
	{
		cout << "Upload canceled";
		home();
	}
	newcomment.commentnum = 0;
	newcomment.ifcomment = 0;
	newcomment.nickname = currentnickname;
	newcomment.phonum = currentphonum;
	newcomment.time = gettime();
	allcontent[currentpostnum - 1].comments[currentcomment - 1].ifcomment = 1;
	allcontent[currentpostnum - 1].comments[currentcomment - 1].commentnum++;
	allcontent[currentpostnum - 1].comments[currentcomment - 1].comments.push_back(newcomment);
	ofstream out_file("content", ios::out);
	if (!out_file)
	{
		cout << "An error occurred: failed to open file" << endl;
		exit(-1);
	}
	out_file << endl;
	out_file.close();
	for (content c : allcontent)
	{
		postinfile(c);
	}
	cout << "Replied successfully" << endl;
	display_selections(3, "Back to Comments,Home,Exit");
	choose_module();
}
#include<string>
#include<iostream>
#include<fstream>
#include<cctype>
#include<random>
#include"GeneralFunctions.h"
#include"Choose_Module.h"
#include"GlobalVariable.h"

using namespace std;

string currentphonum, currentnickname;
accounts acc[200];
int currentaccno;

string geranstring(int length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const int max_index = sizeof(charset) - 2;
    random_device rd; 
    mt19937 generator(rd()); 
    uniform_int_distribution<> distribution(0, max_index);

    string random_string;
    for (int i = 0; i < length; ++i) {
        random_string += charset[distribution(generator)];
    }

    return random_string;
}

int phonumvalidity(string phonum)
{
	const string validbeginn[] = { "134","135","136","137","138","139","147","150","151","152","157","158","159","188","130","131","132","155","156","185","186","133","149","153","173","177","180","181","189" };
	if (phonum.size() != 11)
	{
		cout << "Invalid phone number, please enter again"<<endl;
		return -1;
	}
	for (char i : phonum)
	{
		if (!(i >= '0' && i <= '9'))
		{
			cout << "Invalid phone number, please enter again" << endl;
			return -1;
		}
	}
	if (phonum.size() != 11)
	{
		cout << "Invalid phone number, please enter again" << endl;
		return -1;
	}
	string phonumbeginn;
	for (int i = 0; i < 3; i++)
		phonumbeginn += phonum[i];
	bool whethervalid = 0;
	for (string validphonumbeginn : validbeginn)
		if (phonumbeginn == validphonumbeginn)
			whethervalid = 1;
	if(whethervalid==0)
	{
		cout << "Invalid phone number, please enter again"<<endl;
		return -1;
	}
	return 0;
}

int passwordvalidity(string password)
{
	bool whethervalid = 0;
	if (password.size() < 8)
	{
		cout << "The password should not be less than 8 characters, please enter again"<<endl;
		return -1;
	}
	bool lower = 0, upper = 0, whenum = 0;
	for (char i : password)
	{
		if (isdigit(i))
			whenum = 1;
		else if (islower(i))
			lower = 1;
		else if (isupper(i))
			upper = 1;
	}
	if(whenum==0||upper==0||lower==0)
	{
		cout << "The password must contain both uppercase and lowercase letters and numbers, please enter again"<<endl;
		return -1;
	}
	return 0;
}

int accountunique(string phonum)
{
	struct accounts
	{
		string accphonum;
		string accpassword;
		string nickname;
	};
	int sum = 1;
	accounts acc[200];
	ifstream in_file("accounts", ios::in);
	if (!in_file)
	{
		cout << "An error occurred: failed to open file" << endl;
		exit(-1);
	}
	in_file >> acc[0].accphonum >> acc[0].accpassword;
	while (!in_file.fail())
	{
		in_file >> acc[sum].accphonum >> acc[sum].accpassword;
		sum++;
	}
	in_file.close();
	for(accounts i:acc)
		if (phonum == i.accphonum)
		{
			cout << "This phone number has already been registered, please enter again"<<endl;
			return 0;
		}
	return 1;
}

void login()
{
	int accnum = -1, sum = 0, failnum = 0;
	bool find = 0;
	string phnum, password, verifyinput;
	string verify;
	clearscreen();
	ifstream in_file("accounts", ios::in);
	if (!in_file)
	{
		cout << "An error occurred: failed to open file" << endl;
		exit(-1);
	}
	getline(in_file, acc[0].accphonum);
	getline(in_file, acc[0].accpassword);
	getline(in_file, acc[0].nickname);
	in_file >> acc[0].subscrinum;
	if (acc[0].subscrinum != 0)
	{
		for (int i = 0; i < acc[0].subscrinum; i++)
		{
			string subscri;
			in_file >> subscri;
			acc[0].subscription.push_back(subscri);
		}
	}
	sum++;
	while (!in_file.fail())
	{
		in_file.ignore();
		getline(in_file, acc[sum].accphonum);
		getline(in_file, acc[sum].accpassword);
		getline(in_file, acc[sum].nickname);	
		in_file >> acc[sum].subscrinum;
		if (acc[sum].subscrinum != 0)
		{
			for (int i = 0; i < acc[sum].subscrinum; i++)
			{
				string subscri;
				in_file >> subscri;
				acc[sum].subscription.push_back(subscri);
			}
		}
		sum++;
	}
	in_file.close();
	cin.ignore();
enterpass:
	cout << "Please enter your phone number below" << endl;
	getline(cin, phnum);
	cout << "Please enter your password below" << endl;
	std::getline(std::cin, password);
	verify = geranstring(4);
	cout << "Please enter the verification code shown below" << endl;
	cout << verify<<endl;
	std::getline(std::cin, verifyinput);
	if (verifyinput != verify)
	{
		cout << "Wrong verification code" << endl;
		goto enterpass;
	}
	if (contain_space(phnum) == 1 || contain_space(password) == 1)
	{
		cout << "Your input contains spaces, please re-enter it" << endl;
		goto enterpass;
	}
	accnum = -1;
	for (accounts i : acc)
	{
		accnum++;
		if (i.accphonum == phnum)
		{
			find = 1;
			break;
		}
	}
	if (find == 1)
	{
		if (password == acc[accnum].accpassword)
		{
			cout << "Log in succesfully" << endl;
			currentnickname = acc[accnum].nickname;
			currentphonum = acc[accnum].accphonum;
			currentaccno = accnum;
			loginstatus = 1;
			display_selections(2, "Home,Exit");
			choose_module();
		}
		else
		{
			failnum++;
			cout << "Wrong password, please enter your phone number and password again" << endl;
			cout << "You have entered wrong password for " << failnum << " times." << endl;
			if (failnum > 3)
			{
				cout << "The program has been forced to exit" << endl;
				exit(-1);
			}
			cout << "Please note that if you entered wrong password more than 3 times, the program will be forced to exit." << endl;
			goto enterpass;
		}
	}
	else
	{
		cout << "This phone number has not been registered";
		display_selections(2, "Register,Exit");
		choose_module();
	}
}

void regis()
{
	string phonum, password, repassword, nickname, verify,verifyinput;
	clearscreen();
	cout << "Please enter your phone number below"<<endl;
	cin.ignore();
	std::getline(std::cin, phonum);
	while (phonumvalidity(phonum) == -1)
		std::getline(std::cin, phonum);
	while (accountunique(phonum) == 0)
		std::getline(std::cin, phonum);
	cout << "Please set your nickname"<<endl;
	std::getline(std::cin, nickname);
	cout << "Please enter your password below" << endl;
regisenterpass:
	std::getline(std::cin, password);
	do
	{
		verify = geranstring(4);
		cout << "Please enter the verification code shown below" << endl;
		cout << verify << endl;
		std::getline(std::cin, verifyinput);
		if (verifyinput != verify)
		{
			cout << "Wrong verification code" << endl;
		}
	} while (verifyinput != verify);
	while (passwordvalidity(password) == -1)
		goto regisenterpass;
	cout << "Please Re-enter your password below"<<endl;
	std::getline(std::cin, repassword);
	if (repassword != password)
	{
		cout << "Incorrect password,please set your password again"<<endl;
		goto regisenterpass;
	}
	ofstream out_file("accounts", ios::app);
	if (!out_file)
	{
		cout << "An error occurred: failed to open file";
		exit(-1);
	}
	out_file << phonum << endl << password << endl << nickname << endl << '0' << endl;
	cout << "Successfully Registered"<<endl;
	out_file.close();
	display_selections(2, "Log in,Exit");
	choose_module();
}

void accountsinfile()
{
	int sum = 0;
	ifstream in_file("accounts", ios::in);
	if (!in_file)
	{
		cout << "An error occurred: failed to open file" << endl;
		exit(-1);
	}
	getline(in_file, acc[0].accphonum);
	getline(in_file, acc[0].accpassword);
	getline(in_file, acc[0].nickname);
	in_file >> acc[0].subscrinum;
	acc[0].subscription.clear();
	if (acc[0].subscrinum != 0)
	{
		for (int i = 0; i < acc[0].subscrinum; i++)
		{
			string subscri;
			in_file >> subscri;
			acc[0].subscription.push_back(subscri);
		}
	}
	sum++;
	while (!in_file.fail())
	{
		in_file.ignore();
		getline(in_file, acc[sum].accphonum);
		getline(in_file, acc[sum].accpassword);
		getline(in_file, acc[sum].nickname);
		in_file >> acc[sum].subscrinum;
		acc[sum].subscription.clear();
		if (acc[sum].subscrinum != 0)
		{
			for (int i = 0; i < acc[sum].subscrinum; i++)
			{
				string subscri;
				in_file >> subscri;
				acc[sum].subscription.push_back(subscri);
			}
		}
		sum++;
	}
	in_file.close();
}
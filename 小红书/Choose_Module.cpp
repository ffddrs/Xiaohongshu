#include<string>
#include<iostream>
#include"Login&Register.h"
#include"Home.h"
#include"GlobalVariable.h"
#include"Upload.h"
#include"Browse.h"
#include"Delete.h"

using namespace std;

void choose_module()
{
    if (final_selection == "Log in")
        login();
    else if (final_selection == "Register")
        regis();
    else if (final_selection == "Exit")
        exit(0);
    else if (final_selection == "Home")
        home();
    else if (final_selection == "Upload")
        upload();
    else if (final_selection == "Browse")
        browse();
    else if (final_selection == "Choose one")
        chooseone();
    else if (final_selection == "Delete")
        deletepost();
    else if (final_selection == "Back to Browse")
        browse();
    else if (final_selection == "Comment")
        comment();

    else if(true)
    {
        cout << "Invalid input, go to home page";
        home();
    }
}

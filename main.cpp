// temp for our project


#pragma once
#include <iostream>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#define N 30  // max char for username

typedef struct {
	char name[N];  // name +last name 
	//char lname[N];
	char username[N];  // username
	int password;
	int type;  //  1 = HR  ,  2 = Employee  ,  3 = Contractor
} User;

void mainmenu();
void login();
void sign();
void tech();
void employe();
void HR();
void contractor();


int main()
{
	cout << "\nCCCCCC                                                       MMM    MMM " << endl;
	cout << "CC       ooo   n       t                           t        M   M  M   M" << endl;
	cout << "C       o   o  nnnn   ttt   r rrrr  aaaa    cccc  ttt      M     MM     M    eeee" << endl;
	cout << "CC      o   o  n   n   t     r      a  a    c      t      M              M   e--- " << endl;
	cout << "CCCCCC   ooo   n   n   tttt  r      aaaaaa  cccc   tttt  M                M  eeee " << endl;

	cout << "\n\n\n+++++++++++++++++++++++++++++++++++++++++++\n+++  HELLO! :), welcome to ContractMe!  +++  (for technical support press '0' at anytime)\n+++++++++++++++++++++++++++++++++++++++++++\n" << endl;
	

	mainmenu();
	
// Good Bye message with hand gesture :DD
return 0;
}

void mainmenu()
{
	int choice = 99;
	cout << "\n\tLOGIN & Sign up page\n\tEnter your choice:\n\n1. Login \n2. Sign up \n9. Exit\n" << endl;
	cin >> choice;
	switch (choice)
	{
	case 0: // technical support
		tech();
		break;
	case 1: // login
		login();
		break;
	case 2: // sign up
		sign();
		break;
	case 9: // exit
		break;
	default:
		cout << "\nError, please try again:\n" << endl;
		mainmenu(); // entering to main again, (loop)
	}
}
void login()
{
	char user[N];
	cout << "please enter your user name:\n" << endl;
	cin >> user;
	// entering database to check if username exists.
	// if no, error
	// if yes, checking if password matchs, 
	// if no error,
	// if yes -> returning from function the Type of the user
	//


	//int type = func();

	//cout << "\n\tLOGIN & Sign up page\n\tEnter your choice:\n\n1. Login \n2. Sign up \n9. Exit\n" << endl;
	//cin >> choice;
	//switch (choice)
	//{
	//case 0: // tech
	//	tech();
	//	break;
	//case 1: // type 1 = HR
	//	HR();
	//	break;
	//case 2: // type 2 = employe
	//	employe();
	//	break;
	//case 3: // type 3 = contractor
	//	contractor();
	//	break;
	//case 9: // exit
	//	break;
	//default:
	//	cout << "\nError, please try again:\n" << endl;
	//	login(); // entering to login again, (loop)
	//}
}

void sign()
{

}

void tech()
{

}

void employe()
{

}

void HR()
{

}

void contractor()
{

}
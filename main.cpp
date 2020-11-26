#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#define N 30  // max char for username

const int HR_TYPE = 1;
const int EMPLOYEER_TYPE = 2;
const int CONSTARCTOR_TYPE = 3;

int ContractorCount = 0; // Contractor user count.
int EmployerCount = 0;  // Employer user count.

typedef struct {
	char *name;  // name +last name 
	char *username;  // username
	char *password;
	int UserType=0;  //  1 = HR  ,  2 = Employeer  ,  3 = Contractor
} User;

typedef struct {
	User details;
	int salary;
	//WorkDay *workDay;
	int WorkDaySize;
}Contractor;
 
typedef struct {
	int day;
	int month;
	int startTime;
	int endTime;
}WorkDay;

void mainmenu();
void login();
void signUp();
void lowercase(char*);
void writeUserToFile(User);
void tech();
void hrMenu();
void employeerMenu();
void contractorMenu();
void ChooseMenu(int type);


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
	int choice;
	
	do {
		cout << "\n\tLOGIN & Sign up page\n\tEnter your choice:\n\n1. Login \n2. Sign up \n3. Exit\n" << endl;
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
			signUp();
			break;
		case 3: // exit
			break;
		default:
			cout << "\nError, please try again:\n" << endl;
		} 
	} while (choice != 3);
}

void login()
{
	char user[N];
	int pass;
	cout << "please enter your username:\n" << endl;
	cin >> user;
	cout << "please enter your password:\n" << endl;
	cin >> pass;

	lowercase(user); //Change to lowercase before searching.
	
	ifstream inFile;
	inFile.open("database.txt");
	if (inFile.fail()) {
		cerr << "error opening file" << endl;
		exit(1);
	}
	char* checkuser = new char[strlen(user) + 1];
	int checkpass;
	int checktype;
	while (!inFile.eof()) { // needs to compare only with the username, (for now it compares to everything which is wrong.)
		{
			inFile >> checkuser;  // name is in temp - not using.
			inFile >> checkuser;
			cout << checkuser << endl;
			if (strcmp(checkuser, user) == 0)
			{
				cout << "USER EXISTS\n";
				inFile >> checkpass;
				if (checkpass == pass)
				{
					cout << "Welcome\n";
					inFile >> checktype;
					inFile.close();
					ChooseMenu(checktype);
					return;
				}
				else cout << "Wrong pass.\n";
				return;
			}
		}
	}
	cout << "user does not exsist in the database, try again";
	inFile.close();
	return;
}

void signUp() // only Employer
{
	User u1;
	char name[N], username[N], password[N];

	cout << ("\nHello, enter your name, user and password:\n");
	cin >> name >> username >> password;
	
	lowercase(username); //Account usernames will be stored in lowercase on the DataBase.
	u1.name = name;
	u1.username = username;
	u1.password = password;
	u1.UserType = EMPLOYEER_TYPE;  // employer 
	writeUserToFile(u1);

	EmployerCount++; // Counting the number of employers in the system - for "Statistic Analysis"
}

void lowercase(char* lower)
{
	for (unsigned int i = 0; i < strlen(lower); i++) // to lowercase the chars
	{
		lower[i] = tolower(lower[i]);
	}
}

void writeUserToFile(User newUser)
{
	ofstream inFile;
	inFile.open("database.txt",ios::app);
	if (inFile.fail()) {
		cout << "error opening file" << endl;
		exit(1);
	}
	inFile << "\n";
	inFile << newUser.name << " ";
	inFile << newUser.username << " ";
	inFile << newUser.password << " ";
	inFile << newUser.UserType << " ";
	//if (newUser.UserType == 3) // if its contractor
	//	inFile << newUser.salary;
	inFile.close();
}

void ChooseMenu(int type)
{
	if (type == 1)
		hrMenu();
	else if (type == 2)
		employeerMenu();
	else
		contractorMenu();
}

void tech()
{

}

void hrMenu()
{

}
void employeerMenu()
{

}

void contractorMenu()
{

}


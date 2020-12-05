#pragma once
#include <iostream>
#include <windows.h> 
#include <conio.h>
#include <dos.h>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>

using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#define N 40  // max char for username

const int HR_TYPE = 1;
const int EMPLOYEER_TYPE = 2;
const int CONTRACTOR_TYPE = 3;

int ContractorCount = 0; // Contractor user count.
int ContractorHired = 0;
int EmployerCount = 0;  // Employer user count.


typedef struct {
	char *fullName;
	char *username;
	char *password;
	int UserType = 0;  //  1 = HR  ,  2 = Employeer  ,  3 = Contractor
} User;

typedef struct {
	User details;
	int salary;
	//WorkDay *workDay;
}Contractor;

typedef struct {
	int day;
	int startTime;
	int endTime;
}WorkDay;


void textColor(int textcolor);
void ourLogo();
void printBye();
void mainmenu();
string calendar(char*);
void login();
void signUp();
void writeUserToFile(User);
void tech();
bool checkUserExists(ifstream&, char*);
void ChooseMenu(int type, char *userInput);
void lowercase(char*);
int calculateHours(int start, int finish);

void hrMenu(char *userInput);
void statisticAnalysis();
void addNewWorker();
void monitorHiring();
void workersFeed();

void employeerMenu(char *userInput);
void hiringHistory(char*);
void searchContractor(char*);

void contractorMenu(char *userInput);


int main()
{
	//system("color 1");  // cmd background color
	//textColor(1);

	//color tester
	/*HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int k=0;
	SetConsoleTextAttribute(hConsole, k);
	for (k = 1; k < 255; k++)
	{
		// pick the colorattribute k you want
		SetConsoleTextAttribute(hConsole, k);
		cout << k << " I want to be nice today!" << endl;
	}
	*/
	
	ourLogo(); // function to print our logo


	textColor(15);
	cout << endl << endl
		 <<"+++++++++++++++++++++++++++++++++++++++++++" << endl
		 <<"+++  HELLO! :), welcome to ContractMe!  +++  (for technical support press '0' at anytime)" << endl
		 <<"+++++++++++++++++++++++++++++++++++++++++++" << endl;

	textColor(15); // white text
	//calendar("Maayan");
	mainmenu();

	printBye();
	getchar();
	getchar();
	return 0;
}

void textColor(int textcolor)  // function to switch text colors
{
	/*
	0 = black
	1 = dark blue
	3 = dark cyan
	9 = blue
	11 = cyan
	15 = white
	31 = white text on blue background
	240 = black text on white background
	241 = dark blue text on white background
	249 = blue text on white background
	*/
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, textcolor);
}

void ourLogo() // func to print our logo
{
	textColor(48);
	cout << "                                                                                  " << endl;
	textColor(48); cout << "  ";textColor(1); cout << " CCCCCCC                                                   M     M            "; textColor(48); cout << "  " << endl;
	textColor(48); cout << "  ";textColor(1); cout << " CCC           n      t                         t         MMM   MMM     eeeee "; textColor(48); cout << "  " << endl;
	textColor(48); cout << "  ";textColor(1); cout << " CC       ooo  nnnn  ttt   r rrrr aaaaa  ccccc ttt       M   M M   M    e     "; textColor(48); cout << "  " << endl;
	textColor(48); cout << "  ";textColor(1); cout << " CC      o   o n   n  t     r     a   a  c      t       M     M     M   eeee  "; textColor(48); cout << "  " << endl;
	textColor(48); cout << "  ";textColor(1); cout << " CCC     o   o n   n  t     r     a   a  c      t      M             M  e     "; textColor(48); cout << "  " << endl;
	textColor(48); cout << "  ";textColor(1); cout << " CCCCCCC  ooo  n   n  tttt  r     aaaaaa ccccc  tttt  M               M eeeee "; textColor(48); cout << "  " << endl;
	textColor(48);
	cout << "                                                                                  " << endl;
	textColor(15); // returning to white text
}

void printBye()
{
	cout << " " << endl
		<< "                        .-''''-.     " << endl
		<< "                       / .===. \\  " << endl
		<< "                       \\/ 6 6 \\/  "<< endl
		<< "                       ( \\___/ )  "<< endl
		<< "  _________________ooo__\\_____/_____________________ " << endl
		<< " /                                                  \\ " << endl
		<< " |  Good bye & and thank you for using ContractMe!   | " << endl
		<< " \\______________________________ooo_________________/ " << endl
		<< "                        |  |  | " << endl
		<< "                        |_ | _| " << endl
		<< "                        |  |  | " << endl
		<< "                        |__|__| " << endl
		<< "                        /-'Y'-\\ " << endl
		<< "                       (__/ \\__)  " << endl;
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
	char userInput[N];
	int pass;
	cout << "please enter your username:\n";
	cin >> userInput;
	cout << "please enter your password:\n";
	cin >> pass;

	lowercase(userInput); //Change to lowercase before checking if exists.

	ifstream inFile;
	inFile.open("database.txt");
	if (inFile.fail()) {
		cerr << "error opening file" << endl;
		exit(1);
	}
	//char* checkuser = new char[strlen(user) + 1];
	int checkpass;
	int checktype;
	if (checkUserExists(inFile, userInput)) {
		inFile >> checkpass;
		if (checkpass == pass)
		{
			cout << "\n";
			inFile >> checktype;
			inFile.close();
			ChooseMenu(checktype, userInput);
			return;
		}
		else cout << "Wrong pass.\n";
		return;
	}
	cout << "user does not exsist in the database, try again";
	inFile.close();
	return;
}

void signUp() // only Employer can signup
{
	User u1;
	char name[N], username[N], password[N];

	cout << ("\nHello, enter your name, username and password:\n");
	cout << "name: " << endl;
	cin >> name;
	cout << "username: " << endl;
	cin >> username;
	cout << "password: " << endl;
	cin >> password;

	lowercase(username); //Account usernames will be stored in lowercase on the DataBase.

	// Username in database must be unique.
	ifstream inFile;
	inFile.open("database.txt");
	if (inFile.fail()) {
		cerr << "error opening file" << endl;
		exit(1);
	}
	while (checkUserExists(inFile, username)) {
		cout << "Username taken."
			<< "Enter another username " << endl;
		cin >> username;
	}
	u1.fullName = name;
	u1.username = username;
	u1.password = password;
	u1.UserType = EMPLOYEER_TYPE;  // employer 
	writeUserToFile(u1);

	EmployerCount++; // Counting the number of employers in the system - for "Statistic Analysis"
	employeerMenu(username);
}

void writeUserToFile(User newUser)
{
	ofstream inFile;
	inFile.open("database.txt", ios::app);
	if (inFile.fail()) {
		cout << "error opening file" << endl;
		exit(1);
	}
	inFile << "\n";
	inFile << newUser.username << " ";
	inFile << newUser.password << " ";
	inFile << newUser.fullName << " ";
	inFile << newUser.UserType << " ";
	inFile.close();
	inFile.open("HiringHistory.txt", ios::app);
	if (inFile.fail()) {
		cout << "error opening file" << endl;
		exit(1);
	}
	inFile << "UserName: " << newUser.username << endl;
	inFile << "HiringHistory: ";
	inFile << endl;
	inFile.close();
}

void ChooseMenu(int type, char *userInput)
{
	if (type == 1)
		hrMenu(userInput);
	else if (type == 2)
		employeerMenu(userInput);
	else // type 3
		contractorMenu(userInput);
}

void tech()
{
	string problem;
	cout << "\nHello, welcome to tech support.\n please describe your problem: " << endl;
	cin >> problem;
	cout << "\nThank you for your message, we will return to you with a solution asap " << endl;
	ofstream inFile;
	inFile.open("problem.txt", ios::app);
	if (inFile.fail()) {
		cout << "error opening file" << endl;
		exit(1);
	}
	// inFile << problem << //   bad loop

	inFile.close();
	
}

void contractorMenu(char *userInput)
{
	//// name username password type workHours payPerHour NotAvailable(DayOfMonth)
		// welcome to the contractor menu, and print his work hours and salary
	cout << "Hello '" << userInput << "', ";
	cout << "Welcome to the Contractor Menu" << endl;

	fstream inFile; //getting workHours and payPerHour from the database
	inFile.open("database.txt");
	if (inFile.fail()) {
		cout << "error opening file" << endl;
		exit(1);
	}
	int workHours = 0, payPerHour = 0;
	char* checkInput = new char[strlen(userInput) + 1];
	while (!inFile.eof()) {
		inFile >> checkInput; // Getting the UserName field from the file.
		if (strcmp(checkInput, userInput) == 0) // we are now in the correct user
		{
			inFile >> workHours; // Ignoring first word after username (pass).
			inFile >> workHours; // Ignoring type
			inFile >> workHours; // getting workHours
			inFile >> payPerHour; // getting payPerHour
			break;
		}
	}
	
	inFile.close();

	cout << "You worked " << workHours << " hours this month, and your salary is: " << (workHours * payPerHour) << endl;

	// entering to the contractor menu options
	int choice = 0;
	int startHour = 0, finishHour = 0, TodayHours = 0, hourlyPay = 0, vacation = 0;
	while (choice != 3) {
		cout << "\nWhat do you want to do next? " << endl
			<< "1.Report work hours" << endl
			<< "2.Report vacation" << endl
			<< "3.Sign out" << endl;
		cin >> choice;
		switch (choice) {
		case 0: // technical support
			tech();
			break;
		case 1: //report work hours
			cout << "Enter the hour u Started to work today: " << endl;
			cin >> startHour;
			cout << "Enter the hour u Finished to work today: " << endl;
			cin >> finishHour;
			TodayHours = calculateHours(startHour, finishHour);
			cout << "Enter your hourly pay: " << endl;
			cin >> hourlyPay;
			cout << "you worked " << TodayHours << " hours today." << endl;
			// now we need to enter these values to the database:
			// add the TodayHours to his hours.
			// update the hourly pay if nessesary
			break;
		case 2: //Report vacation
			cout << "Enter the date (number of the day in this month) u are in vacation: " << endl;
			cin >> vacation;
			// now we need to add this day to the database:
			// if he wants to add another vacation day, he can re enter this option.
			break;
		case 3:
			// edit
			break;
		case 4:
			cout << "Signed out of the system." << endl;
			break;
		default:
			cout << "Please enter choice between 1-3 only, 3 to sign out." << endl;
		}
	}
}

//  
// HELPERS FUNCTION
// 

int calculateHours(int start, int finish) // example:: start = 8, finish = 17 ... => = 9 hours
{
	int hours = 0;
	for (int i = start; i < finish; i++)
	{
		hours++;
	}
	return hours;
}

void lowercase(char* lower)
{
	for (unsigned int i = 0; i < strlen(lower); i++) // to lowercase the chars
	{
		lower[i] = tolower(lower[i]);
	}
}

bool checkUserExists(ifstream& inFile, char* userInput)
{
	char* checkInput = new char[strlen(userInput) + 1];
	string skipLine;
	while (!inFile.eof()) {
		inFile >> checkInput; // Getting the UserName field from the file.
		if (strcmp(checkInput, userInput) == 0) {
			return true;
		}
		getline(inFile, skipLine); // Skiping line
	}
	return false; // If no matching user was found.
}

void statisticAnalysis() {
	cout << "Hello," << endl
		<< "Company’s Statistic Analysis  " << endl;
	cout << "Contractor numbers: " << ContractorCount << endl
		<< "Contractor Hired: " << ContractorHired << endl
		<< "Employer Numbers: " << EmployerCount << endl;
}

void hrMenu(char *userInput)
{
	int choice = 0;
	while (choice != 5) {
		cout << "Hello, welcome to the HR Menu, what do you want to do next? " << endl
			<< "1.Statistic Analysis" << endl
			<< "2.Monitor Hiring" << endl
			<< "3.Add New Worker" << endl
			<< "4.Workers Feed" << endl
			<< "5.Sign out" << endl;
		cin >> choice;
		switch (choice) {
		case 0: // technical support
			tech();
			break;
		case 1:
			statisticAnalysis();
			break;
		case 2:
			monitorHiring();
			break;
		case 3:
			addNewWorker();
			break;
		case 4:
			workersFeed();
			break;
		case 5:
			cout << "Signed out of the system." << endl;
			break;
		default:
			cout << "Please enter choice between 1-5 only, 5 to sign out." << endl;
		}
	}
}

void addNewWorker() {
	char username[N], fullName[N], skills[N], place[N];
	int password, wage;
	cout << "Hello, welcome to add a new worker " << endl;
	cout << "Enter username: ";
	cin >> username;
	cout << endl << "Enter password: ";
	cin >> password;
	cout << endl << "Enter full name: ";
	cin >> fullName;
	cout << endl << "Enter wage: ";
	cin >> wage;
	cout << endl << "Enter intersts: ";
	cin >> skills;
	cout << endl << "Enter place: ";
	cin >> place;
	ofstream inFile;
	inFile.open("database.txt", ios::app);
	if (inFile.fail()) {
		cout << "error opening file" << endl;
		exit(1);
	}
	inFile << username << " ";
	inFile << password << " ";
	inFile << fullName << " ";
	inFile << CONTRACTOR_TYPE << " ";
	inFile << wage << " ";
	inFile << skills << " ";
	inFile << place << " ";
	inFile.close();
	inFile.open("workHistory.txt", ios::app);
	if (inFile.fail()) {
		cout << "error opening file" << endl;
		exit(1);
	}
	inFile << "UserName: " << username << endl;
	inFile << "ReportedDays: ";
	inFile << endl;
	inFile.close();
}

void monitorHiring() {
	fstream inFile;
	inFile.open("HiringHistory.txt");
	if (inFile.fail()) {
		cout << "error opening file" << endl;
		exit(1);
	}
	string getLine;
	while (!inFile.eof()) {
		getline(inFile, getLine); // Skiping line
		cout << getLine;
		//cout << endl;
	}
	inFile.close();
}

void workersFeed() {
	ifstream inFile;
	inFile.open("database.txt");
	if (inFile.fail()) {
		cout << "error opening file" << endl;
		exit(1);
	}
	char userName[N];
	char temp[N];
	cout << "Hello, Please enter the username" << endl;
	cin >> userName;
	if (checkUserExists(inFile, userName)) {
		inFile >> temp; // skipping password field.
		inFile >> temp; // reading fullname field.
		cout << temp;
		inFile >> temp; // skipping user Type.
		inFile >> temp; // reading wage field.
		cout << temp;
		inFile >> temp; // reading skills field.
		cout << temp;
		inFile >> temp; // reading place field.
		cout << temp;
		inFile.close();
		inFile.open("workHistory.txt");
		while (!inFile.eof()) {
			inFile >> temp;
			inFile >> temp;
			if (strcmp(temp, userName) == 0) {
				while (temp != "UserName:") {
					inFile >> temp;
					cout << temp;
					// cout << endl;
				}
			}
		}
	}
	else cout << "User does not exist." << endl;
	inFile.close();
}

void employeerMenu(char *userInput)
{
	int choice = 0;
	while (choice != 3) {
		cout << "Hello, welcome to the Employeer Menu, what do you want to do next? " << endl
			<< "1.Hiring History" << endl
			<< "2.Search Contractor" << endl
			<< "3.Sign out" << endl;
		cin >> choice;
		switch (choice) {
		case 0: // technical support
			tech();
			break;
		case 1:
			hiringHistory(userInput);
			break;
		case 2:
			searchContractor(userInput);
			break;
		case 3:
			cout << "Signed out of the system." << endl;
			break;
		default:
			cout << "Please enter choice between 1-3 only, 3 to sign out." << endl;
		}
	}
}

void hiringHistory(char* currentUser) {
	ifstream inFile;
	char temp[N];
	inFile.open("HiringHistory.txt");
	while (!inFile.eof()) {
		inFile >> temp;
		if (strcmp(temp, "UserName:")) {
			inFile >> temp;
			if (strcmp(temp, currentUser)) {
				while (strcmp(temp, "UserName:") != 0) {
					inFile >> temp;
					cout << temp;
				}
				inFile.close();
				return;
			}
		}
	}
	inFile.close();
}

void searchContractor(char* currentUser) {
	char location[N], skills[N];
	int minWage, maxWage;
	string date;
	cout << "Enter location ( 0 if not needed)" << endl;
	cin >> location;
	cout << "Enter Skills ( 0 if not needed)" << endl;
	cin >> skills;
	cout << "Enter minimum wage ( 0 if not needed)" << endl;
	cin >> minWage;
	cout << "Enter maxWage ( 0 if not needed)" << endl;
	cin >> maxWage;
	cout << "Enter date ( 0 if not needed)" << endl;
	date = calendar(currentUser);
}

string calendar(char* currentUser) {
	int month, day;
	do {
		cout << "Enter your month (1-12)" << endl
			<< "1 - January " << endl
			<< "2 - February " << endl
			<< "3 - March " << endl
			<< "4 - April " << endl
			<< "5 - May " << endl
			<< "6 - June " << endl
			<< "7 - July " << endl
			<< "8 - August " << endl
			<< "9 - September " << endl
			<< "10 - October " << endl
			<< "11 - November " << endl
			<< "12 - December " << endl;
		cin >> month;
		if (month < 1 || month > 12) {
			cout << "Error, Month must be between 1 and 12 Try again, "
				<< currentUser << endl;
		}
	} while (month < 1 || month > 12);
	do {
		cout << "Enter day" << endl;
		cin >> day;
		if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12)) {
			if ((day < 1) || (day > 31))
				cout << "Error, in Months 1,3,5,7,8,10,12 the Day must be between 1 and 31\nTry again, "
				<< currentUser << endl;
			else break;
		}
		else if ((month == 4) || (month == 6) || (month == 9) || (month == 11)) {
			if ((day < 1) || (day > 31))
				cout << "Error, in Months 4,6,9,11 the Day must be between 1 and 30\nTry again, "
				<< currentUser << endl;
			else break;
		}
		else {
			if ((day < 1) || (day > 28))
				cout << "Error, in Month February the Day must be between 1 and 28\nTry again, "
				<< currentUser << endl;
			else break;
		}
	} while (1);
	ostringstream oss;
	oss << day << "/" << month;
	string date = oss.str();
	return date;
}
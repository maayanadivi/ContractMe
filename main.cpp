#pragma once
#define _CRT_SECURE_NO_WARNINGS
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
#define N 40  // max char for username
#define currentYear 2020

const int HR_TYPE = 1;
const int EMPLOYEER_TYPE = 2;
const int CONTRACTOR_TYPE = 3;

int ContractorCount = 0; // Contractor user count.
int ContractorHired = 0;
int EmployerCount = 0;  // Employer user count.


typedef struct User {
	char* fullName = NULL;
	char* username = NULL;
	char* password = NULL;
	int UserType = 0;  //  1 = HR  ,  2 = Employeer  ,  3 = Contractor
} User;

typedef struct WorkDay {
	int day;
	int month;
	int year;
	int startTime;
	int endTime;
}WorkDay;

typedef struct Contractor {
	User details;
	int salary;
	char place[N];
	int numskills;
	string* skill = NULL;
	int numOfWorkDays = 0;
	WorkDay* workDay;
}Contractor;


void textColor(int textcolor);
void ourLogo();
void printBye();
void mainmenu();
WorkDay calendar(char*);
void writeHRtoFile();
void login();
void signUp();
void writeUserToFile(User);
void tech();
bool checkUserExists(ifstream&, char*);
void ChooseMenu(int type, char* userInput);
void lowercase(char*);
int calculateHours(int start, int finish);

void hrMenu(char* userInput);
void statisticAnalysis();
void addNewWorker();
void monitorHiring();
void workersFeed();

void employeerMenu(char* userInput);
void hiringHistory(char*);
void searchContractor(char*);
bool checkSkills(string* skills, int length, char* skill);
void bookContractor(const char* username, char* currentUser, WorkDay date);
bool checkDate(WorkDay date, char* userName);

void contractorMenu(char* userInput);
void addworkday(Contractor&);
void updateWorkHistory(Contractor&);
void addvacation(Contractor&);
void buildContractor(Contractor& worker, const char* userInput);


int main()
{
	ourLogo(); // function to print our logo

	textColor(15);
	cout << endl << endl
		<< "+++++++++++++++++++++++++++++++++++++++++++" << endl
		<< "+++  HELLO! :), welcome to ContractMe!  +++  (for technical support press '0' at anytime)" << endl
		<< "+++++++++++++++++++++++++++++++++++++++++++" << endl;

	textColor(15); // changing back to white text
	//calendar("Maayan");
	mainmenu();

	printBye();
	getchar();
	getchar();
	return 0;
}

void textColor(int textcolor)  // function to switch text colors
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, textcolor);
}

void ourLogo() // func to print our logo
{
	textColor(48);
	cout << "                                                                                  " << endl;
	textColor(48); cout << "  "; textColor(1); cout << " CCCCCCC                                                   M     M            "; textColor(48); cout << "  " << endl;
	textColor(48); cout << "  "; textColor(1); cout << " CCC           n      t                         t         MMM   MMM     eeeee "; textColor(48); cout << "  " << endl;
	textColor(48); cout << "  "; textColor(1); cout << " CC       ooo  nnnn  ttt   r rrrr aaaaa  ccccc ttt       M   M M   M    e     "; textColor(48); cout << "  " << endl;
	textColor(48); cout << "  "; textColor(1); cout << " CC      o   o n   n  t     r     a   a  c      t       M     M     M   eeee  "; textColor(48); cout << "  " << endl;
	textColor(48); cout << "  "; textColor(1); cout << " CCC     o   o n   n  t     r     a   a  c      t      M             M  e     "; textColor(48); cout << "  " << endl;
	textColor(48); cout << "  "; textColor(1); cout << " CCCCCCC  ooo  n   n  tttt  r     aaaaaa ccccc  tttt  M               M eeeee "; textColor(48); cout << "  " << endl;
	textColor(48);
	cout << "                                                                                  " << endl;
	textColor(15); // returning to white text
}

void printBye()
{
	cout << " " << endl
		<< "                        .-''''-.     " << endl
		<< "                       / .===. \\  " << endl
		<< "                       \\/ 6 6 \\/  " << endl
		<< "                       ( \\___/ )  " << endl
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
	//writeHRtoFile(); //writing the HR workers to the users file
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

void writeHRtoFile()
{
	ofstream inFile;
	inFile.open("database.txt");
	inFile << "yarden ";
	inFile << "123 ";
	inFile << "yarden ";
	inFile << HR_TYPE << endl;
	inFile << "mayaan ";
	inFile << "456 ";
	inFile << "mayaan ";
	inFile << HR_TYPE << endl;
	inFile << "david ";
	inFile << "789 ";
	inFile << "david ";
	inFile << HR_TYPE << endl;
	inFile << "benny ";
	inFile << "159 ";
	inFile << "benny ";
	inFile << HR_TYPE << endl;
	inFile << "michael ";
	inFile << "357 ";
	inFile << "michael ";
	inFile << HR_TYPE << endl;
	inFile.close();
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
	char temp[N];
	if (checkUserExists(inFile, userInput)) {
		inFile >> checkpass;
		if (checkpass == pass)
		{
			cout << "\n";
			inFile >> temp; // skipping the name 
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
	inFile.open("database.txt", ios::app);
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
	inFile << newUser.username << " ";
	inFile << newUser.password << " ";
	inFile << newUser.fullName << " ";
	inFile << newUser.UserType << endl;
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

void ChooseMenu(int type, char* userInput)
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

}


void buildContractor(Contractor& worker, const char* userInput)
{
	fstream inFile; //getting workHours and payPerHour from the database
	inFile.open("database.txt");
	if (inFile.fail()) {
		cout << "error opening file" << endl;
		exit(1);
	}
	string temp;
	char* checkInput = new char[strlen(userInput) + 1];
	while (!inFile.eof())
	{
		inFile >> checkInput; // Getting the UserName field from the file.
		if (strcmp(checkInput, userInput) == 0) // we are now in the correct user
		{
			worker.details.username = checkInput;
			inFile >> temp; //pass
			inFile >> temp;//name
			inFile >> worker.details.UserType; //type
			inFile >> worker.salary; //salary
			inFile >> worker.numskills;
			worker.skill = new string[worker.numskills];
			for (int i = 0; i < worker.numskills; ++i)
			{
				inFile >> worker.skill[i];
			}
			break;
		}
	}
	inFile.close();
	//cout << "Hello '" << name << "', " << endl;
	//int totalHours = 0;
	inFile.open("workHistory.txt");
	while (!inFile.eof())
	{
		inFile >> checkInput; // Getting the UserName field from the file.
		if (strcmp(checkInput, userInput) == 0) // we are now in the correct user
		{
			inFile >> worker.numOfWorkDays;
			worker.workDay = new WorkDay[worker.numOfWorkDays];
			for (int i = 0; i < worker.numOfWorkDays; i++)
			{
				inFile >> worker.workDay[i].day; // ignoring day date
				inFile >> worker.workDay[i].month; // ignoring mpnth date
				inFile >> worker.workDay[i].year; // ignoring year date
				inFile >> worker.workDay[i].startTime; // getting start Time
				inFile >> worker.workDay[i].endTime; // getting End time
			}
			break;
		}
	}
	inFile.close();
	//delete[] checkInput;
}

void contractorMenu(char* userInput)
{
	//// name username password type workHours payPerHour NotAvailable(DayOfMonth)
		// welcome to the contractor menu, and print his work hours and salary
	Contractor worker;
	int totalHours = 0;
	buildContractor(worker, userInput);
	cout << "Hello " << userInput << endl;
	for (int i = 0; i < worker.numOfWorkDays; i++)
	{
		cout << worker.workDay[i].day << "/" << worker.workDay[i].month << "/" << worker.workDay[i].year << "\t" << worker.workDay[i].startTime << ":00 - " << worker.workDay[i].endTime << ":00" << endl;
		totalHours += calculateHours(worker.workDay[i].startTime, worker.workDay[i].endTime);
	}
	cout << "And your total salary is:" << totalHours * worker.salary << endl;
	cout << "Welcome to the Contractor Menu" << endl;
	// entering to the contractor menu options
	int choice = 0;
	int startHour = 0, finishHour = 0, day1 = 0, month1 = 0, year1 = 0, TodayHours = 0, hourlyPay = 0, vacation = 0;
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
			addworkday(worker);
			updateWorkHistory(worker);
			break;
		case 2: //Report vacation
			addvacation(worker);
			updateWorkHistory(worker);
			// now we need to add this day to the database:
			// if he wants to add another vacation day, he can re enter this option.
			break;
		case 3:
			// edit
			break;
		case 4:
			delete[] worker.skill;
			delete[]worker.workDay;
			cout << "Signed out of the system." << endl;
			break;
		default:
			cout << "Please enter choice between 1-3 only, 3 to sign out." << endl;
		}
	}
}

void addvacation(Contractor& worker)
{
	int starthour = 0, endhour = 0;
	cout << "enter the date you start the vacation" << endl;
	WorkDay startVacation = calendar(worker.details.username);
	cout << "enter the date you end the vacation" << endl;
	WorkDay endVacation = calendar(worker.details.username);
	for (int i = 0; i < worker.numOfWorkDays; ++i)
	{
		if (startVacation.year <= worker.workDay[i].year && endVacation.year >= worker.workDay[i].year)
			if (startVacation.month <= worker.workDay[i].month && endVacation.month >= worker.workDay[i].month)
				if (startVacation.day <= worker.workDay[i].day && endVacation.day >= worker.workDay[i].day)
				{
					cout << "You can't report a vacation on this day, you already reported a workday on this day" << endl;
					return;
				}
	}
	while (!(startVacation.day == endVacation.day + 1 && startVacation.month == endVacation.month && startVacation.year == endVacation.year))
	{
		if (startVacation.day == 32)
		{
			startVacation.day = 1;
			startVacation.month++;
			if (startVacation.month == 13)
			{
				startVacation.month = 1;
				startVacation.year++;
			}
		}
		worker.numOfWorkDays++;
		WorkDay* temp = new WorkDay[worker.numOfWorkDays];
		temp[0].day = startVacation.day;
		temp[0].month = startVacation.month;
		temp[0].year = startVacation.year;
		temp[0].startTime = starthour;
		temp[0].endTime = endhour;
		for (int i = 1; i < worker.numOfWorkDays; ++i)
		{
			temp[i].day = worker.workDay[i - 1].day;
			temp[i].month = worker.workDay[i - 1].month;
			temp[i].year = worker.workDay[i - 1].year;
			temp[i].startTime = worker.workDay[i - 1].startTime;
			temp[i].endTime = worker.workDay[i - 1].endTime;
		}
		delete[] worker.workDay;
		worker.workDay = temp;
		startVacation.day++;
	}
}

void addworkday(Contractor& worker)
{
	int day, month, year, starthour, endhour;
	cout << "\nEnter date: " << endl;
	cout << "day: " << endl;
	cin >> day;
	cout << "month: " << endl;
	cin >> month;
	cout << "year: " << endl;
	cin >> year;
	cout << "Enter the hour u Started to work: " << endl;
	cin >> starthour;
	cout << "Enter the hour u Finished to work: " << endl;
	cin >> endhour;
	for (int i = 0; i < worker.numOfWorkDays; ++i)
	{
		if (day == worker.workDay[i].day)
			if (month == worker.workDay[i].month)
				if (year == worker.workDay[i].year)
				{
					worker.workDay[i].startTime = starthour;
					worker.workDay[i].endTime = endhour;
					return;
				}
	}
	worker.numOfWorkDays++;
	WorkDay* temp = new WorkDay[worker.numOfWorkDays];
	temp[0].day = day;
	temp[0].month = month;
	temp[0].year = year;
	temp[0].startTime = starthour;
	temp[0].endTime = endhour;
	for (int i = 1; i < worker.numOfWorkDays; ++i)
	{
		temp[i].day = worker.workDay[i - 1].day;
		temp[i].month = worker.workDay[i - 1].month;
		temp[i].year = worker.workDay[i - 1].year;
		temp[i].startTime = worker.workDay[i - 1].startTime;
		temp[i].endTime = worker.workDay[i - 1].endTime;
	}
	delete[] worker.workDay;
	worker.workDay = temp;
}

void updateWorkHistory(Contractor& worker)
{
	char* checkInput = new char[N];
	ifstream original;
	original.open("workHistory.txt");
	ofstream replica;
	replica.open("workHistory2.txt");
	while (!original.eof())
	{
		original.getline(checkInput, N);
		if (strcmp(checkInput, worker.details.username) == 0)
			break;
		replica << checkInput << endl;
	}
	string temp;
	int num;
	original >> num;
	for (int i = 0; i < num + 1; ++i)
	{
		getline(original, temp);
	}
	while (!original.eof())
	{
		getline(original, temp);
		replica << temp;
		if (!original.eof())
			replica << endl;
	}
	replica << worker.details.username << endl;
	replica << worker.numOfWorkDays << endl;
	for (int i = 0; i < worker.numOfWorkDays; ++i)
	{
		replica << worker.workDay[i].day << " ";
		replica << worker.workDay[i].month << " ";
		replica << worker.workDay[i].year << " ";
		replica << worker.workDay[i].startTime << " ";
		replica << worker.workDay[i].endTime << endl;
	}
	original.close();
	replica.close();
	remove("workHistory.txt");
	rename("workHistory2.txt", "workHistory.txt");
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

void hrMenu(char* userInput)
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
	char username[N], fullName[N], place[N], temp[N];
	int password, wage, numberSkills;
	cout << "Hello, welcome to add a new worker " << endl;
	cout << "Enter username: ";
	cin >> username;
	cout << endl << "Enter password: ";
	cin >> password;
	cout << endl << "Enter full name: ";
	cin >> fullName;
	cout << endl << "Enter wage: ";
	cin >> wage;
	cout << "enter how much interes the contractor has :";
	cin >> numberSkills;
	char** skills = new char*[numberSkills];
	if (skills == NULL)
	{
		cout << "cannot allocate memory" << endl;
		return;
	}
	for (int i = 0; i < numberSkills; ++i)
	{
		cout << endl << "Enter intersts: ";
		cin >> temp;
		skills[i] = new char[strlen(temp)];
		strcpy(skills[i], temp);
	}
	cout << endl << "Enter place: ";
	cin >> place;
	fstream inFile;
	inFile.open("database.txt", ios::app);
	if (inFile.fail()) {
		cout << "error opening file" << endl;
		exit(1);
	}
	lowercase(username);
	inFile << username << " ";
	inFile << password << " ";
	inFile << fullName << " ";
	inFile << CONTRACTOR_TYPE << " ";
	inFile << wage << " ";
	inFile << numberSkills << " ";
	for (int i = 0; i < numberSkills; ++i)
	{
		inFile << skills[i] << " ";
	}
	inFile << place << endl;
	inFile.close();
	inFile.open("workHistory.txt", ios::app);
	if (inFile.fail()) {
		cout << "error opening file" << endl;
		exit(1);
	}
	inFile << username << endl;
	inFile << "0" << endl;
	for (int i = 0; i < numberSkills; ++i)
		delete[] skills[i];
	delete[] skills;
	inFile.close();
	++ContractorCount;
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
		cout << "contracrot details: " << endl;
		inFile >> temp; // skipping password field.
		inFile >> temp; // reading fullname field.
		cout << temp << endl;
		inFile >> temp; // skipping user Type.
		inFile >> temp; // reading wage field.
		cout << temp << endl;
		inFile >> temp; // reading skills field.
		cout << temp << endl;
		inFile >> temp; // reading place field.
		cout << temp << endl;
		inFile.close();
		inFile.open("workHistory.txt");
		while (!inFile.eof()) {
			inFile >> temp;
			inFile >> temp;
			if (strcmp(temp, userName) == 0) {
				while (temp != "UserName:") {
					inFile >> temp;
					cout << temp;
					cout << endl;
				}
			}
		}
	}
	else cout << "User does not exist." << endl;
	inFile.close();
}

void employeerMenu(char* userInput)
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
	char location[N], skill[N], temp[N];
	int minWage, maxWage;
	WorkDay date;
	cout << "Enter location ( 0 if not needed)" << endl;
	cin >> location;
	cout << "Enter Skills ( 0 if not needed)" << endl;
	cin >> skill;
	cout << "Enter minimum wage ( 0 if not needed)" << endl;
	cin >> minWage;
	cout << "Enter maxWage ( 0 if not needed)" << endl;
	cin >> maxWage;
	cout << "Enter date ( 0 if not needed)" << endl;
	date = calendar(currentUser);
	fstream inFile;
	inFile.open("database.txt");
	if (inFile.fail()) {
		cout << "error opening file" << endl;
		exit(1);
	}
	int checkType;
	char UserName[N];
	int userPass, userNumSkills;
	char userUsername[N];
	int userSalary;
	char userPlace[N];
	int flag = 0;
	cout << "searching workers for:" << skill << "\t";
	cout << date.day << "/" << date.month << "/" << date.year << endl;
	while (!inFile.eof()) {
		inFile >> userUsername;
		inFile >> userPass;
		inFile >> UserName;
		inFile >> checkType;
		if (checkType == CONTRACTOR_TYPE)//if the user is contractor 
		{
			inFile >> userSalary;
			inFile >> userNumSkills;
			string *userSkills = new string[userNumSkills];
			if (userSkills == NULL)
			{
				cout << "cannot allocate memory" << endl;
				return;
			}
			for (int i = 0; i < userNumSkills; ++i) {

				inFile >> userSkills[i];
			}
			inFile >> userPlace;
			if (strcmp(userPlace, location) == 0 || strcmp("0", location) == 0)
			{
				if (checkSkills(userSkills, userNumSkills, skill) || strcmp("0", skill) == 0)
				{
					if ((userSalary > minWage && userSalary < maxWage) || (minWage < userSalary && maxWage == 0))
					{
						if (checkDate(date, userUsername))//check if the contractor is available
						{
							++flag;
							cout << UserName << endl;
							cout << userSalary << endl;
							for (int i = 0; i < userNumSkills; ++i) {
								cout << userSkills[i];
								cout << ",";
							}

						}
					}
				}
			}
			delete[] userSkills;
		}
	}
	if (flag == 0)
	{
		cout << "cannot find contractor that fit to your needs" << endl;
		inFile.close();
		return;
	}
	cout << "please enter the name of the contractor you want to book" << endl;
	cin >> UserName;
	bookContractor(UserName, currentUser, date); // contrator, employer , date
	inFile.close();
}

bool checkSkills(string* skills, int length, char* skill)
{
	string newSkill(skill);

	for (int i = 0; i < length; ++i)
		if (skills[i] == newSkill)
			return true;
	return false;
}

bool checkDate(WorkDay date, char* userName)
{
	char tempUser[N];
	WorkDay temp; //temp date
	fstream inFile;
	inFile.open("workHistory.txt");
	if (inFile.fail()) {
		cout << "error opening file" << endl;
		exit(1);
	}
	while (!inFile.eof())
	{
		inFile >> tempUser;
		if (strcmp(tempUser, userName) == 0)
		{
			int numofdays;
			inFile >> numofdays;
			for (int i = 0; i < numofdays; ++i)
			{
				inFile >> temp.day;
				inFile >> temp.month;
				inFile >> temp.year;
				inFile >> temp.startTime;
				inFile >> temp.endTime;
				if (temp.day == date.day)
					if (temp.month == date.month)
						if (temp.year == date.year)
						{
							inFile.close();
							return false;
						}

			}

		}
	}
	inFile.close();
	return true;
}

void bookContractor(const char* username, char* currentUser, WorkDay date)
{
	Contractor worker;
	buildContractor(worker, username);
	worker.numOfWorkDays++;
	WorkDay* temp = new WorkDay[worker.numOfWorkDays];
	temp[0].day = date.day;
	temp[0].month = date.month;
	temp[0].year = date.year;
	temp[0].startTime = -1; //worker need to report starttime and endtime
	temp[0].endTime = -1;
	for (int i = 1; i < worker.numOfWorkDays; ++i)
	{
		temp[i].day = worker.workDay[i - 1].day;
		temp[i].month = worker.workDay[i - 1].month;
		temp[i].year = worker.workDay[i - 1].year;
		temp[i].startTime = worker.workDay[i - 1].startTime;
		temp[i].endTime = worker.workDay[i - 1].endTime;
	}
	delete[] worker.workDay;
	worker.workDay = temp;
	updateWorkHistory(worker);


	cout << "test" << endl;
	char checkInput[N];
	ifstream original;
	original.open("HiringHistory.txt");
	ofstream replica;
	replica.open("HiringHistory2.txt");
	ofstream replica2;
	replica2.open("HiringHistory3.txt");
	cout << "test2" << endl;
	while (!original.eof()) // copying to hiring2  untill reach user name  // 1
	{
		original >> checkInput;
		if (strcmp(checkInput, worker.details.username) == 0)
			break;
		replica << checkInput;
	    replica << endl;
	}
	cout << "test3" << endl;
	while (!original.eof()) // copying the current user // old fff
	{
		original >> checkInput;
		if (strcmp(checkInput, "UserName:") == 0)
		replica2 << checkInput << endl;
	}
	replica2 << username << " ";
	replica2 << date.day << " " << date.month << " " << date.year << " " << endl;
	while (!original.eof()) // next user+rest
	{
		original >> checkInput;
		replica2 << checkInput << endl;
	}

	cout << "test4" << endl;
	original.close(); // Done withcopying
	replica.close();
	replica2.close();
	////////////////////////////////////////// done copying
	ifstream copy;
	copy.open("HiringHistory2.txt");
	ifstream copy2;
	copy2.open("HiringHistory3.txt");

	remove("HiringHistory.txt");
	ofstream done;
	done.open("HiringHistory.txt");

	while (!copy.eof()) // copying the current user
	{
		copy >> checkInput;
		done << checkInput;
		if (strcmp(checkInput, "2019") == 0)
			done << endl;
		if (strcmp(checkInput, "2020") == 0)
			done << endl;
		if (strcmp(checkInput, "2021") == 0)
			done << endl;
		if (strcmp(checkInput, "2022") == 0)
			done << endl;
		done << " ";
	}
	
	
	while (!copy2.eof()) 
	{
		
		copy2 >> checkInput;
		done << checkInput;	
		if (strcmp(checkInput, "2019") == 0)
			done << endl;
		if (strcmp(checkInput, "2020") == 0)
			done << endl;
		if (strcmp(checkInput, "2021") == 0)
			done << endl;
		if (strcmp(checkInput, "2022") == 0)
			done << endl;
		done << " ";
	}
	
	copy.close();
	copy2.close();
	done.close();
	remove("HiringHistory2.txt");
	remove("HiringHistory3.txt");
	
	++ContractorHired;//increas the number of contractor that hired
}

WorkDay calendar(char* currentUser) {
	int month, day, year;
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
	do {
		cout << "enter year: ";
		cin >> year;
	} while (year < currentYear);
	/*ostringstream oss;
	oss << day << "/" << month << "/" << year;
	string date = oss.str();
	return date;*/
	WorkDay temp;
	temp.day = day;
	temp.month = month;
	temp.year = year;
	return temp;
}
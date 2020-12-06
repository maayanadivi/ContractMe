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


typedef struct {
	char *fullName;
	char *username;
	char *password;
	int UserType = 0;  //  1 = HR  ,  2 = Employeer  ,  3 = Contractor
} User;

typedef struct {
	User details;
	int salary;
	char place[N];
	char interes[N];
	//WorkDay *workDay;
}Contractor;

typedef struct {
	int day;
	int month;
	int year;
	int startTime;
	int endTime;
}WorkDay;


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
bool checkSkills(char** skills, int lenght, char* skill);
void bookContractor(const char * username, char* currentUser, WorkDay date);
bool checkDate(WorkDay date, char* userName);

void contractorMenu(char *userInput);


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
	writeHRtoFile(); //writing the HR workers to the users file
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
	inFile << "UserName:" << newUser.username << endl;
	inFile << "HiringHistory:";
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
	char **skills = new char*[numberSkills];
	if (*skills == NULL)
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
	inFile << place << " ";
	inFile.close();
	inFile.open("workHistory.txt", ios::app);
	if (inFile.fail()) {
		cout << "error opening file" << endl;
		exit(1);
	}
	inFile << "UserName:" << username << endl;
	inFile << "workHistory:";
	inFile << "workDay:";
	inFile << endl;
	/*for (int i = 0; i < numberSkills; ++i)
		delete skills[i];
	delete skills;*/
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
	cout << "searching workers for:" << skill << "/t";
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
			char **userSkills = new char*[userNumSkills];
			if (userSkills == NULL)
			{
				cout << "cannot allocate memory" << endl;
				return;
			}
			for (int i = 0; i < userNumSkills; ++i) {

				inFile >> temp;
				userSkills[i] = new char[strlen(temp)];
				if (userSkills[i] == NULL)
				{
					cout << "cannot allocate memory" << endl;
					return;
				}
				strcpy(userSkills[i], temp);
			}
			inFile >> userPlace;
			if (userPlace == location || location == 0)
			{
				if (checkSkills(userSkills, userNumSkills, skill) || skill == 0)
				{
					if ((userSalary > minWage && userSalary < maxWage) || (minWage < userSalary&& maxWage == 0))
					{
						if (checkDate(date, userUsername))//check if the contractor is available
						{
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
		}

	}

	cout << "please enter the name of the contractor you want to book" << endl;
	cin >> UserName;
	bookContractor(UserName, currentUser, date);
	inFile.close();
}

bool checkSkills(char** skills, int length, char* skill)
{
	for (int i = 0; i < length; ++i)
		if (skills[i] == skill)
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
	inFile >> tempUser;
	while (inFile.eof())
	{
		if (tempUser == "username:")
		{
			inFile >> tempUser;
			if (tempUser == userName)
			{
				inFile << tempUser;
				if (tempUser == "workDay:")
				{
					inFile >> temp.day;
					inFile >> temp.month;
					inFile >> temp.year;
					inFile >> temp.startTime;
					inFile >> temp.endTime;
					if (temp.day == date.day)
						if (temp.month == date.month)
							if (temp.year == date.year)
								if (temp.startTime != 0 && temp.endTime != 0)
									return true;
				}


			}
			return false;
		}
	}
	inFile.close();
}

void bookContractor(const char * username, char* currentUser, WorkDay date)
{
	char temp[N];
	fstream inFile;
	inFile.open("workHistory.txt", ios::app);
	if (inFile.fail()) {
		cout << "error opening file" << endl;
		exit(1);
	}
	while (inFile.eof())
	{
		inFile >> temp;
		if (temp == "UserName:")
		{
			inFile >> temp;
			if (strcmp(username, temp))
			{
				inFile >> temp;//skipping the "workHistory"
				inFile << date.day;
				inFile << date.month;
				inFile << date.year;
			}

		}
	}
	inFile.close();
	fstream File;
	File.open("HiringHistory.txt", ios::app);
	if (File.fail()) {
		cout << "error opening file" << endl;
		exit(1);
	}
	while (File.eof())
	{
		File >> temp;
		if (temp == "UserName:")
		{
			File >> temp;
			if (strcmp(temp, currentUser))
			{
				File >> temp;//skipping the "HiringHistory"
				//להוסיף שכר ויכולות
				File << date.day;
				File << date.month;
				File << date.year;
			}

		}
	}
	File.close();

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
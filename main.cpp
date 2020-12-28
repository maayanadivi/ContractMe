// temp for our project

#pragma once

#include "helpers.cpp"

<<<<<<< Updated upstream
=======
const int HR_TYPE = 1;
const int EMPLOYEER_TYPE = 2;
const int CONTRACTOR_TYPE = 3;
const int YEAR = 2020;
>>>>>>> Stashed changes


int CCount=0; // Contractor user count.
int ECount = 0; // Employer user count.

typedef struct {
	char name[N];  // name +last name 
	char username[N];  // username
	char password[N];
	int UserType;  //  1 = HR  ,  2 = Employee  ,  3 = Contractor
} User;


<<<<<<< Updated upstream
void mainmenu();
void login();
void sign();
void add();
void tech();
void employe();
void HR();
void contractor();
void checkpass();
=======

void textColor(int);
void ourLogo();
void printBye();

void mainmenu();
void login();
void signUp();
void writeUserToFile(User);
void ChooseMenu(int, string);
void tech();

void contractorMenu(string);
void buildContractor(Contractor&, string);
void addworkday(Contractor&);
void addvacation(Contractor&);
void updateWorkHistory(Contractor&);
void editprofile(Contractor&);
int calculateHours(int, int, int);

void hrMenu(string);
void statisticAnalysis();
void monitorHiring();
void addNewWorker();
void workersFeed();
void editWorkday(Contractor&);
void printAllContractorNames();

void employeerMenu(string);
void hiringHistory(string);
void searchContractor(string);
void bookContractor(string, WorkDay);//string, string, WorkDay);
void printDetails(string);
>>>>>>> Stashed changes


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
	char user;
	char pass;
	char check;
	cout << "please enter your username:\n" << endl;
	cin >> user;
	cout << "please enter your password:\n" << endl;
	cin >> pass;

	ifstream inFile;
	inFile.open("database.txt");
	if (inFile.fail()) {
		cerr << "error opening file" << endl;
		exit(1);
	}
<<<<<<< Updated upstream
	int found = 0;
	while (!inFile.eof()) {
		inFile >> check;
		if (check == user)
			found = 1;
=======
	string checkpass;
	int checktype;
	string temp;
	if (checkUserExists(inFile, userInput)) {
		inFile >> checkpass;
		if (checkpass == pass)
		{
			inFile >> temp; // skipping the name 
			inFile >> checktype;
			inFile.close();
			ChooseMenu(checktype, userInput);
			return;
		}
		else cout << "Wrong pass.\n";
		return;
	}
	cout << "User does not exsist in the database, try again";
	inFile.close();

	return;
}

void signUp() // only Employer can signup
{
	ourLogo();
	User u1;
	string name, username, password;

	cout << ("\nHello, enter your name, username and password:\n");
	cout << "name: " << endl;
	cin >> name;
	cout << "username: " << endl;
	cin >> username;
	cout << "password: " << endl;
	cin >> password;
	while (password.length() < 6)
	{
		cout << "The password is too short, please try again:" << endl;
		cin >> password;
	}
	lowercase(username); //Account usernames will be stored in lowercase on the DataBase.

	// Username in database must be unique.
	ifstream inFile;
	inFile.open("database.txt");
	if (inFile.fail()) {
		cerr << "error opening file" << endl;
		exit(1);
	}
	while (checkUserExists(inFile, username))
	{
		cout << "Username taken." << endl << "Enter another username: ";
		cin >> username;
		lowercase(username);
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
	inFile << "UserName:" << endl << newUser.username << endl;
	inFile << "HiringHistory:" << endl;
	inFile.close();
}

void ChooseMenu(int type, string userInput)
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
	ourLogo();
	string problem;
	cout << "\nHello, welcome to tech support.\n please describe your problem: " << endl;
	cin >> problem;
	cout << "\nThank you for your message, we will return to you with a solution asap " << endl;

}

void contractorMenu(string userInput)
{
	//// name username password type workHours payPerHour NotAvailable(DayOfMonth)
		// welcome to the contractor menu, and print his work hours and salary
	Contractor worker;
	buildContractor(worker, userInput);
	int totalSalary = 0;
	// entering to the contractor menu options
	int choice = 0;
	while (choice != 4)
	{
		ourLogo();
		totalSalary = 0;
		cout << "Hello " << worker.details.fullName << endl;
		for (int i = 0; i < worker.numOfWorkDays; i++)
		{
			if ((worker.workDay[i].startTime != 0 && worker.workDay[i].endTime != 0) && (worker.workDay[i].startTime != -1 && worker.workDay[i].endTime != -1))
			{
				cout << worker.workDay[i].day << "/" << worker.workDay[i].month << "/" << worker.workDay[i].year << "\t" << worker.workDay[i].startTime << ":00 - " << worker.workDay[i].endTime << ":00"
					<< "\t" << "$" << worker.workDay[i].wage << endl;
				totalSalary += calculateHours(worker.workDay[i].startTime, worker.workDay[i].endTime, worker.workDay[i].wage);
			}
		}
		cout << "And your total salary is:" << totalSalary << endl;
		cout << "Welcome to the Contractor Menu" << endl;
		cout << "\nWhat do you want to do next? " << endl
			<< "1.Report work hours" << endl
			<< "2.Report vacation" << endl
			<< "3.Edit profile" << endl
			<< "4.Sign out" << endl;
		cin >> choice;
		switch (choice) {
		case 0: // technical support
			tech();
			break;
		case 1: //report work hours
			addworkday(worker);
			break;
		case 2: //Report vacation
			addvacation(worker);
			break;
		case 3:
			// edit
			editprofile(worker);
			break;
		case 4:
			delete[] worker.skill;
			delete[]worker.workDay;
			cout << "Signed out of the system." << endl;
			break;
		default:
			cout << "Please enter choice between 1-4 only, 4 to sign out." << endl;
		}
	}
}

void buildContractor(Contractor& worker, string userInput)
{
	fstream inFile; //getting workHours and payPerHour from the database
	inFile.open("database.txt");
	if (inFile.fail()) {
		cout << "error opening file" << endl;
		exit(1);
	}
	string temp;
	string checkInput;
	while (!inFile.eof())
	{
		inFile >> checkInput; // Getting the UserName field from the file.
		if (checkInput == userInput) // we are now in the correct user
		{
			worker.details.username = checkInput;
			inFile >> worker.details.password; //pass
			inFile >> worker.details.fullName;//name
			inFile >> worker.details.UserType; //type
			inFile >> worker.salary; //salary
			inFile >> worker.numskills;
			worker.skill = new string[worker.numskills];
			for (int i = 0; i < worker.numskills; ++i)
			{
				inFile >> worker.skill[i];
			}
			getline(inFile, worker.place);
			break;
		}
		getline(inFile, temp);
	}
	inFile.close();
	//cout << "Hello '" << name << "', " << endl;
	//int totalHours = 0;
	inFile.open("workHistory.txt");
	while (!inFile.eof())
	{
		inFile >> checkInput; // Getting the UserName field from the file.
		if (checkInput == userInput) // we are now in the correct user
		{
			inFile >> worker.numOfWorkDays;
			worker.workDay = new WorkDay[worker.numOfWorkDays];
			for (int i = 0; i < worker.numOfWorkDays; i++)
			{
				inFile >> worker.workDay[i].day; // ignoring day date
				inFile >> worker.workDay[i].month; // ignoring mpnth date
				inFile >> worker.workDay[i].year; // ignoring year date
				inFile >> worker.workDay[i].startTime; // getting start Time
				inFile >> worker.workDay[i].endTime;// getting End time
				inFile >> worker.workDay[i].wage; //getting wage
			}
			break;
		}
	}
	inFile.close();
}

void addworkday(Contractor& worker)
{
	WorkDay date = calendar(worker.details.username);
	cout << "Enter work start hour " << endl;
	cin >> date.startTime;
	cout << "Enter work end hour " << endl;
	cin >> date.endTime;
	for (int i = 0; i < worker.numOfWorkDays; ++i)
	{
		if (date.day == worker.workDay[i].day)
			if (date.month == worker.workDay[i].month)
				if (date.year == worker.workDay[i].year)
				{
					worker.workDay[i].startTime = date.startTime;
					worker.workDay[i].endTime = date.endTime;
					updateWorkHistory(worker);
					return;
				}
	}
	worker.numOfWorkDays++;
	WorkDay* temp = new WorkDay[worker.numOfWorkDays];
	temp[0].day = date.day;
	temp[0].month = date.month;
	temp[0].year = date.year;
	temp[0].startTime = date.startTime;
	temp[0].endTime = date.endTime;
	temp[0].wage = worker.salary;
	for (int i = 1; i < worker.numOfWorkDays; ++i)
	{
		temp[i].day = worker.workDay[i - 1].day;
		temp[i].month = worker.workDay[i - 1].month;
		temp[i].year = worker.workDay[i - 1].year;
		temp[i].startTime = worker.workDay[i - 1].startTime;
		temp[i].endTime = worker.workDay[i - 1].endTime;
		temp[i].wage = worker.workDay[i - 1].wage;
	}
	delete[] worker.workDay;
	worker.workDay = temp;
	updateWorkHistory(worker);
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
		temp[0].wage = worker.salary;
		for (int i = 1; i < worker.numOfWorkDays; ++i)
		{
			temp[i].day = worker.workDay[i - 1].day;
			temp[i].month = worker.workDay[i - 1].month;
			temp[i].year = worker.workDay[i - 1].year;
			temp[i].startTime = worker.workDay[i - 1].startTime;
			temp[i].endTime = worker.workDay[i - 1].endTime;
			temp[i].wage = worker.workDay[i - 1].wage;
		}
		delete[] worker.workDay;
		worker.workDay = temp;
		startVacation.day++;
	}
	updateWorkHistory(worker);
}

void updateWorkHistory(Contractor& worker)
{
	string checkInput;
	ifstream original;
	original.open("workHistory.txt");
	if (original.fail()) {
		cerr << "error opening file" << endl;
		exit(1);
	}
	ofstream replica;
	replica.open("workHistory2.txt");
	while (!original.eof())
	{
		getline(original, checkInput);
		if (checkInput == worker.details.username)
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
		replica << worker.workDay[i].endTime << " ";
		replica << worker.workDay[i].wage << endl;
	}
	original.close();
	replica.close();
	remove("workHistory.txt");
	rename("workHistory2.txt", "workHistory.txt");
}

void editprofile(Contractor& worker)
{
	ourLogo();
	ifstream original("database.txt");
	ofstream replica("database1.txt");
	string tmp;
	original >> tmp;
	do
	{
		//original >> tmp; //get username
		if (tmp == worker.details.username)
		{
			original >> worker.details.password;
			original >> worker.details.fullName;
			original >> worker.details.UserType; //skip type
			original >> worker.salary;
			original >> worker.numskills;
			worker.skill = new string[worker.numskills];
			for (int i = 0; i < worker.numskills; ++i)
				original >> worker.skill[i];
			getline(original, worker.place);
		}
		else
		{
			replica << tmp;
			getline(original, tmp);
			replica << tmp << endl;
		}
		original >> tmp;
	} while (!original.eof());
	original.close();
	replica.close();
	remove("database.txt");
	rename("database1.txt", "database.txt");
	int choise = 0;
	ofstream inFile("database.txt", ios::app);
	string* temp;
	while (choise != 4)
	{
		cout << "What you want to edit:" << endl << "1 - Wage" << endl << "2 - Location" << endl << "3 - Add skill" << endl << "4 - Save" << endl;
		cin >> choise;
		switch (choise)
		{
		case 0:
			tech();
			break;
		case 1:
			cout << "Enter new wage: ";
			cin >> worker.salary;
			while (worker.salary < 0)
			{
				cout << "The wage must be positive integer- please try again" << endl;
				cin >> worker.salary;
			}
			break;
		case 2:
			cout << "Enter new location: - north/ south / center ";
			cin.ignore();
			getline(cin, worker.place);
			//worker.place = " " + worker.place;
			while (worker.place != "north" && worker.place != "center" && worker.place != "south")
			{
				cout << "The location is incorrect, try again" << endl << "Enter location - north/center/south ( 0 if not needed)" << endl;
				getline(cin, worker.place);
			}

			break;
		case 3:
			temp = new string[worker.numskills + 1];
			for (int i = 0; i < worker.numskills; ++i)
				temp[i] = worker.skill[i];
			delete[] worker.skill;
			worker.skill = temp;
			cout << "Enter new skill: ";
			cin >> worker.skill[worker.numskills];
			worker.numskills++;
			break;
		case 4:
			inFile << worker.details.username << " " << worker.details.password << " " << worker.details.fullName << " " << CONTRACTOR_TYPE << " " << worker.salary << " " << worker.numskills;
			for (int i = 0; i < worker.numskills; ++i)
				inFile << " " << worker.skill[i];
			inFile << " " << worker.place << endl;
			break;
		default:
			cout << "Incorrect input" << endl;
			break;
		}
	}
	inFile.close();
}

int calculateHours(int start, int finish, int wage) // example:: start = 8, finish = 17 ... => = 9 hours
{
	int hours = 0;
	for (int i = start; i < finish; i++)
		hours++;
	return hours * wage;
}

void hrMenu(string userInput)
{
	int choice = 0;
	while (choice != 5)
	{
		ourLogo();
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

void statisticAnalysis()
{
	ourLogo();
	cout << "Company�s Statistic Analysis:" << endl;
	cout << "Contractor numbers: " << ContractorCount << endl;
	cout << "Contractor Hired: " << ContractorHired << endl;
	cout << "Employer Numbers: " << EmployerCount << endl;
	cout << "Return to menu - press Enter";
	getchar();
	getchar();
}

void monitorHiring()
{
	ourLogo();
	if (!ContractorHired)
	{
		cout << "There is no hiring in the compny - press enter to get back to the menu" << endl;
		getchar();
		while (getchar() != '\n');
		return;
	}
	fstream inFile;
	inFile.open("HiringHistory.txt");
	if (inFile.fail()) {
		cout << "error opening file" << endl;
		exit(1);
	}
	string getLine;
	while (!inFile.eof()) {
		getline(inFile, getLine); // Skiping line
		cout << getLine << endl;
		//cout << endl;
	}
	cout << "Return to menu - press Enter";
	getchar();
	getchar();
	inFile.close();
}

void addNewWorker()
{
	ourLogo();
	ifstream checkDatabase;
	checkDatabase.open("database.txt");
	if (checkDatabase.fail()) {
		cout << "error opening file" << endl;
		exit(1);
	}
	string username, fullName, place, pass;
	int wage, numberSkills;
	cout << "Hello, welcome to add a new worker " << endl;
	cout << "Enter username: ";
	cin >> username;
	lowercase(username);
	while (checkUserExists(checkDatabase, username))
	{
		cout << "Username already taken, enter another: ";
		cin >> username;
		lowercase(username);
	}
	cout << "Enter password: ";
	cin >> pass;
	while (pass.length() < 6)
	{
		cout << "The password is too short, please try again:" << endl;
		cin >> pass;
	}
	cout << "Enter name: ";
	cin >> fullName;
	cout << "Enter wage: ";
	cin >> wage;
	while (wage < 0)
	{
		cout << "The wage must be a positive integer - please enter again:" << endl;
		cin >> wage;
	}
	cout << "Enter how much skills contractor has: ";
	cin >> numberSkills;
	string* skills = new string[numberSkills];
	if (skills == NULL)
	{
		cout << "cannot allocate memory" << endl;
		return;
>>>>>>> Stashed changes
	}
	if (found == 0)
	{
<<<<<<< Updated upstream
		cout << ("user does not exsist in the database, try again");
		inFile.close();
		login(); // re entering login 
	}
	if (found == 1)// user found
	{
		//checkpass(user);
	}

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
	
	char name[N],  username[N], password[N];
	cout << ("\nHello, enter your name, user and password:\n");

	cin >> name >> username >> password;
=======
		cout << "Enter " << i + 1 << " skill: ";
		cin >> skills[i];
	}
	cout << "Enter area: ";
	cin.ignore();
	getline(cin, place);
	while (place != "north" && place != "center" && place != "south" && place != "0")
	{
		cout << "The area is incorrect, try again" << endl << "Enter area - north/center/south ( 0 if not needed)" << endl;
		getline(cin, place);
	}
	checkDatabase.close();
	ofstream inFile;
	inFile.open("database.txt", ios::app);
	if (inFile.fail()) {
		cout << "error opening file" << endl;
		exit(1);
	}
>>>>>>> Stashed changes
	lowercase(username);
	cout << username;
	//User u1;
	//u1.name = name;
	//u1.username = username;
	//u1.password = password;
	//add(u1);
	getchar();
	getchar();
}

<<<<<<< Updated upstream
=======
void workersFeed()
{
	/*if (!ContractorCount)
	{
		while (getchar() != '\n')
			return;
	}*/
	ourLogo();
	printAllContractorNames();
	ifstream inFile;
	char choice;
	inFile.open("database.txt");
	if (inFile.fail()) {
		cout << "error opening file" << endl;
		exit(1);
	}
	string userName;
	string temp;
	Contractor user;
	cout << "Hello, Please enter the username: " << endl;
	cin >> userName;
	if (checkUserExists(inFile, userName))
	{
		buildContractor(user, userName);
		cout << "Contractor details: " << endl;
		cout << "Name: " << user.details.fullName << endl;
		cout << "Wage: " << user.salary << endl;
		cout << "Skills:" << endl;
		for (int i = 1; i <= user.numskills; ++i)
		{
			cout << "\t" << i << ": " << user.skill[i - 1] << endl;
		}
		cout << "Area: " << user.place << endl;
		cout << "Workhistory:" << endl;
		for (int i = 0; i < user.numOfWorkDays; ++i)
		{
			if ((user.workDay[i].startTime != 0 && user.workDay[i].endTime != 0) && (user.workDay[i].startTime != -1 && user.workDay[i].endTime != -1))
				cout << "\t" << user.workDay[i].day << "/" << user.workDay[i].month << "/" << user.workDay[i].year << "\t" << user.workDay[i].startTime << ":00 - " << user.workDay[i].endTime << ":00"
				<< "\t $" << user.workDay[i].wage << " for hour" << endl;
			else if (user.workDay[i].startTime == 0 && user.workDay[i].endTime == 0)
				cout << "\t" << user.workDay[i].day << "/" << user.workDay[i].month << "/" << user.workDay[i].year << " - Vacation" << endl;
		}
		inFile.close();
		cout << "If you want to edit a workday  - press 1" << endl << "If you want to exit  - press 0" << endl;;
		cin >> choice;
		if (choice == '1')
		{
			addworkday(user);
		}
		else
			return;
	}
	else cout << "User does not exist. Return to menu - press Enter" << endl;
	getchar();
	inFile.close();

}
>>>>>>> Stashed changes

void add(User)
{
}

<<<<<<< Updated upstream
void tech()
{

=======
void hiringHistory(string currentUser)
{
	ourLogo();
	ifstream inFile;
	string temp;
	inFile.open("HiringHistory.txt");
	while (!inFile.eof())
	{
		getline(inFile, temp);
		if (temp == "UserName:")
		{
			getline(inFile, temp);
			if (temp == currentUser)
			{
				getline(inFile, temp);
				//getline(inFile, temp);
				inFile >> temp;
				if (temp != "UserName:")
				{
					do
					{
						cout << temp << "  "; // print
						printDetails(temp);
						inFile >> temp;//copy the day name
						cout << temp << "/";
						inFile >> temp;//copy the month name
						cout << temp << "/";
						inFile >> temp;//copy the year name
						cout << temp << endl;
						/*cout << temp << endl;
						getline(inFile, temp);*/
						inFile >> temp;
					} while ((temp != "UserName:") && (!inFile.eof()));
					inFile.close();
					cout << "Return to menu - press Enter";
					getchar();
					getchar();
					return;
				}
			}
		}
	}
	inFile.close();
	cout << "Return to menu - press Enter";
	getchar();
	getchar();
}

void searchContractor(string currentUser)
{
	ourLogo();
	string location, skill, temp;
	int minWage, maxWage;
	WorkDay date;
	cout << "Enter location - north/center/south ( 0 if not needed)" << endl;
	cin.ignore();
	getline(cin, location);
	while (location != "north" && location != "center" && location != "south" && location != "0")
	{
		cout << "The location is incorrect, try again" << endl << "Enter location - north/center/south ( 0 if not needed)" << endl;
		getline(cin, location);
	}
	cout << "Enter Skill ( 0 if not needed)" << endl;
	cin >> skill;
	cout << "Enter minimum wage ( 0 if not needed)" << endl;
	cin >> minWage;
	while (minWage < 0)
	{
		cout << "The wage must be positive integer- please try again" << endl;
		cin >> minWage;
	}
	cout << "Enter maxWage ( 0 if not needed)" << endl;
	cin >> maxWage;
	while (maxWage < 0)
	{
		cout << "The wage must be positive integer- please try again" << endl;
		cin >> maxWage;
	}
	cout << "Enter date " << endl;
	date = calendar(currentUser);
	ifstream inFile;
	inFile.open("database.txt");
	if (inFile.fail()) {

		cout << "error opening file" << endl;
		exit(1);
	}
	int checkType, userNumSkills, userSalary, flag = 0;
	string UserName, userPass, userUsername, userPlace;
	cout << "searching workers for: " << skill << "\t" << date.day << "/" << date.month << "/" << date.year << endl;
	getline(inFile, temp);
	inFile >> userUsername;
	while (!inFile.eof()) {
		inFile >> userPass;
		inFile >> UserName;
		inFile >> checkType;
		if (checkType == CONTRACTOR_TYPE)//if the user is contractor 
		{
			inFile >> userSalary;
			inFile >> userNumSkills;
			string* userSkills = new string[userNumSkills];
			if (userSkills == NULL)
			{
				cout << "cannot allocate memory" << endl;
				return;
			}
			for (int i = 0; i < userNumSkills; ++i) {

				inFile >> userSkills[i];
			}
			getline(inFile, userPlace);
			if (userPlace == location || location == " 0")
			{
				if (checkSkills(userSkills, userNumSkills, skill) || skill == "0")
				{
					if ((userSalary > minWage && userSalary < maxWage) || (minWage < userSalary && maxWage == 0))
					{
						if (checkDate(date, userUsername))//check if the contractor is available
						{
							++flag;
							cout << "Username: " << userUsername << endl << "Wage: " << userSalary << endl << "Skills: " << endl;
							for (int i = 0; i < userNumSkills; ++i)
							{
								cout << userSkills[i] << endl;
							}
							cout << "===================================================================" << endl;
						}
					}
				}
			}
			delete[] userSkills;
		}
		inFile >> userUsername;

	}
	if (flag == 0)
	{
		cout << "Cannot find contractor that fit to your needs, return to menu - press Enter" << endl;
		inFile.close();
		getchar();
		getchar();
		return;
	}

	getchar();
	bookContractor(currentUser, date);
	inFile.close();
}

void bookContractor(string currentUser, WorkDay date)
{
	string username;
	cout << "Please enter the name of the contractor you want to book" << endl;
	cin >> username;
	ifstream inFile;
	inFile.open("database.txt");
	if (inFile.fail()) {
		cout << "error opening file" << endl;
		exit(1);
	}
	if (!checkUserExists(inFile, username))
	{
		cout << "this user is not exist, please enter correct name:";
		cin >> username;
	}
	Contractor worker;
	buildContractor(worker, username);
	worker.numOfWorkDays++;
	WorkDay* temp = new WorkDay[worker.numOfWorkDays];
	temp[0].day = date.day;
	temp[0].month = date.month;
	temp[0].year = date.year;
	temp[0].startTime = -1; //worker need to report starttime and endtime
	temp[0].endTime = -1;
	temp[0].wage = worker.salary;
	for (int i = 1; i < worker.numOfWorkDays; ++i)
	{
		temp[i].day = worker.workDay[i - 1].day;
		temp[i].month = worker.workDay[i - 1].month;
		temp[i].year = worker.workDay[i - 1].year;
		temp[i].startTime = worker.workDay[i - 1].startTime;
		temp[i].endTime = worker.workDay[i - 1].endTime;
		temp[i].wage = worker.workDay[i - 1].wage;
	}
	delete[] worker.workDay;
	worker.workDay = temp;
	updateWorkHistory(worker);


	string datestring = username;
	datestring += " ";
	datestring += to_string(date.day);
	datestring += " ";
	datestring += to_string(date.month);
	datestring += " ";
	datestring += to_string(date.year);
	string tmp;
	ifstream original("HiringHistory.txt");
	ofstream replica("HiringHistory2.txt");
	getline(original, tmp);
	while (!original.eof() && tmp != currentUser)
	{
		replica << tmp << endl;
		getline(original, tmp);
	}
	replica << tmp << endl;
	getline(original, tmp);
	replica << tmp << endl;
	replica << datestring << endl;
	while (!original.eof())
	{
		getline(original, tmp);
		replica << tmp << endl;
	}
	original.close();
	replica.close();
	remove("HiringHistory.txt");
	rename("HiringHistory2.txt", "HiringHistory.txt");
	++ContractorHired;//increas the number of contractor that hired
	inFile.close();
>>>>>>> Stashed changes
}

void employe()
{
<<<<<<< Updated upstream
=======
	int checkType;
	string UserName;
	int userPass, userNumSkills;
	string userUsername;
	int userSalary;
	string userPlace;
	string* userSkills = NULL;
	fstream inFile;
	inFile.open("database.txt");
	if (inFile.fail()) {
		cout << "error opening file" << endl;
		exit(1);
	}
	getline(inFile, UserName);
	while (!inFile.eof()) {
		inFile >> userUsername;
		inFile >> userPass;
		inFile >> UserName;
		inFile >> checkType;
		if (checkType == CONTRACTOR_TYPE)//if the user is contractor 
		{
			inFile >> userSalary;
			inFile >> userNumSkills;
			userSkills = new string[userNumSkills];
			if (userSkills == NULL)
			{
				cout << "cannot allocate memory" << endl;
				return;
			}
			for (int i = 0; i < userNumSkills; ++i) {

				inFile >> userSkills[i];
			}
			inFile >> userPlace;
			if (username == userUsername)
			{
				cout << userSalary << "$  ";
				for (int i = 0; i < userNumSkills; ++i)
					cout << userSkills[i] << " ";
				cout << " ";
			}
		}
>>>>>>> Stashed changes

}

void HR()
{
<<<<<<< Updated upstream
=======

	if (!ContractorCount)
	{
		cout << "There are no contractor registered in the company yet ! - to return press enter" << endl;
		getchar();
	}
	int checkType;
	string userUsername;
	string temp;
	fstream inFile;
	inFile.open("database.txt");
	if (inFile.fail()) {
		cout << "error opening file" << endl;
		exit(1);
	}
	cout << "The contractors names:" << endl;
	getline(inFile, temp);
	inFile >> userUsername;
	while (!inFile.eof()) {
		inFile >> temp;
		inFile >> temp;
		inFile >> checkType;
		if (checkType == CONTRACTOR_TYPE)//if the user is contractor 
		{
			getline(inFile, temp);
			cout << userUsername << endl;
		}
		inFile >> userUsername;
	}
	inFile.close();

}
>>>>>>> Stashed changes

}

void contractor()
{

}

bool checkpass(string check, string check2)
{
<<<<<<< Updated upstream
	return 0;
=======
	string tempUser;
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
		if (tempUser == userName)
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

WorkDay calendar(string currentUser) {
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
	cout << "enter year: ";
	cin >> year;
	while (year < YEAR) {
		cout << "The year is not coorect, please enter new one:" << endl;
		cin >> year;
	}
	WorkDay temp;
	temp.day = day;
	temp.month = month;
	temp.year = year;
	return temp;
}

void readStatistic() {
	ifstream inFile;
	inFile.open("database.txt");
	if (inFile.fail()) {
		cerr << "error opening file" << endl;
		exit(1);
	}
	inFile >> ContractorCount;
	inFile >> ContractorHired;
	inFile >> EmployerCount;
	inFile.close();
>>>>>>> Stashed changes
}

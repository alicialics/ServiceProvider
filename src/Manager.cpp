#include "Manager.h"

//constructor
Manager::Manager(Data* _database) {
	currentUser = nullptr; //constructor set current user to null
	database = _database; //update the database
}

//destructor
Manager::~Manager() {
	for (Users* oneUser : allUsers) {
		delete oneUser;
	}
	for (auto oneService : allService) {
		delete oneService;
	}
}

//function to load data and save to manager
bool Manager::createData() {
	vector<Savedata*> dataPrev = database->loadData(); //get all previous saved data from database class
	for (int i = 0; i < dataPrev.size(); i++)
	{
		if (dataPrev[i]->dataTitle() == "Users")
		{
			//down casting from base to derived object: Savedata to Users
			allUsers.push_back(static_cast<Users*>(dataPrev[i]));
		}//if
		else
		{
			allService.push_back(static_cast<Service*>(dataPrev[i]));//down casting
		}//elseIf
	}//for
	return true;
}

//setSteps function parse a string that contains step information and store into allSteps by calling setAction function from step class
bool Manager::setSteps() {
	string parse_action = R"(
    0 signIn 1
    0 createAccount 1
    1 buyMenu 2
    1 sellMenu 3
    1 signOut 0
    2 displayAvailableService 2
    2 buyService 2
    2 viewHistory 1
    2 goBack 1
    3 addService 1
    3 goBack 1
    )";
	stringstream ss(parse_action);
	int index, next_index;
	string action;
	while (ss >> index >> action >> next_index) {
		allSteps[index].setAction(action, &allSteps[next_index]);
	}
	currentStep = &allSteps[0];  //initiate current step to step0
	return true;
}

//execute function implement all the user interface process
void Manager::execute()
{
	//output initial greeting upon sign in
	cout << "Welcome To ServiceBay!\n\nHere, you will find a wide variety of services for any need.\nYou can also sell a service and be your own boss!\n\n";
	cout << "What would you like to do?\n";

	//user will go from one step to another follow allSteps set before
	while (true)
	{
		map<string, string> convert;

		//get all actions of current step in the process
		for (int i = 0; i < currentStep->getActions().size(); i++) {
			cout << i + 1 << "." << currentStep->getActions()[i] << "\n";
			convert[to_string(i + 1)] = currentStep->getActions()[i]; //a convert map from number action to alphabet one
		}
		if (currentStep == &allSteps[0]) {
			cout << "[Or enter 'Q' to exit the marketplace]\n";
		}

		//user selects their choice of what to do
		string action;
		cin >> action;

		if (action == "q" || action == "Q")
		{
			cout << endl << "Thank you for visiting ServiceBay. Goodbye!" << endl << endl;
			break;
		}

		if (convert.find(action) != convert.end()) { //if user enter number action
			action = convert[action];  //convert number to alphabet action
		}

		if (currentStep->nextStep(action) != nullptr)   //if input is correct
		{
			if (executeAction(action)) //execute user action
			{
				currentStep = currentStep->nextStep(action); //goes to next step
			}
		}//if
		else
		{
			cout << "wrong input" << endl << endl;
		}//else
	}//while
}//execute

//Excecute the action users choice
bool Manager::executeAction(string action){
    

	if (action == "signIn") {
		return signIn();
	}
	else if (action == "createAccount") {
		return createAccount();
	}
	else if (action == "signOut") {
		return signOut();
	}
	else if (action == "buyMenu") {
		return buyMenu();
	}
	else if (action == "sellMenu") {
		return sellMenu();
	}
	else if (action == "buyService") {
		return buyService();
	}
	else if (action == "addService") {
		return addService();
	}
	else if (action == "displayAvailableService") {
		return displayAvailableService();
	}
	else if (action == "viewHistory") {
		return viewHistory();
	}
	else if (action == "goBack") {
		cout << "MAIN MENU" << endl;
		return goBack();
	}
	cout << endl << endl;
	return false;
}

//createAccount function prompt user enter user information, create an user object and push back to allUsers vectore
//then update current user
bool Manager::createAccount() {
	cout << "Enter your firstName: ";
	string first, last, email;
	cin >> first;
	cout << "Enter your lastName: ";
	cin >> last;
	cout << "Enter your email: ";
	cin >> email; cout << endl;
	for (Users* user : allUsers)
	{
		if (user->getEmail() == email) return false; //if this email already exists, return false
	}//for

	//create a new user object and push into users vector
	Users* newUser = new Users(first, last, email); //create newuser
	allUsers.push_back(newUser);
	currentUser = allUsers.back();

	database->saveData(currentUser);

	//welcome the new user
	cout << "Welcome,";
	if (currentUser)
	{
		cout << " " + currentUser->getFirst();
	}//if
	cout << "!\nWhat would you like to do?\n" << endl << "MAIN MENU" << endl;
	return true;
}

bool Manager::signIn() {
	cout << "Enter your email: ";
	string email;
	cin >> email; cin.ignore(1000, 10);
	cout << endl;
	for (Users* user : allUsers) {  //reference not copy of each user
		if (user->getEmail() == email)
		{
			currentUser = user;
			cout << "Welcome";
			if (currentUser) {
				cout << ", " + currentUser->getFirst();
			}
			cout << "!\n" << "What would you like to do?\n" << endl << "MAIN MENU" << endl;

			return true;
		}
	}
	return false;
}

bool Manager::buyMenu()
{
	cout << "\nWelcome to the buy menu. Please select one of the options below:\n\nBUY MENU" << endl;
	return true;
}

bool Manager::sellMenu()
{
	cout << "\nWelcome to the sell menu. Please select one of the options below:\n\nSELL MENU" << endl;
	return true;
}

bool Manager::signOut() {
	currentUser = nullptr;
	return true;
}

bool Manager::displayAvailableService()
{
	cout << "All Services:" << endl;
	cout << "#    Service               Location                 Price       Available?" << endl;
	cout << "-    -------               --------                 -----       ----------" << endl;
	for (int i = 0; i < allService.size(); i++)
	{
		allService[i]->printServiceTable(i + 1);
	}//for
	cout << endl;
	return true;
}

bool Manager::buyService()
{
	//Display the list of available services
	displayAvailableService();

	//User enters the index number of the service they want in the list above
	int choice;
	string s;
	cout << "Which service would you like to choose? [or enter -99 to go back]: ";
	getline(cin, s);
	stringstream(s) >> choice;
	cout << endl;
	if (choice <= 0 || choice > allService.size()) return false;

	//details about the service they selected are printed
	allService[choice - 1]->printService();

	//prompt the user to buy the service or go back to the menu
	char yn = 'x';
	cout << "Would you like to buy this service? [Y/N]: ";
	while (getline(cin, s))
	{
		stringstream(s) >> yn;
		yn = toupper(yn);
		//cout << "Would you like to buy this service? [Y/N]: ";
		try
		{
			if (yn == 'Y')
			{
				//if service unavailable reject
				if (allService[choice - 1]->getAvail() == false) throw 666;
				//execute the buy option
				allService[choice - 1]->setBuyer(currentUser->getEmail());
				allService[choice - 1]->setAvail(false);
				database->saveData(allService[choice - 1]);
				break;
			}//if
			if (yn == 'N') return false;
			else throw yn;
		}//try
		catch (int)
		{
			cout << endl << "Sorry, this service is unavailable!" << endl << endl;
			return false;
		}//catch
		catch (char)
		{
			cout << "Invalid Entry. You must enter either 'y' to buy the service or 'n' to go back." << endl << endl;
			cout << "Would you like to buy this service? [Y/N]: ";
		}//catch
	}//while
	cout << endl << "You have just successfully purchased the ";
	cout << allService[choice - 1]->getName() << " service." << endl;
	cout << endl << "BUY MENU" << endl;

	return true;
}//buyService



bool Manager::viewHistory()
{
	//new index to print out table
	int index = 1;

	//print out the table of previously purchased services
	cout << "PURCHASE HISTORY" << endl << endl;
	//cout << "----------------" << endl << endl;
	cout << "#    Service               Location                 Price       Available?" << endl;
	cout << "-    -------               --------                 -----       ----------" << endl;
	for (Service* service : allService)
	{
		if (service->getBuyer() == currentUser->getEmail())
		{
			service->printServiceTable(index);
			index++;
		}//if
	}//for
	cout << endl;

	//user is prompted to view details of any of the services in their history
	int choice;
	string buf;
	cout << "Enter a service number to view details, or -99 to return: ";
	cin >> buf; choice = atoi(buf.c_str()); cin.ignore(1000, 10);
	cout << endl;
	if (choice == -99) { cout << endl << "MAIN MENU" << endl; return true; }
	int index2 = 1;
	for (Service* service : allService)
	{
		if (service->getBuyer() == currentUser->getEmail())
		{
			if (index2 == choice)
			{
				service->printService();
			}//ifInner
			index2++;
		}//ifOuter
	}//for
	cout << endl << "MAIN MENU" << endl;
	return true;
}//viewHistory

bool Manager::goBack() {
	return true;
}

bool Manager::addService()
{
	//output menu
	cout << "What type of service are you offering? [or enter 99 to go back]" << endl << endl;
	cout << "1. Business/Office Services (subject to fee)" << endl;
	cout << "2. Automotive Services" << endl;
	cout << "3. Personal Services" << endl;
	cout << "4. Home Services" << endl << endl;

	//user selects choice
	int choice = 98;
	cin >> choice;
	if (choice == 99)
	{
		cout << "MAIN MENU" << endl;
		return true;
	}//if

	//add a new business service object
	if (choice == 1)
	{
		BusinessService* bus1 = new BusinessService();
		bus1->addBusService();
		allService.push_back(bus1);
		database->saveData(bus1);
	}//ifOne

	//add a new automotive service object
	if (choice == 2)
	{
		AutomotiveService* auto1 = new AutomotiveService();
		auto1->addAutoService();
		allService.push_back(auto1);
		database->saveData(auto1);
	}//ifTwo

	//add a new personal service object
	if (choice == 3)
	{
		PersonalService* per1 = new PersonalService();
		per1->addPerService();
		allService.push_back(per1);
		database->saveData(per1);
	}//ifThree

	//add a new home service objects
	if (choice == 4)
	{
		HomeService* home1 = new HomeService();
		home1->addHomeService();
		allService.push_back(home1);
		database->saveData(home1);
	}//ifFour

	return true;
}//addService


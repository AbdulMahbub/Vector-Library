#include "Library.h"
#include <limits>

using namespace std;

Library::Library() {}

void Library::runProgram()
{
	string trash = "";
	char action = 0;

	// Start Library with 5 books
	Book myBook1("The Starless Sea", "Eren Morgenstern", 9780593106488, false);
	books.push_back(myBook1);

	Book myBook2("Mark of Athena", "Rick Riordan", 9788424652791, false);
	books.push_back(myBook2);

	Book myBook3("The Fourth Stall", "Chris Rylander", 9780061994975, false);
	books.push_back(myBook3);

	Book myBook4("The Insitute", "Stephen King", 9781982110567, false);
	books.push_back(myBook4);

	Book myBook5("The Giver of Stars", "Jojo Moyes", 9781984879967, false);
	books.push_back(myBook5);
	// Start Library with 5 books



	// Start Library with 5 journals
	Journal myJournal1("Marijuana and the Brain", 3, 349323653, false);
	journals.push_back(myJournal1);

	Journal myJournal2("Why Cows Understand Emotions", 2, 48539233, false);
	journals.push_back(myJournal2);

	Journal myJournal3("The Science Behind Weather", 7, 84592485, false);
	journals.push_back(myJournal3);

	Journal myJournal4("Journal of Greek Mythology", 5, 98470234, false);
	journals.push_back(myJournal4);

	Journal myJournal5("History of the Aztecs", 1, 35485903, false);
	journals.push_back(myJournal5);
	// Start Library with 5 journals

	// Start Library with 5 magazines
	Magazine myMagazine1("Glamour", 3, 84592054, false);
	magazines.push_back(myMagazine1);

	Magazine myMagazine2("Men's Fitness", 5, 94503581, false);
	magazines.push_back(myMagazine2);

	Magazine myMagazine3("TIMES", 11, 38494523, false);
	magazines.push_back(myMagazine3);

	Magazine myMagazine4("Cosmo", 6, 74589234, false);
	magazines.push_back(myMagazine4);

	Magazine myMagazine5("Celebrity Tea", 4, 49345890, false);
	magazines.push_back(myMagazine5);
	// Start Library with 5 magazines

	displayChoices();
	while (true)
	{
		try
		{	// Calling functions for main menu

			cout << "\nPlease select: ";
			cin >> action; getline(cin, trash);
			switch (action) {
			case '1':searchItem();
				break;
			case '2':checkoutItem();
				break;
			case '3':returnItem();
				break;
			case '4':addItem();
				break;
			case '5': displayChoices();
				break;
			case '6':
				return;

			default:cout << "Invalid Input. Try again.\n";
			}

		}
		catch (exception e)
		{
			cout << e.what() << endl;
			cin.clear();
			getline(cin, trash);
		}
	}
}

void Library::printBooks()		// Store name into variable then list book names
{
	vector<Book>::iterator index;

	for (index = books.begin(); index != books.end(); index++)
	{
		string temp;
		temp=index->getName();
		cout << temp;
		cout << endl;

	}

}

void Library::printJournals()		// Store name into variable then list journal names
{
	vector<Journal>::iterator index;

	for (index = journals.begin(); index != journals.end(); index++)
	{
		string temp;
		temp = index->getName();
		cout << temp;
		cout << endl;

	}
}

void Library::printMagazines()		// Store name into variable then list magazine names
{
	vector<Magazine>::iterator index;

	for (index = magazines.begin(); index != magazines.end(); index++)
	{
		string temp;
		temp = index->getName();
		cout << temp;
		cout << endl;

	}
}

void Library::displayChoices() const
{
	cout << "\n     Main Menu" << endl;
	cout << "--------------------" << endl;
	cout << "1. Search Catalog" << endl;
	cout << "2. Check Out" << endl;			
	cout << "3. Return" << endl;			
	cout << "4. Add a new item" << endl;	
	cout << "5. Display Menu" << endl;
	cout << "6. Exit" << endl;
}

void Library::addBook()
{
	string tempItem;
	cout << "\nEnter the work's name: ";
	getline(cin, tempItem);
	cin.clear();

	vector<Book>::iterator index;		//Loop to see if book already exists
	for (index = books.begin(); index != books.end(); index++)
	{
		string temp;
		temp = index->getName();

		if (tempItem == temp) {		// If books share a name 

			string tempAN;
			cout << "Enter the author's name: ";
			getline(cin, tempAN);
			cin.clear();

			string temp2;
			temp2 = index->getAuthor_name();

			if (tempAN == temp2)		// Check if same book name shares the same author
			{
				cout << "\nBook by this author already exists." << endl;
				cout << "Returning to menu..." << endl;
				return;
			}

			int tempID;
			cout << "Enter it's ID: ";

			while (!(cin >> tempID)) {		// Handles any input that isn't an integer
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "ID must be an int. Book not added.\n";
				return;
			}

			Book myBook(tempItem, tempAN, tempID, false);
			books.push_back(myBook);

			cout << "Book added to library." << endl;
			return;

		}

	}

	string tempAN;
	cout << "Enter the author's name: ";
	getline(cin, tempAN);
	cin.clear();


	int tempID;
	cout << "Enter it's ID: ";

	while (!(cin >> tempID)) {		// Handles any input that isn't an integer
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "ID must be an int. Book not added.\n";
		return;
	}

	Book myBook(tempItem, tempAN, tempID, false);
	books.push_back(myBook);

	cout << "Book added to library." << endl;
}

void Library::addJournal()
{
	string tempItem1;
	cout << "\nEnter the work's name: ";
	getline(cin, tempItem1);
	cin.clear();

	vector<Journal> ::iterator index;		//Loop to see if journal already exists
	for (index = journals.begin(); index != journals.end(); index++)
	{
		string temp;
		temp = index->getName();

		if (tempItem1 == temp) {
			cout << "Journal cannot be added if it's already inside the library" << endl;
			return;
		}

	}

	int tempVol;
	cout << "Enter the volume: ";

	while (!(cin >> tempVol)) {		// Handles any input that isn't an integer
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Volume must be an int. Journal not added.\n";
		return;
	}

	int tempID;
	cout << "Enter it's ID: ";

	while (!(cin >> tempID)) {		// Handles any input that isn't an integer
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "ID must be an int. Journal not added.\n";
		return;
	}

	Journal myJournal(tempItem1, tempVol, tempID, false);
	journals.push_back(myJournal);

	cout << "Journal added to library." << endl;
}

void Library::addMagazine()
{
	string tempItem1;
	cout << "\nEnter the work's name: ";
	getline(cin, tempItem1);
	cin.clear();

	vector<Magazine> ::iterator index;		//Loop to see if journal already exists
	for (index = magazines.begin(); index != magazines.end(); index++)
	{
		string temp;
		temp = index->getName();

		if (tempItem1 == temp) {
			cout << "Magazine cannot be added if it's already inside the library" << endl;
			return;
		}

	}

	int tempIssue;
	cout << "Enter the issue number: ";

	while (!(cin >> tempIssue)) {		// Handles any input that isn't an integer
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Issue number must be an int. Magazine not added.\n";
		return;
	}

	int tempID;
	cout << "Enter it's ID: ";

	while (!(cin >> tempID)) {		// Handles any input that isn't an integer
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "ID must be an int. Magazine not added.\n";
		return;
	}

	Magazine myMagazine(tempItem1, tempIssue, tempID, false);
	magazines.push_back(myMagazine);

	cout << "Magazine added to library." << endl;
}

void Library::addItem()
{
	cout << "Type the item's category: Book, Magazine, Journal\n" << endl;

	string choice;
	getline(cin, choice);
	cin.clear();

	if (choice == "Book")
	{
		addBook();
	}

	else if (choice == "Journal")
	{
		addJournal();
	}

	else if (choice == "Magazine")
	{
		addMagazine();
	}

	else
	{
		cout << "Error: Input must be one of the keywords." << endl;
		cout << "Returning to menu..." << endl;
		displayChoices();
		return;
	}

}

void Library::checkoutItem()
{

	cout << "Type the item's category: Book, Magazine, Journal\n" << endl;

	string choice;
	getline(cin, choice);
	cin.clear();

	if (choice == "Book")
	{
		string tempItem;

		cout << "\nEnter an item to check out: ";
		getline(cin, tempItem);
		cin.clear();

		vector<Book>::iterator index2;
		int check = 0;

		for (index2 = books.begin(); index2 != books.end(); index2++) {

			if (index2->getName() == tempItem)
			{
				check++;			// For loop that tests how many books with name exist
			}

		}

		if (check == 1)		//If only one book has that name 
		{
			vector<Book>::iterator index;
			for (index = books.begin(); index != books.end(); index++) {
				if ((index->getName()) == tempItem) {

					if (index->getStatus() == false)
					{
						index->setStatus(true);
						cout << "Item Checked Out" << endl;
						return;
					}

					else
					{
						cout << "Item is already checked out" << endl;
						return;
					}
				}
			}

		}

		else if(check>1)	// If more than one book share a name
		{
			string tempname;
			cout << "Some books in the library share that name." << endl;
			cout << "Enter that book's author name:";
			getline(cin, tempname);
			cin.clear();

			vector<Book>::iterator index;
			for (index = books.begin(); index != books.end(); index++) {
				if ((index->getAuthor_name()) == tempname) {

					if (index->getStatus() == false)
					{
						index->setStatus(true);
						cout << "Item Checked Out" << endl;
						return;
					}

					else
					{
						cout << "Item is already checked out" << endl;
						return;
					}
				}
			}
		}

		cout << "Book not found" << endl;

	}

	else if (choice == "Journal")
	{
		string tempItem;

		cout << "\nEnter an item to check out: ";
		getline(cin, tempItem);
		cin.clear();

		vector<Journal>::iterator index;

		for (index = journals.begin(); index != journals.end(); index++) {
			if ((index->getName()) == tempItem) {

				if (index->getStatus() == false)
				{
					index->setStatus(true);
					cout << "Item Checked Out" << endl;
					return;
				}

				else
				{
					cout << "Item is already checked out" << endl;
					return;
				}
			}
		}

		cout << "Journal not found" << endl;

	}
	// sdfhskldjflksdj

	else if (choice == "Magazine")
	{
		string tempItem;

		cout << "\nEnter an item to check out: ";
		getline(cin, tempItem);
		cin.clear();

		vector<Magazine>::iterator index;
		for (index = magazines.begin(); index != magazines.end(); index++) {
			if ((index->getName()) == tempItem) {

				if (index->getStatus() == false)
				{
					index->setStatus(true);
					cout << "Item Checked Out" << endl;
					return;
				}

				else
				{
					cout << "Item is already checked out" << endl;
					return;
				}
			}
		}

		cout << "Magazine not found" << endl;

	}

	else
	{
		cout << "Error: Input must be one of the keywords." << endl;
		cout << "Returning to menu..." << endl;
		displayChoices();
		return;
	}
}


void Library::searchItem()
{
	cout << "Type the item's category: Book, Magazine, Journal\n" << endl;

	string choice;
	getline(cin, choice);
	cin.clear();

	if (choice == "Book")
	{
		cout << "\nBooks affiliated with Library" << endl;
		cout << "-----------------------------" << endl;

		printBooks();

		string find;

		cout << "\nEnter the author name of the book that you want to search: ";
		getline(cin, find);
		cin.clear();

		vector<Book>::iterator index2;
		int check = 0;

		for (index2 = books.begin(); index2 != books.end(); index2++) {

			if (index2->getAuthor_name() == find)
			{
				check++;			// For loop that tests how many books author has
			}				

		}

		if (check == 0)		// If author's book is not in the library
		{
			cout << "Book not found" << endl;
		}

		else if (check == 1)		// Searches if author only has one book
		{
			vector<Book>::iterator index4;
			for (index4 = books.begin(); index4 != books.end(); index4++)
			{
				if (index4->getAuthor_name() == find) {

					index4->printBook();
					return;

				}
			}
	
		}

		// See if the book searched shares an author name 
		else if (check > 1)
		{

			cout << find << " has more than one book." << endl << endl;
			cout << find << "'s books" << endl;
			cout << "----------------------------------"<< endl;

			vector<Book>::iterator sameAuthor;		//Print list of books under author name
			for (sameAuthor = books.begin(); sameAuthor != books.end(); sameAuthor++)
			{
				if (sameAuthor->getAuthor_name() == find)
				{
					string bkName = sameAuthor->getName();
					cout << bkName << endl;
				}
			}

			cout << "\nEnter the book's name: ";
			string tempName;
			getline(cin, tempName);
			cin.clear();

			vector<Book>::iterator index3;
			for (index3 = books.begin(); index3 != books.end(); index3++)
			{
				if (tempName == index3->getName())
				{
					index3->printBook();
					return;
				}

			}

			cout << "Book not found" << endl;

		}


	}

	else if (choice == "Journal")
	{
		cout << "\nJournals affiliated with Library" << endl;
		cout << "--------------------------------" << endl;

		printJournals();

		string find;

		cout << "\nEnter the name of the journal that you want to search: ";
		getline(cin, find);
		cin.clear();

		vector<Journal>::iterator index2;

		for (index2 = journals.begin(); index2 != journals.end(); index2++) {
			if ((index2->getName()) == find) {

				index2->printJournal();
				return;
			}
		}

		cout << "Journal not found" << endl;

	}
	

	else if (choice == "Magazine")
	{
		cout << "\nMagazines affiliated with Library" << endl;
		cout << "---------------------------------" << endl;

		printMagazines();

		string find;

		cout << "\nEnter the name of the magazine that you want to search: ";
		getline(cin, find);
		cin.clear();

		vector<Magazine>::iterator index2;

		for (index2 = magazines.begin(); index2 != magazines.end(); index2++) {
			if ((index2->getName()) == find) {

				index2->printMagazine();
				return;
			}
		}

		cout << "Magazine not found" << endl;

	}

	else
	{
		cout << "Error: Input must be one of the keywords." << endl;
		cout << "Returning to menu..." << endl;
		displayChoices();
		return;
	}
}

void Library::returnItem()
{
	cout << "Type the item's category: Book, Magazine, Journal\n" << endl;

	string choice;
	getline(cin, choice);
	cin.clear();

	if (choice == "Book")
	{
		string tempItem;

		cout << "\nEnter an item to return: ";
		getline(cin, tempItem);
		cin.clear();

		vector<Book>::iterator index2;
		int check = 0;

		for (index2 = books.begin(); index2 != books.end(); index2++) {

			if (index2->getName() == tempItem)
			{
				check++;			// For loop that tests how many books with name exist
			}

		}

		if (check == 1)		//If only one book has that name 
		{
			vector<Book>::iterator index;
			for (index = books.begin(); index != books.end(); index++) {
				if ((index->getName()) == tempItem) {

					if (index->getStatus() == true)
					{
						index->setStatus(false);
						cout << "Item Returned" << endl;
						return;
					}

					else
					{
						cout << "Item is already in stock." << endl;
						return;
					}
				}
			}

		}

		else if (check > 1)	// If more than one book share a name
		{
			string tempname;
			cout << "Some books in the library share that name." << endl;
			cout << "\nEnter that book's author name:";
			getline(cin, tempname);
			cin.clear();

			vector<Book>::iterator index;
			for (index = books.begin(); index != books.end(); index++) {
				if ((index->getAuthor_name()) == tempname) {

					if (index->getStatus() == true)
					{
						index->setStatus(false);
						cout << "Item Returned" << endl;
						return;
					}

					else
					{
						cout << "Item is already in stock" << endl;
						return;
					}
				}
			}
		}

		cout << "That book is not affiliated with the library." << endl;
	}

	else if (choice == "Journal")
	{
		string tempItem;

		cout << "\nEnter an item to return: ";
		getline(cin, tempItem);
		cin.clear();

		vector<Journal>::iterator index;

		for (index = journals.begin(); index != journals.end(); index++) {
			if ((index->getName()) == tempItem) {

				if (index->getStatus() == true)
				{
					index->setStatus(false);
					cout << "Item Returned" << endl;
					return;
				}

				else
				{
					cout << "Item is already in stock" << endl;
					return;
				}
			}
		}

		cout << "That journal is not affiliated with the library." << endl;
	}
	

	else if (choice == "Magazine")
	{
		string tempItem;

		cout << "\nEnter an item to return: ";
		getline(cin, tempItem);
		cin.clear();

		vector<Magazine>::iterator index;

		for (index = magazines.begin(); index != magazines.end(); index++) {
			if ((index->getName()) == tempItem) {

				if (index->getStatus() == true)
				{
					index->setStatus(false);
					cout << "Item Returned" << endl;
					return;
				}

				else
				{
					cout << "Item is already in stock" << endl;
					return;
				}
			}
		}

		cout << "That magazine is not affiliated with the library." << endl;
	}

	else
	{
		cout << "Error: Input must be one of the keywords." << endl;
		cout << "Returning to menu..." << endl;
		displayChoices();
		return;
	}
}

#ifndef LIBRARY_H
#define LIBRARY_H
#include <string>
#include <vector>
#include <algorithm>
#include "Book.h"
#include "Journal.h"
#include "Magazine.h"

class Library
{
public:
	Library();	//Constructor
	void runProgram();

private:

	void displayChoices() const;
	void checkoutItem();
	void returnItem();
	void searchItem();
	void addItem();
	void addBook();
	void addJournal();
	void addMagazine();
	void printBooks();
	void printJournals();
	void printMagazines();

	std::vector<Book> books;
	std::vector<Journal> journals;
	std::vector<Magazine> magazines;
};
#endif // !LIBRARY_H

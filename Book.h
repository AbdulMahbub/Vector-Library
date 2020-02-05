#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>

class Book
{
public:
	Book(std::string n = "", std::string An = "", int id = 0, bool stat = false); //Constructor
	void setName(std::string n);
	void setAuthor_name(std::string An);
	void setID(int id);
	void setStatus(bool stat);

	std::string getName() const;
	std::string getAuthor_name() const;
	int getID() const;
	bool getStatus() const;
	void printBook() const;

private:
	std::string name;
	std::string Author_name;
	int ID;
	bool status;		// False= In Library		True= Checked Out
};

#endif // !Book_H


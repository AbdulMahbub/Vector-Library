#include "Book.h"

Book::Book(std::string n, std::string An, int id, bool stat)	//Make sure order is right
	:name(n), Author_name(An), ID(id), status(stat) {}

void Book::setName(std::string n)
{
	name = n;
}

void Book::setID(int id)
{
	ID = id;
}

void Book::setAuthor_name(std::string An)
{
	Author_name = An;
}

void Book::setStatus(bool stat)
{
	status = stat;
}

std::string Book::getName() const
{
	return name;
}

int Book::getID() const
{
	return ID;
}

std::string Book::getAuthor_name() const
{
	return Author_name;
}

bool Book::getStatus()const
{
	return status;
}

void Book::printBook() const
{
	std::cout << "Name: " << name;
	std::cout << "\nAuthor Name: " << Author_name;
	std::cout << "\nID: " << ID;

	if (status == false) {
		std::cout << "\nStatus: " << "In Stock" << std::endl;
	}

	else
		std::cout << "\nStatus: " << "Checked Out" << std::endl;
}

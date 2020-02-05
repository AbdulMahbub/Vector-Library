#include "Magazine.h"

Magazine::Magazine(std::string n, int iss, int id, bool stat)	//Make sure order is right
	:name(n), issue(iss), ID(id), status(stat) {}

void Magazine::setName(std::string n)
{
	name = n;
}

void Magazine::setID(int id)
{
	ID = id;
}

void Magazine::setIssue(int iss)
{
	issue = iss;
}

void Magazine::setStatus(bool stat)
{
	status = stat;
}

std::string Magazine::getName() const
{
	return name;
}

int Magazine::getID() const
{
	return ID;
}

int Magazine::getIssue() const
{
	return issue;
}

bool Magazine::getStatus()const
{
	return status;
}

void Magazine::printMagazine() const
{
	std::cout << "Name: " << name;
	std::cout << "\nIssue: " << issue;
	std::cout << "\nID: " << ID;

	if (status == false) {
		std::cout << "\nStatus: " << "In Stock" << std::endl;
	}

	else
		std::cout << "\nStatus: " << "Checked Out" << std::endl;
}
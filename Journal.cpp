#include "Journal.h"

Journal::Journal(std::string n, int vol, int id, bool stat)	//Make sure order is right
	:name(n), volume(vol), ID(id), status(stat) {}

void Journal::setName(std::string n)
{
	name = n;
}

void Journal::setID(int id)
{
	ID = id;
}

void Journal::setVolume(int vol)
{
	volume = vol;
}

void Journal::setStatus(bool stat)
{
	status = stat;
}

std::string Journal::getName() const
{
	return name;
}

int Journal::getID() const
{
	return ID;
}

int Journal::getVolume() const
{
	return volume;
}

bool Journal::getStatus()const
{
	return status;
}

void Journal::printJournal() const
{
	std::cout << "Name: " << name;
	std::cout << "\nVolume: " << volume;
	std::cout << "\nID: " << ID;

	if (status == false) {
		std::cout << "\nStatus: " << "In Stock" << std::endl;
	}

	else
		std::cout << "\nStatus: " << "Checked Out" << std::endl;
}
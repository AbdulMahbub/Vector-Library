#ifndef JOURNAL_H
#define JOURNAL_H
#include <iostream>
#include <string>

class Journal
{
public:
	Journal(std::string n = "", int vol=0, int id = 0, bool stat = false);	//Constructor
	void setName(std::string n);
	void setVolume(int vol);
	void setID(int id);
	void setStatus(bool stat);

	std::string getName() const;
	int getVolume() const;
	int getID() const;
	bool getStatus() const;
	void printJournal() const;

private:
	std::string name;
	int volume;
	int ID;
	bool status;		// False= In Library		True= Checked Out
};

#endif //  !JOURNAL_H

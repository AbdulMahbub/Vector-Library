#ifndef MAGAZINE_H
#define MAGAZINE_H
#include <iostream>
#include <string>

class Magazine
{
public:
	Magazine(std::string n = "", int iss = 0, int id = 0, bool stat = false);	//Constructor
	void setName(std::string n);
	void setIssue(int iss);
	void setID(int id);
	void setStatus(bool stat);

	std::string getName() const;
	int getIssue() const;
	int getID() const;
	bool getStatus() const;
	void printMagazine() const;

private:
	std::string name;
	int issue;
	int ID;
	bool status;		// False= In Library		True= Checked Out
};

#endif //  !MAGAZINE_H
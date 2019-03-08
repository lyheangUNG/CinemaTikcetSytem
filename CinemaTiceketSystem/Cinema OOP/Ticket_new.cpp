#include "Ticket.h"
#include <string>
#include <iomanip>

using namespace std;

Room * Ticket::getRoom()
{
	return room;
}

void Ticket::setTitle(std::string title)
{
	movieTitle = title;
}

void Ticket::setAge(int a)
{
	age = a;
}

void Ticket::setBarcode(int a)
{
	barcode = a;
}

void Ticket::setTicketNum(int a)
{
	ticketNum = std::to_string(a);
}

void Ticket::setDate(int day, int month, int year)
{
	issueDate.day = day;
	issueDate.month = month;
	issueDate.year = year;
	expireDate.day = issueDate.day + 1;
	expireDate.month = issueDate.month + 1;
	expireDate.year = issueDate.year + 1;
}

void Ticket::setRoom(int roomNum)
{
	Room *room1 = new Room(40, 10);
	Room *room2 = new Room(40, 15);
	if (roomNum == 1)
		room = room1;
	else if (roomNum == 2)
		room = room2;
}

/*void Ticket::inputTicketInfo()
{
	cin >> *this;
}*/

unsigned long long int Ticket::getBarcode()
{
	return barcode;
}

void Ticket::displayTicketInfo()
{
	cout << *this;
}

Ticket::Ticket()
{
}


Ticket::~Ticket()
{
}

/*istream & operator<<(istream & is, Ticket & t)
{
	Room r;
	cout << "\t\tInput Ticket Info" << endl;
	cout << "Ticket Num: "; cin >> t.ticketNum;
	cout << "Movie Title: "; cin >> t.movieTitle;




}*/

ostream & operator<<(ostream & os, Ticket &t)
{
	os << "Ticket No: " << t.ticketNum << endl;
	os << "Movie Title: " << t.movieTitle << endl;
	cout << "Time: " << t.time.hour << ":" << t.time.min << endl;
	cout << "Issue Date: " << t.issueDate.month << "/" << t.issueDate.day << "/" << t.issueDate.year << endl;
	cout << "Expire Date: " << t.expireDate.month << "/" << t.expireDate.day << "/" << t.expireDate.year << endl;
	cout << "Barcode: " << t.barcode << endl;
	return os;
}

#include "Ticket.h"
#include<iostream>
#include<time.h>
#include<sstream>
using namespace std;

void Ticket::inputErrorPrevention(int *menuOption) {
	bool check_fail;
	do {
		cout << "Option: ";
		cin >> *menuOption;
		check_fail = cin.fail();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << endl;
		cout << "\033[1;33mWarning!\033[0m" << endl;
		cout << "Please enter number only" << endl;
		cout << "========================" << endl;
		cout << endl;

	} while (check_fail == true);
}

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

void Ticket::setTicketNum()
{
	ticketNum = std::to_string(seatNum);
}

void Ticket::setDate(int issueDay, int issueMonth,
	int issueYear, int expDay, int expMonth, int expYear)
{
	issueDate.day = issueDay;
	issueDate.month = issueMonth;
	issueDate.year = issueYear;
	expireDate.day = expDay;
	expireDate.month = expMonth;
	expireDate.year = expYear;
}

void Ticket::setTime(unsigned int hour, unsigned int min)
{
	airingTime.hour = hour;
	airingTime.min = min;
}

void Ticket::setRoom(Room * room)
{
	this->room = room;
}

void Ticket::setSeatNum(unsigned int seatNum)
{
	this->seatNum = seatNum;
	setTicketNum();
}

//void Ticket::inputTicketInfo()
//{
//
//}

std::string Ticket::getTicketNum()
{
	return ticketNum;
}

unsigned long long int Ticket::getBarcode()
{
	return barcode;
}

int Ticket::getHour()
{
	return airingTime.hour;
}

void Ticket::displayTicketInfo()
{
	cout << *this;
}

void Ticket::setBarcode()
{
	srand(unsigned int(time(nullptr)));
	const string CurrentClientID = "1";
	ostringstream os, os2;
	for (int i = 0; i < 6; ++i) {
		int digit = rand() % 9;
		int digit2 = rand() % 9;
		os << digit;
		os2 << digit2;
	}
	string result = CurrentClientID + os.str() + os2.str();
	istringstream stream(result);
	barcode = stoull(result);
	list_barcode.push_back(barcode);
}

void Ticket::setRoomNum(int a)
{
	roomNum = a;
}

istream & operator>>(istream & is, Ticket & t)
{
	Room r;
	cout << "\t\tInput Ticket Info" << endl;
	cout << "Movie Title: "; is >> t.movieTitle;
	return  is;
}

ostream & operator<<(ostream & os, Ticket &t)
{
	//system("CLS");
	os << "Ticket Number: " << t.ticketNum << endl;
	os << "Ticket Class: " << t.ticketClass << endl;
	os << "Room Number: " << t.roomNum << endl;
	os << "Barcode: " << t.barcode << endl;
	os << "Seat Number: " << t.seatNum << endl;
	os << "Movie Title: " << t.movieTitle << endl;
	os << "Time: " << t.airingTime.hour << ":" << t.airingTime.min << endl;
	os << "Issue Date: " << t.issueDate.month << "/" << t.issueDate.day << "/" << t.issueDate.year << endl;
	os << "Expire Date: " << t.expireDate.month << "/" << t.expireDate.day << "/" << t.expireDate.year << endl;
	os << "Price: " << t.price << endl<<endl;
	//system("PAUSE");
	//system("CLS");
	return os;
}
Ticket::Ticket()
{
	
}


Ticket::~Ticket()
{
}

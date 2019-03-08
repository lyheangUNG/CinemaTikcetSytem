#pragma once
#include<string>
#include<iostream>
#include"Room.h"
using namespace std;
struct Date
{
	unsigned int day, month, year;
};
struct Time
{
	unsigned int hour, min;
};
class Ticket
{
public:
	std::string ticketNum;
	std::string movieTitle, ticketClass;
	Room *room;
	unsigned int age, seatNum, roomNum;
	unsigned long long int barcode;	
	float price;
	Date issueDate, expireDate;
	Time airingTime;
	vector<long long> list_barcode;
public:
	Room *getRoom();
	void setTitle(std::string title);
	void setAge(int a);
	void setBarcode();
	void setRoomNum(int a);
	virtual void setTicketNum();
	void setDate(int issueDay, int issueMonth,
		int issueYear, int expDay, int expMonth, int expYear);
	void setTime(unsigned int hour, unsigned int min);
	void setRoom(Room *room);
	void setSeatNum(unsigned int seatNum);
	//void inputTicketInfo();
	std::string getTicketNum();
	unsigned long long int getBarcode();
	int getHour();
	virtual void displayTicketInfo();
	void inputErrorPrevention(int *menuOption);
	//friend istream& operator>>(istream &is, Ticket &t);
	friend ostream& operator<<(ostream &os, Ticket &t);
	Ticket();
	~Ticket();
};


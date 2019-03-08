#pragma once
#include<string>
#include"Room.h"
#include <iostream>
using namespace std;
class Ticket
{
protected:
	std::string ticketNum;
	std::string movieTitle;
	Room *room;
	unsigned int age;
	unsigned long long int barcode;	
	float price;
	struct Date
	{
		unsigned int day, month, year;
	}issueDate, expireDate;
	struct Time
	{
		unsigned int min, hour;
	}time;
	
public:
	Room *getRoom();
	void setTitle(std::string title);
	void setAge(int a);
	void setBarcode(int a);
	void setTicketNum(int a);
	void setDate(int day, int month, int year);
	void setRoom(int roomNum);
//	virtual double getPrice() = 0;
	virtual void inputTicketInfo();
	virtual void displayTicketInfo();
	unsigned long long int getBarcode();
	friend istream& operator<<(istream &is, Ticket &t);
	friend ostream& operator<<(ostream &os, Ticket &t);
	Ticket();
	~Ticket();
};


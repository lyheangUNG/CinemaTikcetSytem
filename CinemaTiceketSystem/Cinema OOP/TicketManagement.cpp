#include "TicketManagement.h"
#include <string>
#include<algorithm>
#include "Child.h"
#include "ChildVIP.h"
#include "Student.h"
#include "StudentVIP.h"
#include "Teen.h"
#include "TeenVIP.h"
#include "Adult.h"
#include "AdultVIP.h"
#include "Ticket.h"
#include "Room.h"
#include<time.h>
#include<iostream>
using namespace std;

bool TicketManagement::displayAllBarcodes() {
	if (listTicket.empty()) 
	{
		cout << "No Tickets!\n";
		return false;	
	}
	else {
		cout << "All barcodes:\n";
		for (auto i = 0; i < listTicket.size(); i++)
		{
			cout << listTicket[i]->barcode << endl;
		}
		return true;
	}
}

void TicketManagement::searchTicket()
{
	if (listTicket.empty())
	{
		cout << "No Tickets!\n";
	}
	else {
		int ticketClass;
		cout << "1. Classic\n";
		cout << "2. VIP\n";
		cout << "Input the class type : ";
		cin >> ticketClass;
		string ticketSearchNum;
		switch (ticketClass)
		{
		case 1: //classic
		{
			system("CLS");
			cout << "Input ticket number: ";
			cin >> ticketSearchNum;
			for (auto i = 0; i < listTicket.size(); i++)
			{
				if (listTicket[i]->ticketClass == "Classic")
				{
					if (ticketSearchNum == listTicket[i]->ticketNum)
						listTicket[i]->displayTicketInfo();
					else
						cout << "Not found!\n";
				}
			}
			break;
		}
		case 2: //VIP
		{
			system("CLS");
			cout << "Input ticket number: ";
			cin >> ticketSearchNum;
			for (auto i = 0; i < listTicket.size(); i++)
			{
				if (listTicket[i]->ticketClass == "VIP")
				{
					if (ticketSearchNum == listTicket[i]->ticketNum)
						listTicket[i]->displayTicketInfo();
					else
						cout << "Not found!\n";
				}
			}
			break;
		}
		default:
			cout << "Wrong input \n";
			break;
		}
	}
}

void TicketManagement::Sort_By_issueDate()
{
	sort(listTicket.begin(), listTicket.end(), [](Ticket *l, Ticket *r)
	{
		if ((*l).issueDate.year < (*r).issueDate.year) {
			return true;
		}
		else if ((*l).issueDate.year > (*r).issueDate.year) {
			return false;
		}
		else {
			if ((*l).issueDate.month < (*r).issueDate.month) {
				return true;
			}
			else if ((*l).issueDate.month > (*r).issueDate.month) {
				return false;
			}
			else {
				return ((*l).issueDate.day < (*r).issueDate.day);
			}
		}
	});
}


void TicketManagement::find_barcode() {
	
	if (displayAllBarcodes())
	{
		long long user_barcode;
		bool barcode_valid = true;
		cout << "Enter barcode: "; 
		cin >> user_barcode;
		bool check_fail = cin.fail();
		if (check_fail) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << endl;
		}
		for (auto i = 0; i < listTicket.size(); i++) {
			if (user_barcode == listTicket[i]->getBarcode())
			{
				int hour;
				cout << "Enter current hour: "; cin >> hour;
				if (listTicket[i]->getHour() + 2 == hour) {
					cout << "Invalid ticket\n";
				}
				else {
					cout << "OK\n";
					barcode_valid = false;
				}
			}
		}
		if (barcode_valid)
		{
			cout << "Invalid barcode\n";
		}
	}
	system("PAUSE");
}

void TicketManagement::displayAllTicket()
{
	if (listTicket.empty())
		cout << "No Tickets!\n";
	else
		for (auto i = 0; i < listTicket.size(); i++)
		{
			listTicket[i]->displayTicketInfo();
		}
}

//unsigned long long int TicketManagement::returnBarcode()
//{
//	for(auto i=0; i<listTicket.size(); i++)
//		return listTicket[i]->getBarcode();
//}

Ticket * TicketManagement::inputTicket(int ticketType)
{
	Ticket *t = new Ticket;
	switch (ticketType)
	{
	case 1:
	{
		t = new Student;
		return t;
		break;
	}
	default:
		break;
	}
}

//Ticket * TicketManagement::TicketType(int ticketType, int ticketClass)
Ticket * TicketType(int ticketType, int ticketClass)
{
	Ticket *t;
	switch (ticketClass)
	{
	case 1:
	{
		switch (ticketType)
		{
		case 1:
			t = new Student;
			return t;
		case 2:
			t = new Child;
			return t;
		case 3:
			t = new Teen;
			return t;
		case 4:
			t = new Adult;
			return t;
		default:
			break;
		}

	}
	case 2://VIP
	{
		switch (ticketType)
		{
		case 1:
			t = new StudentVIP;
			return t;
		case 2:
			t = new ChildVIP;
			return t;
		case 3:
			t = new TeenVIP;
			return t;
		case 4:
			t = new AdultVIP;
			return t;
		default:
			break;
		}

	}
	default:
		break;
	}
	
}

void TicketManagement::addTicket(int roomNum, int ticketType, int ticketClass, Room *room, 
	string title, int seatNum, int airHour, int airMin, int issueDay, int issueMonth,
	int issueYear, int expDay, int expMonth, int expYear)
{
	Ticket *t = TicketType(ticketType, ticketClass);
	t->setRoomNum(roomNum);
	t->setRoom(room);
	t->setTitle(title);
	t->setSeatNum(seatNum);
	t->setBarcode();
	t->setDate(issueDay,  issueMonth, issueYear,  expDay,  expMonth,  expYear);
	t->setTime(airHour, airMin);
	if (t->room->bookSeat(ticketClass, seatNum))
		cout << "Success";
	else
		cout << "fail";
	system("CLS");
	listTicket.push_back(t);
}

TicketManagement::TicketManagement()
{
}

TicketManagement::~TicketManagement()
{
}

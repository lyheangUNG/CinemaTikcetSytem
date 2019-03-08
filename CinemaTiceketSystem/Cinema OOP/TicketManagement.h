#pragma once
#include "Ticket.h"
#include "Student.h"
#include <vector>
using namespace std;
class TicketManagement
{
public:
	vector<Ticket*> listTicket;
public:
	void displayAllTicket();
	//unsigned long long int returnBarcode();
	Ticket* inputTicket(int ticketType);
	//Ticket* TicketType(int ticketType, int ticketClass);
	void addTicket(int roomNum, int ticketType, int ticketClass, Room *room, 
		string title, int seatNum, int airHour, int airMin, int issueDay, int issueMonth, 
		int issueYear, int expDay, int expMonth, int expYear);
	void find_barcode();
	bool displayAllBarcodes();
	void searchTicket();
	void Sort_By_issueDate();
	TicketManagement();
	~TicketManagement();
};


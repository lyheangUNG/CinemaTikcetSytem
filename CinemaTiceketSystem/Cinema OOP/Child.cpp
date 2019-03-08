#include "Child.h"



void Child::setTicketNum()
{
	ticketNum = "CH00" + std::to_string(seatNum);
	ticketClass = "Classic";
}

Child::Child()
{
	price = 2;
}


Child::~Child()
{
}

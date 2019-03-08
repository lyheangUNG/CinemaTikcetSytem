#include "Teen.h"



void Teen::setTicketNum()
{
	ticketNum = "TE00" + std::to_string(seatNum);
	ticketClass = "Classic";
}

Teen::Teen()
{
	price = 4;
}


Teen::~Teen()
{
}

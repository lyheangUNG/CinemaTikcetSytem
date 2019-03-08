#include "Adult.h"



void Adult::setTicketNum()
{
	ticketNum = "AD00" + std::to_string(seatNum);
	ticketClass = "Classic";
}

Adult::Adult()
{
	price = 5;
}


Adult::~Adult()
{
}
